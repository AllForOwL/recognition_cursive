#include "RecognitionWord.h"


RecognitionWord::RecognitionWord(Bitmap^ imageForRead)
{
	f_bitmapForRead = gcnew Bitmap(imageForRead);

	m_iWidth = f_bitmapForRead->Width;
	m_iHeight = f_bitmapForRead->Height;

	myBitmap = gcnew Bitmap(m_iWidth, m_iHeight);

	m_arriImage = gcnew array<int, 2>(m_iWidth, m_iHeight);   
}

void RecognitionWord::ReadPixelsImage()
{
	Color f_ColorPixel;
	int red, green, blue = 0;

	for (int i = 0; i < m_iWidth; i++)
	{
		for (int j = 0; j < m_iHeight; j++)
		{
			f_ColorPixel = f_bitmapForRead->GetPixel(i, j);


			if (
				Convert::ToInt16(f_ColorPixel.B) < 20
			   )
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
	int countDeletePixels = 99;

	while (countDeletePixels != 0)
	{
		countDeletePixels = 0;
		for (int i = 1; i < m_iWidth-1; i++)
		{
			for (int j = 1; j < m_iHeight-1; j++)
			{
				if (DeleteCurrentPixels(i, j, 1))
				{
					this->m_arriImage[i,j] = 0;
					++countDeletePixels;
				}
			}
		}
		for (int i = 1; i < m_iWidth-1; i++)
		{
			for (int j = 1; j < m_iHeight-1; j++)
			{
				if (DeleteCurrentPixels(i, j, 2))
				{
					this->m_arriImage[i,j] = 0;
					++countDeletePixels;
				}
			}
		}
	}

	

    for (int x = 0; x < m_iWidth; x++)
    {
        for (int y = 0; y < m_iHeight; y++)
        {
			if (m_arriImage[x,y] == 0)
			{
				myBitmap->SetPixel(x, y, Color::White);
			}
			else 
			{
				myBitmap->SetPixel(x, y, Color::Black);
			}
           
        }
    }
}

bool RecognitionWord::DeleteCurrentPixels(int x, int y, int countIteration)
{
	int countTrue = 0;

	if (this->m_arriImage[x,y] == 1)
	{
		++countTrue;
	}
	if (SumSequences(x, y) >= 2 && SumSequences(x, y) <= 6)
	{
		++countTrue;
	}
	if (CountSequences(x, y) == 1)
	{
		++countTrue;
	}
	if (countIteration == 1)
	{
		if (this->m_arriImage[x-1,y] * this->m_arriImage[x,y+1] * this->m_arriImage[x+1,y] == 0)
		{
			++countTrue;
		}
		if (this->m_arriImage[x,y+1] * this->m_arriImage[x+1,y] * this->m_arriImage[x,y-1] == 0)
		{
			++countTrue;
		}
	}
	else if (countIteration == 2)
	{
		if (this->m_arriImage[x-1,y] * this->m_arriImage[x,y+1] * this->m_arriImage[x,y-1] == 0)
		{
			++countTrue;
		}
		if (this->m_arriImage[x-1,y+1] * this->m_arriImage[x+1,y] * this->m_arriImage[x,y-1] == 0)
		{
			++countTrue;
		}
	}

	if (countTrue == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int RecognitionWord::CountSequences(int x, int y)
{
	int f_count = 0;

	if (this->m_arriImage[x-1,y] == 0 && this->m_arriImage[x-1,y+1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x-1,y+1] == 0 && this->m_arriImage[x,y+1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x,y+1] == 0 && this->m_arriImage[x+1,y+1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x+1,y+1] == 0 && this->m_arriImage[x+1,y] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x+1,y] == 0 && this->m_arriImage[x+1,y-1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x+1,y-1] == 0 && this->m_arriImage[x,y-1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x,y-1] == 0 && this->m_arriImage[x-1,y-1] == 1)
	{
		++f_count;
	}
	if (this->m_arriImage[x-1,y-1] == 0 && this->m_arriImage[x-1,y] == 1)
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

