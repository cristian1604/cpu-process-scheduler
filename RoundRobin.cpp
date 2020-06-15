#include "RoundRobin.h"
#include <vector>
#include "Process.h"
#include <iostream>
using namespace std;

RoundRobin::RoundRobin() {
	
}

#define NONE -1
#define WAITING 0
#define PROCESSING 1

void RoundRobin::SolveGantt(vector <Process> &P, int quantum, float &avg_wt, float &avg_st) {
	// Para conocer la longitud del diagrama, sumo todos los burst-time
	int total_burst = 0;
	for (int i = 0; i < P.size(); i++) {
		P[i].setId(i+1);
		total_burst += P[i].getCpuTime();
	}
	
	// ordenar vector por timepo de llegada de cada proceso
	// empleo bubble sort, ya que la cantidad de elementos admite un ordenamiento O(n²)
	Process aux;
	for (int i = 0; i < P.size(); i++) {
		for (int j = i; j < P.size(); j++) {
			if (P[j].getArrivalTime() < P[i].getArrivalTime()) {
				aux = P[i];
				P[i] = P[j];
				P[j] = aux;
			}
		}
		
		// Establecer los vectores de Gantt de cada proceso en cero
		P[i].Gantt.resize(total_burst);
		for (int j = 0; j < total_burst; j++) {
			P[i].Gantt[j] = NONE;
		}
	}
	
	avg_st = 0;
	int remaining_bursts;					// Ráfagas de CPU restantes
	int bt = 0;
	vector <Process> queue = P;
	
	while (bt < total_burst) {
		for (int pos = 0; pos < P.size(); pos++) {
			//if (bt < P[pos].getArrivalTime()) {continue;}
			remaining_bursts = queue[pos].getCpuTime();
			if (remaining_bursts == 0) { continue; }
			
			for (int q = 0; q < quantum; q++) {				
				
				P[pos].Gantt[bt++] = PROCESSING;	
				
				if (--remaining_bursts == 0) { break; }
				
			}
			queue[pos].setCpuTime(remaining_bursts);
		}
	}
	avg_wt = calculateWaitingTimes(P);
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
