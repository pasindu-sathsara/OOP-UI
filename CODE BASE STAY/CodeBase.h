#pragma once
#include "MyForm2.h"

namespace CODEBASESTAY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CodeBase : public System::Windows::Forms::Form
	{
	public:
		CodeBase(void)
		{
			InitializeComponent();
		}

	protected:
		~CodeBase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Login;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CodeBase::typeid));
			this->Login = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Login
			// 
			this->Login->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->Login->BackColor = System::Drawing::SystemColors::InfoText;
			this->Login->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Login.BackgroundImage")));
			this->Login->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Login->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Login->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Login->ForeColor = System::Drawing::SystemColors::MenuText;
			this->Login->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Login.Image")));
			this->Login->Location = System::Drawing::Point(239, 365);
			this->Login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Login->Name = L"Login";
			this->Login->Size = System::Drawing::Size(136, 46);
			this->Login->TabIndex = 0;
			this->Login->Text = L"Login";
			this->Login->UseMnemonic = false;
			this->Login->UseVisualStyleBackColor = false;
			this->Login->Click += gcnew System::EventHandler(this, &CodeBase::button1_Click);
			// 
			// CodeBase
			// 
			this->AcceptButton = this->Login;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1348, 721);
			this->Controls->Add(this->Login);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"CodeBase";
			this->Text = L"StaySync";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();

		MyForm2^ nextPage = gcnew MyForm2();

		nextPage->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
		nextPage->Location = this->Location;

		nextPage->ShowDialog();

		Application::Exit();
	}
	};
}