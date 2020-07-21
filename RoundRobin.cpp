#include "RoundRobin.h"
#include <vector>
#include "Process.h"
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

RoundRobin::RoundRobin() {
	
}

#define NONE -1
#define WAITING 0
#define PROCESSING 1

void makeFIFO(list <Process> &ProcessList, list <Process> &FIFO, int bt, int total_burst) {
	list <Process>::iterator itL = ProcessList.begin();
	while (!ProcessList.empty() && itL != ProcessList.end()) {
		if (itL->getArrivalTime() <= bt) {
			//cout<<"Inserto proceso "<<itL->getProcessName()<<" que llega en "<<itL->getArrivalTime()<<" en tiempo "<<bt<<endl;
			FIFO.push_back(*itL);
			((--FIFO.end())->Gantt).resize(total_burst, NONE);
			itL = ProcessList.erase(itL);
		} else {
			++itL;
		}
	}
}

void RoundRobin::SolveGantt(vector <Process> &P, int quantum, float &avg_wt, float &avg_st) {
	// Lista de procesos
	list <Process> ProcessList;
	list <Process> FIFO;
	vector <Process> Res;
	
	// Para conocer la longitud del diagrama, sumo todos los burst-time
	int total_burst = 0;
	for (int i = 0; i < P.size(); i++) {
		P[i].setId(i+1);
		total_burst += P[i].getCpuTime();
	}
	
	// Llenar la ProcessList
	for (int i = 0; i < P.size(); i++) {
		ProcessList.insert(ProcessList.end(), P[i]);
	}
	
	int bt = 0;
	list <Process>::iterator itL;
	makeFIFO(ProcessList, FIFO, bt, total_burst);
	
	while (true) {		
		
		if (FIFO.size() == 0 && !ProcessList.empty()) {
			continue;
		}
		
		int q = 0;
		itL = FIFO.begin();
		if (itL == FIFO.end()) break;
		int remaining_bursts = itL->getCpuTime();
		while (q < quantum && remaining_bursts > 0) {
			itL->Gantt[bt++] = PROCESSING;
			--remaining_bursts;
			++q;
		}
		
		itL->setCpuTime(remaining_bursts);
		
		makeFIFO(ProcessList, FIFO, bt, total_burst);
		
		if (itL->getCpuTime() > 0) {
			FIFO.insert(FIFO.end(), *itL);
		}
		
		if (itL->getCpuTime() == 0) {
			Res.push_back(*itL);
		}
		
		FIFO.erase(FIFO.begin());
		
		if (ProcessList.size() == P.size() && FIFO.empty()) break;
	}
	
	
	// Reestablecer las variables CPUTime
	for (int i = 0; i < P.size(); i++) {
		for (int j = 0; j < Res.size(); j++) {
			if (P[i].getId() == Res[j].getId()) {
				P[i].Gantt = Res[j].Gantt;
				break;
			}
		}
	}
	
	avg_wt = calculateWaitingTimes(P);
	
	/*
	// Show Gantt Diagram on console
	for (int i = 0; i < P.size(); i++) {
	cout<<P[i].getProcessName()<<": ";
	for (int k = 0; k < (P[i].Gantt).size(); k++) {
	switch(P[i].Gantt[k]){
	case NONE:
	cout<<".";
	break;
	case PROCESSING:
	cout<<"X";
	break;
	case WAITING:
	cout<<"w";
	break;
	}
	}
	cout<<endl;
	}
	*/
	
}


// Calcular tiempos de espera entre turnos de procesamiento en RoundRobin
// Calcula tanto los ServiceTime y los WaitTime, como también setea las esperas en el vector de Gantt
float RoundRobin::calculateWaitingTimes(vector <Process> &P) {
	float res = 0;
	int wt;
	
	for (int i = 0; i < P.size(); i++) {
		bool started = false;
		int bursts = P[i].getCpuTime();
		wt = 0;
		for (int j = 0; j < (P[i].Gantt).size(); j++) {
			if (P[i].Gantt[j] == PROCESSING) {
				started = true;
				--bursts;
			}
			
			if ((P[i].Gantt[j] == NONE && started && bursts > 0) || (P[i].Gantt[j] == NONE && P[i].getArrivalTime() <= j  && bursts > 0)) {
				P[i].Gantt[j] = WAITING;			// seteo de espera en el vector de Gantt
				++res;
				++wt;
			}
		}
		P[i].setServiceTime(wt+P[i].getCpuTime());
		P[i].setWaitTime(wt);
	}
	
	return res/P.size();
}
