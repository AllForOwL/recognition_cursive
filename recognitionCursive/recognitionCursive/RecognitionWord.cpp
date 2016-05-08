#include "RecognitionWord.h"

RecognitionWord::RecognitionWord(Bitmap^ imageForRead)
{
	f_bitmapForRead = gcnew Bitmap(imageForRead);

	m_iWidth = f_bitmapForRead->Width;
	m_iHeight = f_bitmapForRead->Height;

	myBitmap = gcnew Bitmap(m_iWidth, m_iHeight);

	m_arriImage         = gcnew array<int, 2>(m_iWidth, m_iHeight);
	m_arriLetter        = gcnew array<SScopeWord^>(COUNT_LETTERS);
	m_listVectorsLetter = gcnew array<int>(COUNT_LETTERS); 

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

void RecognitionWord::FindScopeWord()
{
	this->FindScopeBeginWord();
	this->FindScopeEndWord();

	for (int x = this->m_stScopeWord.xBegin; x < this->m_stScopeWord.xEnd; x++)
	{
		myBitmap->SetPixel(x, this->m_stScopeWord.yBegin, Color::Red);
	}

	for (int x = this->m_stScopeWord.xBegin; x < this->m_stScopeWord.xEnd; x++)
	{
		myBitmap->SetPixel(x, this->m_stScopeWord.yEnd,   Color::Red);
	}

}

void RecognitionWord::FindScopeBeginWord()
{
	int f_iSumPrevRows, f_iSumCurrentRows = 0;

	for (int x = 0; x < m_iWidth; x++)	// find rows begin word
	{
		f_iSumCurrentRows = 0;
		for (int y = 0; y < m_iHeight; y++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentRows;
			}
		}
		
		if (f_iSumCurrentRows - f_iSumPrevRows > COOUNT_PIXELS)
		{
			this->m_stScopeWord.xBegin = x;
			break;
		}
	}

	int f_iSumPreCols, f_iSumCurrentCols = 0;

	for (int y = 0; y < m_iHeight; y++)	// find cols begin word
	{
		f_iSumCurrentCols = 0;
		for (int x = 0; x < m_iWidth; x++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentCols;
			}
		}
		
		if (f_iSumCurrentCols - f_iSumPreCols > COOUNT_PIXELS)
		{
			this->m_stScopeWord.yBegin = y;
			break;
		}
	}
}

void RecognitionWord::FindScopeEndWord()
{
	int f_iSumPrevRows, f_iSumCurrentRows = 0;

	for (int x = m_iWidth-1; x > 0; --x)	// find rows end word
	{
		f_iSumCurrentRows = 0;
		for (int y = m_iHeight-1; y > 0; --y)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentRows;
			}
		}
		
		if (f_iSumCurrentRows > COOUNT_PIXELS)
		{
			this->m_stScopeWord.xEnd = x;
			
			break;
		}

		f_iSumPrevRows = f_iSumCurrentRows;
	}

	int f_iSumPreCols, f_iSumCurrentCols = 0;

	for (int y = m_iHeight-1; y > 0; --y)	// find cols end word
	{
		f_iSumCurrentCols = 0;
		for (int x = m_iWidth-1; x > 0; --x)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentCols;
			}
		}
		
		if (f_iSumCurrentCols > COOUNT_PIXELS)
		{
			this->m_stScopeWord.yEnd = y;
			break;
		}

		f_iSumPreCols = f_iSumCurrentCols;
	}
}

