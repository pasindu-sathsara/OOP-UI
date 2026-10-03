#include "CodeBase.h"
#include "MyForm2.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Start with the main welcome/landing screen
    CODEBASESTAY::CodeBase^ homeForm = gcnew CODEBASESTAY::CodeBase();
    Application::Run(homeForm);

    return 0;
}