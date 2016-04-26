#pragma once

#include "OperationFromWords.h"

namespace recognitionCursive {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� formMain
	/// </summary>
	public ref class formMain : public System::Windows::Forms::Form
	{
		public:
			OperationFromWords^ m_OperationWord;
	
		formMain(void)
		{
			InitializeComponent();
			
			m_OperationWord = gcnew OperationFromWords();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~formMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 


	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;


	private:
		/// <summary>
		/// ��������� ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ������������ ����� ��� ��������� ������������ - �� ���������
		/// ���������� ������� ������ ��� ������ ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 61);
			this->button1->TabIndex = 0;
			this->button1->Text = L"������� ����� � ������� ����������� ������\r\n";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &formMain::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->ImeMode = System::Windows::Forms::ImeMode::On;
			this->textBox1->Location = System::Drawing::Point(12, 80);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(139, 235);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(163, 104);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(108, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &formMain::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(280, 104);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(108, 20);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(394, 104);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(108, 20);
			this->textBox4->TabIndex = 6;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(163, 80);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"������";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &formMain::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(280, 80);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(108, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"��������";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &formMain::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(394, 80);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"�������";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &formMain::button6_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(554, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 69);
			this->button2->TabIndex = 10;
			this->button2->Text = L"������� ����� c ��������� ��������\r\n\r\n";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &formMain::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(699, 80);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &formMain::button3_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(780, 80);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 12;
			this->button7->Text = L"��������";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &formMain::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(861, 80);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 13;
			this->button8->Text = L"�������";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &formMain::button8_Click);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(699, 109);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(75, 20);
			this->textBox5->TabIndex = 14;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(780, 109);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(75, 20);
			this->textBox6->TabIndex = 15;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(861, 109);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(75, 20);
			this->textBox7->TabIndex = 16;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(554, 87);
			this->textBox8->Multiline = true;
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(128, 211);
			this->textBox8->TabIndex = 17;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(163, 12);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(108, 61);
			this->button9->TabIndex = 18;
			this->button9->Text = L"������ � ����";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &formMain::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(688, 12);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(86, 61);
			this->button10->TabIndex = 19;
			this->button10->Text = L"������ � ����";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &formMain::button10_Click);
			// 
			// formMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1077, 367);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"formMain";
			this->Text = L"formMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_OperationWord->BuildCompressedTree();
					
				 StreamReader^ readWordFromFile = gcnew StreamReader("tree.txt");

				 while (!readWordFromFile->EndOfStream)
				 {
					 textBox1->AppendText(readWordFromFile->ReadLine() + Environment::NewLine);
				 }

				 readWordFromFile->Close();
			 }
			 private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e)
					  {
						  StreamWriter^ writeWordTree = gcnew StreamWriter("compressedTree.txt", false);
			 
						  for (int i = 0; i < CNT_COUNT_WORD; i++)
							{
							 writeWordTree->WriteLine(m_OperationWord->m_arDictionary[i]);
							}

								 writeWordTree->Close();
							}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ searchWord = textBox2->Text;

			 Node^ searchNode = gcnew Node("",0);
			 searchNode = nullptr;

			 searchNode = m_OperationWord->find(m_OperationWord->m_nodeRootTree, searchWord, searchWord->Length);

			 if (searchNode != nullptr)
			 {
				 MessageBox::Show(searchWord);
			 }
			 else
			 {
				 MessageBox::Show("����� �� �������");
			 }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ addWord = textBox3->Text;

			 m_OperationWord->insert(m_OperationWord->m_nodeRootTree, addWord, addWord->Length);
			 //m_OperationWord->m_arDictionary[m_OperationWord->m_arDictionary->si] = addWord;
			 
			 textBox1->AppendText(addWord);
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ removeStr = textBox4->Text;

			 m_OperationWord->remove(m_OperationWord->m_nodeRootTree, removeStr, removeStr->Length);

			 int fiCountLines = textBox1->Lines->Length;

			 array<String^>^ farrWord = gcnew array<String^>(fiCountLines);

			 for (int i = 0; i < fiCountLines; i++)
			 {
				 farrWord[i] = textBox1->Lines[i]->ToString();
				 if (String::Compare(farrWord[i],removeStr))
				 {
					 farrWord[i] = " ";
					 textBox1->Lines[i] = farrWord[i];
					 break;
				 }
			 }

		 }

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 	 m_OperationWord->BuildCompressedTree();
					
				 StreamReader^ readWordFromFile = gcnew StreamReader("finaly.txt");

				 while (!readWordFromFile->EndOfStream)
				 {
					 textBox8->AppendText(readWordFromFile->ReadLine() + Environment::NewLine);
				 }

				 readWordFromFile->Close();
				 }
		 private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
				  {
					   String^ searchWord = textBox5->Text;

					 Node^ searchNode = gcnew Node("",0);
					 searchNode = nullptr;

					 searchNode = m_OperationWord->find(m_OperationWord->m_nodeRootTree, searchWord, searchWord->Length);

					 if (searchNode != nullptr)
					 {
						 MessageBox::Show(searchWord);
					 }
					 else
					 {
						 MessageBox::Show("����� �� �������");
					 }
				  }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ addWord = textBox6->Text;

			 m_OperationWord->insert(m_OperationWord->m_nodeRootTree, addWord, addWord->Length);
			 //m_OperationWord->m_arDictionary[m_OperationWord->m_arDictionary->si] = addWord;
			 
			 textBox8->AppendText(addWord);
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			  String^ removeStr = textBox7->Text;

			 m_OperationWord->remove(m_OperationWord->m_nodeRootTree, removeStr, removeStr->Length);

			 int fiCountLines = textBox1->Lines->Length;

			 array<String^>^ farrWord = gcnew array<String^>(fiCountLines);

			 for (int i = 0; i < fiCountLines; i++)
			 {
				 farrWord[i] = textBox8->Lines[i]->ToString();
				 if (String::Compare(farrWord[i],removeStr))
				 {
					 farrWord[i] = " ";
					 textBox1->Lines[i] = farrWord[i];
					 break;
				 }
			 }
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 StreamWriter^ write = gcnew StreamWriter("tree.txt", false);
			 
			 Node^	 findNode = gcnew Node("", 0);
			 int	 fiMaxCountLineTextBox = textBox1->Lines->Length;
			 String^ fstrTextBox;

			 for (int i = 0; i < fiMaxCountLineTextBox; i++)
			 {
				 if (textBox1->Lines[i] == "")
				 {
					 break;
				 }

				 fstrTextBox = Convert::ToString(textBox1->Lines[i]);
				 m_OperationWord->remove(m_OperationWord->m_nodeRootTree, fstrTextBox, fstrTextBox->Length);
				 write->WriteLine(fstrTextBox);
			}

			write->Close();
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 StreamWriter^ write = gcnew StreamWriter("finaly.txt", false);
			 
			 Node^	 findNode = gcnew Node("", 0);
			 int	 fiMaxCountLineTextBox = textBox8->Lines->Length;
			 String^ fstrTextBox;

			 for (int i = 0; i < fiMaxCountLineTextBox; i++)
			 {
				 if (textBox8->Lines[i] == "")
				 {
					 break;
				 }

				 fstrTextBox = Convert::ToString(textBox8->Lines[i]);
				 m_OperationWord->remove(m_OperationWord->m_nodeRootTree, fstrTextBox, fstrTextBox->Length);
				 write->WriteLine(fstrTextBox);
			 }
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
