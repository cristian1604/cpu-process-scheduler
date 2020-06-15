#ifndef PRIORITYNONPREEMPTIVE_H
#define PRIORITYNONPREEMPTIVE_H
#include "Process.h"
#include <vector>
using namespace std;

#define NONE -1
#define WAITING 0
#define PROCESSING 1

class PriorityNonPreemptive {
public:
	PriorityNonPreemptive();
	void SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st);
private:
	int findNextProcessToExecute(vector <Process> &P, vector <Process> &stack, int bt);
	int getIndex(vector <Process> &P, Process elem);
	vector <Process> updateStack(vector <Process> stack);
	float calculateWaitingTimes(vector <Process> &P);
};

#endif

