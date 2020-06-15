#ifndef WIN_EXAMPLE_H
#define WIN_EXAMPLE_H
#include "wxfb_project.h"
#include <map>
#include <vector>
#include "Process.h"
#include "FileManager.h"
using namespace std;


class VentanaInicio : public wxfbExample {
private:
	int selectedRow;
	vector <Process> P;
	FileManager DataProvider;
protected:
	void process( wxCommandEvent& event )  override;
	void m_addRowOnKeyDown( wxKeyEvent& event )  override;
	void addRow( wxCommandEvent& event )  override;
	void delRow( wxCommandEvent& event )  override;
	void quickLoad();
	void quickSave();

public:
	VentanaInicio(wxWindow *parent=NULL);
	void OnButtonClose(wxCommandEvent &evt);
};

#endif
