#include "SRT.h"
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define NONE -1
#define WAITING 0
#define PROCESSING 1

SRT::SRT() {
	
}

void SRT::SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st) {
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
	avg_wt = 0;
	int remaining_bursts;					// Ráfagas de CPU restantes
	int bt = 0;
	vector <Process> stack = P;
	
	//return; 
	while (bt < total_burst) {
		if (stack.empty()) break;
		int pos = findNextProcessToExecute(P, stack, bt);
		int i = getIndex(stack, P[pos]);
		
		remaining_bursts = stack[i].getCpuTime();
		while (remaining_bursts > 0) {
			P[pos].Gantt[bt++] = PROCESSING;
			stack[i].setCpuTime(--remaining_bursts);
			
			// Buscar si no entra un proceso con un CPU burst más corto para continuar
			int x = findNextProcessToExecute(P, stack, bt);
			if (P[pos].getId() != stack[i].getId()) {
				break;
			}
		}
		
		stack = updateStack(stack);
	}
	avg_wt = calculateWaitingTimes(P);
}


// Esta funcion devuelve el indice del vector principal P para el elemento elem dado
int SRT::getIndex(vector <Process> &P, Process elem) {
	for (int i = 0; i < P.size(); i++) {
		if (P[i].getId() == elem.getId()) {
			return i;
		}
	}
	return -1;
}

// Retorna solo los elementos que restan ser procesados (con CpuTime > 0)
vector <Process> SRT::updateStack(vector <Process> stack) {
	vector <Process> res;
	for (int i = 0; i < stack.size(); i++) {
		if (stack[i].getCpuTime() > 0) {
			res.push_back(stack[i]);
		}
	}
	return res;
}

// Función que determina el próximo proceso que deberá ser ejecutado por el CPU
int SRT::findNextProcessToExecute(vector <Process> &P, vector <Process> &stack, int bt) {	
	int pos = getIndex(P, stack[0]);
	int min_cpu_time = P[pos].getCpuTime();
	Process aux;
	
	for (int j = 0; j < stack.size(); j++) {
		if (stack[j].getArrivalTime() > bt) {continue;}
		if (stack[j].getCpuTime() < min_cpu_time && stack[j].getCpuTime() > 0) {
			min_cpu_time = stack[j].getCpuTime();
			aux = stack[0];
			stack[0] = stack[j];
			stack[j] = aux;
			pos = getIndex(P, stack[0]);
		}
	}	
	return pos;
}

// Calcular tiempos de espera entre turnos de procesamiento en RoundRobin
// Calcula tanto los ServiceTime y los WaitTime, como también setea las esperas en el vector de Gantt
float SRT::calculateWaitingTimes(vector <Process> &P) {
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
