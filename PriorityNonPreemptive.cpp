#include "PriorityNonPreemptive.h"
#include <list>
#include "Process.h"
#include <iostream>
using namespace std;

PriorityNonPreemptive::PriorityNonPreemptive() {
	
}

void PriorityNonPreemptive::SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st) {
	// Lista de procesos
	list <Process> ProcessList;
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
	Process Prc;
	
	while (!ProcessList.empty()) {
		Prc = findNextProcessToExecute(ProcessList, bt, total_burst);
		int remaining_bursts = Prc.getCpuTime();
		while (remaining_bursts > 0) {
			Prc.Gantt[bt++] = PROCESSING;
			--remaining_bursts;
		}
		
		Prc.setCpuTime(remaining_bursts);
		
		if (Prc.getCpuTime() == 0) {
			Res.push_back(Prc);
		}
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
}


// Función que determina el próximo proceso que deberá ser ejecutado por la CPU
Process PriorityNonPreemptive::findNextProcessToExecute(list <Process> &ProcessList, int bt, int total_burst) {
	Process min = *(ProcessList.begin());
	list <Process>::iterator erase_elem = ProcessList.begin();
	list <Process>::iterator itL = ProcessList.begin();
	(min.Gantt).resize(total_burst, NONE);
	while (itL != ProcessList.end()) {
		if (min.getPriority() > itL->getPriority()) {
			min = *itL;
			(min.Gantt).resize(total_burst, NONE);
			erase_elem = itL;
		} else if (min.getPriority() == itL->getPriority() && min.getArrivalTime() > itL->getArrivalTime()) {
			min = *itL;
			(min.Gantt).resize(total_burst, NONE);
			erase_elem = itL;
		}
		++itL;
	}	
	ProcessList.erase(erase_elem);
	cout<<min.getProcessName()<<endl;
	return min;
}

// Calcular tiempos de espera entre turnos de procesamiento
// Calcula tanto los ServiceTime y los WaitTime, como también setea las esperas en el vector de Gantt
float PriorityNonPreemptive::calculateWaitingTimes(vector <Process> &P) {
	float res = 0;
	int wt;
	for (int i = 0; i < P.size(); i++) {
		bool started = false;
		int bursts = P[i].getCpuTime();
		wt = 0;
		for (int j = 0; j < P[i].Gantt.size(); j++) {
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


