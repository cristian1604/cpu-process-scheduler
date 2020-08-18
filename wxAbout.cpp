#include "wxAbout.h"

wxAbout::wxAbout(wxWindow *parent) : About(parent) {
	m_version->SetLabel("Version 1.0 - August 2020");
	m_hyperlink1->SetFocus();
}

wxAbout::~wxAbout() {
	
}

