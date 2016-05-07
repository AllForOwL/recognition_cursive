#include "OperationFromWords.h"
#include "formMain.h"

OperationFromWords::OperationFromWords(void)
{
	m_arDictionary = gcnew array<String^>(CNT_COUNT_WORD*2);

	String^ text = "���"; 
	m_arDictionary[0] = text;
	m_iCountWordTree = 0;
	m_iCountWordFinaly = 0;

	m_arLeaf = gcnew array<Node^>(CNT_COUNT_WORD);
	m_nodeRootTree = gcnew Node(text, text->Length);
}

void OperationFromWords::ReadDictionaryFromFile()
{
	String^ pathFile = Path::GetFullPath("allword.txt");

	StreamReader^ readAllWords = gcnew StreamReader(pathFile);
	
	String^ wordRecognition = "";
	int countWord = 0;

	while (!readAllWords->EndOfStream)
	{
		m_arDictionary[countWord] = readAllWords->ReadLine();
		++countWord;
	}

	readAllWords->Close();
}

void OperationFromWords::BuildCompressedTree()
{
	StreamReader^ ffileReadTree = gcnew StreamReader("tree.txt");

	Node^ node;

	while (!ffileReadTree->EndOfStream)
	{
		++m_iCountWordTree;
		m_arDictionary[m_iCountWordTree] = ffileReadTree->ReadLine();
		node = this->insert(m_nodeRootTree, m_arDictionary[m_iCountWordTree], m_arDictionary[m_iCountWordTree]->Length);
	}

	ffileReadTree->Close();
}

void OperationFromWords::BuildCompressedFinaly()
{
	StreamReader^ ffileReadTree = gcnew StreamReader("finaly.txt");

	Node^ node;

	while (!ffileReadTree->EndOfStream)
	{
		++m_iCountWordFinaly;
		m_arDictionary[m_iCountWordFinaly] = ffileReadTree->ReadLine();
		node = this->insert(m_nodeRootTree, m_arDictionary[m_iCountWordFinaly], m_arDictionary[m_iCountWordFinaly]->Length);
	}

	ffileReadTree->Close();
}

void OperationFromWords::OutputWordFromTree()
{
	Node^ node = gcnew Node("",0);
	for (int i(0); i < CNT_COUNT_WORD; i++)
	{
		node = this->find(this->m_nodeRootTree, m_arDictionary[i], m_arDictionary[i]->Length);
		
	}
}


// ���������� ���������� ����� ������� � ��������� ��� �����  
int OperationFromWords::prefix(String^ x, int n, String^ key, int m)
{
	int m_ = key->Length;

	for( int k=0; k<n; k++ )
		if( k==m_ || key == "" || x[k]!=key[k]) 
		{
			return k;
		}

	return n;
}

Node^ OperationFromWords::find(Node^ t, String^ x, int n)
{
	if( !n ) n = x->Length; 
	if( !t ) return nullptr;
	int k = prefix(x,n,t->key,t->len);
	if( k==0 ) return find(t->next,x,n); // ������ � ������
	if( k==n ) return t;
	String^ a;
	a = x->Substring(k, n-k);
	//t->key = t->key->Substring(k, t->key->Length-k);
	if( k==t->len ) return find(t->link,a,n-k); // ������ � ������� ������
	
	return nullptr; 
}

void OperationFromWords::split(Node^ t, int k) // ��������� ���� t �� k-�� ������� �����
{
	String^ a;
	a = t->key->Substring(0, k);
	t->key = t->key->Substring(k, t->key->Length-k);

	Node^ p = gcnew Node(t->key,t->len);
	p->link = t->link;
	t->link = p;	
	delete[] t->key;
	t->key = a;
	t->len = k;
}

Node^ OperationFromWords::insert(Node^ t, String^ x, int n) // ������� ����� x � ������ t
{
	if( !n ) n = x->Length-1;
	if( !t ) return gcnew Node(x,n);
	int k = prefix(x,n,t->key,t->len);
	if( k==0 ) t->next = insert(t->next,x,n);
	else if( k<n )
	{
		if( k<t->len ) // ����� ��� ���?
			split(t,k);
		x = x->Substring(k, x->Length-k);
		t->link = insert(t->link,x,x->Length);
	}
	return t;
}


int OperationFromWords::CountGeneralLetter(String^ key, String^ word)
{
	int  countGeneral = 0;
	bool input = true;

	for (int i = 0; i < word->Length; i++)
	{
		if (key[i] == word[i] && input)
		{
			++countGeneral;
		}
		else
		{
			input = false;
			break;
		}
	}

	return countGeneral;
}

