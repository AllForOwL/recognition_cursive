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
	/// —водка дл€ formMain
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
		/// ќсвободить все используемые ресурсы.
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

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 47);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(139, 61);
			this->button1->TabIndex = 0;
			this->button1->Text = L"считать все слова";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &formMain::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 62);
			this->button2->TabIndex = 1;
			this->button2->Text = L"запись на основе сжатого префиксного дерева";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 182);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 59);
			this->button3->TabIndex = 2;
			this->button3->Text = L"запись на основе конечного автомата";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(362, 78);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 3;
			// 
			// formMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 314);
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

				 StreamWriter^ writeRecognition = gcnew StreamWriter("compressedTree.txt", false);

				 for (int i = 0; i < 5000; i++)
				 {
					 writeRecognition->WriteLine(m_OperationWord->m_arDictionary[i]);
				 }

				 writeRecognition->Close();

				 StreamWriter^ writeRecognition2 = gcnew StreamWriter("finaleMachine.txt", false);

				 for (int i = 5000; i < 10000; i++)
				 {
					 writeRecognition2->WriteLine(m_OperationWord->m_arDictionary[i]);
				 }

				 writeRecognition2->Close();

			 }
	private: System::Void formMain_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
