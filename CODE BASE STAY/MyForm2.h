#pragma once

#include "Dashboard.h"

namespace CODEBASESTAY {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();

			// Automatically focus username textbox
			this->ActiveControl = textBox1;
		}

	protected:
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ errorLabel;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));

			this->panel1 =
				(gcnew System::Windows::Forms::Panel());

			this->errorLabel =
				(gcnew System::Windows::Forms::Label());

			this->button2 =
				(gcnew System::Windows::Forms::Button());

			this->button1 =
				(gcnew System::Windows::Forms::Button());

			this->textBox2 =
				(gcnew System::Windows::Forms::TextBox());

			this->textBox1 =
				(gcnew System::Windows::Forms::TextBox());

			this->label3 =
				(gcnew System::Windows::Forms::Label());

			this->label2 =
				(gcnew System::Windows::Forms::Label());

			this->label1 =
				(gcnew System::Windows::Forms::Label());

			this->panel1->SuspendLayout();
			this->SuspendLayout();

			// =====================================================
			// panel1
			// =====================================================

			this->panel1->Controls->Add(this->errorLabel);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);

			this->panel1->Location =
				System::Drawing::Point(171, 210);

			this->panel1->Name =
				L"panel1";

			this->panel1->Size =
				System::Drawing::Size(308, 250);

			this->panel1->TabIndex = 0;


			// =====================================================
			// errorLabel
			// =====================================================

			this->errorLabel->AutoSize = true;

			this->errorLabel->Font =
				(gcnew System::Drawing::Font(
					L"Microsoft Tai Le",
					9,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->errorLabel->ForeColor =
				System::Drawing::Color::Crimson;

			this->errorLabel->Location =
				System::Drawing::Point(24, 170);

			this->errorLabel->Name =
				L"errorLabel";

			this->errorLabel->Size =
				System::Drawing::Size(226, 19);

			this->errorLabel->TabIndex = 6;

			this->errorLabel->Text =
				L"Invalid Username or Password!";

			this->errorLabel->Visible = false;

			this->errorLabel->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm2::errorLabel_Click);


			// =====================================================
			// button2 - Show / Hide Password
			// =====================================================

			this->button2->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->button2->FlatStyle =
				System::Windows::Forms::FlatStyle::Flat;

			this->button2->Font =
				(gcnew System::Drawing::Font(
					L"Microsoft Sans Serif",
					9,
					System::Drawing::FontStyle::Regular,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->button2->Location =
				System::Drawing::Point(187, 128);

			this->button2->Name =
				L"button2";

			this->button2->Size =
				System::Drawing::Size(67, 29);

			this->button2->TabIndex = 5;

			this->button2->Text =
				L"Show";

			this->button2->UseVisualStyleBackColor = true;

			this->button2->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm2::button2_Click);


			// =====================================================
			// button1 - Login
			// =====================================================

			this->button1->Cursor =
				System::Windows::Forms::Cursors::Hand;

			this->button1->Font =
				(gcnew System::Drawing::Font(
					L"MS Reference Sans Serif",
					10.8F,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->button1->ForeColor =
				System::Drawing::Color::Navy;

			this->button1->Location =
				System::Drawing::Point(82, 192);

			this->button1->Name =
				L"button1";

			this->button1->Size =
				System::Drawing::Size(94, 35);

			this->button1->TabIndex = 1;

			this->button1->Text =
				L"Login";

			this->button1->UseVisualStyleBackColor = true;

			this->button1->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm2::button1_Click);


			// =====================================================
			// textBox2 - Password
			// =====================================================

			this->textBox2->Font =
				(gcnew System::Drawing::Font(
					L"Bookman Old Style",
					10.8F,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->textBox2->Location =
				System::Drawing::Point(28, 128);

			this->textBox2->Name =
				L"textBox2";

			this->textBox2->PasswordChar =
				'*';

			this->textBox2->Size =
				System::Drawing::Size(164, 29);

			this->textBox2->TabIndex = 4;

			this->textBox2->TextChanged +=
				gcnew System::EventHandler(
					this,
					&MyForm2::textBox2_TextChanged);

			this->textBox2->KeyDown +=
				gcnew System::Windows::Forms::KeyEventHandler(
					this,
					&MyForm2::textBox2_KeyDown);


			// =====================================================
			// textBox1 - Username
			// =====================================================

			this->textBox1->Font =
				(gcnew System::Drawing::Font(
					L"Bookman Old Style",
					10.8F,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->textBox1->Location =
				System::Drawing::Point(28, 51);

			this->textBox1->MaxLength = 15;

			this->textBox1->Name =
				L"textBox1";

			this->textBox1->Size =
				System::Drawing::Size(226, 29);

			this->textBox1->TabIndex = 3;

			this->textBox1->TextChanged +=
				gcnew System::EventHandler(
					this,
					&MyForm2::textBox1_TextChanged_1);

			this->textBox1->KeyDown +=
				gcnew System::Windows::Forms::KeyEventHandler(
					this,
					&MyForm2::textBox1_KeyDown);


			// =====================================================
			// label3 - Password
			// =====================================================

			this->label3->AutoSize = true;

			this->label3->Font =
				(gcnew System::Drawing::Font(
					L"MS Reference Sans Serif",
					12,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->label3->ForeColor =
				System::Drawing::SystemColors::Desktop;

			this->label3->Location =
				System::Drawing::Point(23, 99);

			this->label3->Name =
				L"label3";

			this->label3->Size =
				System::Drawing::Size(113, 26);

			this->label3->TabIndex = 2;

			this->label3->Text =
				L"Password";

			this->label3->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm2::label3_Click);


			// =====================================================
			// label2 - Username
			// =====================================================

			this->label2->AutoSize = true;

			this->label2->Font =
				(gcnew System::Drawing::Font(
					L"MS Reference Sans Serif",
					12,
					System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->label2->ForeColor =
				System::Drawing::SystemColors::Desktop;

			this->label2->Location =
				System::Drawing::Point(23, 22);

			this->label2->Name =
				L"label2";

			this->label2->Size =
				System::Drawing::Size(122, 26);

			this->label2->TabIndex = 1;

			this->label2->Text =
				L"Username";


			// =====================================================
			// label1 - Login Page
			// =====================================================

			this->label1->AutoSize = true;

			this->label1->BackColor =
				System::Drawing::Color::Transparent;

			this->label1->Font =
				(gcnew System::Drawing::Font(
					L"Constantia",
					16.2F,
					static_cast<System::Drawing::FontStyle>(
						(System::Drawing::FontStyle::Bold |
							System::Drawing::FontStyle::Italic)),
					System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));

			this->label1->ForeColor =
				System::Drawing::SystemColors::WindowFrame;

			this->label1->Location =
				System::Drawing::Point(247, 172);

			this->label1->Name =
				L"label1";

			this->label1->Size =
				System::Drawing::Size(157, 35);

			this->label1->TabIndex = 0;

			this->label1->Text =
				L"Login Page";

			this->label1->TextAlign =
				System::Drawing::ContentAlignment::MiddleCenter;

			this->label1->Click +=
				gcnew System::EventHandler(
					this,
					&MyForm2::label1_Click);


			// =====================================================
			// MyForm2
			// =====================================================

			this->AutoScaleDimensions =
				System::Drawing::SizeF(8, 16);

			this->AutoScaleMode =
				System::Windows::Forms::AutoScaleMode::Font;

			this->BackgroundImage =
				(cli::safe_cast<System::Drawing::Image^>(
					resources->GetObject(
						L"$this.BackgroundImage")));

			this->BackgroundImageLayout =
				System::Windows::Forms::ImageLayout::Stretch;

			this->ClientSize =
				System::Drawing::Size(1348, 721);

			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);

			this->Margin =
				System::Windows::Forms::Padding(3, 2, 3, 2);

			this->Name =
				L"MyForm2";

			this->Text =
				L"Login";

			this->Load +=
				gcnew System::EventHandler(
					this,
					&MyForm2::MyForm2_Load);

			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();

			this->ResumeLayout(false);
			this->PerformLayout();
		}

#pragma endregion


		// ============================================================
		// EMPTY EVENTS
		// ============================================================

	private:
		System::Void textBox1_TextChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}


	private:
		System::Void label1_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}


	private:
		System::Void label3_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}


		// ============================================================
		// USERNAME ENTER
		// ============================================================

	private:
		System::Void textBox1_KeyDown(
			System::Object^ sender,
			System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode ==
				System::Windows::Forms::Keys::Enter)
			{
				textBox2->Focus();

				e->SuppressKeyPress = true;
				e->Handled = true;
			}
		}


		// ============================================================
		// PASSWORD ENTER
		// ============================================================

	private:
		System::Void textBox2_KeyDown(
			System::Object^ sender,
			System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyCode ==
				System::Windows::Forms::Keys::Enter)
			{
				button1->PerformClick();

				e->SuppressKeyPress = true;
				e->Handled = true;
			}
		}


		// ============================================================
		// LOGIN BUTTON
		// ============================================================

	private:
		System::Void button1_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			// Username = user
			// Password = 123

			if (textBox1->Text == L"user" &&
				textBox2->Text == L"123")
			{
				errorLabel->Visible = false;

				// Hide Login
				this->Hide();

				// Create Dashboard
				CODEBASESTAY::Dashboard^ dashboardForm =
					gcnew CODEBASESTAY::Dashboard();

				// Open Dashboard and wait until it closes
				dashboardForm->ShowDialog();

				// =================================================
				// When Logout closes Dashboard,
				// return to the SAME Login window
				// =================================================

				// Clear password
				textBox2->Clear();

				// Hide any old error
				errorLabel->Visible = false;

				// Show Login again
				this->Show();

				// Put cursor in password field
				textBox2->Focus();
			}
			else
			{
				errorLabel->Visible = true;

				textBox2->Clear();

				textBox2->Focus();
			}
		}


		// ============================================================
		// SHOW / HIDE PASSWORD
		// ============================================================

	private:
		System::Void button2_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (textBox2->PasswordChar == '*')
			{
				textBox2->PasswordChar = '\0';

				button2->Text =
					L"Hide";
			}
			else
			{
				textBox2->PasswordChar = '*';

				button2->Text =
					L"Show";
			}
		}


		// ============================================================
		// USERNAME CHANGED
		// ============================================================

	private:
		System::Void textBox1_TextChanged_1(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			errorLabel->Visible = false;
		}


		// ============================================================
		// PASSWORD CHANGED
		// ============================================================

	private:
		System::Void textBox2_TextChanged(
			System::Object^ sender,
			System::EventArgs^ e)
		{
			if (textBox2->Text->Length > 0)
			{
				errorLabel->Visible = false;
			}
		}


	private:
		System::Void errorLabel_Click(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}


	private:
		System::Void MyForm2_Load(
			System::Object^ sender,
			System::EventArgs^ e)
		{
		}
	};
}