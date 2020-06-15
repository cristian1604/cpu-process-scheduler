#include "wxResults.h"
#include "RoundRobin.h"
#include "SRT.h"
#include "FCFS.h"

wxResults::wxResults(wxWindow *parent, int modo, int quantum) : wxResult(parent) {
	rr_quantum = quantum;
	for (int i = 0; i < m_table->GetNumberCols(); i++) {
		m_table->SetColSize(i, 150);
	}
	
	for (int i = 0; i < m_tablaProcesos->GetNumberCols(); i++) {
		m_tablaProcesos->SetColSize(i, 150);
	}
	m_tablaProcesos->SetColSize(m_tablaProcesos->GetNumberCols()-1, 0);
	m_table->SetColSize(0, 0);
	
	DataProvider.quickLoad(P);
	m_table->AppendRows(P.size()-1);
	m_tablaProcesos->AppendRows(P.size()-1);
	
	stProcess aux;
	for (int pos = 0; pos < P.size(); pos++) {
		aux = P[pos].toStruct();
		m_tablaProcesos->SetCellValue(aux.p_name, pos, 0);
		m_tablaProcesos->SetCellValue((wxString::Format(wxT("%i"),aux.p_cpu)), pos, 1);
		m_tablaProcesos->SetCellValue((wxString::Format(wxT("%i"),aux.p_arrival)), pos, 2);
		m_tablaProcesos->SetCellValue((wxString::Format(wxT("%i"),aux.p_priority)), pos, 3);
	}
	
	mode = modo;
	switch(mode) {
	case ROUND_ROBIN_MODE:
		this->SetLabel("Round Robin");
		m_staticText->SetLabel("Resultados para la planificacion Round Robin. Q = " + wxString::Format(wxT("%i"),quantum));
		solveRoundRobin();
		break;
	case FCFS_MODE:
		this->SetLabel("FCFS / FIFO");
		m_staticText->SetLabel("Resultados para la planificacion First Come First Served (FCFS / FIFO)");
		solveFCFS();
		break;
	case SRTF_MODE:
		this->SetLabel("SRTF");
		m_staticText->SetLabel("Resultados para la planificacion Shortest Remaining Time First (SRTF)");
		solveSRTF();
		break;
	}
}

void wxResults::solveRoundRobin() {
	float avg_wt;
	float avg_st;
	RoundRobin RR;
	RR.SolveGantt(P, rr_quantum, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
}

void wxResults::solveSRTF() {
	float avg_wt;
	float avg_st;
	SRT _SRT;
	_SRT.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
}

void wxResults::solveFCFS() {
	float avg_wt;
	float avg_st;
	FCFS _FCFS;
	_FCFS.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
}

#define NONE -1
#define WAITING 0
#define PROCESSING 1

void wxResults::displayResults(float avg_wt, float avg_st) {
	int cols = P[0].Gantt.size();
	m_gantt->AppendRows(P.size());
	m_gantt->AppendCols(cols);
		
	for (int i = 0; i < P.size(); i++) {
		int row = P.size()-(P[i].getId());
		stProcess aux = P[i].toStruct();
		float is = (aux.p_cpu*1.0f)/aux.service_time;   // indice de servicio
		m_table->SetCellValue((wxString::Format(wxT("%i"),aux.wait_time)), i, 1);
		m_table->SetCellValue((wxString::Format(wxT("%i"),aux.service_time)), i, 2);
		m_table->SetCellValue((wxString::Format(wxT("%.2f"),is)), i, 3);
		
		// Diagrama de Gantt
		if (mode == FCFS_MODE || mode == SRTF_MODE || mode == ROUND_ROBIN_MODE) {
			for (int j = 0; j < cols; j++) {			// Recorro el vector de columnas de Gantt
				m_gantt->SetColSize(j, 30);
				if (P[i].Gantt[j] == WAITING) {
					m_gantt->SetCellBackgroundColour(row, j, wxColour(202, 222, 230));
				}
				
				if (P[i].Gantt[j] == PROCESSING) {
					m_gantt->SetCellBackgroundColour(row, j, wxColour(255, 0, 0));
				}
				
				m_gantt->SetColLabelValue(j, (wxString::Format(wxT("%i"),j+1)));
				m_gantt->SetRowLabelValue(row, aux.p_name);
				m_gantt->SetRowLabelSize(15*strlen(aux.p_name));
			}
		}
	}
	m_table->AppendRows(1);
	m_table->SetRowLabelValue(m_table->GetNumberRows()-1, "Avg");
	m_table->SetCellValue((wxString::Format(wxT("%.1f"),avg_wt)), P.size(), 1);
	wxFont f;
	f.SetWeight(wxFONTWEIGHT_BOLD);
	m_table->SetCellFont(P.size(), 1, f);
	//m_table->SetCellValue((wxString::Format(wxT("%.1f"),avg_st)), P.size(), 2);
	m_table->SetCellBackgroundColour(P.size(), 1, wxColour(117, 223, 230));
}

wxResults::~wxResults() {
	
}

void wxResults::highlightDataCell( wxGridEvent& event )  {
	highlightCell(true);
}

void wxResults::highlightResultsCell( wxGridEvent& event )  {
	highlightCell(false);
}

void wxResults::highlightCell(bool side) {
	int row = m_tablaProcesos->GetGridCursorRow();
	int col = m_tablaProcesos->GetGridCursorCol();
	if (!side) {
		row = m_table->GetGridCursorRow();
		col = m_table->GetGridCursorCol();
	}
	// clear background color
	for (int i = 0; i < m_tablaProcesos->GetNumberCols(); i++) {
		for (int j = 0; j < m_tablaProcesos->GetNumberRows(); j++) {
			m_tablaProcesos->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
		}
	}
	for (int i = 0; i < m_table->GetNumberCols(); i++) {
		for (int j = 0; j < m_table->GetNumberRows(); j++) {
			m_table->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
		}
	}
	
	// Colouring rows
	for (int i = 0; i < m_table->GetNumberCols(); i++) {
		m_table->SetCellBackgroundColour(row, i, wxColour(186, 255, 188));
		m_table->Refresh(false);
	}
	for (int i = 0; i < m_tablaProcesos->GetNumberCols(); i++) {
		m_tablaProcesos->SetCellBackgroundColour(row, i, wxColour(186, 255, 188));
		m_tablaProcesos->Refresh(false);
	}
}

