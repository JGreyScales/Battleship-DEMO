#pragma once

#include <stdlib.h>
#include <string>
#include <iostream>

#define CURL_STATICLIB
#include <curl\curl.h>
#include <msclr\marshal_cppstd.h>




namespace bootPage {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ play;
	protected:

	protected:

	private: System::Windows::Forms::CheckBox^ createGameBool;
	private: System::Windows::Forms::TextBox^ gamePin;
	protected:


	private: System::Windows::Forms::Label^ gamePinLabel;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::Label^ debugLabel;
	private: System::Windows::Forms::Label^ UserID;






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
			this->play = (gcnew System::Windows::Forms::Button());
			this->createGameBool = (gcnew System::Windows::Forms::CheckBox());
			this->gamePin = (gcnew System::Windows::Forms::TextBox());
			this->gamePinLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->debugLabel = (gcnew System::Windows::Forms::Label());
			this->UserID = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// play
			// 
			this->play->Location = System::Drawing::Point(40, 91);
			this->play->Name = L"play";
			this->play->Size = System::Drawing::Size(156, 35);
			this->play->TabIndex = 0;
			this->play->Text = L"Play";
			this->play->UseVisualStyleBackColor = true;
			this->play->Click += gcnew System::EventHandler(this, &MyForm::play_Click);
			// 
			// createGameBool
			// 
			this->createGameBool->AutoSize = true;
			this->createGameBool->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->createGameBool->Checked = true;
			this->createGameBool->CheckState = System::Windows::Forms::CheckState::Checked;
			this->createGameBool->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->createGameBool->Location = System::Drawing::Point(40, 16);
			this->createGameBool->Name = L"createGameBool";
			this->createGameBool->Size = System::Drawing::Size(88, 17);
			this->createGameBool->TabIndex = 1;
			this->createGameBool->Text = L"Create Game";
			this->createGameBool->UseVisualStyleBackColor = false;
			this->createGameBool->CheckedChanged += gcnew System::EventHandler(this, &MyForm::createGameBool_CheckedChanged);
			// 
			// gamePin
			// 
			this->gamePin->BackColor = System::Drawing::SystemColors::ControlDark;
			this->gamePin->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->gamePin->Location = System::Drawing::Point(96, 39);
			this->gamePin->MaxLength = 10;
			this->gamePin->Name = L"gamePin";
			this->gamePin->ReadOnly = true;
			this->gamePin->Size = System::Drawing::Size(100, 20);
			this->gamePin->TabIndex = 2;
			// 
			// gamePinLabel
			// 
			this->gamePinLabel->AutoSize = true;
			this->gamePinLabel->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->gamePinLabel->Location = System::Drawing::Point(37, 42);
			this->gamePinLabel->Name = L"gamePinLabel";
			this->gamePinLabel->Size = System::Drawing::Size(53, 13);
			this->gamePinLabel->TabIndex = 3;
			this->gamePinLabel->Text = L"Game Pin";
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->usernameLabel->Location = System::Drawing::Point(37, 68);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(55, 13);
			this->usernameLabel->TabIndex = 5;
			this->usernameLabel->Text = L"Username";
			// 
			// username
			// 
			this->username->BackColor = System::Drawing::SystemColors::ControlDark;
			this->username->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->username->Location = System::Drawing::Point(96, 65);
			this->username->MaxLength = 10;
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(100, 20);
			this->username->TabIndex = 4;
			// 
			// debugLabel
			// 
			this->debugLabel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->debugLabel->AutoSize = true;
			this->debugLabel->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->debugLabel->Location = System::Drawing::Point(93, 129);
			this->debugLabel->Name = L"debugLabel";
			this->debugLabel->Size = System::Drawing::Size(0, 13);
			this->debugLabel->TabIndex = 6;
			this->debugLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// UserID
			// 
			this->UserID->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->UserID->AutoSize = true;
			this->UserID->BackColor = System::Drawing::Color::Transparent;
			this->UserID->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->UserID->ForeColor = System::Drawing::Color::Transparent;
			this->UserID->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->UserID->Location = System::Drawing::Point(93, 129);
			this->UserID->Name = L"UserID";
			this->UserID->Size = System::Drawing::Size(40, 13);
			this->UserID->TabIndex = 7;
			this->UserID->Text = L"UserID";
			this->UserID->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(228, 163);
			this->Controls->Add(this->UserID);
			this->Controls->Add(this->debugLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->username);
			this->Controls->Add(this->gamePinLabel);
			this->Controls->Add(this->gamePin);
			this->Controls->Add(this->createGameBool);
			this->Controls->Add(this->play);
			this->Name = L"MyForm";
			this->Text = L"BattleShipDemo";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	System::String^ genPin(int length) {
		// generate a pin which will be used during initiation of game
		System::String^ pin = "";
		for (int i = 0; i < length; i++) {
			pin += (rand())% 10;
		}
		return pin;
	}


	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// on Loadup assume the player will initiate the game and generate the pin
		srand(time(NULL));
		gamePin->Text = genPin(4);
		srand(234922 * rand());
		UserID->Text = genPin(7);
	}

	private: System::Void createGameBool_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		// handle if the user will initiate the game or join an existing game
		if (createGameBool->Checked) {gamePin->Text = genPin(4);}
		else {gamePin->Text = "";}
		gamePin->ReadOnly = createGameBool->Checked;
	}

	private: System::Void play_Click(System::Object^ sender, System::EventArgs^ e) {
		//begin launching the game
		//insure all the proper information is filled in
		if (username->Text != "" && gamePin->Text != "") {
			// curl init
			CURL* curl;
			CURLcode res;

			curl = curl_easy_init();
			// check to see if the user wishes to initiate the game
			if (createGameBool->Checked) {

				System::String^ querytest = "http://localhost:8008/game?username=" + username->Text + "&gamePin=" + gamePin->Text + "&Hosted=" + createGameBool->Checked + "&userID=" +UserID->Text;

				curl_easy_setopt(curl, CURLOPT_URL, querytest);
				res = curl_easy_perform(curl);
				std::cout << res;
			}
			else {

			}
			
			curl_easy_cleanup(curl);
		} else {MessageBox::Show("Error, please fill out gamePin and Username"); }
	}

};
}
