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

class wxResults : public wxResult {
private:
	FileManager DataProvider;
	vector <Process> P;
	int rr_quantum;
	int mode;
private:
	void highlightCell(bool side);
protected:
	void highlightResultsCell( wxGridEvent& event )  override;
	void highlightDataCell( wxGridEvent& event )  override;
	
public:
	wxResults(wxWindow *parent=NULL, int modo = 0, int quantum = 0);
	~wxResults();
	void solveRoundRobin();
	void solveSRTF();
	void solveFCFS();
	void displayResults(float avg_wt, float avg_st);
};

#endif

