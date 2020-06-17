#include "VentanaInicio.h"
#include <iostream>
#include <wx/msgdlg.h>
#include "wxResults.h"

#define ROUND_ROBIN_MODE 1
#define FCFS_MODE 2
#define SRTF_MODE 3
#define SJF_MODE 4
#include "wxAbout.h"

using namespace std;

VentanaInicio::VentanaInicio(wxWindow *parent) : wxfbExample(parent){
	for (int i = 0; i < m_tablaProcesos->GetNumberCols(); i++) {
		m_tablaProcesos->SetColSize(i, 150);
	}
	m_tablaProcesos->SetColSize(m_tablaProcesos->GetNumberCols()-1, 0);
	quickLoad();
}

void VentanaInicio::quickLoad() {
	// Cargar los ultimos procesos utilizados
	if (DataProvider.quickLoad(P)) {
		m_tablaProcesos->AppendRows(P.size()-1);
		stProcess aux;
		for (int pos = 0; pos < P.size(); pos++) {
			aux = P[pos].toStruct();
			m_tablaProcesos->SetCellValue(pos, 0, aux.p_name);
			m_tablaProcesos->SetCellValue(pos, 1, (wxString::Format(wxT("%i"),aux.p_cpu)));
			m_tablaProcesos->SetCellValue(pos, 2, (wxString::Format(wxT("%i"),aux.p_arrival)));
			m_tablaProcesos->SetCellValue(pos, 3, (wxString::Format(wxT("%i"),aux.p_priority)));
		}
	}
}

void VentanaInicio::quickSave() {
	// Guardar archivo con la lista de procesos para la proxima ejecucion del programa
	P.clear();
	int x = m_tablaProcesos->GetNumberRows();
	stProcess aux;
	for (int i = 0; i < m_tablaProcesos->GetNumberRows(); i++) {
		strcpy(aux.p_name, m_tablaProcesos->GetCellValue(i, 0));
		aux.p_cpu = atoi(m_tablaProcesos->GetCellValue(i, 1));
		aux.p_arrival = atoi(m_tablaProcesos->GetCellValue(i, 2));
		aux.p_priority = atoi(m_tablaProcesos->GetCellValue(i, 3));
		Process Proc(aux);
		P.push_back(Proc);
	}
	DataProvider.quickSave(P);
}

void VentanaInicio::OnButtonClose( wxCommandEvent& event ) { 
	Close();
}

void VentanaInicio::addRow( wxCommandEvent& event )  {
	m_tablaProcesos->AppendRows(1);
	m_tablaProcesos->SetGridCursor(m_tablaProcesos->GetNumberRows()-1, 0);
	m_tablaProcesos->SetFocus();
}

void VentanaInicio::delRow( wxCommandEvent& event )  {
	if (m_tablaProcesos->GetGridCursorRow() == -1) return;
	
	int pos = m_tablaProcesos->GetGridCursorRow();
	m_tablaProcesos->DeleteRows(m_tablaProcesos->GetGridCursorRow(),1);
	
	// Si la fila borrada era la �ltima, posiciona el cursor en la nueva �ltima fila
	if (pos == m_tablaProcesos->GetNumberRows()) {
		m_tablaProcesos->SetGridCursor(pos-1,0);
	}
}

void VentanaInicio::m_addRowOnKeyDown( wxKeyEvent& event )  {
	wxCommandEvent x;
	if (event.GetKeyCode() == 388 || event.GetKeyCode() == 43) {
		addRow(x);
	} else if (event.GetKeyCode() == 390 || event.GetKeyCode() == 45) {
		delRow(x);
	} else if (event.GetKeyCode() == 348) {
		process(x);
	} else {
		event.Skip();
	}
}

void VentanaInicio::process( wxCommandEvent& event )  {	
	quickSave();
	//wxMessageBox("Guardado");
	wxResults *res1 = new wxResults(this, ROUND_ROBIN_MODE, atoi(m_rr_quantum->GetValue()));
	res1->Show();
}

void VentanaInicio::verifyQuantum( wxKeyEvent& event )  {
	wxString str = m_rr_quantum->GetValue();
	if (!str.IsNumber()) {
		wxMessageBox("Debe ingresar un valor num�rico");
		m_rr_quantum->SetValue("1");
	}
	if (event.GetKeyCode() == 330 || event.GetKeyCode() == 13 || event.GetKeyCode() == 348) {
		wxCommandEvent x;
		process(x);
	} else {
		event.Skip();
	}
}

void VentanaInicio::about( wxKeyEvent& event )  {
	if (event.GetKeyCode() == WXK_F1) {
		wxAbout *w = new wxAbout;
		w->Show();
	} else {
		event.Skip();
	}
}

