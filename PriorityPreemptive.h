#ifndef PRIORITYPREEMPTIVE_H
#define PRIORITYPREEMPTIVE_H
#include <vector>
#include "Process.h"
#include <list>

using namespace std;

#define NONE -1
#define WAITING 0
#define PROCESSING 1

class PriorityPreemptive {
public:
	void SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st);
	PriorityPreemptive();
private:
	float calculateWaitingTimes(vector <Process> &P);
	void UpdateReadyProcessList(list <Process> &ProcessList, list <Process> &ReadyProcessList, int bt);
};

#endif

