#pragma once

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
		}

	protected:
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ GuestName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Room;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Amount;







	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->GuestName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Room = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Amount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(-5, -7);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(220, 727);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(54, 224);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(114, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &Dashboard::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(54, 311);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 28);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Room";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(54, 408);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 28);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Guest";
			this->label3->Click += gcnew System::EventHandler(this, &Dashboard::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(54, 659);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 28);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Logout";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label5->Location = System::Drawing::Point(231, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 27);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Welcome Back !";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label6->Location = System::Drawing::Point(270, 36);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(79, 27);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Admin";
			this->label6->Click += gcnew System::EventHandler(this, &Dashboard::label6_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(280, 108);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(218, 149);
			this->panel2->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label7->Location = System::Drawing::Point(35, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 31);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Total Rooms";
			this->label7->Click += gcnew System::EventHandler(this, &Dashboard::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label8->Location = System::Drawing::Point(80, 68);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 27);
			this->label8->TabIndex = 1;
			this->label8->Text = L"120";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Location = System::Drawing::Point(635, 108);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(218, 149);
			this->panel3->TabIndex = 4;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label9->Location = System::Drawing::Point(86, 68);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(48, 27);
			this->label9->TabIndex = 1;
			this->label9->Text = L"120";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label10->Location = System::Drawing::Point(6, 24);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(209, 31);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Occupied Rooms";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel4->Controls->Add(this->label11);
			this->panel4->Controls->Add(this->label12);
			this->panel4->Location = System::Drawing::Point(970, 108);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(218, 149);
			this->panel4->TabIndex = 5;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label11->Location = System::Drawing::Point(80, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(48, 27);
			this->label11->TabIndex = 1;
			this->label11->Text = L"120";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(107)),
				static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->label12->Location = System::Drawing::Point(15, 24);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(188, 31);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Total Bookings";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(93)));
			this->dataGridView1->ColumnHeadersHeight = 40;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->GuestName,
					this->Room, this->Amount
			});
			this->dataGridView1->Location = System::Drawing::Point(280, 378);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(713, 281);
			this->dataGridView1->TabIndex = 6;
			// 
			// GuestName
			// 
			this->GuestName->HeaderText = L"Guest Name";
			this->GuestName->MinimumWidth = 6;
			this->GuestName->Name = L"GuestName";
			this->GuestName->Width = 125;
			// 
			// Room
			// 
			this->Room->HeaderText = L"Room";
			this->Room->MinimumWidth = 6;
			this->Room->Name = L"Room";
			this->Room->Width = 125;
			// 
			// Amount
			// 
			this->Amount->HeaderText = L"Amount";
			this->Amount->MinimumWidth = 6;
			this->Amount->Name = L"Amount";
			this->Amount->Width = 125;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(1348, 721);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}