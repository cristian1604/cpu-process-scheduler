#include "PriorityPreemptive.h"
#include "Process.h"
#include <vector>
#include <list>
using namespace std;

PriorityPreemptive::PriorityPreemptive() {
	
}

void PriorityPreemptive::UpdateReadyProcessList(list <Process> &ProcessList, list <Process> &ReadyProcessList, int bt) {
	list <Process>::iterator it = ProcessList.begin();
	// Agregar los procesos que llegan en el bt indicado
	while (it != ProcessList.end()) {
		if (it->getArrivalTime() <= bt) {
			ReadyProcessList.insert(ReadyProcessList.end(), *it);
			it = ProcessList.erase(it);
		} else {
			++it;
		}
		
	}
	
	// Ordenar procesos por prioridad
	it = ReadyProcessList.begin();
	list <Process>::iterator it2;
	while (it != ReadyProcessList.end()) {
		it2 = it;
		while (it2 != ReadyProcessList.end()) {
			if (it2->getPriority() < it->getPriority()) {
				Process aux = *it;
				*it = *it2;
				*it2 = aux;
			}
			++it2;
		}
		++it;
	}
}

void PriorityPreemptive::SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st) {
	int sizeGantt = 0;
	for (int i = 0; i < P.size(); i++) {
		sizeGantt += P[i].getCpuTime();
	}
	
	// Copiar vector de tareas en una lista que irá eliminando los procesos a medida que sean agregados a la lista de procesos activos
	list <Process> ProcessList;
	for (int i = 0; i < P.size(); i++) {
		P[i].setId(i+1);
		P[i].Gantt.resize(sizeGantt, NONE);
		ProcessList.insert(ProcessList.end(), P[i]);
	}
	
	int bt = 0;
	list <Process> ReadyProcessList;
	list <Process>::iterator it = ProcessList.begin();
	
	UpdateReadyProcessList(ProcessList, ReadyProcessList, bt);	
	
	while (!ReadyProcessList.empty()) {
		it = ReadyProcessList.begin();
		
		it->Gantt[bt++] = PROCESSING;
		it->setCpuTime(it->getCpuTime() - 1);
		
		if (it->getCpuTime() == 0) {
			for (int i = 0; i < P.size(); i++) {
				if (P[i].getId() == it->getId()) {
					P[i].Gantt = it->Gantt;
				}
			}
			ReadyProcessList.erase(it);
		}
		
		UpdateReadyProcessList(ProcessList, ReadyProcessList, bt);
		
	}
	
	avg_wt = calculateWaitingTimes(P);
	
	
}

// Calcular tiempos de espera entre turnos de procesamiento
// Calcula tanto los ServiceTime y los WaitTime, como también setea las esperas en el vector de Gantt
float PriorityPreemptive::calculateWaitingTimes(vector <Process> &P) {
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

