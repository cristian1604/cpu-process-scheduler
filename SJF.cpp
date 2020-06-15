#include "SJF.h"
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

#define NONE -1
#define WAITING 0
#define PROCESSING 1

SJF::SJF() {
	
}

void SJF::SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st) {
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
	}
	
	avg_st = 0;
	avg_wt = 0;
	int prev_process_entry = -1;			// Tiempo en el que el proceso anterior entra al CPU
	int prev_process_end = -1;				// Tiempo en el que el proceso anterior finaliza su ejecución en CPU
	int remaining_bursts;					// Ráfagas de CPU restantes
	int bt = 0;
	vector <Process> done;
	vector <Process> stack = P;
	
	while (stack.size() > 0) {
		if (stack.size() == 0) return;
		
		int pos = findNextProcessToExecute(P, stack, bt);
		remaining_bursts = P[pos].getCpuTime();
		
		// Establecer el vector vacío
		P[pos].Gantt.resize(total_burst);
		for (bt = 0; bt < total_burst; bt++) {
			P[pos].Gantt[bt] = NONE;
		}
		
		// Establecer los tiempos de espera (waiting time -wt-)
		int wt = 0;
		for (bt = P[pos].getArrivalTime(); bt < prev_process_end; bt++) {
			P[pos].Gantt[bt] = WAITING;
			++wt;
		}
		P[pos].setWaitTime(wt);
		avg_wt += wt;
		P[pos].setServiceTime(wt+P[pos].getCpuTime());
		
		// Establecer los tiempos de ejecución
		while (remaining_bursts > 0 && bt < total_burst) {
			P[pos].Gantt[bt++] = PROCESSING;
			--remaining_bursts;
		}
		
		// finalizado el completado del vector, actualizo los valores del último proceso
		prev_process_entry = P[pos].getArrivalTime();
		prev_process_end = bt;
		
		done.push_back(stack[0]);
		stack = processQueue(stack, done);
	}
	avg_wt /= P.size();
}


// La siguiente funcion devuelve un vector de elementos que restan por ser procesados
// (cola de procesos que se encuentran en estado de "listo" y que aún no han llegado
vector <Process> SJF::processQueue(vector <Process> all, vector <Process> executed) {
	bool add;
	vector <Process> res;
	for (int i = 0; i < all.size(); i++) {
		add = true;
		for (int j = 0; j < executed.size(); j++) {
			if (all[i].getId() == executed[j].getId()) {
				add = false;
				break;
			}
		}
		if (add) {
			res.push_back(all[i]);
		}
	}
	return res;
}

// Esta funcion devuelve el indice del vector principal P para el elemento elem dado
int SJF::getIndex(vector <Process> &P, Process elem) {
	for (int i = 0; i < P.size(); i++) {
		if (P[i].getId() == elem.getId()) {
			return i;
		}
	}
	return -1;
}

// Función que determina el próximo proceso que deberá ser ejecutado por el CPU
int SJF::findNextProcessToExecute(vector <Process> &P, vector <Process> &stack, int bt) {
	int pos = getIndex(P, stack[0]);
	int min_cpu_time = P[pos].getCpuTime();
	Process aux;
	
	for (int j = 0; j < stack.size(); j++) {
		if (stack[j].getArrivalTime() > bt) {continue;}
		if (stack[j].getCpuTime() < min_cpu_time) {
			min_cpu_time = stack[j].getCpuTime();
			aux = stack[0];
			stack[0] = stack[j];
			stack[j] = aux;
			pos = getIndex(P, stack[0]);
			//break;
		}
	}
	
	return pos;
}

