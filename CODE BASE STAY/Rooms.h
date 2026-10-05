#pragma once

namespace CODEBASESTAY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ DashboardBtn;
	private: System::Windows::Forms::Button^ Logout;
	private: System::Windows::Forms::Button^ Guest;
	private: System::Windows::Forms::Button^ Rooms;
	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->DashboardBtn = (gcnew System::Windows::Forms::Button());
			   this->Rooms = (gcnew System::Windows::Forms::Button());
			   this->Guest = (gcnew System::Windows::Forms::Button());
			   this->Logout = (gcnew System::Windows::Forms::Button());
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				   static_cast<System::Int32>(static_cast<System::Byte>(93)));
			   this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			   this->panel1->Controls->Add(this->Logout);
			   this->panel1->Controls->Add(this->Guest);
			   this->panel1->Controls->Add(this->Rooms);
			   this->panel1->Controls->Add(this->DashboardBtn);
			   this->panel1->Location = System::Drawing::Point(4, 0);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(296, 1272);
			   this->panel1->TabIndex = 1;
			   // 
			   // DashboardBtn
			   // 
			   this->DashboardBtn->AutoSize = true;
			   this->DashboardBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->DashboardBtn->FlatAppearance->BorderSize = 0;
			   this->DashboardBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->DashboardBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->DashboardBtn->ForeColor = System::Drawing::Color::White;
			   this->DashboardBtn->Location = System::Drawing::Point(26, 183);
			   this->DashboardBtn->Name = L"DashboardBtn";
			   this->DashboardBtn->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			   this->DashboardBtn->Size = System::Drawing::Size(180, 50);
			   this->DashboardBtn->TabIndex = 2;
			   this->DashboardBtn->Text = L"Dashboard";
			   this->DashboardBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->DashboardBtn->UseVisualStyleBackColor = true;
			   this->DashboardBtn->Click += gcnew System::EventHandler(this, &MyForm::DashboardBtn_Click);
			   // 
			   // Rooms
			   // 
			   this->Rooms->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Rooms->FlatAppearance->BorderSize = 0;
			   this->Rooms->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Rooms->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rooms->ForeColor = System::Drawing::Color::White;
			   this->Rooms->Location = System::Drawing::Point(26, 272);
			   this->Rooms->Name = L"Rooms";
			   this->Rooms->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			   this->Rooms->Size = System::Drawing::Size(180, 50);
			   this->Rooms->TabIndex = 3;
			   this->Rooms->Text = L"Rooms";
			   this->Rooms->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->Rooms->UseVisualStyleBackColor = true;
			   // 
			   // Guest
			   // 
			   this->Guest->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Guest->FlatAppearance->BorderSize = 0;
			   this->Guest->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Guest->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Guest->ForeColor = System::Drawing::Color::White;
			   this->Guest->Location = System::Drawing::Point(26, 362);
			   this->Guest->Name = L"Guest";
			   this->Guest->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			   this->Guest->Size = System::Drawing::Size(180, 50);
			   this->Guest->TabIndex = 4;
			   this->Guest->Text = L"Guests";
			   this->Guest->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->Guest->UseVisualStyleBackColor = true;
			   // 
			   // Logout
			   // 
			   this->Logout->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->Logout->FlatAppearance->BorderSize = 0;
			   this->Logout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->Logout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Logout->ForeColor = System::Drawing::Color::White;
			   this->Logout->Location = System::Drawing::Point(27, 630);
			   this->Logout->Name = L"Logout";
			   this->Logout->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			   this->Logout->Size = System::Drawing::Size(180, 50);
			   this->Logout->TabIndex = 5;
			   this->Logout->Text = L"Logout";
			   this->Logout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			   this->Logout->UseVisualStyleBackColor = true;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Gainsboro;
			   this->ClientSize = System::Drawing::Size(1348, 721);
			   this->Controls->Add(this->panel1);
			   this->Name = L"MyForm";
			   this->Text = L"Rooms";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void DashboardBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		// Shows the original owner (Dashboard) and hides Rooms smoothly
		if (this->Owner != nullptr) {
			this->Owner->Location = this->Location;
			this->Owner->Show();
		}
		this->Hide();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}