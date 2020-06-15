#include "FCFS.h"
#include <iostream>
#include <algorithm>
using namespace std;

FCFS::FCFS() {
	
}

void FCFS::findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) { 
	int *service_time  = new int[n];
	service_time[0] = 0; 
	wt[0] = 0; 
	
	// calculating waiting time 
	for (int i = 1; i < n ; i++) { 
		// Add burst time of previous processes 
		service_time[i] = service_time[i-1] + bt[i-1];
		
		// Find waiting time for current process = 
		// sum - at[i] 
		wt[i] = service_time[i] - at[i]; 
		
		// If waiting time for a process is in negative 
		// that means it is already in the ready queue 
		// before CPU becomes idle so its waiting time is 0 
		if (wt[i] < 0) 
			wt[i] = 0; 
	} 
} 

// Function to calculate turn around time 
void FCFS::findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) { 
	// Calculating turnaround time by adding bt[i] + wt[i] 
	for (int i = 0; i < n ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 




void FCFS::Solve(vector <Process> &P, float &avg_wait_time, float &avg_service_time) {
	// Process id's 
	int n = P.size();
	
	int *processes = new int[n];
	int *burst_time = new int[n];
	int *arrival_time = new int[n];
	stProcess aux;
	
	for (int i = 0; i < n; i++) {
		aux = P[i].toStruct();
		burst_time[i] = aux.p_cpu;
		arrival_time[i] = aux.p_arrival;
	}
	
	//findavgTime(processes, n, burst_time, arrival_time); 
	int *wt = new int[n];
	int *tat = new int[n]; 
	
	// Function to find waiting time of all processes 
	findWaitingTime(processes, n, burst_time, wt, arrival_time); 
	
	// Function to find turn around time for all processes 
	findTurnAroundTime(processes, n, burst_time, wt, tat); 
	
	// Display processes along with all details 
	cout << "Processes " << " Burst Time " << " Arrival Time "
		<< " Waiting Time " << " Turn-Around Time "
		<< " Completion Time \n"; 
	int total_wt = 0, total_tat = 0; 
	for (int i = 0 ; i < n ; i++) {
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		int compl_time = tat[i] + arrival_time[i]; 
		cout << " " << i+1 << "\t\t" << burst_time[i] << "\t\t"
			<< arrival_time[i] << "\t\t" << wt[i] << "\t\t "
			<< tat[i]  <<  "\t\t " << compl_time << endl; 
		
		P[i].setServiceTime(tat[i]);
		P[i].setWaitTime(wt[i]);
	} 
	
	cout << "Average waiting time = "
		<< (float)total_wt / (float)n; 
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n; 
	
	avg_wait_time = (float)total_wt / (float)n;
	avg_service_time = (float)total_tat / (float)n;

}


#define NONE -1
#define WAITING 0
#define PROCESSING 1


void FCFS::SolveGantt(vector <Process> &P, float &avg_wait_time, float &avg_service_time) {
	// Para conocer la longitud del diagrama, sumo todos los burst-time
	int total_burst = 0;
	for (int i = 0; i < P.size(); i++) {
		P[i].setId(i+1);
		total_burst += P[i].getCpuTime();
	}
	
	// ordenar vector por CPU bursts de los procesos
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
	
	// con el vector ordenado vamos completando el vector
	avg_wait_time = 0;
	avg_service_time = 0;
	int prev_process_entry = 0;			// Tiempo en el que el proceso anterior entra al CPU
	int prev_process_end = 0;				// Tiempo en el que el proceso anterior finaliza su ejecución en CPU
	int remaining_bursts;					// Ráfagas de CPU restantes
	int bt;
	
	for (int pos = 0; pos < P.size(); pos++) {
		remaining_bursts = P[pos].getCpuTime();
		
		// Establecer el vector vacío
		P[pos].Gantt.resize(total_burst);
		for (bt = 0; bt < total_burst; bt++) {
			P[pos].Gantt[bt] = NONE;
		}
		
		// Establecer los tiempos de espera
		int wt = 0;
		for (bt = P[pos].getArrivalTime(); bt < prev_process_end; bt++) {
			P[pos].Gantt[bt] = WAITING;
			++wt;
		}
		P[pos].setWaitTime(wt);
		P[pos].setServiceTime(P[pos].getCpuTime() + wt);
		avg_wait_time += wt;
		avg_service_time += P[pos].getCpuTime();
		
		
		// Establecer los tiempos de ejecución
		while (remaining_bursts > 0 && bt < total_burst) {
			P[pos].Gantt[bt++] = PROCESSING;
			--remaining_bursts;
		}
		
		// finalizado el completado del vector, actualizo los valores del último proceso
		prev_process_entry = P[pos].getArrivalTime();
		prev_process_end = bt;
	}
	avg_wait_time /= P.size();
	avg_service_time /= P.size();
}
