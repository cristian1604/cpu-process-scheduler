#ifndef WXRESULTS_H
#define WXRESULTS_H
#include "wxfb_project.h"
#include "Process.h"
#include <vector>
#include "FileManager.h"
using namespace std;

#define ROUND_ROBIN_MODE 1
#define FCFS_MODE 2
#define SRTF_MODE 3
#define SJF_MODE 4
#define PREEMPTIVE_PRIORITY_MODE 5
#define NON_PREEMPTIVE_PRIORITY_MODE 6

class wxResults : public wxResult {
private:
	FileManager DataProvider;
	vector <Process> P;
	int rr_quantum;
	int mode;
	bool apropiative_mode;
	bool orden_inverso;
	wxColour selection_color;
	wxColour unselected_color;
	
	void highlightCell(bool side);
	
protected:
	void keyEvent( wxKeyEvent& event )  override;
	void invertOrder( wxCommandEvent& event )  override;
	void showGrid( wxCommandEvent& event )  override;
	void hideGrid( wxCommandEvent& event )  override;
	void displayGanttMenu( wxGridEvent& event )  override;
	void PreemptivePriorityStrategy( wxCommandEvent& event )  override;
	void NonPreemptivePriorityStrategy( wxCommandEvent& event )  override;
	void RoundRobinStrategy( wxCommandEvent& event )  override;
	void SRTFStrategy( wxCommandEvent& event )  override;
	void FCFSStrategy( wxCommandEvent& event )  override;
	void SJFStrategy( wxCommandEvent& event )  override;
	void highlightResultsCell( wxGridEvent& event )  override;
	void highlightDataCell( wxGridEvent& event )  override;
	void executeStrategy();
	void ClearAll();
public:
	wxResults(wxWindow *parent=NULL, int modo = 0, int quantum = 0);
	~wxResults();
	void solveRoundRobin();
	void solveSRTF();
	void solveFCFS();
	void solveSJF();
	void solvePreemptivePriority();
	void solveNonPreemptivePriority();
	void displayResults(float avg_wt, float avg_st);
	void calculateAverages();
};

#endif