void OperationFromWords::join(Node^ t) // ������� ����� t � t->link
{
	Node^ p = t->link;
	String^ a;// = new char[t->len+p->len];
	a = t->key->Substring(0, t->len);
	a += p->key->Substring(0, p->len);
	delete[] t->key;
	t->key = a;
	t->len += p->len;
	t->link = p->link;
	delete p;
}

Node^ OperationFromWords::remove(Node^ t, String^ x, int n) // �������� ����� x �� ������ t
	{
		if( !n ) n = x->Length+1;
		if( !t ) return nullptr;
		int k = prefix(x,n,t->key,t->len);
		if( k==n ) // �������� �����
		{
			Node^ p = t->next;
			delete t;
			return p;
		}
		if( k==0 ) t->next = remove(t->next, x, n);
		else if( k==t->len ) 
		{
			t->link = remove(t->link, x+k, n-k);
			if( t->link && !t->link->next ) // � ���� t ������� ������������ ����?
				join(t);
		}
		return t;
	}

void OperationFromWords::BuildFinaleMachine()
{
	
}

void OperationFromWords::addMinWord(String^ w) 
	{
		// ����� ������������ ������� w � ��������� ��� ���������
		array<int>^ stateList = prefix(w); 
		// ����� ������ ��������� � ����� ����� �������� ���������
		int	confIdx = findConfluence(stateList);
		// ����������� ��� � ��� ����������� ���������
		if(confIdx > -1) 
		{
			int idx = confIdx;
			while (idx < stateList->Length) 
			{
				int	prev = stateList[idx-1];
				int cloned = stateList[idx];
				stateList[idx] = cloned;
				// ����� ������������ ������ ���������
				// ����� �������� ������� � ����������� �� �������������
				idx++;
				confIdx++;
			}
		}
		//��������	�������
		// �������� ��������� ������ ����, ��� ���� � �������. 
		//���� �� ���, �� �������� � ������
	 }

void OperationFromWords::addSuffix(String^ w, array<int>^stateList) 
{
    // �������� ��������� ��������� �� ���� ������ ��������
	int current = stateList[stateList->Length - 1];
	 int s[20];
    for(int i = 0; i < 100; i++) {
        // ��������� ����� ��������� � �������
        int newState = i;
        // �������� ����� �������
        s[i] = newState;
        current = newState;
        // �������� ��������� � ���� ������
        stateList[i + 1] = current;
    }

    // ��������� �������� ����������� ��� s[current
}

void OperationFromWords::replaceOrRegister(String^ w, array<int>^ stateList) 
{
	int	stateIdx = stateList->Length - 1;
	int	wordIdx = w->Length- 1;
	int s[100][100];
	int regState = 10;

	// ������� ��������� ������ � �����
	while (stateIdx > 0) 
	{
		int	state = stateList[stateIdx];
		// �������� �� ������� ���������, ������ state
		if (regState == state) 
		{ 
			// ���� � ������� state ��� ����, �� ��������� � �����������
			continue;  
		} 
		else if	(regState == -1) 
		{
			// ���� ��������� � ������� ���, �� ������� ��� � ������
			state = stateIdx;
		} 
		else
		{ 
			// �������� �����, ����� � ������� ���� ���������, ������ state
			int	in = w[wordIdx];
			// 	������������ �������
			s[stateList[stateIdx - 1]][in] = regState; 
			// �������� ��������� � ���� ������
			stateList[stateIdx] = regState; 
			// ������� ���������� ��������� �	� ��������
		}
		
		wordIdx--;
		stateIdx--;
		}
	}

// ��������� ������� ������ � ��������
// � ������� ������������������ (����) ���������
array<int>^ OperationFromWords::prefix(String^ w)
{
    array<int>^ stateList;
    // ��������� � ��������� ��������� � ���� ������ ��������
    stateList[0] = 0;
    int current = 0;
	int next = 20;

	for(int i = 0; i < w->Length; i++) {
        // ���� �������� ���, �� �����
        if(next == -1)
            break;

        stateList[i+1] = next;
    }
    
    return stateList;
}

// �������� ������� � ��������� ��������� 
// � �������� ��������� �������� � stateList
int OperationFromWords::findConfluence(array<int>^ stateList) 
{
    // �������� ��������� ��������� �� ���� ������ ��������
	int current = stateList[stateList->Length- 1];

	String^ w;
	for(int i = stateList->Length - 1; i < w->Length; i++) {
        // ��������� ����� ��������� � �������
        int newState = i;
        // �������� ����� �������
        current = newState;
        // �������� ��������� � ���� ������
        stateList[i + 1] = current;
    }

	return current;

    // ��������� �������� ����������� ��� s[current]
}

void OperationFromWords::WriteCompressedTree()
{

}

void OperationFromWords::WriteFinaleMachine()
{

}