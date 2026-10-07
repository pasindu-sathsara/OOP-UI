#pragma once
#include "HotelService.h"

namespace CODEBASESTAY
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();

			this->button1->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm1::Book_Click);

			this->textBox4->TextChanged +=
				gcnew System::EventHandler(
					this,
					&MyForm1::BookingDetailsChanged);

			this->dateTimePicker1->ValueChanged +=
				gcnew System::EventHandler(
					this,
					&MyForm1::BookingDetailsChanged);

			this->dateTimePicker2->ValueChanged +=
				gcnew System::EventHandler(
					this,
					&MyForm1::BookingDetailsChanged);
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Label^ label8;
		System::Windows::Forms::Label^ label7;
		System::Windows::Forms::Label^ label5;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Panel^ panel2;
		System::Windows::Forms::Label^ label9;
		System::Windows::Forms::DataGridView^ dgvRooms;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::Label^ label10;
		System::Windows::Forms::TextBox^ textBox4;
		System::Windows::Forms::Label^ label6;
		System::Windows::Forms::Label^ label11;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Label^ lblTotalAmount;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->label1 =
				(gcnew System::Windows::Forms::Label());

			this->panel1 =
				(gcnew System::Windows::Forms::Panel());

			this->button1 =
				(gcnew System::Windows::Forms::Button());

			this->dateTimePicker2 =
				(gcnew System::Windows::Forms::DateTimePicker());

			this->dateTimePicker1 =
				(gcnew System::Windows::Forms::DateTimePicker());

			this->textBox3 =
				(gcnew System::Windows::Forms::TextBox());

			this->textBox2 =
				(gcnew System::Windows::Forms::TextBox());

			this->textBox1 =
				(gcnew System::Windows::Forms::TextBox());

			this->label8 =
				(gcnew System::Windows::Forms::Label());

			this->label7 =
				(gcnew System::Windows::Forms::Label());

			this->label5 =
				(gcnew System::Windows::Forms::Label());

			this->label4 =
				(gcnew System::Windows::Forms::Label());

			this->label3 =
				(gcnew System::Windows::Forms::Label());

			this->label2 =
				(gcnew System::Windows::Forms::Label());

			this->panel2 =
				(gcnew System::Windows::Forms::Panel());

			this->dgvRooms =
				(gcnew System::Windows::Forms::DataGridView());

			this->label9 =
				(gcnew System::Windows::Forms::Label());

			this->comboBox1 =
				(gcnew System::Windows::Forms::ComboBox());

			this->label10 =
				(gcnew System::Windows::Forms::Label());

			this->textBox4 =
				(gcnew System::Windows::Forms::TextBox());

			this->label6 =
				(gcnew System::Windows::Forms::Label());

			this->button2 =
				(gcnew System::Windows::Forms::Button());

			this->label11 =
				(gcnew System::Windows::Forms::Label());

			this->lblTotalAmount =
				(gcnew System::Windows::Forms::Label());

			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();

			(cli::safe_cast<
				System::ComponentModel::ISupportInitialize^>
				(this->dgvRooms))->BeginInit();

			this->SuspendLayout();

			this->label1->AutoSize = true;

			this->label1->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					12,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->label1->ForeColor =
				System::Drawing::Color::DarkGreen;

			this->label1->Location =
				System::Drawing::Point(16, 13);

			this->label1->Name =
				L"label1";

			this->label1->Size =
				System::Drawing::Size(221, 28);

			this->label1->TabIndex =
				0;

			this->label1->Text =
				L"Booking Management";

			this->panel1->AutoScroll =
				true;

			this->panel1->BackColor =
				System::Drawing::Color::White;

			this->panel1->Controls->Add(
				this->lblTotalAmount);

			this->panel1->Controls->Add(
				this->label11);

			this->panel1->Controls->Add(
				this->comboBox1);

			this->panel1->Controls->Add(
				this->label10);

			this->panel1->Controls->Add(
				this->button1);

			this->panel1->Controls->Add(
				this->dateTimePicker2);

			this->panel1->Controls->Add(
				this->dateTimePicker1);

			this->panel1->Controls->Add(
				this->textBox4);

			this->panel1->Controls->Add(
				this->textBox3);

			this->panel1->Controls->Add(
				this->textBox2);

			this->panel1->Controls->Add(
				this->textBox1);

			this->panel1->Controls->Add(
				this->label8);

			this->panel1->Controls->Add(
				this->label7);

			this->panel1->Controls->Add(
				this->label6);

			this->panel1->Controls->Add(
				this->label5);

			this->panel1->Controls->Add(
				this->label4);

			this->panel1->Controls->Add(
				this->label3);

			this->panel1->Controls->Add(
				this->label2);

			this->panel1->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->panel1->Location =
				System::Drawing::Point(29, 83);

			this->panel1->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->panel1->Name =
				L"panel1";

			this->panel1->Size =
				System::Drawing::Size(
					1022, 338);

			this->panel1->TabIndex =
				1;

			this->button1->BackColor =
				System::Drawing::Color::Green;

			this->button1->ForeColor =
				System::Drawing::Color::Black;

			this->button1->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->button1->Location =
				System::Drawing::Point(
					798, 275);

			this->button1->Name =
				L"button1";

			this->button1->Size =
				System::Drawing::Size(
					150, 47);

			this->button1->TabIndex =
				15;

			this->button1->Text =
				L"Book";

			this->button1->UseVisualStyleBackColor =
				false;

			this->dateTimePicker2->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->dateTimePicker2->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->dateTimePicker2->Location =
				System::Drawing::Point(
					641, 224);

			this->dateTimePicker2->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->dateTimePicker2->Name =
				L"dateTimePicker2";

			this->dateTimePicker2->Size =
				System::Drawing::Size(
					307, 27);

			this->dateTimePicker2->TabIndex =
				14;

			this->dateTimePicker1->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->dateTimePicker1->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->dateTimePicker1->Location =
				System::Drawing::Point(
					641, 142);

			this->dateTimePicker1->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->dateTimePicker1->Name =
				L"dateTimePicker1";

			this->dateTimePicker1->Size =
				System::Drawing::Size(
					308, 27);

			this->dateTimePicker1->TabIndex =
				13;

			this->textBox3->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->textBox3->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->textBox3->Location =
				System::Drawing::Point(
					166, 208);

			this->textBox3->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->textBox3->Name =
				L"textBox3";

			this->textBox3->Size =
				System::Drawing::Size(
					308, 27);

			this->textBox3->TabIndex =
				9;

			this->textBox2->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->textBox2->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->textBox2->Location =
				System::Drawing::Point(
					166, 144);

			this->textBox2->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->textBox2->Name =
				L"textBox2";

			this->textBox2->Size =
				System::Drawing::Size(
					308, 27);

			this->textBox2->TabIndex =
				8;

			this->textBox1->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->textBox1->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->textBox1->Location =
				System::Drawing::Point(
					163, 64);

			this->textBox1->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->textBox1->Name =
				L"textBox1";

			this->textBox1->Size =
				System::Drawing::Size(
					308, 27);

			this->textBox1->TabIndex =
				7;

			this->label8->AutoSize =
				true;

			this->label8->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label8->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label8->ForeColor =
				System::Drawing::Color::Black;

			this->label8->Location =
				System::Drawing::Point(
					494, 226);

			this->label8->Name =
				L"label8";

			this->label8->Text =
				L"Check-out Date:";

			this->label7->AutoSize =
				true;

			this->label7->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label7->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label7->ForeColor =
				System::Drawing::Color::Black;

			this->label7->Location =
				System::Drawing::Point(
					494, 140);

			this->label7->Name =
				L"label7";

			this->label7->Text =
				L"Check-in Date:";

			this->label5->AutoSize =
				true;

			this->label5->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label5->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label5->ForeColor =
				System::Drawing::Color::Black;

			this->label5->Location =
				System::Drawing::Point(
					24, 208);

			this->label5->Name =
				L"label5";

			this->label5->Text =
				L"NIC :";

			this->label4->AutoSize =
				true;

			this->label4->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label4->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label4->ForeColor =
				System::Drawing::Color::Black;

			this->label4->Location =
				System::Drawing::Point(
					21, 140);

			this->label4->Name =
				L"label4";

			this->label4->Text =
				L"Phone Number :";

			this->label3->AutoSize =
				true;

			this->label3->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label3->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label3->ForeColor =
				System::Drawing::Color::Black;

			this->label3->Location =
				System::Drawing::Point(
					21, 64);

			this->label3->Name =
				L"label3";

			this->label3->Text =
				L"Guest Name :";

			this->label2->AutoSize =
				true;

			this->label2->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label2->ForeColor =
				System::Drawing::Color::DarkGreen;

			this->label2->Location =
				System::Drawing::Point(
					14, 13);

			this->label2->Name =
				L"label2";

			this->label2->Text =
				L"Booking Details";

			this->panel2->BackColor =
				System::Drawing::Color::White;

			this->panel2->Controls->Add(
				this->button2);

			this->panel2->Controls->Add(
				this->dgvRooms);

			this->panel2->Controls->Add(
				this->label9);

			this->panel2->Location =
				System::Drawing::Point(
					29, 446);

			this->panel2->Name =
				L"panel2";

			this->panel2->Size =
				System::Drawing::Size(
					1021, 316);

			this->panel2->TabIndex =
				2;

			this->dgvRooms->AllowUserToAddRows =
				false;

			this->dgvRooms->AllowUserToDeleteRows =
				false;

			this->dgvRooms->AutoGenerateColumns =
				true;

			this->dgvRooms->AutoSizeColumnsMode =
				System::Windows::Forms::
				DataGridViewAutoSizeColumnsMode::Fill;

			this->dgvRooms->BackgroundColor =
				System::Drawing::Color::White;

			this->dgvRooms->BorderStyle =
				System::Windows::Forms::
				BorderStyle::None;

			this->dgvRooms->ColumnHeadersHeight =
				40;

			this->dgvRooms->Location =
				System::Drawing::Point(
					18, 72);

			this->dgvRooms->MultiSelect =
				false;

			this->dgvRooms->Name =
				L"dgvRooms";

			this->dgvRooms->ReadOnly =
				true;

			this->dgvRooms->RowHeadersVisible =
				false;

			this->dgvRooms->RowHeadersWidth =
				51;

			this->dgvRooms->RowTemplate->Height =
				24;

			this->dgvRooms->SelectionMode =
				System::Windows::Forms::
				DataGridViewSelectionMode::
				FullRowSelect;

			this->dgvRooms->Size =
				System::Drawing::Size(
					933, 201);

			this->dgvRooms->TabIndex =
				2;

			this->label9->AutoSize =
				true;

			this->label9->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label9->ForeColor =
				System::Drawing::Color::DarkGreen;

			this->label9->Location =
				System::Drawing::Point(
					14, 14);

			this->label9->Name =
				L"label9";

			this->label9->Text =
				L"Booking List";

			this->comboBox1->DropDownStyle =
				System::Windows::Forms::
				ComboBoxStyle::DropDownList;

			this->comboBox1->FormattingEnabled =
				true;

			this->comboBox1->Items->AddRange(
				gcnew cli::array<
				System::Object^>(3)
			{
				L"Single",
					L"Double",
					L"Suite"
			});

			this->comboBox1->Location =
				System::Drawing::Point(
					163, 275);

			this->comboBox1->Name =
				L"comboBox1";

			this->comboBox1->Size =
				System::Drawing::Size(
					308, 31);

			this->comboBox1->TabIndex =
				17;

			this->label10->AutoSize =
				true;

			this->label10->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label10->ForeColor =
				System::Drawing::Color::Black;

			this->label10->Location =
				System::Drawing::Point(
					20, 278);

			this->label10->Name =
				L"label10";

			this->label10->Text =
				L"Room Type :";

			this->textBox4->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->textBox4->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI Semibold",
					9,
					System::Drawing::FontStyle::Bold));

			this->textBox4->Location =
				System::Drawing::Point(
					640, 68);

			this->textBox4->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->textBox4->Name =
				L"textBox4";

			this->textBox4->Size =
				System::Drawing::Size(
					308, 27);

			this->textBox4->TabIndex =
				10;

			this->label6->AutoSize =
				true;

			this->label6->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->label6->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->label6->ForeColor =
				System::Drawing::Color::Black;

			this->label6->Location =
				System::Drawing::Point(
					494, 64);

			this->label6->Name =
				L"label6";

			this->label6->Text =
				L"Room No:";

			this->button2->BackColor =
				System::Drawing::Color::Green;

			this->button2->ForeColor =
				System::Drawing::Color::Black;

			this->button2->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->button2->Location =
				System::Drawing::Point(
					801, 14);

			this->button2->Name =
				L"button2";

			this->button2->Size =
				System::Drawing::Size(
					150, 47);

			this->button2->TabIndex =
				16;

			this->button2->Text =
				L"Delete";

			this->button2->UseVisualStyleBackColor =
				false;

			this->label11->AutoSize =
				true;

			this->label11->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					12,
					System::Drawing::FontStyle::Bold));

			this->label11->ForeColor =
				System::Drawing::Color::Crimson;

			this->label11->Location =
				System::Drawing::Point(
					493, 294);

			this->label11->Name =
				L"label11";

			this->label11->Text =
				L"Total:";

			this->lblTotalAmount->AutoSize =
				true;

			this->lblTotalAmount->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					12,
					System::Drawing::FontStyle::Bold));

			this->lblTotalAmount->ForeColor =
				System::Drawing::Color::Crimson;

			this->lblTotalAmount->Location =
				System::Drawing::Point(
					558, 294);

			this->lblTotalAmount->Name =
				L"lblTotalAmount";

			this->lblTotalAmount->Text =
				L"Rs. 0.00";

			this->AutoScaleDimensions =
				System::Drawing::SizeF(
					10, 23);

			this->AutoScaleMode =
				System::Windows::Forms::
				AutoScaleMode::Font;

			this->AutoScroll =
				true;

			this->BackColor =
				System::Drawing::Color::Gainsboro;

			this->ClientSize =
				System::Drawing::Size(
					1098, 766);

			this->Controls->Add(
				this->panel2);

			this->Controls->Add(
				this->panel1);

			this->Controls->Add(
				this->label1);

			this->Font =
				(gcnew System::Drawing::Font(
					L"Segoe UI",
					10.2F,
					System::Drawing::FontStyle::Bold));

			this->ForeColor =
				System::Drawing::Color::DarkGreen;

			this->Margin =
				System::Windows::Forms::Padding(
					3, 5, 3, 5);

			this->Name =
				L"MyForm1";

			this->Text =
				L"Booking";

			this->Load +=
				gcnew System::EventHandler(
					this,
					&MyForm1::MyForm1_Load);

			this->panel1->ResumeLayout(
				false);

			this->panel1->PerformLayout();

			this->panel2->ResumeLayout(
				false);

			this->panel2->PerformLayout();

			(cli::safe_cast<
				System::ComponentModel::
				ISupportInitialize^>
				(this->dgvRooms))->EndInit();

			this->ResumeLayout(
				false);

			this->PerformLayout();
		}