void RecognitionWord::FindScopeLetters()
{
	array<SScopeWord^>^ f_arrstScopeLEtters = gcnew array<SScopeWord^>(COUNT_LETTERS*2);
	int counLetter = 0;

	/*f_arrstScopeLEtters[counLetter] = FindScopeLetter(this->m_stScopeWord.xBegin);

	for (int x = f_arrstScopeLEtters[counLetter]->xBegin; x < f_arrstScopeLEtters[counLetter]->xEnd; x++)
	{
		myBitmap->SetPixel(x, f_arrstScopeLEtters[counLetter]->yBegin, Color::Blue);
	}
	for (int x = f_arrstScopeLEtters[counLetter]->xBegin; x < f_arrstScopeLEtters[counLetter]->xEnd; x++)
	{
		myBitmap->SetPixel(x, f_arrstScopeLEtters[counLetter]->yEnd, Color::Blue);
	}
	
	*/
	/*do 
	{
		++counLetter;

		f_arrstScopeLEtters[counLetter] = FindScopeLetter(f_arrstScopeLEtters[counLetter-1]->xEnd+1);

	}
	while(counLetter < 10);
	*/

	int current_X = this->m_stScopeWord.xBegin;
	int current_Y_Top = this->m_stScopeWord.yBegin;
	int current_Y_Bottom = this->m_stScopeWord.yEnd;

	for (int j = 0; j < 10; j++)
	{
		current_X += 2;
		for (int i = 0; i < 60; i++)
		{
			this->myBitmap->SetPixel(++current_X, current_Y_Top, Color::Blue);
			this->myBitmap->SetPixel(++current_X, current_Y_Bottom, Color::Blue);
		}
	}
}

void RecognitionWord::SeparationLetters()
{
	FindScopeWord();
	
	array<int>^ f_arriCountBlackPixels = gcnew array<int>(this->m_stScopeWord.xEnd - this->m_stScopeWord.xBegin);
	int countColsBlackPixels = 0;

	for (int x = this->m_stScopeWord.xBegin; x < this->m_stScopeWord.xEnd; x++)
	{
		for (int y = this->m_stScopeWord.yBegin; y < this->m_stScopeWord.yEnd; y++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_arriCountBlackPixels[countColsBlackPixels];
			}
		}
		++countColsBlackPixels;
	}
}

SScopeWord^ RecognitionWord::FindScopeLetter(int beginNextLetter)
{
	int f_iSumPrevRows, f_iSumCurrentRows = 0;
	int f_iSumPreCols, f_iSumCurrentCols = 0;

	SScopeWord^ f_stScopeLetter = gcnew SScopeWord();

	for (int x = beginNextLetter; x < this->m_stScopeWord.xEnd; x++)	// find rows begin letter
	{
		f_iSumCurrentCols = 0;
		for (int y = this->m_stScopeWord.yBegin; y < this->m_stScopeWord.yEnd; y++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentCols;
			}
		}
		if (f_iSumCurrentCols >= COUNT_PIXELS_LETTER)
		{
			f_stScopeLetter->xBegin = x;
			break;
		}
	}

	int iter = 0;

	for (int x = f_stScopeLetter->xBegin; x < this->m_stScopeWord.xEnd; x++)	// find rows end letter
	{
		f_iSumCurrentCols = 0;
		for (int y = beginNextLetter; y < this->m_stScopeWord.yEnd; y++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentCols;
			}
		}
		
		if (f_iSumCurrentCols <= 1 && iter >= 40)
		{
			f_stScopeLetter->xEnd = x-1;
			break;
		}
		++iter;
	}

	for (int y = 0; y < this->m_stScopeWord.yEnd; y++)	// find cols begin letter
	{
		f_iSumCurrentRows = 0;
		for (int x = f_stScopeLetter->xBegin; x < f_stScopeLetter->xEnd; x++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentRows;
			}
		}
		
		if (f_iSumCurrentRows >= COUNT_PIXELS_LETTER)
		{
			f_stScopeLetter->yBegin = y;
			break;
		}

		f_iSumPrevRows = f_iSumCurrentRows;
	}

	for (int y = f_stScopeLetter->yBegin; y < this->m_iHeight; y++)	// find rows end letter
	{
		f_iSumCurrentRows = 0;
		for (int x = f_stScopeLetter->xBegin; x < f_stScopeLetter->xEnd; x++)
		{
			if (this->m_arriImage[x,y] == 1)
			{
				++f_iSumCurrentRows;
			}
		}
		
		if (f_iSumCurrentRows == 0)
		{
			f_stScopeLetter->yEnd = y-1;
			break;
		}

		f_iSumPrevRows = f_iSumCurrentRows;
	}

	return f_stScopeLetter;

}
ArrayList^ RecognitionWord::Fourier(const int** scopeLetter)
{
	return gcnew ArrayList;
}