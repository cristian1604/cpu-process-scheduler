#ifndef WXCOMPARERESULTS_H
#define WXCOMPARERESULTS_H
#include "wxfb_project.h"
#include "Process.h"
#include <vector>
#include "FileManager.h"

using namespace std;

class wxCompareResults : public wxCompare {
	
private:
	FileManager DataProvider;
	vector <Process> P;
	
protected:
	
public:
	wxCompareResults(wxWindow *parent=NULL, int quantum = 0);
	~wxCompareResults();
};

#endif

