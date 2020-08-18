#ifndef PRIORITYNONPREEMPTIVE_H
#define PRIORITYNONPREEMPTIVE_H
#include "Process.h"
#include <vector>
#include <list>

using namespace std;

#define NONE -1
#define WAITING 0
#define PROCESSING 1

class PriorityNonPreemptive {
public:
	PriorityNonPreemptive();
	void SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st);
private:
	float calculateWaitingTimes(vector <Process> &P);
	void UpdateReadyProcessList(list <Process> &ProcessList, list <Process> &ReadyProcessList, int bt);
};

#endif

