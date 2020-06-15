///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

wxfbExample::wxfbExample( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Scheduler"), wxDefaultPosition, wxSize( -1,-1 ), wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
	m_staticText1->Wrap( 300 );
	bSizer1->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_tablaProcesos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_tablaProcesos->CreateGrid( 1, 5 );
	m_tablaProcesos->EnableEditing( true );
	m_tablaProcesos->EnableGridLines( true );
	m_tablaProcesos->EnableDragGridSize( false );
	m_tablaProcesos->SetMargins( 0, 0 );
	
	// Columns
	m_tablaProcesos->SetColSize( 0, 77 );
	m_tablaProcesos->SetColSize( 1, 98 );
	m_tablaProcesos->SetColSize( 2, 146 );
	m_tablaProcesos->SetColSize( 3, 86 );
	m_tablaProcesos->SetColSize( 4, 31 );
	m_tablaProcesos->AutoSizeColumns();
	m_tablaProcesos->EnableDragColMove( false );
	m_tablaProcesos->EnableDragColSize( true );
	m_tablaProcesos->SetColLabelSize( 30 );
	m_tablaProcesos->SetColLabelValue( 0, wxT("Proceso") );
	m_tablaProcesos->SetColLabelValue( 1, wxT("CPU Burst") );
	m_tablaProcesos->SetColLabelValue( 2, wxT("Tiempo de llegada") );
	m_tablaProcesos->SetColLabelValue( 3, wxT("Prioridad") );
	m_tablaProcesos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_tablaProcesos->EnableDragRowSize( true );
	m_tablaProcesos->SetRowLabelSize( 40 );
	m_tablaProcesos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_tablaProcesos->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_tablaProcesos->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	bSizer1->Add( m_tablaProcesos, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 7, 0, 0 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_addRow = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_addRow->SetToolTip( wxT("Agregar nuevo proceso (+)") );
	
	gSizer2->Add( m_addRow, 0, wxALL, 5 );
	
	m_delRow = new wxButton( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	m_delRow->SetToolTip( wxT("Eliminar proceso seleccionado (-)") );
	
	gSizer2->Add( m_delRow, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Presione la tecla + para agregar un nuevo proceso.\nPresione la tecla - para quitar un proceso de la tabla"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	
	gSizer2->Add( m_staticText2, 0, wxALL, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	gSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Quantum = "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	m_staticText21->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );
	
	gSizer2->Add( m_staticText21, 0, wxALL, 5 );
	
	m_rr_quantum = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_rr_quantum->HasFlag( wxTE_MULTILINE ) )
	{
	m_rr_quantum->SetMaxLength( 2 );
	}
	#else
	m_rr_quantum->SetMaxLength( 2 );
	#endif
	gSizer2->Add( m_rr_quantum, 0, wxALL, 5 );
	
	
	bSizer1->Add( gSizer2, 0, 0, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Procesar"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button6, 0, wxALL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button7, 0, wxALL, 5 );
	
	
	bSizer1->Add( gSizer3, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_tablaProcesos->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxfbExample::m_addRowOnKeyDown ), NULL, this );
	m_addRow->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::addRow ), NULL, this );
	m_addRow->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxfbExample::m_addRowOnKeyDown ), NULL, this );
	m_delRow->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::delRow ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::process ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::OnButtonClose ), NULL, this );
}

wxfbExample::~wxfbExample()
{
	// Disconnect Events
	m_tablaProcesos->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxfbExample::m_addRowOnKeyDown ), NULL, this );
	m_addRow->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::addRow ), NULL, this );
	m_addRow->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxfbExample::m_addRowOnKeyDown ), NULL, this );
	m_delRow->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::delRow ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::process ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::OnButtonClose ), NULL, this );
	
}

wxResult::wxResult( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText->Wrap( -1 );
	bSizer2->Add( m_staticText, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_tablaProcesos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_tablaProcesos->CreateGrid( 1, 5 );
	m_tablaProcesos->EnableEditing( false );
	m_tablaProcesos->EnableGridLines( true );
	m_tablaProcesos->EnableDragGridSize( false );
	m_tablaProcesos->SetMargins( 0, 0 );
	
	// Columns
	m_tablaProcesos->SetColSize( 0, 77 );
	m_tablaProcesos->SetColSize( 1, 98 );
	m_tablaProcesos->SetColSize( 2, 146 );
	m_tablaProcesos->SetColSize( 3, 86 );
	m_tablaProcesos->SetColSize( 4, 31 );
	m_tablaProcesos->AutoSizeColumns();
	m_tablaProcesos->EnableDragColMove( false );
	m_tablaProcesos->EnableDragColSize( true );
	m_tablaProcesos->SetColLabelSize( 30 );
	m_tablaProcesos->SetColLabelValue( 0, wxT("Proceso") );
	m_tablaProcesos->SetColLabelValue( 1, wxT("CPU Burst") );
	m_tablaProcesos->SetColLabelValue( 2, wxT("Tiempo de llegada") );
	m_tablaProcesos->SetColLabelValue( 3, wxT("Prioridad") );
	m_tablaProcesos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_tablaProcesos->EnableDragRowSize( true );
	m_tablaProcesos->SetRowLabelSize( 40 );
	m_tablaProcesos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_tablaProcesos->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_tablaProcesos->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	gSizer3->Add( m_tablaProcesos, 1, wxALL, 5 );
	
	m_table = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_table->CreateGrid( 1, 4 );
	m_table->EnableEditing( false );
	m_table->EnableGridLines( true );
	m_table->EnableDragGridSize( false );
	m_table->SetMargins( 0, 0 );
	
	// Columns
	m_table->AutoSizeColumns();
	m_table->EnableDragColMove( false );
	m_table->EnableDragColSize( true );
	m_table->SetColLabelSize( 30 );
	m_table->SetColLabelValue( 0, wxT("Proceso") );
	m_table->SetColLabelValue( 1, wxT("Tiempo de espera") );
	m_table->SetColLabelValue( 2, wxT("Tiempo de servicio") );
	m_table->SetColLabelValue( 3, wxT("Indice de servicio") );
	m_table->SetColLabelValue( 4, wxEmptyString );
	m_table->SetColLabelValue( 5, wxEmptyString );
	m_table->SetColLabelValue( 6, wxEmptyString );
	m_table->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_table->EnableDragRowSize( true );
	m_table->SetRowLabelSize( 40 );
	m_table->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_table->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_TOP );
	gSizer3->Add( m_table, 1, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer2->Add( gSizer3, 0, wxEXPAND, 5 );
	
	
	bSizer2->Add( 0, 0, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Diagrama de Gantt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	bSizer2->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_gantt = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gantt->CreateGrid( 0, 0 );
	m_gantt->EnableEditing( true );
	m_gantt->EnableGridLines( false );
	m_gantt->EnableDragGridSize( false );
	m_gantt->SetMargins( 0, 0 );
	
	// Columns
	m_gantt->EnableDragColMove( false );
	m_gantt->EnableDragColSize( true );
	m_gantt->SetColLabelSize( 30 );
	m_gantt->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_gantt->EnableDragRowSize( true );
	m_gantt->SetRowLabelSize( 40 );
	m_gantt->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_gantt->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( m_gantt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_tablaProcesos->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightDataCell ), NULL, this );
	m_table->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightResultsCell ), NULL, this );
}

wxResult::~wxResult()
{
	// Disconnect Events
	m_tablaProcesos->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightDataCell ), NULL, this );
	m_table->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightResultsCell ), NULL, this );
	
}
