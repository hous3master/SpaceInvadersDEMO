#include "MyForm.h"  
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);  Application::Run(gcnew SpaceInvadersDEMO::MyForm()); //THE NAME BEHIND IS THE PROJECT NAME
}