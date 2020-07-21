#include "wxAbout.h"

wxAbout::wxAbout(wxWindow *parent) : About(parent) {
	m_version->SetLabel("Version 0.9 - July 2020");
	m_hyperlink1->SetFocus();
}

wxAbout::~wxAbout() {
	
}

