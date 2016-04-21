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
	/// Сводка для formMain
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 61);
			this->button1->TabIndex = 0;
			this->button1->Text = L"\r\nСчитать слова в сжатое префиксное дерево";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &formMain::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(157, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 62);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Запись в файл на основе сжатого префиксного дерева";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &formMain::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(302, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 59);
			this->button3->TabIndex = 2;
			this->button3->Text = L"запись на основе конечного автомата";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
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
			this->button4->Text = L"Искать";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(280, 80);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(108, 23);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Добавить";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(394, 80);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(108, 23);
			this->button6->TabIndex = 9;
			this->button6->Text = L"Удалить";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// formMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 314);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"formMain";
			this->Text = L"formMain";
			this->Load += gcnew System::EventHandler(this, &formMain::formMain_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 m_OperationWord->ReadDictionaryFromFile();
				
				 m_OperationWord->BuildCompressedTree();

				 Node^ findNode = gcnew Node("", 0);

				 for (int i(0); i < CNT_COUNT_WORD; i++)
				 {
					 findNode = m_OperationWord->find(m_OperationWord->m_nodeRootTree, m_OperationWord->m_arDictionary[i], m_OperationWord->m_arDictionary[i]->Length);
					 textBox1->Text =findNode->key;
				 }
			 }
	private: System::Void formMain_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
