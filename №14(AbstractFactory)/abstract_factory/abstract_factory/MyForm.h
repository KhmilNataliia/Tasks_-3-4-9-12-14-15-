#pragma once

#include"abstract_factory.h"

namespace abstract_factory {

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
	private: System::Windows::Forms::CheckBox^  eng;
	private: System::Windows::Forms::CheckBox^  ukr;
	private: System::Windows::Forms::CheckBox^  itl;
	protected:

	protected:


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

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
			this->eng = (gcnew System::Windows::Forms::CheckBox());
			this->ukr = (gcnew System::Windows::Forms::CheckBox());
			this->itl = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// eng
			// 
			this->eng->AutoSize = true;
			this->eng->Location = System::Drawing::Point(647, 151);
			this->eng->Name = L"eng";
			this->eng->Size = System::Drawing::Size(75, 21);
			this->eng->TabIndex = 0;
			this->eng->Text = L"english";
			this->eng->UseVisualStyleBackColor = true;
			// 
			// ukr
			// 
			this->ukr->AutoSize = true;
			this->ukr->Location = System::Drawing::Point(647, 215);
			this->ukr->Name = L"ukr";
			this->ukr->Size = System::Drawing::Size(85, 21);
			this->ukr->TabIndex = 1;
			this->ukr->Text = L"ukranian";
			this->ukr->UseVisualStyleBackColor = true;
			// 
			// itl
			// 
			this->itl->AutoSize = true;
			this->itl->Location = System::Drawing::Point(647, 273);
			this->itl->Name = L"itl";
			this->itl->Size = System::Drawing::Size(67, 21);
			this->itl->TabIndex = 2;
			this->itl->Text = L"italian";
			this->itl->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(647, 339);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 44);
			this->button1->TabIndex = 3;
			this->button1->Text = L"show";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(41, 54);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 4;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(178, 52);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(106, 24);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->Text = L"english";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(311, 44);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 32);
			this->button2->TabIndex = 6;
			this->button2->Text = L"add film";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(1, 151);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(620, 414);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 594);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->itl);
			this->Controls->Add(this->ukr);
			this->Controls->Add(this->eng);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		film_store* store;
		english_factory* engf;
		ukr_factory* ukrf;
		italian_factory* itlf;
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		comboBox1->Items->Add("english");
		comboBox1->Items->Add("ukranian");
	    comboBox1->Items->Add("italian");
		comboBox1->SelectedIndex = 0;
		store = new film_store();
		engf = new english_factory();
		ukrf = new ukr_factory();
		itlf = new italian_factory();
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	string st = "";
	String^ str = textBox1->Text;
	if (str != "" && str != " ")
	{
		for (int i = 0; i < str->Length; i++) st += str[i];
		int l = comboBox1->SelectedIndex;
		switch (l)
		{
		case 0: { store->add_film(st, engf); break; }
		case 1: { store->add_film(st, ukrf); break; }
		case 2: { store->add_film(st, itlf); break; }
		}
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	richTextBox1->Clear();
	vector<film*> films;
	String^ pr = "";
	if (eng->Checked)
	{
		films = store->show_films_by_cryteria(ENG);
		for (int i = 0; i < films.size(); i++)
		{
			String^ temp = gcnew String(films[i]->get_description().c_str());
			pr += temp + "\n";
			pr += ", ";
		}
	}
	films.clear();
	if (ukr->Checked)
	{
		films = store->show_films_by_cryteria(UKR);
		for (int i = 0; i < films.size(); i++)
		{
			String^ temp = gcnew String(films[i]->get_description().c_str());
			pr += temp + "\n";
			pr += ", ";
		}
	}
	films.clear();
	if (itl->Checked)
	{
		films = store->show_films_by_cryteria(ITL);
		for (int i = 0; i < films.size(); i++)
		{
			String^ temp = gcnew String(films[i]->get_description().c_str());
			pr += temp + "\n";
			pr += ", ";
		}
	}
	richTextBox1->Text = pr;
}
};
}
