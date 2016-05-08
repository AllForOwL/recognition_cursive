#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections;

using namespace std;

const int COUNT_LETTERS = 20;
const int COOUNT_PIXELS = 10;

ref struct SScopeWord
{
	int xBegin, xEnd, yBegin, yEnd;

	SScopeWord()
	{
		xBegin = 0;
		xEnd   = 0;
		yBegin = 0;
		yEnd   = 0;
	}
};

ref class RecognitionWord
{
public:
	Bitmap^ myBitmap;
	Bitmap^ f_bitmapForRead;
	array<int, 2>^ m_arriImage;
	array<int>^ m_listVectorsLetter;	// массив векторов дл€ каждой буквы
	array<SScopeWord^>^ m_arriLetter;       // массив координат дл€ каждой буквы
	SScopeWord m_stScopeWord;
	int m_iWidth;
	int m_iHeight;

public:
	RecognitionWord		(Bitmap^ imageForRead);
	// скелетизаци€
	void ReadPixelsImage();
	void Skelet			();
	bool DeleteCurrentPixels (int x, int y, int countIteration);  
	int  CountSequences		 (int x, int y);
	int  SumSequences	     (int x, int y);

				// ¬≈ “ќ–»«ј÷»я //
	
	// поиск границы слова
	void FindScopeWord();
	void FindScopeBeginWord();
	void FindScopeEndWord();

	// поиск границы букв слова
	void FindScopeLetters();
	SScopeWord^ FindScopeLetter(int beginNextLetter);

	ArrayList^ Fourier(const int** scopeLetter);

};

