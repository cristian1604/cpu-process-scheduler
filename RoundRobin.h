#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H
#include <vector>
#include "Process.h"
using namespace std;

class RoundRobin {
public:
	RoundRobin();
	void SolveGantt(vector <Process> &P, int quantum, float &avg_wt, float &avg_st);
private:
	float calculateWaitingTimes(vector <Process> &P);
};

#endif
