#include "wxResults.h"
#include "RoundRobin.h"
#include "SRT.h"
#include "FCFS.h"
#include "SJF.h"
#include "PriorityPreemptive.h"
#include "PriorityNonPreemptive.h"
#include "wxAbout.h"

wxResults::wxResults(wxWindow *parent, int modo, int quantum) : wxResult(parent) {
	rr_quantum = quantum;
	mode = modo;
	orden_inverso = false;
	
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
		m_tablaProcesos->SetCellValue(pos, 0, aux.p_name);
		m_tablaProcesos->SetCellValue(pos, 1, (wxString::Format(wxT("%i"),aux.p_cpu)));
		m_tablaProcesos->SetCellValue(pos, 2, (wxString::Format(wxT("%i"),aux.p_arrival)));
		m_tablaProcesos->SetCellValue(pos, 3, (wxString::Format(wxT("%i"),aux.p_priority)));
	}
	
	selection_color = m_button_rr->GetBackgroundColour();
	unselected_color = m_button_sjf->GetBackgroundColour();
	executeStrategy();

}

void wxResults::executeStrategy() {
	//DataProvider.quickLoad(P);
	wxString title("Simulacion de planificacion de procesos - ");
	switch(mode) {
	case ROUND_ROBIN_MODE:
		this->SetLabel(title + "Round Robin");
		m_staticText->SetLabel("Resultados para la planificacion Round Robin. Q = " + wxString::Format(wxT("%i"),rr_quantum));
		solveRoundRobin();
		apropiative_mode = true;
		break;
	case FCFS_MODE:
		this->SetLabel(title + "FCFS / FIFO");
		m_staticText->SetLabel("Resultados para la planificacion First Come First Served (FCFS / FIFO)");
		solveFCFS();
		apropiative_mode = false;
		break;
	case SRTF_MODE:
		this->SetLabel(title + "SRTF");
		m_staticText->SetLabel("Resultados para la planificacion Shortest Remaining Time First (SRTF)");
		solveSRTF();
		apropiative_mode = true;
		break;
	case SJF_MODE:
		this->SetLabel(title + "SJF");
		m_staticText->SetLabel("Resultados para la planificacion Shortest Job First (SJF)");
		solveSJF();
		apropiative_mode = true;
		break;
	case PREEMPTIVE_PRIORITY_MODE:
		this->SetLabel(title + "Prioridad Apropiativa");
		m_staticText->SetLabel("Resultados para la planificacion para prioridad apropiativa (preemptive priority)");
		solvePreemptivePriority();
		apropiative_mode = true;
		break;
	case NON_PREEMPTIVE_PRIORITY_MODE:
		this->SetLabel(title + "Prioridad No Apropiativa");
		m_staticText->SetLabel("Resultados para la planificacion para prioridad no apropiativa (non preemptive priority)");
		solveNonPreemptivePriority();
		apropiative_mode = false;
		break;
	}
	
	// Información adicional
	if (apropiative_mode) {
		m_strategy_type->SetLabel("Apropiativa");
		m_strategy_type->SetForegroundColour(wxColour(0, 177, 25));
	} else {
		m_strategy_type->SetLabel("No apropiativa");
		m_strategy_type->SetForegroundColour(wxColour(0,0,0));
	}
}

void wxResults::solveRoundRobin() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	RoundRobin RR;
	RR.SolveGantt(P, rr_quantum, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
}

void wxResults::solveSJF() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	SJF _SJF;
	_SJF.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
}

void wxResults::solveSRTF() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	SRT _SRT;
	_SRT.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
}

void wxResults::solveFCFS() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	FCFS _FCFS;
	_FCFS.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
}

void wxResults::solvePreemptivePriority() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	PriorityPreemptive _PP;
	_PP.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
}

