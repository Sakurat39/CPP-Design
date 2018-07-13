#include "ServerCreate.h"
#include "MainForm.h"
#pragma once
namespace Windowcreate {
	using namespace ChesscppCLR;
	ref class loadwindows {
		
	public:
		void loadserverwindows() {
			ChesscppCLR::ServerCreate^ sc = gcnew ChesscppCLR::ServerCreate();
			sc->Show();
		}
		static void createserver(String^ str,int c) {
			//MainForm::CreateServer(c, str);
		}
	};
}