#pragma endregion

	private:
		System::Void Book_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			int roomNumber;

			if (!System::Int32::TryParse(
				textBox4->Text,
				roomNumber)
				||
				roomNumber <= 0)
			{
				MessageBox::Show(
					"Enter a valid room number.");

				return;
			}

			if (dateTimePicker2->Value.Date <=
				dateTimePicker1->Value.Date)
			{
				MessageBox::Show(
					"Check-out date must be after check-in date.");

				return;
			}

			try
			{
				HotelService^ backend =
					gcnew HotelService();

				int bookingId =
					backend->CreateBooking(
						textBox1->Text,
						textBox2->Text,
						textBox3->Text,
						roomNumber,
						dateTimePicker1->Value,
						dateTimePicker2->Value);

				MessageBox::Show(
					System::String::Format(
						"Booking saved successfully!\nBooking ID: {0}",
						bookingId));

				LoadBookings();

				ClearFields();
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(
					ex->Message,
					"Booking failed");
			}
		}

	private:
		void CalculateBookingTotal()
		{
			lblTotalAmount->Text =
				"Rs. 0.00";

			comboBox1->SelectedIndex =
				-1;

			int roomNumber;

			if (!System::Int32::TryParse(
				textBox4->Text,
				roomNumber))
			{
				return;
			}

			if (roomNumber <= 0)
			{
				return;
			}

			System::DateTime checkIn =
				dateTimePicker1->Value.Date;

			System::DateTime checkOut =
				dateTimePicker2->Value.Date;

			int nights =
				(checkOut - checkIn).Days;

			if (nights <= 0)
			{
				return;
			}

			try
			{
				HotelService^ backend =
					gcnew HotelService();

				System::Data::DataTable^ rooms =
					backend->GetRooms();

				for each (
					System::Data::DataRow ^ row
					in rooms->Rows)
				{
					int databaseRoomNumber =
						System::Convert::ToInt32(
							row["Room_id"]);

					if (databaseRoomNumber ==
						roomNumber)
					{
						System::String^ roomType =
							System::Convert::ToString(
								row["type"]);

						if (roomType == "Single")
						{
							comboBox1->SelectedIndex =
								0;
						}
						else if (
							roomType->Trim() ==
							"Double")
						{
							comboBox1->SelectedIndex =
								1;
						}
						else if (
							roomType == "Suite")
						{
							comboBox1->SelectedIndex =
								2;
						}

						System::Decimal roomPrice;

						bool validPrice =
							System::Decimal::TryParse(
								System::Convert::ToString(
									row["price"]),
								System::Globalization::
								NumberStyles::Number,
								System::Globalization::
								CultureInfo::
								InvariantCulture,
								roomPrice);

						if (!validPrice)
						{
							return;
						}

						System::Decimal total =
							System::Decimal::Multiply(
								roomPrice,
								System::Decimal(nights));

						lblTotalAmount->Text =
							"Rs. " +
							total.ToString("0.00");

						return;
					}
				}
			}
			catch (System::Exception^)
			{
				lblTotalAmount->Text =
					"Rs. 0.00";
			}
		}

	private:
		System::Void BookingDetailsChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			CalculateBookingTotal();
		}

	private:
		void LoadBookings()
		{
			try
			{
				HotelService^ backend =
					gcnew HotelService();

				System::Data::DataTable^ bookings =
					backend->GetBookings();

				dgvRooms->DataSource =
					nullptr;

				dgvRooms->Columns->Clear();

				dgvRooms->AutoGenerateColumns =
					true;

				dgvRooms->DataSource =
					bookings;

				if (dgvRooms->Columns[
					"booking_id"] != nullptr)
				{
					dgvRooms->Columns[
						"booking_id"]
						->HeaderText =
						"Booking ID";
				}

				if (dgvRooms->Columns[
					"guest_name"] != nullptr)
				{
					dgvRooms->Columns[
						"guest_name"]
						->HeaderText =
						"Guest Name";
				}

				if (dgvRooms->Columns[
					"room_id"] != nullptr)
				{
					dgvRooms->Columns[
						"room_id"]
						->HeaderText =
						"Room No";
				}

				if (dgvRooms->Columns[
					"check_in"] != nullptr)
				{
					dgvRooms->Columns[
						"check_in"]
						->HeaderText =
						"Check-in";

					dgvRooms->Columns[
						"check_in"]
						->DefaultCellStyle
						->Format =
						"yyyy-MM-dd";
				}

				if (dgvRooms->Columns[
					"check_out"] != nullptr)
				{
					dgvRooms->Columns[
						"check_out"]
						->HeaderText =
						"Check-out";

					dgvRooms->Columns[
						"check_out"]
						->DefaultCellStyle
						->Format =
						"yyyy-MM-dd";
				}

				if (dgvRooms->Columns[
					"nights"] != nullptr)
				{
					dgvRooms->Columns[
						"nights"]
						->HeaderText =
						"Nights";
				}

				if (dgvRooms->Columns[
					"total_amount"] != nullptr)
				{
					dgvRooms->Columns[
						"total_amount"]
						->HeaderText =
						"Total";
				}

				if (dgvRooms->Columns[
					"status"] != nullptr)
				{
					dgvRooms->Columns[
						"status"]
						->HeaderText =
						"Status";
				}

				dgvRooms->ReadOnly =
					true;

				dgvRooms->AllowUserToAddRows =
					false;

				dgvRooms->AllowUserToDeleteRows =
					false;

				dgvRooms->MultiSelect =
					false;

				dgvRooms->SelectionMode =
					System::Windows::Forms::
					DataGridViewSelectionMode::
					FullRowSelect;

				dgvRooms->AutoSizeColumnsMode =
					System::Windows::Forms::
					DataGridViewAutoSizeColumnsMode::
					Fill;
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(
					ex->Message,
					"Could not refresh booking list");
			}
		}

	private:
		void ClearFields()
		{
			textBox1->Clear();
			textBox2->Clear();
			textBox3->Clear();
			textBox4->Clear();

			comboBox1->SelectedIndex =
				-1;

			lblTotalAmount->Text =
				"Rs. 0.00";

			textBox1->Focus();
		}

	private:
		System::Void MyForm1_Load(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			LoadBookings();
			CalculateBookingTotal();
		}
	};
}