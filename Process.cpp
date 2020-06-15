#include "Process.h"
#include <cstring>
using namespace std;

Process::Process() {
	
}

Process::Process(stProcess p) {
	strcpy(p_name,p.p_name);
	p_cpu = p.p_cpu;
	p_priority = p.p_priority;
	p_arrival = p.p_arrival;
}

stProcess Process::toStruct() {
	stProcess res;
	strcpy(res.p_name, p_name);
	res.p_cpu = p_cpu;
	res.p_priority = p_priority;
	res.p_arrival = p_arrival;
	
	res.service_time = service_time;
	res.wait_time = wait_time;
	return res;
}


void Process::setServiceTime(int val) {
	service_time = val;
	
}

void Process::setWaitTime(int val) {
	wait_time = val;
}

int Process::getArrivalTime() {
	return p_arrival;
}

void Process::setCpuTime(int bursts) {
	p_cpu = bursts;
}

int Process::getCpuTime() {
	return p_cpu;
}

char* Process::getProcessName() {
	return p_name;
}

void Process::setId(int id) {
	p_id = id;
}

int Process::getId() {
	return p_id;
}


