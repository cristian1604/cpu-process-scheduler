#include "wxCompareResults.h"
#include "RoundRobin.h"
#include "SRT.h"
#include "FCFS.h"
#include "SJF.h"
#include "PriorityPreemptive.h"
#include "PriorityNonPreemptive.h"

#define ROUND_ROBIN_MODE 1
#define FCFS_MODE 2
#define SRTF_MODE 3
#define SJF_MODE 4
#define PREEMPTIVE_PRIORITY_MODE 5
#define NON_PREEMPTIVE_PRIORITY_MODE 6
#include <cfloat>
#include <cstdlib>
using namespace std;

wxCompareResults::wxCompareResults(wxWindow *parent, int quantum) : wxCompare(parent) {
	
	DataProvider.quickLoad(P);
	
	wxString title;
	bool apropiative_mode;
	
	pair <int, float> min_avg_wt;
	
	min_avg_wt.first = -1;
	min_avg_wt.second = FLT_MAX;
	
	for (int i = 1; i <= 6; i++) {
		float avg_wt;
		float avg_st;
		P.clear();
		DataProvider.quickLoad(P);
		
		switch(i) {
		case ROUND_ROBIN_MODE: {
			title = "Round Robin";
			RoundRobin RR;
			RR.SolveGantt(P, quantum, avg_wt, avg_st);
			apropiative_mode = true;
			break; }
		case FCFS_MODE: {
			title = "FCFS / FIFO";
			FCFS _FCFS;
			_FCFS.SolveGantt(P, avg_wt, avg_st);
			apropiative_mode = false;
			break; }
		case SRTF_MODE: {
			title = "SRTF";
			SRT _SRT;
			_SRT.SolveGantt(P, avg_wt, avg_st);
			apropiative_mode = true;
			break; }
		case SJF_MODE: {
			title = "SJF";
			SJF _SJF;
			_SJF.SolveGantt(P, avg_wt, avg_st);
			apropiative_mode = true;
			break; }
		case PREEMPTIVE_PRIORITY_MODE: {
			title = "Prioridad Aprop";
			PriorityPreemptive _PP;
			_PP.SolveGantt(P, avg_wt, avg_st);
			apropiative_mode = true;
			break; }
		case NON_PREEMPTIVE_PRIORITY_MODE: {
			title = "Prioridad No Aprop";
			PriorityNonPreemptive _PNP;
			_PNP.SolveGantt(P, avg_wt, avg_st);
			apropiative_mode = false;
			break; }
		}
		
		m_comparer->InsertRows(m_comparer->GetNumberRows());
		m_comparer->SetRowLabelValue(m_comparer->GetNumberRows()-1, title);
		m_comparer->SetCellValue(m_comparer->GetNumberRows()-1, 0, wxString::Format(wxT("%f"),avg_wt));
	}
	
	for (int i = 0; i < m_comparer->GetNumberRows(); i++) {
		if (atof(m_comparer->GetCellValue(i, 0)) < min_avg_wt.second) {
			min_avg_wt.first = i;
			min_avg_wt.second = atof(m_comparer->GetCellValue(i, 0));
		}
	}

	this->SetTitle("Comparativa de tiempos");
	m_comparer->SetCellBackgroundColour(min_avg_wt.first, 0, wxColour(186, 255, 188));
	
	wxSize size = parent->GetSize();
	int x, y;
	parent->GetPosition(&x, &y);
	this->Move(x + size.GetWidth() + 10, y + 50);
	
}

wxCompareResults::~wxCompareResults() {
	
}
