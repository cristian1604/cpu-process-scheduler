#ifndef SRT_H
#define SRT_H
#include <vector>
#include "Process.h"
using namespace std;

class SRT {
public:
	SRT();
	void SolveGantt(vector <Process> &P, float &avg_wt, float &avg_st);
private:
	int findNextProcessToExecute(vector <Process> &P, vector <Process> &stack, int bt);
	int getIndex(vector <Process> &P, Process elem);
	vector <Process> updateStack(vector <Process> stack);
	float calculateWaitingTimes(vector <Process> &P);
};

#endif

