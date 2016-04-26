#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

using namespace std;

ref class RecognitionWord
{
private:
	array<int, 2>^ m_arriImage;
	int m_iWidth;
	int m_iHeight;

public:
	RecognitionWord		(int width, int height);
	void ReadPixelsImage(String^ pathToBitmap);
	void Skelet			();
	bool DeleteCurrentPixels (int x, int y);  
	int  CountSequences		 (int x, int y);
	int  SumSequences	     (int x, int y);
};

