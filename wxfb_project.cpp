///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

wxMain::wxMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Scheduler"), wxDefaultPosition, wxSize( -1,-1 ), wxST_NO_AUTORESIZE|wxALIGN_CENTER_HORIZONTAL );
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
	m_tablaProcesos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Rows
	m_tablaProcesos->EnableDragRowSize( true );
	m_tablaProcesos->SetRowLabelSize( 40 );
	m_tablaProcesos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Label Appearance
	
	// Cell Defaults
	m_tablaProcesos->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_tablaProcesos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_TOP );
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
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Presione la tecla + para agregar un nuevo proceso.\nPresione la tecla - para quitar el proceso seleccionado\nPresione F9 para realizar la simulación"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	gSizer2->Add( m_staticText21, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_rr_quantum = new wxTextCtrl( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !m_rr_quantum->HasFlag( wxTE_MULTILINE ) )
	{
	m_rr_quantum->SetMaxLength( 2 );
	}
	#else
	m_rr_quantum->SetMaxLength( 2 );
	#endif
	m_rr_quantum->SetToolTip( wxT("Sólo válido para planificación Round Robin") );
	
	gSizer2->Add( m_rr_quantum, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer1->Add( gSizer2, 0, 0, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("Simular  (F9)"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button6, 0, wxALL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer3->Add( m_button7, 0, wxALL, 5 );
	
	
	bSizer1->Add( gSizer3, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::about ) );
	m_tablaProcesos->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::m_addRowOnKeyDown ), NULL, this );
	m_addRow->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::addRow ), NULL, this );
	m_addRow->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::m_addRowOnKeyDown ), NULL, this );
	m_delRow->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::delRow ), NULL, this );
	m_rr_quantum->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::verifyQuantum ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::process ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::OnButtonClose ), NULL, this );
}

wxMain::~wxMain()
{
	// Disconnect Events
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::about ) );
	m_tablaProcesos->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::m_addRowOnKeyDown ), NULL, this );
	m_addRow->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::addRow ), NULL, this );
	m_addRow->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::m_addRowOnKeyDown ), NULL, this );
	m_delRow->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::delRow ), NULL, this );
	m_rr_quantum->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxMain::verifyQuantum ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::process ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxMain::OnButtonClose ), NULL, this );
	
}