void wxResults::solveNonPreemptivePriority() {
	vector <Process> Tmp = P;
	float avg_wt;
	float avg_st;
	PriorityNonPreemptive _PNP;
	_PNP.SolveGantt(P, avg_wt, avg_st);
	displayResults(avg_wt, avg_st);
	P = Tmp;
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
		if (orden_inverso) row = i;
		stProcess aux = P[i].toStruct();
		float is = (aux.p_cpu*1.0f)/aux.service_time;   // indice de servicio
		m_table->SetCellValue(i, 1, (wxString::Format(wxT("%i"),aux.wait_time)));
		m_table->SetCellValue(i, 2, (wxString::Format(wxT("%i"),aux.service_time)));
		m_table->SetCellValue(i, 3, (wxString::Format(wxT("%.2f"),is)));
		m_table->SetRowLabelValue(i, P[i].getProcessName());
		
		// Diagrama de Gantt
		if (mode == FCFS_MODE || mode == SRTF_MODE || mode == ROUND_ROBIN_MODE || mode == SJF_MODE || mode == PREEMPTIVE_PRIORITY_MODE || mode == NON_PREEMPTIVE_PRIORITY_MODE) {
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
	m_table->SetCellValue(P.size(), 1, (wxString::Format(wxT("%.1f"),avg_wt)));
	wxFont f;
	f.SetWeight(wxFONTWEIGHT_BOLD);
	m_table->SetCellFont(P.size(), 1, f);
	m_table->SetCellBackgroundColour(P.size(), 1, wxColour(117, 223, 230));
	
	calculateAverages();
}

void wxResults::calculateAverages() {
	int rows = m_tablaProcesos->GetNumberRows();
	float avg_st = 0;
	double avg_si = 0;
	double aux;
	
	for (int i = 0; i < rows; i++) {
		avg_st += wxAtoi(m_table->GetCellValue(i, 2));
		(m_table->GetCellValue(i, 3)).ToDouble(&aux);
		avg_si += aux;
	}
	avg_st = avg_st/rows;
	avg_si = avg_si/rows;
	
	m_table->SetCellValue(P.size(), 2, (wxString::Format(wxT("%.2f"),avg_st)));
	m_table->SetCellValue(P.size(), 3, (wxString::Format(wxT("%.0f"),avg_si*100)) + "%");
	wxFont f;
	f.SetWeight(wxFONTWEIGHT_BOLD);
	m_table->SetCellFont(P.size(), 2, f);
	m_table->SetCellFont(P.size(), 3, f);
	m_table->SetCellBackgroundColour(P.size(), 2, wxColour(117, 223, 230));
	m_table->SetCellBackgroundColour(P.size(), 3, wxColour(117, 223, 230));
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
	for (int i = 0; i < m_tablaProcesos->GetNumberCols()+1; i++) {
		for (int j = 0; j < m_tablaProcesos->GetNumberRows()+1; j++) {
			m_tablaProcesos->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
			m_table->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
		}
	}
	
	if (row >= P.size()) {
		return;
	}
	
	// Colouring rows
	for (int i = 0; i < m_table->GetNumberCols(); i++) {
		m_table->SetCellBackgroundColour(row, i, wxColour(186, 255, 188));
		m_table->Refresh(true);
	}
	for (int i = 0; i < m_tablaProcesos->GetNumberCols(); i++) {
		m_tablaProcesos->SetCellBackgroundColour(row, i, wxColour(186, 255, 188));
		m_tablaProcesos->Refresh(true);
	}
}

void wxResults::RoundRobinStrategy( wxCommandEvent& event )  {
	mode = ROUND_ROBIN_MODE;
	ClearAll();
	m_button_rr->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::SRTFStrategy( wxCommandEvent& event )  {
	mode = SRTF_MODE;
	ClearAll();
	m_button_srtf->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::FCFSStrategy( wxCommandEvent& event )  {
	mode = FCFS_MODE;
	ClearAll();
	m_button_fcfs->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::SJFStrategy( wxCommandEvent& event )  {
	mode = SJF_MODE;
	ClearAll();
	m_button_sjf->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::PreemptivePriorityStrategy( wxCommandEvent& event )  {
	mode = PREEMPTIVE_PRIORITY_MODE;
	ClearAll();
	m_button_preemptivepriority->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::NonPreemptivePriorityStrategy( wxCommandEvent& event )  {
	mode = NON_PREEMPTIVE_PRIORITY_MODE;
	ClearAll();
	m_button_nonpreemptivepriority->SetBackgroundColour(selection_color);
	executeStrategy();
}

void wxResults::ClearAll() {
	m_button_rr->SetBackgroundColour(unselected_color);
	m_button_srtf->SetBackgroundColour(unselected_color);
	m_button_sjf->SetBackgroundColour(unselected_color);
	m_button_fcfs->SetBackgroundColour(unselected_color);
	m_button_preemptivepriority->SetBackgroundColour(unselected_color);
	m_button_nonpreemptivepriority->SetBackgroundColour(unselected_color);
	m_gantt->ClearBackground();
	m_gantt->DeleteRows(0, m_gantt->GetNumberRows());
	m_gantt->DeleteCols(0, m_gantt->GetNumberCols(), true);
	m_table->DeleteRows(m_table->GetNumberRows()-1, 1);
}

void wxResults::displayGanttMenu( wxGridEvent& event )  {
	(m_menu1->FindItemByPosition(0))->Check(m_gantt->GridLinesEnabled());
	PopupMenu(m_menu1);
}

void wxResults::showGrid( wxCommandEvent& event )  {
	m_gantt->EnableGridLines(!m_gantt->GridLinesEnabled());
}

void wxResults::hideGrid( wxCommandEvent& event )  {
	m_gantt->EnableGridLines(false);
	event.Skip();
}

void wxResults::invertOrder( wxCommandEvent& event )  {
	orden_inverso = !orden_inverso;
	(m_menu1->FindItemByPosition(3))->Check(orden_inverso);
	ClearAll();
	executeStrategy();
}

void wxResults::keyEvent( wxKeyEvent& event )  {
	if (event.GetKeyCode() == WXK_F1) {
		wxAbout *w = new wxAbout;
		w->Show();
		return;
	}
	
	wxCommandEvent null;
	switch(event.GetKeyCode()) {
	case WXK_NUMPAD1: case 49:
		RoundRobinStrategy(null);
		break;
	case WXK_NUMPAD2: case 50:
		SRTFStrategy(null);
		break;
	case WXK_NUMPAD3: case 51:
		FCFSStrategy(null);
		break;
	case WXK_NUMPAD4: case 52:
		SJFStrategy(null);
		break;
	case WXK_NUMPAD5: case 53:
		PreemptivePriorityStrategy(null);
		break;
	case WXK_NUMPAD6: case 54:
		NonPreemptivePriorityStrategy(null);
		break;
	default:
		return;
	}
}

