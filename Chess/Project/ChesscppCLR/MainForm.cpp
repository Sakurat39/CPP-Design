#include "MainForm.h"
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::IO;
using namespace System::Drawing;
using namespace System::Windows::Forms;
int main()
{
	//System::Windows::Forms::Application::Run(gcnew ChesscppCLR::MainForm());
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//MessageBox::Show(Application::ExecutablePath);
	Application::Run(gcnew ChesscppCLR::MainForm());
	
	return 0;
}