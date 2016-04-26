#include "RecognitionWord.h"


RecognitionWord::RecognitionWord(int width, int height)
{
	m_iWidth = width;
	m_iHeight = height;

	m_arriImage = gcnew array<int, 2>(m_iWidth, m_iHeight);
}

void RecognitionWord::ReadPixelsImage(String^ pathToBitmap)
{
	Bitmap^ f_bitmapForRead = gcnew Bitmap(pathToBitmap);
	Color f_ColorPixel;
	int red, green, blue = 0;
	

	for (int i = 0; i < m_iWidth; i++)
	{
		for (int j = 0; j < m_iHeight; j++)
		{
			f_ColorPixel = f_bitmapForRead->GetPixel(i, j);

			if (f_ColorPixel == Color::Black)
			{
				this->m_arriImage[i,j] = 1;
			}
			else
			{
				this->m_arriImage[i,j] = 0;
			}
		}
	}
}

void RecognitionWord::Skelet()
{
	for (int i = 1; i < m_iWidth-1; i++)
	{
		for (int j = 1; j < m_iHeight-1; j++)
		{
			if (DeleteCurrentPixels(i, j))
			{
				this->m_arriImage[i,j] = 0;
			}
		}
	}
}

bool RecognitionWord::DeleteCurrentPixels(int x, int y)
{
	if (SumSequences(x, y) >= 2 && SumSequences(x, y) < 6)
	{
		return true;
	}
	else if (CountSequences(x, y) == 1)
	{
		return true;
	}
	else if (this->m_arriImage[x-1,y] * this->m_arriImage[x,y+1] * this->m_arriImage[x+1,y] == 0)
	{
		return true;
	}
	else if (this->m_arriImage[x,y+1] * this->m_arriImage[x+1,y] * this->m_arriImage[x,y-1] == 0)
	{
		return true;
	}
	else if (this->m_arriImage[x-1,y] * this->m_arriImage[x,y+1] * this->m_arriImage[x,y-1] == 0)
	{
		return true;
	}
	else if (this->m_arriImage[x-1,y+1] * this->m_arriImage[x+1,y] * this->m_arriImage[x,y-1] == 0)
	{
		return true;
	}
}

int RecognitionWord::CountSequences(int x, int y)
{
	int f_count = 0;

	if (this->m_arriImage[x-1,y] == 0 && this->m_arriImage[x-1,y+1] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x-1,y+1] == 0 && this->m_arriImage[x,y+1] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x,y+1] == 0 && this->m_arriImage[x+1,y+1] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x+1,y+1] == 0 && this->m_arriImage[x+1,y] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x+1,y] == 0 && this->m_arriImage[x+1,y-1] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x+1,y-1] == 0 && this->m_arriImage[x,y-1] == 1)
	{
		++f_count;
	}
	else if (this->m_arriImage[x,y-1] == 0 && this->m_arriImage[x-1,y-1] == 1)
	{
		++f_count;
	}

	return f_count;
}

int RecognitionWord::SumSequences(int x, int y)
{
	return this->m_arriImage[x-1,y]   + this->m_arriImage[x-1,y+1] + this->m_arriImage[x,y+1]   +
		   this->m_arriImage[x+1,y+1] + this->m_arriImage[x+1,y]   + this->m_arriImage[x+1,y-1] +
		   this->m_arriImage[x,y-1]   + this->m_arriImage[x-1,y-1]; 
}

