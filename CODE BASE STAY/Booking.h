#pragma once

namespace CODEBASESTAY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel2;






	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::DataGridView^ dgvRooms;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Stt;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ checkin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ checkout;
	private: System::Windows::Forms::Button^ button1;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dgvRooms = (gcnew System::Windows::Forms::DataGridView());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Stt = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkout = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRooms))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DarkGreen;
			this->label1->Location = System::Drawing::Point(16, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Booking Management";
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->dateTimePicker2);
			this->panel1->Controls->Add(this->dateTimePicker1);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel1->Location = System::Drawing::Point(29, 83);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1022, 338);
			this->panel1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::DarkGreen;
			this->label2->Location = System::Drawing::Point(14, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 23);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Booking Details";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(21, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 23);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Guest Name :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(21, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(140, 23);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Phone Number :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(21, 221);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 23);
			this->label5->TabIndex = 3;
			this->label5->Text = L"NIC :";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(494, 64);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 23);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Room No:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(494, 140);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(127, 23);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Check-in Date:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Black;
			this->label8->Location = System::Drawing::Point(494, 226);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(139, 23);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Check-out Date:";
			// 
			// textBox1
			// 
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(163, 64);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(308, 27);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(166, 144);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(308, 27);
			this->textBox2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(163, 221);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(308, 27);
			this->textBox3->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(640, 68);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(308, 27);
			this->textBox4->TabIndex = 10;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Location = System::Drawing::Point(641, 142);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(308, 27);
			this->dateTimePicker1->TabIndex = 13;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->dateTimePicker2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker2->Location = System::Drawing::Point(641, 224);
			this->dateTimePicker2->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(307, 27);
			this->dateTimePicker2->TabIndex = 14;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->dgvRooms);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Location = System::Drawing::Point(29, 446);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1021, 316);
			this->panel2->TabIndex = 2;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::DarkGreen;
			this->label9->Location = System::Drawing::Point(14, 14);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(110, 23);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Booking List";
			// 
			// dgvRooms
			// 
			this->dgvRooms->AllowUserToAddRows = false;
			this->dgvRooms->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvRooms->BackgroundColor = System::Drawing::Color::White;
			this->dgvRooms->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgvRooms->ColumnHeadersHeight = 40;
			this->dgvRooms->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Type, this->Price,
					this->Stt, this->checkin, this->checkout
			});
			this->dgvRooms->Location = System::Drawing::Point(18, 72);
			this->dgvRooms->MultiSelect = false;
			this->dgvRooms->Name = L"dgvRooms";
			this->dgvRooms->ReadOnly = true;
			this->dgvRooms->RowHeadersVisible = false;
			this->dgvRooms->RowHeadersWidth = 51;
			this->dgvRooms->RowTemplate->Height = 24;
			this->dgvRooms->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvRooms->Size = System::Drawing::Size(933, 201);
			this->dgvRooms->TabIndex = 2;
			// 
			// Type
			// 
			this->Type->HeaderText = L"Booking ID";
			this->Type->MinimumWidth = 6;
			this->Type->Name = L"Type";
			this->Type->ReadOnly = true;
			// 
			// Price
			// 
			this->Price->HeaderText = L"Guest Name";
			this->Price->MinimumWidth = 6;
			this->Price->Name = L"Price";
			this->Price->ReadOnly = true;
			// 
			// Stt
			// 
			this->Stt->HeaderText = L"Room No";
			this->Stt->MinimumWidth = 6;
			this->Stt->Name = L"Stt";
			this->Stt->ReadOnly = true;
			// 
			// checkin
			// 
			this->checkin->HeaderText = L"Check-in";
			this->checkin->MinimumWidth = 6;
			this->checkin->Name = L"checkin";
			this->checkin->ReadOnly = true;
			// 
			// checkout
			// 
			this->checkout->HeaderText = L"Check-out";
			this->checkout->MinimumWidth = 6;
			this->checkout->Name = L"checkout";
			this->checkout->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Green;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(798, 275);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 47);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Book";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(1098, 766);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::DarkGreen;
			this->Margin = System::Windows::Forms::Padding(3, 5, 3, 5);
			this->Name = L"MyForm1";
			this->Text = L"Booking";
			this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvRooms))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