wxResult::wxResult( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 7, 0, 0 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("Estrategia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer4->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button_rr = new wxButton( this, wxID_ANY, wxT("Round Robin"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_rr->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_button_rr->SetToolTip( wxT("Round Robin (1)") );
	
	gSizer4->Add( m_button_rr, 0, wxALL, 5 );
	
	m_button_srtf = new wxButton( this, wxID_ANY, wxT("SRTF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_srtf->SetToolTip( wxT("SRTF (2)") );
	
	gSizer4->Add( m_button_srtf, 0, wxALL, 5 );
	
	m_button_fcfs = new wxButton( this, wxID_ANY, wxT("FCFS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_fcfs->SetToolTip( wxT("FCFS (3)") );
	
	gSizer4->Add( m_button_fcfs, 0, wxALL, 5 );
	
	m_button_sjf = new wxButton( this, wxID_ANY, wxT("SJF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_sjf->SetToolTip( wxT("SJF (4)") );
	
	gSizer4->Add( m_button_sjf, 0, wxALL, 5 );
	
	m_button_preemptivepriority = new wxButton( this, wxID_ANY, wxT("Prioridad Aprop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_preemptivepriority->SetToolTip( wxT("Prioridad Apropiativa (5)") );
	
	gSizer4->Add( m_button_preemptivepriority, 0, wxALL, 5 );
	
	m_button_nonpreemptivepriority = new wxButton( this, wxID_ANY, wxT("Prioridad No Aprop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button_nonpreemptivepriority->SetToolTip( wxT("Prioridad No Apropiativa (6)") );
	
	gSizer4->Add( m_button_nonpreemptivepriority, 0, wxALL, 5 );
	
	
	bSizer2->Add( gSizer4, 0, 0, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer2->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	m_staticText = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText->Wrap( -1 );
	bSizer2->Add( m_staticText, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 1, 2, 0, 0 );
	
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
	m_tablaProcesos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Rows
	m_tablaProcesos->EnableDragRowSize( true );
	m_tablaProcesos->SetRowLabelSize( 40 );
	m_tablaProcesos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Label Appearance
	
	// Cell Defaults
	m_tablaProcesos->SetDefaultCellFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	m_tablaProcesos->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_TOP );
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
	m_table->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Rows
	m_table->EnableDragRowSize( true );
	m_table->SetRowLabelSize( 40 );
	m_table->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Label Appearance
	
	// Cell Defaults
	m_table->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_TOP );
	gSizer3->Add( m_table, 1, wxALL|wxALIGN_RIGHT, 5 );
	
	
	bSizer2->Add( gSizer3, 0, wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Diagrama de Gantt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	bSizer2->Add( m_staticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_gantt = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_gantt->CreateGrid( 0, 0 );
	m_gantt->EnableEditing( true );
	m_gantt->EnableGridLines( true );
	m_gantt->EnableDragGridSize( false );
	m_gantt->SetMargins( 0, 0 );
	
	// Columns
	m_gantt->EnableDragColMove( false );
	m_gantt->EnableDragColSize( true );
	m_gantt->SetColLabelSize( 30 );
	m_gantt->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Rows
	m_gantt->EnableDragRowSize( true );
	m_gantt->SetRowLabelSize( 40 );
	m_gantt->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	
	// Label Appearance
	
	// Cell Defaults
	m_gantt->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( m_gantt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 0, 1, 0, 0 );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Datos") ), wxVERTICAL );
	
	sbSizer1->SetMinSize( wxSize( 300,70 ) ); 
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText7 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Estrategia:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gSizer5->Add( m_staticText7, 0, wxALL, 5 );
	
	m_strategy_type = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("APROPIATIVA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_strategy_type->Wrap( -1 );
	m_strategy_type->SetFont( wxFont( 9, 74, 90, 92, false, wxT("Arial") ) );
	m_strategy_type->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	gSizer5->Add( m_strategy_type, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Referencias:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	gSizer5->Add( m_staticText13, 0, wxALL, 5 );
	
	
	gSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText14 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("▬ EJECUCIÓN"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetFont( wxFont( 9, 70, 90, 92, false, wxT("Arial") ) );
	m_staticText14->SetForegroundColour( wxColour( 255, 0, 0 ) );
	
	gSizer5->Add( m_staticText14, 0, wxALL, 5 );
	
	
	gSizer5->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText15 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("▬ ESPERA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 9, 70, 90, 92, false, wxT("Arial") ) );
	m_staticText15->SetForegroundColour( wxColour( 103, 162, 184 ) );
	m_staticText15->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	gSizer5->Add( m_staticText15, 0, wxALL, 5 );
	
	
	sbSizer1->Add( gSizer5, 1, wxEXPAND, 5 );
	
	
	gSizer9->Add( sbSizer1, 0, wxALL, 5 );
	
	
	bSizer2->Add( gSizer9, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Mostrar grilla") ) , wxEmptyString, wxITEM_CHECK );
	m_menu1->Append( m_menuItem1 );
	
	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Ocultar grilla") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem2 );
	
	m_menu1->AppendSeparator();
	
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Invertir orden de resultados") ) , wxEmptyString, wxITEM_CHECK );
	m_menu1->Append( m_menuItem3 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( wxResult::wxResultOnContextMenu ), NULL, this ); 
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxResult::keyEvent ) );
	this->Connect( wxEVT_MOTION, wxMouseEventHandler( wxResult::moveWindow ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( wxResult::moveWindow ) );
	m_button_rr->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::RoundRobinStrategy ), NULL, this );
	m_button_srtf->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::SRTFStrategy ), NULL, this );
	m_button_fcfs->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::FCFSStrategy ), NULL, this );
	m_button_sjf->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::SJFStrategy ), NULL, this );
	m_button_preemptivepriority->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::PreemptivePriorityStrategy ), NULL, this );
	m_button_nonpreemptivepriority->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::NonPreemptivePriorityStrategy ), NULL, this );
	m_tablaProcesos->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightDataCell ), NULL, this );
	m_table->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightResultsCell ), NULL, this );
	m_gantt->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( wxResult::displayGanttMenu ), NULL, this );
	this->Connect( m_menuItem1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::showGrid ) );
	this->Connect( m_menuItem2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::hideGrid ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::invertOrder ) );
}

