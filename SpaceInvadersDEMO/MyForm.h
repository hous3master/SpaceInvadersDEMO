#pragma once
#include "Game.h"
namespace SpaceInvadersDEMO {

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
			objGame = new Game();
			bmpAlien = gcnew Bitmap("alien.png");
			bmpSpaceship = gcnew Bitmap("spaceship.png");
			bmpBG = gcnew Bitmap("background.png");
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Game* objGame;
		Bitmap^ bmpAlien;
		Bitmap^ bmpSpaceship;
	private: System::Windows::Forms::Label^ label_points;
	private: System::Windows::Forms::Label^ label_lifes;
		   Bitmap^ bmpBG;
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_points = (gcnew System::Windows::Forms::Label());
			this->label_lifes = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label_points
			// 
			this->label_points->BackColor = System::Drawing::Color::Lime;
			this->label_points->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_points->Location = System::Drawing::Point(12, 9);
			this->label_points->Name = L"label_points";
			this->label_points->Size = System::Drawing::Size(132, 29);
			this->label_points->TabIndex = 0;
			this->label_points->Text = L"points = XXX";
			this->label_points->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label_points->Click += gcnew System::EventHandler(this, &MyForm::label_points_Click);
			// 
			// label_lifes
			// 
			this->label_lifes->BackColor = System::Drawing::Color::Lime;
			this->label_lifes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_lifes->Location = System::Drawing::Point(686, 9);
			this->label_lifes->Name = L"label_lifes";
			this->label_lifes->Size = System::Drawing::Size(84, 29);
			this->label_lifes->TabIndex = 1;
			this->label_lifes->Text = L"lifes = X";
			this->label_lifes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(782, 753);
			this->Controls->Add(this->label_lifes);
			this->Controls->Add(this->label_points);
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(800, 800);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//BACKGROUND
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = space->Allocate(g, ClientRectangle);
		bf->Graphics->DrawImage(bmpBG, 0, 0, bmpBG->Width, bmpBG->Height); //Custom BG

		//Execution
		objGame->Draw_arrEntity(bf->Graphics, bmpAlien);
		objGame->Draw_SpaceShip(bf->Graphics, bmpSpaceship);
		objGame->EnemyShooting();
		objGame->Colission();
		if (objGame->End_Game())
			timer1->Enabled = false;
		label_points->Text = "points = " + objGame->return_text_points();
		label_lifes->Text = "lifes = " + objGame->return_text_lifes();

		bf->Render(g);
		delete bf, space, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left) objGame->new_orientation(direction::left);
		if (e->KeyCode == Keys::Right) objGame->new_orientation(direction::right);
		if (e->KeyCode == Keys::Space) objGame->shoot();
	}
	private: System::Void label_points_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
