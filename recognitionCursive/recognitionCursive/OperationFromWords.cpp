#include "OperationFromWords.h"
#include "formMain.h"

OperationFromWords::OperationFromWords(void)
{
	m_arDictionary = gcnew array<String^>(CNT_COUNT_WORD);

	m_arLeaf = gcnew array<Node^>(CNT_COUNT_WORD);
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
	String^ word;

	//word = m_arDictionary[0];
	m_nodeRootTree = gcnew Node(m_arDictionary[0], m_arDictionary[0]->Length);

	Node^ node;

	int b = 1;

	for (int i = 1; i < CNT_COUNT_WORD; i++)
	{
		word = m_arDictionary[i];
		m_arLeaf[i] = this->insert(m_nodeRootTree, word, word->Length);
	}

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
	if( !n ) n = x->Length+1; 
	if( !t ) return nullptr;
	int k = prefix(x,n,t->key,t->len);
	if( k==0 ) return find(t->next,x,n); // ������ � ������
	if( k==n ) return t;
	if( k==t->len ) return find(t->link,x+k,n-k); // ������ � ������� ������
	
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

/*void OperationFromWords::addMinWord(String^ w) 
	{
		// ����� ������������ ������� w � ��������� ��� ���������
		array<int>^ stateList = prefix(w); 
		// ����� ������ ��������� � ����� ����� �������� ���������
		int	confIdx = findConfluence(stateList);
		// ����������� ��� � ��� ����������� ���������
		if(confIdx > -1) 
		{
			int idx = confIdx;
			while (idx < length(stateList)) 
			{
				int	prev = stateList[idx-1];
				int cloned = cloneState(stateList[idx]);
				stateList[idx] = cloned;
				// ����� ������������ ������ ���������
				// ����� �������� ������� � ����������� �� �������������
				s[prev][w[idx-1]] = cloned;
				idx++;
				confIdx++;
			}
		}
		//��������	�������
		addSuffix(w, stateList);
		// �������� ��������� ������ ����, ��� ���� � �������. 
		//���� �� ���, �� �������� � ������
		replaceOrRegister(w, nodeList);
	 }
void replaceOrRegister(String^ w, array<int>^ stateList) 
{
	int	stateIdx = stateList->Length - 1;
	int	wordIdx = w->Length- 1;

	// ������� ��������� ������ � �����
	while (stateIdx > 0) 
	{
		int	state = stateList[stateIdx];
		// �������� �� ������� ���������, ������ state
		int	regState = registerGet(state); 
		if (regState == state) 
		{ 
			// ���� � ������� state ��� ����, �� ��������� � �����������
			continue;  
		} 
		else if	(regState == -1) 
		{
			// ���� ��������� � ������� ���, �� ������� ��� � ������
			registerAdd(state);
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
			removeState(state);  
		}
		
		wordIdx--;
		stateIdx--;
		}
	}

// ��������� ������� ������ � ��������
// � ������� ������������������ (����) ���������
array<int>^ prefix(String^ w)
{
    array<int>^ stateList;
    // ��������� � ��������� ��������� � ���� ������ ��������
    stateList[0] = 0;
    int current = 0;

	for(int i = 0; i < w->Length; i++) {
        int next = s[current][w[i]];

        // ���� �������� ���, �� �����
        if(next == -1)
            break;

        stateList[i+1] = next;
    }
    
    return stateList;
}

// �������� ������� � ��������� ��������� 
// � �������� ��������� �������� � stateList
int findConfluence(array<int>^ stateList) 
{
    // �������� ��������� ��������� �� ���� ������ ��������
	int current = stateList[stateList->Length- 1];

	String^ w;
	for(int i = stateList->Length - 1; i < w->Length; i++) {
        // ��������� ����� ��������� � �������
        int newState = addState();
        // �������� ����� �������
        array <int>^ s[current][w[i]] = newState;
        current = newState;
        // �������� ��������� � ���� ������
        stateList[i + 1] = current;
    }

    // ��������� �������� ����������� ��� s[current]
    setFinal(current);
}

// �������� ����� ������ � trie
void add(String^ w) {
    // ����� ������������ ����� �������
    int[] prefixStates = prefix(w);
    // �������� ���������� ������� � �������
    addSuffix(w, prefixStates)
}
*/
void OperationFromWords::WriteCompressedTree()
{

}

void OperationFromWords::WriteFinaleMachine()
{

}