wxResult::~wxResult()
{
	// Disconnect Events
	this->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( wxResult::keyEvent ) );
	this->Disconnect( wxEVT_MOTION, wxMouseEventHandler( wxResult::moveWindow ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( wxResult::moveWindow ) );
	m_button_rr->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::RoundRobinStrategy ), NULL, this );
	m_button_srtf->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::SRTFStrategy ), NULL, this );
	m_button_fcfs->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::FCFSStrategy ), NULL, this );
	m_button_sjf->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::SJFStrategy ), NULL, this );
	m_button_preemptivepriority->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::PreemptivePriorityStrategy ), NULL, this );
	m_button_nonpreemptivepriority->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxResult::NonPreemptivePriorityStrategy ), NULL, this );
	m_tablaProcesos->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightDataCell ), NULL, this );
	m_table->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxResult::highlightResultsCell ), NULL, this );
	m_gantt->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( wxResult::displayGanttMenu ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::showGrid ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::hideGrid ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( wxResult::invertOrder ) );
	
	delete m_menu1; 
}

About::About( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Multiple strategies CPU process"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 15, 74, 90, 92, false, wxT("Sans") ) );
	
	bSizer3->Add( m_staticText15, 0, wxALIGN_CENTER|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText151 = new wxStaticText( this, wxID_ANY, wxT("scheduler simulator"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	m_staticText151->SetFont( wxFont( 15, 74, 90, 92, false, wxT("Sans") ) );
	
	bSizer3->Add( m_staticText151, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Written by Cristian Bottazzi"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer3->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_version = new wxStaticText( this, wxID_ANY, wxT("Version 0.8 - June 2020"), wxDefaultPosition, wxDefaultSize, 0 );
	m_version->Wrap( -1 );
	bSizer3->Add( m_version, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxGridSizer* gSizer7;
	gSizer7 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Icon: IronDevil"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	gSizer7->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_hyperlink2 = new wxHyperlinkCtrl( this, wxID_ANY, wxT(" ID's Space Lab Icons"), wxT("http://www.iconarchive.com/show/ids-space-lab-icons-by-iron-devil.html"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	gSizer7->Add( m_hyperlink2, 0, wxALL, 5 );
	
	
	bSizer3->Add( gSizer7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Source code on GitHub"), wxT("https://github.com/cristian1604/cpu-process-scheduler"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer3->Add( m_hyperlink1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

About::~About()
{
}

wxCompare::wxCompare( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_comparer = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_comparer->CreateGrid( 0, 1 );
	m_comparer->EnableEditing( false );
	m_comparer->EnableGridLines( true );
	m_comparer->EnableDragGridSize( true );
	m_comparer->SetMargins( 0, 0 );
	
	// Columns
	m_comparer->SetColSize( 0, 95 );
	m_comparer->EnableDragColMove( false );
	m_comparer->EnableDragColSize( true );
	m_comparer->SetColLabelSize( 30 );
	m_comparer->SetColLabelValue( 0, wxT("Espera") );
	m_comparer->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_comparer->EnableDragRowSize( true );
	m_comparer->SetRowLabelSize( 170 );
	m_comparer->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_comparer->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer4->Add( m_comparer, 1, wxEXPAND|wxALL, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

wxCompare::~wxCompare()
{
}
