#ifndef PROCESS_H
#define PROCESS_H
#include <vector>
using namespace std;


struct stProcess {
	// process information
	char p_name[20];
	int p_cpu;
	int p_arrival;
	int p_priority;
	
	// results from process
	int wait_time;
	int service_time;
};

class Process {
private:
	// results from Process
	int p_id;
	char p_name[20];
	int p_cpu;
	int p_arrival;
	int p_priority;
	
	// results from Process
	int wait_time;
	int service_time;	

public:
	vector <int> Gantt;
	Process();
	Process(stProcess p);
	stProcess toStruct();
	void setServiceTime(int val);
	void setWaitTime(int val);
	int getArrivalTime();
	void setCpuTime(int bursts);
	int getCpuTime();
	char *getProcessName();
	void setId(int id);
	int getId();
private:
};

#endif

