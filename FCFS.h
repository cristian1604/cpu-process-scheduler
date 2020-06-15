#ifndef FCFS_H
#define FCFS_H
#include <vector>
#include "Process.h"
using namespace std;

class FCFS {
public:
	FCFS();
	void Solve(vector <Process> &P, float &avg_wait_time, float &avg_service_time);
	void SolveGantt(vector <Process> &P, float &avg_wait_time, float &avg_service_time);
private:
	void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
	void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]);
};

#endif

