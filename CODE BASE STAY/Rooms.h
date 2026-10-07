#pragma once
#include "HotelService.h"

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

			btnAddRoom->Click += gcnew System::EventHandler(
				this, &MyForm::btnAddRoom_Click);
			btnUpdate->Click += gcnew System::EventHandler(
				this, &MyForm::btnUpdate_Click);
			btnDelete->Click += gcnew System::EventHandler(
				this, &MyForm::btnDelete_Click);
			dgvRooms->CellClick += gcnew
				System::Windows::Forms::DataGridViewCellEventHandler(
					this, &MyForm::RoomList_CellClick);
		}
	
	private:
		System::Void btnAddRoom_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			int roomNumber;
			System::Decimal price;

			if (!System::Int32::TryParse(
				textBox1->Text, roomNumber) || roomNumber <= 0)
			{
				MessageBox::Show("Enter a valid positive room number.");
				return;
			}

			if (!System::Decimal::TryParse(
				textBox2->Text, price) ||
				price <= System::Decimal(0))
			{
				MessageBox::Show("Enter a valid positive price.");
				return;
			}

			if (comboBox1->SelectedIndex < 0 ||
				comboBox2->SelectedIndex < 0)
			{
				MessageBox::Show("Select a room type and status.");
				return;
			}

			try
			{
				HotelService^ backend = gcnew HotelService();

				backend->AddRoom(
					roomNumber,
					comboBox1->SelectedItem->ToString()->Trim(),
					price,
					comboBox2->SelectedItem->ToString()->Trim());

				MessageBox::Show("Room saved successfully!");
			}
			catch (MySql::Data::MySqlClient::MySqlException^ ex)
			{
				if (ex->Number == 1062)
				{
					MessageBox::Show(
						"That room number already exists.");
				}
				else
				{
					MessageBox::Show(ex->Message, "Database error");
				}
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error");
			}
		}

	/*private:*/
		System::Void btnUpdate_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			int roomNumber;
			System::Decimal price;

			if (!System::Int32::TryParse(
				textBox1->Text, roomNumber) || roomNumber <= 0)
			{
				MessageBox::Show("Enter the room number to update.");
				return;
			}

			if (!System::Decimal::TryParse(
				textBox2->Text, price) ||
				price <= System::Decimal(0))
			{
				MessageBox::Show("Enter a valid positive price.");
				return;
			}

			if (comboBox1->SelectedIndex < 0 ||
				comboBox2->SelectedIndex < 0)
			{
				MessageBox::Show("Select a room type and status.");
				return;
			}

			try
			{
				HotelService^ backend = gcnew HotelService();

				bool updated = backend->UpdateRoom(
					roomNumber,
					comboBox1->SelectedItem->ToString()->Trim(),
					price,
					comboBox2->SelectedItem->ToString()->Trim());

				if (updated)
				{
					MessageBox::Show("Room updated successfully!");
					LoadRooms();
				}
				else
				{
					MessageBox::Show(
						"No update reported. Check that the room exists "
						"and whether its values are already the same.");
				}
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Update failed");
			}
		}

		System::Void btnDelete_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			int roomNumber;

			if (!System::Int32::TryParse(
				textBox1->Text, roomNumber) || roomNumber <= 0)
			{
				MessageBox::Show("Enter the room number to delete.");
				return;
			}

			System::Windows::Forms::DialogResult answer =
				MessageBox::Show(
					System::String::Format(
						"Delete room {0}?", roomNumber),
					"Confirm deletion",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question);

			if (answer != System::Windows::Forms::DialogResult::Yes)
				return;

			try
			{
				HotelService^ backend = gcnew HotelService();

				if (backend->DeleteRoom(roomNumber))
				{
					MessageBox::Show("Room deleted successfully!");
					textBox1->Clear();
					textBox2->Clear();
					comboBox1->SelectedIndex = -1;
					comboBox2->SelectedIndex = -1;
				}
				else
				{
					MessageBox::Show("That room number was not found.");
				}
			}
			catch (MySql::Data::MySqlClient::MySqlException^ ex)
			{
				if (ex->Number == 1451)
				{
					MessageBox::Show(
						"This room is linked to a reservation "
						"and cannot be deleted.");
				}
				else
				{
					MessageBox::Show(ex->Message, "Delete failed");
				}
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Delete failed");
			}
		}

		void LoadRooms()
		{
			try
			{
				HotelService^ backend = gcnew HotelService();
				System::Data::DataTable^ rooms = backend->GetRooms();

				dgvRooms->DataSource = nullptr;
				dgvRooms->Columns->Clear();
				dgvRooms->AutoGenerateColumns = true;
				dgvRooms->DataSource = rooms;

				dgvRooms->Columns["Room_id"]->HeaderText = "Room Number";
				dgvRooms->Columns["type"]->HeaderText = "Type";
				dgvRooms->Columns["price"]->HeaderText = "Price";
				dgvRooms->Columns["status"]->HeaderText = "Status";

				dgvRooms->ReadOnly = true;
				dgvRooms->AllowUserToAddRows = false;
				dgvRooms->AllowUserToDeleteRows = false;
				dgvRooms->MultiSelect = false;
				dgvRooms->SelectionMode =
					DataGridViewSelectionMode::FullRowSelect;
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Could not refresh room list");
			}
		}

		System::Void RoomList_CellClick(
			System::Object^ sender,
			System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0)
				return;

			DataGridViewRow^ row = dgvRooms->Rows[e->RowIndex];

			textBox1->Text =
				System::Convert::ToString(row->Cells["Room_id"]->Value);

			textBox2->Text =
				System::Convert::ToString(row->Cells["price"]->Value);

			comboBox1->SelectedIndex = -1;
			comboBox2->SelectedIndex = -1;

			System::String^ roomType =
				System::Convert::ToString(row->Cells["type"]->Value)->Trim();

			for (int i = 0; i < comboBox1->Items->Count; i++)
			{
				if (comboBox1->Items[i]->ToString()->Trim() == roomType)
				{
					comboBox1->SelectedIndex = i;
					break;
				}
			}

			comboBox2->SelectedItem =
				System::Convert::ToString(row->Cells["status"]->Value)->Trim();
		}

	


	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ pnlTotalRooms;
	private: System::Windows::Forms::Label^ lblTotalRoomsTitle;
	private: System::Windows::Forms::Panel^ pnlOccupiedRooms;
	private: System::Windows::Forms::Label^ lblOccupiedRoomsTitle;
	private: System::Windows::Forms::Panel^ pnlTotalBookings;
	private: System::Windows::Forms::Label^ lblTotalBookingsTitle;
	private: System::Windows::Forms::Panel^ pnlRoomDetails;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnAddRoom;
	private: System::Windows::Forms::Panel^ pnlRoomList;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ dgvRooms;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Stt;




	protected:






	private: System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pnlTotalRooms = (gcnew System::Windows::Forms::Panel());
			   this->lblTotalRoomsTitle = (gcnew System::Windows::Forms::Label());
			   this->pnlOccupiedRooms = (gcnew System::Windows::Forms::Panel());
			   this->lblOccupiedRoomsTitle = (gcnew System::Windows::Forms::Label());
			   this->pnlTotalBookings = (gcnew System::Windows::Forms::Panel());
			   this->lblTotalBookingsTitle = (gcnew System::Windows::Forms::Label());
			   this->pnlRoomDetails = (gcnew System::Windows::Forms::Panel());
			   this->btnClear = (gcnew System::Windows::Forms::Button());
			   this->btnDelete = (gcnew System::Windows::Forms::Button());
			   this->btnUpdate = (gcnew System::Windows::Forms::Button());
			   this->btnAddRoom = (gcnew System::Windows::Forms::Button());
			   this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->pnlRoomList = (gcnew System::Windows::Forms::Panel());
			   this->dgvRooms = (gcnew System::Windows::Forms::DataGridView());
			   this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Stt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->pnlTotalRooms->SuspendLayout();
			   this->pnlOccupiedRooms->SuspendLayout();
			   this->pnlTotalBookings->SuspendLayout();
			   this->pnlRoomDetails->SuspendLayout();
			   this->pnlRoomList->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRooms))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::DarkGreen;
			   this->label1->Location = System::Drawing::Point(12, 9);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(277, 38);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Room Management";
			   // 
			   // pnlTotalRooms
			   // 
			   this->pnlTotalRooms->BackColor = System::Drawing::Color::White;
			   this->pnlTotalRooms->Controls->Add(this->lblTotalRoomsTitle);
			   this->pnlTotalRooms->Location = System::Drawing::Point(21, 53);
			   this->pnlTotalRooms->Name = L"pnlTotalRooms";
			   this->pnlTotalRooms->Size = System::Drawing::Size(230, 68);
			   this->pnlTotalRooms->TabIndex = 3;
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
			   this->pnlOccupiedRooms->Location = System::Drawing::Point(301, 53);
			   this->pnlOccupiedRooms->Name = L"pnlOccupiedRooms";
			   this->pnlOccupiedRooms->Size = System::Drawing::Size(230, 68);
			   this->pnlOccupiedRooms->TabIndex = 4;
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
			   this->pnlTotalBookings->Location = System::Drawing::Point(592, 53);
			   this->pnlTotalBookings->Name = L"pnlTotalBookings";
			   this->pnlTotalBookings->Size = System::Drawing::Size(230, 68);
			   this->pnlTotalBookings->TabIndex = 5;
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
			   // pnlRoomDetails
			   // 
			   this->pnlRoomDetails->BackColor = System::Drawing::Color::White;
			   this->pnlRoomDetails->Controls->Add(this->btnClear);
			   this->pnlRoomDetails->Controls->Add(this->btnDelete);
			   this->pnlRoomDetails->Controls->Add(this->btnUpdate);
			   this->pnlRoomDetails->Controls->Add(this->btnAddRoom);
			   this->pnlRoomDetails->Controls->Add(this->comboBox2);
			   this->pnlRoomDetails->Controls->Add(this->comboBox1);
			   this->pnlRoomDetails->Controls->Add(this->textBox2);
			   this->pnlRoomDetails->Controls->Add(this->textBox1);
			   this->pnlRoomDetails->Controls->Add(this->label6);
			   this->pnlRoomDetails->Controls->Add(this->label5);
			   this->pnlRoomDetails->Controls->Add(this->label4);
			   this->pnlRoomDetails->Controls->Add(this->label3);
			   this->pnlRoomDetails->Controls->Add(this->label2);
			   this->pnlRoomDetails->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->pnlRoomDetails->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->pnlRoomDetails->Location = System::Drawing::Point(21, 127);
			   this->pnlRoomDetails->Name = L"pnlRoomDetails";
			   this->pnlRoomDetails->Size = System::Drawing::Size(801, 270);
			   this->pnlRoomDetails->TabIndex = 6;
			   // 
			   // btnClear
			   // 
			   this->btnClear->BackColor = System::Drawing::Color::LightSlateGray;
			   this->btnClear->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnClear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnClear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnClear->Location = System::Drawing::Point(660, 190);
			   this->btnClear->Name = L"btnClear";
			   this->btnClear->Size = System::Drawing::Size(111, 36);
			   this->btnClear->TabIndex = 12;
			   this->btnClear->Text = L"Clear";
			   this->btnClear->UseVisualStyleBackColor = false;
			   this->btnClear->Click += gcnew System::EventHandler(this, &MyForm::btnClear_Click);
			   // 
			   // btnDelete
			   // 
			   this->btnDelete->BackColor = System::Drawing::Color::Firebrick;
			   this->btnDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnDelete->Location = System::Drawing::Point(469, 190);
			   this->btnDelete->Name = L"btnDelete";
			   this->btnDelete->Size = System::Drawing::Size(111, 36);
			   this->btnDelete->TabIndex = 11;
			   this->btnDelete->Text = L"Delete";
			   this->btnDelete->UseVisualStyleBackColor = false;
			   // 
			   // btnUpdate
			   // 
			   this->btnUpdate->BackColor = System::Drawing::Color::LightGreen;
			   this->btnUpdate->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnUpdate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnUpdate->Location = System::Drawing::Point(280, 190);
			   this->btnUpdate->Name = L"btnUpdate";
			   this->btnUpdate->Size = System::Drawing::Size(111, 36);
			   this->btnUpdate->TabIndex = 10;
			   this->btnUpdate->Text = L"Update";
			   this->btnUpdate->UseVisualStyleBackColor = false;
			   // 
			   // btnAddRoom
			   // 
			   this->btnAddRoom->BackColor = System::Drawing::Color::DarkGreen;
			   this->btnAddRoom->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->btnAddRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->btnAddRoom->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->btnAddRoom->Location = System::Drawing::Point(73, 190);
			   this->btnAddRoom->Name = L"btnAddRoom";
			   this->btnAddRoom->Size = System::Drawing::Size(111, 36);
			   this->btnAddRoom->TabIndex = 9;
			   this->btnAddRoom->Text = L"Add Room";
			   this->btnAddRoom->UseVisualStyleBackColor = false;
			   // 
			   // comboBox2
			   // 
			   this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox2->FormattingEnabled = true;
			   this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Available", L"Occupied" });
			   this->comboBox2->Location = System::Drawing::Point(581, 125);
			   this->comboBox2->Name = L"comboBox2";
			   this->comboBox2->Size = System::Drawing::Size(190, 31);
			   this->comboBox2->TabIndex = 8;
			   this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Single", L"Double ", L"Suite" });
			   this->comboBox1->Location = System::Drawing::Point(581, 67);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(190, 31);
			   this->comboBox1->TabIndex = 7;
			   this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(201, 130);
			   this->textBox2->MaxLength = 10;
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(190, 30);
			   this->textBox2->TabIndex = 6;
			   this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			   this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Enter);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(201, 70);
			   this->textBox1->MaxLength = 5;
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(190, 30);
			   this->textBox1->TabIndex = 5;
			   this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Enter);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label6->Location = System::Drawing::Point(465, 133);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(70, 23);
			   this->label6->TabIndex = 4;
			   this->label6->Text = L"Status :";
			   this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label5->Location = System::Drawing::Point(57, 133);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(142, 23);
			   this->label5->TabIndex = 3;
			   this->label5->Text = L"Price per Night :";
			   this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(465, 70);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(110, 23);
			   this->label4->TabIndex = 2;
			   this->label4->Text = L"Room Type :";
			   this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->Location = System::Drawing::Point(57, 70);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(138, 23);
			   this->label3->TabIndex = 1;
			   this->label3->Text = L"Room Number :";
			   this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::DarkGreen;
			   this->label2->Location = System::Drawing::Point(56, 13);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(149, 30);
			   this->label2->TabIndex = 0;
			   this->label2->Text = L"Room Details";
			   this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			   // 
			   // pnlRoomList
			   // 
			   this->pnlRoomList->BackColor = System::Drawing::Color::White;
			   this->pnlRoomList->Controls->Add(this->dgvRooms);
			   this->pnlRoomList->Controls->Add(this->label7);
			   this->pnlRoomList->Location = System::Drawing::Point(21, 403);
			   this->pnlRoomList->Name = L"pnlRoomList";
			   this->pnlRoomList->Size = System::Drawing::Size(801, 288);
			   this->pnlRoomList->TabIndex = 7;
			   // 
			   // dgvRooms
			   // 
			   this->dgvRooms->AllowUserToAddRows = false;
			   this->dgvRooms->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->dgvRooms->BackgroundColor = System::Drawing::Color::White;
			   this->dgvRooms->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->dgvRooms->ColumnHeadersHeight = 40;
			   this->dgvRooms->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				   this->Type, this->Price,
					   this->Stt
			   });
			   this->dgvRooms->Location = System::Drawing::Point(51, 63);
			   this->dgvRooms->MultiSelect = false;
			   this->dgvRooms->Name = L"dgvRooms";
			   this->dgvRooms->ReadOnly = true;
			   this->dgvRooms->RowHeadersVisible = false;
			   this->dgvRooms->RowHeadersWidth = 51;
			   this->dgvRooms->RowTemplate->Height = 24;
			   this->dgvRooms->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->dgvRooms->Size = System::Drawing::Size(720, 201);
			   this->dgvRooms->TabIndex = 1;
			   this->dgvRooms->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dgvRooms_CellContentClick);
			   // 
			   // Type
			   // 
			   this->Type->HeaderText = L"Type";
			   this->Type->MinimumWidth = 6;
			   this->Type->Name = L"Type";
			   this->Type->ReadOnly = true;
			   // 
			   // Price
			   // 
			   this->Price->HeaderText = L"Price";
			   this->Price->MinimumWidth = 6;
			   this->Price->Name = L"Price";
			   this->Price->ReadOnly = true;
			   // 
			   // Stt
			   // 
			   this->Stt->HeaderText = L"Status";
			   this->Stt->MinimumWidth = 6;
			   this->Stt->Name = L"Stt";
			   this->Stt->ReadOnly = true;
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->ForeColor = System::Drawing::Color::DarkGreen;
			   this->label7->Location = System::Drawing::Point(12, 25);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(106, 28);
			   this->label7->TabIndex = 0;
			   this->label7->Text = L"Room List";
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->AutoScroll = true;
			   this->BackColor = System::Drawing::Color::Gainsboro;
			   this->ClientSize = System::Drawing::Size(878, 533);
			   this->Controls->Add(this->pnlRoomList);
			   this->Controls->Add(this->pnlRoomDetails);
			   this->Controls->Add(this->pnlTotalRooms);
			   this->Controls->Add(this->pnlOccupiedRooms);
			   this->Controls->Add(this->pnlTotalBookings);
			   this->Controls->Add(this->label1);
			   this->Name = L"MyForm";
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->pnlTotalRooms->ResumeLayout(false);
			   this->pnlTotalRooms->PerformLayout();
			   this->pnlOccupiedRooms->ResumeLayout(false);
			   this->pnlOccupiedRooms->PerformLayout();
			   this->pnlTotalBookings->ResumeLayout(false);
			   this->pnlTotalBookings->PerformLayout();
			   this->pnlRoomDetails->ResumeLayout(false);
			   this->pnlRoomDetails->PerformLayout();
			   this->pnlRoomList->ResumeLayout(false);
			   this->pnlRoomList->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRooms))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

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
		LoadRooms();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dgvRooms_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Clear();
	this->textBox2->Clear();

	// Reset your dropdowns using their exact designer names
	this->comboBox1->SelectedIndex = -1;
	this->comboBox1->Text = "";

	this->comboBox2->SelectedIndex = -1;
	this->comboBox2->Text = "";

	// Return cursor focus back to the first text box
	this->textBox1->Focus();
}

private: System::Void Enter(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	TextBox^ txt = dynamic_cast<TextBox^>(sender);

	// Allow digits, control keys, and a decimal point
	if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar) && e->KeyChar != '.') {
		e->Handled = true;
	}

	// Prevent typing more than one decimal point
	if (e->KeyChar == '.' && txt->Text->Contains(".")) {
		e->Handled = true;
	}
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}