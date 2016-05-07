#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

using namespace std;

ref class RecognitionWord
{
private:
	Bitmap^ f_bitmapForRead;
	array<int, 2>^ m_arriImage;
	int m_iWidth;
	int m_iHeight;

public:
	RecognitionWord		(Bitmap^ imageForRead);
	void ReadPixelsImage();
	void Skelet			();
	bool DeleteCurrentPixels (int x, int y, int countIteration);  
	int  CountSequences		 (int x, int y);
	int  SumSequences	     (int x, int y);
};

