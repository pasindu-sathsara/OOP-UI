#pragma once
#include "Rooms.h"
#include "Guest.h" 

namespace CODEBASESTAY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
		{
			InitializeComponent();
			// Set initial active highlight on Dashboard button
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(50, 80, 70);
		}

	protected:
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panelSidebar;
		System::Windows::Forms::Panel^ panelMainContent;

		// Sidebar Buttons
		System::Windows::Forms::Button^ btnDashboard;
		System::Windows::Forms::Button^ btnRooms;
		System::Windows::Forms::Button^ btnGuests;
		System::Windows::Forms::Button^ btnLogout;

		// Dashboard Screen Controls
		System::Windows::Forms::Label^ lblWelcome;
		System::Windows::Forms::Label^ lblAdmin;
		System::Windows::Forms::Panel^ pnlTotalRooms;
		System::Windows::Forms::Label^ lblTotalRoomsTitle;

		System::Windows::Forms::Panel^ pnlOccupiedRooms;
		System::Windows::Forms::Label^ lblOccupiedRoomsTitle;

		System::Windows::Forms::Panel^ pnlTotalBookings;
		System::Windows::Forms::Label^ lblTotalBookingsTitle;

		System::Windows::Forms::Panel^ pnlRecentBookings;
		System::Windows::Forms::Label^ lblRecentTitle;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::DataGridViewTextBoxColumn^ GuestN;
		System::Windows::Forms::DataGridViewTextBoxColumn^ Amount;
		System::Windows::Forms::DataGridViewTextBoxColumn^ RoomCol;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelSidebar = (gcnew System::Windows::Forms::Panel());
			this->btnDashboard = (gcnew System::Windows::Forms::Button());
			this->btnRooms = (gcnew System::Windows::Forms::Button());
			this->btnGuests = (gcnew System::Windows::Forms::Button());
			this->btnLogout = (gcnew System::Windows::Forms::Button());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->lblAdmin = (gcnew System::Windows::Forms::Label());
			this->panelMainContent = (gcnew System::Windows::Forms::Panel());
			this->pnlTotalRooms = (gcnew System::Windows::Forms::Panel());
			this->lblTotalRoomsTitle = (gcnew System::Windows::Forms::Label());
			this->pnlOccupiedRooms = (gcnew System::Windows::Forms::Panel());
			this->lblOccupiedRoomsTitle = (gcnew System::Windows::Forms::Label());
			this->pnlTotalBookings = (gcnew System::Windows::Forms::Panel());
			this->lblTotalBookingsTitle = (gcnew System::Windows::Forms::Label());
			this->pnlRecentBookings = (gcnew System::Windows::Forms::Panel());
			this->lblRecentTitle = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->GuestN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panelSidebar->SuspendLayout();
			this->panelMainContent->SuspendLayout();
			this->pnlTotalRooms->SuspendLayout();
			this->pnlOccupiedRooms->SuspendLayout();
			this->pnlTotalBookings->SuspendLayout();
			this->pnlRecentBookings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panelSidebar
			// 
			this->panelSidebar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->panelSidebar->Controls->Add(this->btnDashboard);
			this->panelSidebar->Controls->Add(this->btnRooms);
			this->panelSidebar->Controls->Add(this->btnGuests);
			this->panelSidebar->Controls->Add(this->btnLogout);
			this->panelSidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelSidebar->Location = System::Drawing::Point(0, 0);
			this->panelSidebar->Name = L"panelSidebar";
			this->panelSidebar->Size = System::Drawing::Size(260, 721);
			this->panelSidebar->TabIndex = 0;
			// 
			// btnDashboard
			// 
			this->btnDashboard->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDashboard->FlatAppearance->BorderSize = 0;
			this->btnDashboard->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDashboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnDashboard->ForeColor = System::Drawing::Color::White;
			this->btnDashboard->Location = System::Drawing::Point(15, 180);
			this->btnDashboard->Name = L"btnDashboard";
			this->btnDashboard->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->btnDashboard->Size = System::Drawing::Size(230, 55);
			this->btnDashboard->TabIndex = 0;
			this->btnDashboard->Text = L"Dashboard";
			this->btnDashboard->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnDashboard->UseVisualStyleBackColor = true;
			this->btnDashboard->Click += gcnew System::EventHandler(this, &Dashboard::btnDashboard_Click);
			// 
			// btnRooms
			// 
			this->btnRooms->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRooms->FlatAppearance->BorderSize = 0;
			this->btnRooms->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRooms->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnRooms->ForeColor = System::Drawing::Color::White;
			this->btnRooms->Location = System::Drawing::Point(15, 255);
			this->btnRooms->Name = L"btnRooms";
			this->btnRooms->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->btnRooms->Size = System::Drawing::Size(230, 55);
			this->btnRooms->TabIndex = 1;
			this->btnRooms->Text = L"Rooms";
			this->btnRooms->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnRooms->UseVisualStyleBackColor = true;
			this->btnRooms->Click += gcnew System::EventHandler(this, &Dashboard::Rooms_Click);
			// 
			// btnGuests
			// 
			this->btnGuests->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnGuests->FlatAppearance->BorderSize = 0;
			this->btnGuests->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGuests->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnGuests->ForeColor = System::Drawing::Color::White;
			this->btnGuests->Location = System::Drawing::Point(15, 330);
			this->btnGuests->Name = L"btnGuests";
			this->btnGuests->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->btnGuests->Size = System::Drawing::Size(230, 55);
			this->btnGuests->TabIndex = 2;
			this->btnGuests->Text = L"Guests";
			this->btnGuests->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnGuests->UseVisualStyleBackColor = true;
			this->btnGuests->Click += gcnew System::EventHandler(this, &Dashboard::btnGuests_Click);
			// 
			// btnLogout
			// 
			this->btnLogout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogout->FlatAppearance->BorderSize = 0;
			this->btnLogout->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogout->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->btnLogout->ForeColor = System::Drawing::Color::White;
			this->btnLogout->Location = System::Drawing::Point(15, 630);
			this->btnLogout->Name = L"btnLogout";
			this->btnLogout->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->btnLogout->Size = System::Drawing::Size(230, 55);
			this->btnLogout->TabIndex = 3;
			this->btnLogout->Text = L"Logout";
			this->btnLogout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLogout->UseVisualStyleBackColor = true;
			this->btnLogout->Click += gcnew System::EventHandler(this, &Dashboard::btnLogout_Click);
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
			this->lblWelcome->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->lblWelcome->Location = System::Drawing::Point(290, 25);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(239, 41);
			this->lblWelcome->TabIndex = 1;
			this->lblWelcome->Text = L"Welcome Back !";
			// 
			// lblAdmin
			// 
			this->lblAdmin->AutoSize = true;
			this->lblAdmin->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold));
			this->lblAdmin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->lblAdmin->Location = System::Drawing::Point(292, 68);
			this->lblAdmin->Name = L"lblAdmin";
			this->lblAdmin->Size = System::Drawing::Size(72, 28);
			this->lblAdmin->TabIndex = 2;
			this->lblAdmin->Text = L"Admin";
			// 
			// panelMainContent
			// 
			this->panelMainContent->Controls->Add(this->pnlTotalRooms);
			this->panelMainContent->Controls->Add(this->pnlOccupiedRooms);
			this->panelMainContent->Controls->Add(this->pnlTotalBookings);
			this->panelMainContent->Controls->Add(this->pnlRecentBookings);
			this->panelMainContent->Location = System::Drawing::Point(280, 115);
			this->panelMainContent->Name = L"panelMainContent";
			this->panelMainContent->Size = System::Drawing::Size(1040, 580);
			this->panelMainContent->TabIndex = 3;
			// 
			// pnlTotalRooms
			// 
			this->pnlTotalRooms->BackColor = System::Drawing::Color::White;
			this->pnlTotalRooms->Controls->Add(this->lblTotalRoomsTitle);
			this->pnlTotalRooms->Location = System::Drawing::Point(15, 15);
			this->pnlTotalRooms->Name = L"pnlTotalRooms";
			this->pnlTotalRooms->Size = System::Drawing::Size(315, 130);
			this->pnlTotalRooms->TabIndex = 0;
			// 
			// lblTotalRoomsTitle
			// 
			this->lblTotalRoomsTitle->AutoSize = true;
			this->lblTotalRoomsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblTotalRoomsTitle->ForeColor = System::Drawing::Color::Gray;
			this->lblTotalRoomsTitle->Location = System::Drawing::Point(20, 20);
			this->lblTotalRoomsTitle->Name = L"lblTotalRoomsTitle";
			this->lblTotalRoomsTitle->Size = System::Drawing::Size(129, 28);
			this->lblTotalRoomsTitle->TabIndex = 0;
			this->lblTotalRoomsTitle->Text = L"Total Rooms";
			// 
			// pnlOccupiedRooms
			// 
			this->pnlOccupiedRooms->BackColor = System::Drawing::Color::White;
			this->pnlOccupiedRooms->Controls->Add(this->lblOccupiedRoomsTitle);
			this->pnlOccupiedRooms->Location = System::Drawing::Point(350, 15);
			this->pnlOccupiedRooms->Name = L"pnlOccupiedRooms";
			this->pnlOccupiedRooms->Size = System::Drawing::Size(315, 130);
			this->pnlOccupiedRooms->TabIndex = 1;
			// 
			// lblOccupiedRoomsTitle
			// 
			this->lblOccupiedRoomsTitle->AutoSize = true;
			this->lblOccupiedRoomsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblOccupiedRoomsTitle->ForeColor = System::Drawing::Color::Gray;
			this->lblOccupiedRoomsTitle->Location = System::Drawing::Point(20, 20);
			this->lblOccupiedRoomsTitle->Name = L"lblOccupiedRoomsTitle";
			this->lblOccupiedRoomsTitle->Size = System::Drawing::Size(170, 28);
			this->lblOccupiedRoomsTitle->TabIndex = 0;
			this->lblOccupiedRoomsTitle->Text = L"Occupied Rooms";
			// 
			// pnlTotalBookings
			// 
			this->pnlTotalBookings->BackColor = System::Drawing::Color::White;
			this->pnlTotalBookings->Controls->Add(this->lblTotalBookingsTitle);
			this->pnlTotalBookings->Location = System::Drawing::Point(685, 15);
			this->pnlTotalBookings->Name = L"pnlTotalBookings";
			this->pnlTotalBookings->Size = System::Drawing::Size(340, 130);
			this->pnlTotalBookings->TabIndex = 2;
			// 
			// lblTotalBookingsTitle
			// 
			this->lblTotalBookingsTitle->AutoSize = true;
			this->lblTotalBookingsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
			this->lblTotalBookingsTitle->ForeColor = System::Drawing::Color::Gray;
			this->lblTotalBookingsTitle->Location = System::Drawing::Point(20, 20);
			this->lblTotalBookingsTitle->Name = L"lblTotalBookingsTitle";
			this->lblTotalBookingsTitle->Size = System::Drawing::Size(152, 28);
			this->lblTotalBookingsTitle->TabIndex = 0;
			this->lblTotalBookingsTitle->Text = L"Total Bookings";
			// 
			// pnlRecentBookings
			// 
			this->pnlRecentBookings->BackColor = System::Drawing::Color::White;
			this->pnlRecentBookings->Controls->Add(this->lblRecentTitle);
			this->pnlRecentBookings->Controls->Add(this->dataGridView1);
			this->pnlRecentBookings->Location = System::Drawing::Point(15, 165);
			this->pnlRecentBookings->Name = L"pnlRecentBookings";
			this->pnlRecentBookings->Size = System::Drawing::Size(1010, 400);
			this->pnlRecentBookings->TabIndex = 3;
			// 
			// lblRecentTitle
			// 
			this->lblRecentTitle->AutoSize = true;
			this->lblRecentTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblRecentTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->lblRecentTitle->Location = System::Drawing::Point(20, 20);
			this->lblRecentTitle->Name = L"lblRecentTitle";
			this->lblRecentTitle->Size = System::Drawing::Size(184, 30);
			this->lblRecentTitle->TabIndex = 0;
			this->lblRecentTitle->Text = L"Recent Bookings";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->GuestN,
					this->Amount, this->RoomCol
			});
			this->dataGridView1->Location = System::Drawing::Point(20, 70);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(970, 310);
			this->dataGridView1->TabIndex = 1;
			// 
			// GuestN
			// 
			this->GuestN->HeaderText = L"Guest Name";
			this->GuestN->MinimumWidth = 6;
			this->GuestN->Name = L"GuestN";
			this->GuestN->ReadOnly = true;
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Amount";
			this->Amount->MinimumWidth = 6;
			this->Amount->Name = L"Amount";
			this->Amount->ReadOnly = true;
			// 
			// RoomCol
			// 
			this->RoomCol->HeaderText = L"Room";
			this->RoomCol->MinimumWidth = 6;
			this->RoomCol->Name = L"RoomCol";
			this->RoomCol->ReadOnly = true;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 28);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(246)));
			this->ClientSize = System::Drawing::Size(1348, 721);
			this->Controls->Add(this->panelMainContent);
			this->Controls->Add(this->lblAdmin);
			this->Controls->Add(this->lblWelcome);
			this->Controls->Add(this->panelSidebar);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->MaximizeBox = false;
			this->Name = L"Dashboard";
			this->Text = L"Dashboard - Code Base StaySync";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->panelSidebar->ResumeLayout(false);
			this->panelMainContent->ResumeLayout(false);
			this->pnlTotalRooms->ResumeLayout(false);
			this->pnlTotalRooms->PerformLayout();
			this->pnlOccupiedRooms->ResumeLayout(false);
			this->pnlOccupiedRooms->PerformLayout();
			this->pnlTotalBookings->ResumeLayout(false);
			this->pnlTotalBookings->PerformLayout();
			this->pnlRecentBookings->ResumeLayout(false);
			this->pnlRecentBookings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void btnDashboard_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(50, 80, 70);
			this->btnRooms->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);
			this->btnGuests->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);

			this->panelMainContent->Controls->Clear();
			this->panelMainContent->Controls->Add(this->pnlTotalRooms);
			this->panelMainContent->Controls->Add(this->pnlOccupiedRooms);
			this->panelMainContent->Controls->Add(this->pnlTotalBookings);
			this->panelMainContent->Controls->Add(this->pnlRecentBookings);
		}

		System::Void Rooms_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnRooms->BackColor = System::Drawing::Color::FromArgb(50, 80, 70);
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);
			this->btnGuests->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);

			CODEBASESTAY::MyForm^ roomsForm = gcnew CODEBASESTAY::MyForm();
			roomsForm->TopLevel = false;
			roomsForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			roomsForm->Dock = System::Windows::Forms::DockStyle::Fill;

			this->panelMainContent->Controls->Clear();
			this->panelMainContent->Controls->Add(roomsForm);
			roomsForm->Show();
		}

		System::Void btnGuests_Click(System::Object^ sender, System::EventArgs^ e) {
			this->btnGuests->BackColor = System::Drawing::Color::FromArgb(50, 80, 70);
			this->btnDashboard->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);
			this->btnRooms->BackColor = System::Drawing::Color::FromArgb(76, 107, 93);

			CODEBASESTAY::MyForm1^ guestForm = gcnew CODEBASESTAY::MyForm1();
			guestForm->TopLevel = false;
			guestForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			guestForm->Dock = System::Windows::Forms::DockStyle::Fill;

			this->panelMainContent->Controls->Clear();
			this->panelMainContent->Controls->Add(guestForm);
			guestForm->Show();
		}

		System::Void btnLogout_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}

	private:
		System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
		}
	};
}