///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFB_PROJECT_H__
#define __WXFB_PROJECT_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/grid.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/valgen.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/statline.h>
#include <wx/statbox.h>
#include <wx/hyperlink.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxfbExample
///////////////////////////////////////////////////////////////////////////////
class wxfbExample : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxGrid* m_tablaProcesos;
		wxButton* m_addRow;
		wxButton* m_delRow;
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_rr_quantum;
		wxButton* m_button6;
		wxButton* m_button7;
		
		// Virtual event handlers, overide them in your derived class
		virtual void about( wxKeyEvent& event ) { event.Skip(); }
		virtual void m_addRowOnKeyDown( wxKeyEvent& event ) { event.Skip(); }
		virtual void addRow( wxCommandEvent& event ) { event.Skip(); }
		virtual void delRow( wxCommandEvent& event ) { event.Skip(); }
		virtual void verifyQuantum( wxKeyEvent& event ) { event.Skip(); }
		virtual void process( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClose( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxfbExample( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sistemas Operativos - Planificador de procesos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 763,459 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~wxfbExample();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class wxResult
///////////////////////////////////////////////////////////////////////////////
class wxResult : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText8;
		wxButton* m_button_rr;
		wxButton* m_button_srtf;
		wxButton* m_button_fcfs;
		wxButton* m_button_sjf;
		wxButton* m_button_preemptivepriority;
		wxButton* m_button_nonpreemptivepriority;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText;
		wxGrid* m_tablaProcesos;
		wxGrid* m_table;
		wxStaticText* m_staticText5;
		wxGrid* m_gantt;
		wxStaticText* m_staticText7;
		wxStaticText* m_strategy_type;
		wxStaticText* m_staticText71;
		wxStaticText* m_strategy_type1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void about( wxKeyEvent& event ) { event.Skip(); }
		virtual void RoundRobinStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void SRTFStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void FCFSStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void SJFStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void PreemptivePriorityStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void NonPreemptivePriorityStrategy( wxCommandEvent& event ) { event.Skip(); }
		virtual void highlightDataCell( wxGridEvent& event ) { event.Skip(); }
		virtual void highlightResultsCell( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxResult( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Resultado"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1200,559 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL|wxVSCROLL );
		
		~wxResult();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class About
///////////////////////////////////////////////////////////////////////////////
class About : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText151;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText161;
		wxHyperlinkCtrl* m_hyperlink1;
	
	public:
		
		About( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 446,191 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~About();
	
};

#endif //__WXFB_PROJECT_H__
