#include <wx/image.h>
#include "Application.h"
#include "VentanaInicio.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	wxInitAllImageHandlers();
	VentanaInicio *win = new VentanaInicio(NULL);
	win->Show();
	return true;
}

