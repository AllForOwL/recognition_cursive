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

// определяет наибольший общий префикс и возвржает его длину  
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
	if( k==0 ) return find(t->next,x,n); // поищем у сестры
	if( k==n ) return t;
	if( k==t->len ) return find(t->link,x+k,n-k); // поищем у старшей дочери
	
	return nullptr; 
}

void OperationFromWords::split(Node^ t, int k) // разбиение узла t по k-му символу ключа
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

Node^ OperationFromWords::insert(Node^ t, String^ x, int n) // вставка ключа x в дерево t
{
	if( !n ) n = x->Length-1;
	if( !t ) return gcnew Node(x,n);
	int k = prefix(x,n,t->key,t->len);
	if( k==0 ) t->next = insert(t->next,x,n);
	else if( k<n )
	{
		if( k<t->len ) // режем или нет?
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

void OperationFromWords::join(Node^ t) // слияние узлов t и t->link
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

Node^ OperationFromWords::remove(Node^ t, String^ x, int n) // удаление ключа x из дерева t
	{
		if( !n ) n = x->Length+1;
		if( !t ) return nullptr;
		int k = prefix(x,n,t->key,t->len);
		if( k==n ) // удаление листа
		{
			Node^ p = t->next;
			delete t;
			return p;
		}
		if( k==0 ) t->next = remove(t->next, x, n);
		else if( k==t->len ) 
		{
			t->link = remove(t->link, x+k, n-k);
			if( t->link && !t->link->next ) // у узла t имеется единственная дочь?
				join(t);
		}
		return t;
	}

void OperationFromWords::BuildFinaleMachine()
{
	
}

/*void OperationFromWords::addMinWord(String^ w) 
	{
		// найти максимальный префикс w и сохранить его состояния
		array<int>^ stateList = prefix(w); 
		// найти первое состояние с более одним входящим переходом
		int	confIdx = findConfluence(stateList);
		// клонировать его и все последующие состояния
		if(confIdx > -1) 
		{
			int idx = confIdx;
			while (idx < length(stateList)) 
			{
				int	prev = stateList[idx-1];
				int cloned = cloneState(stateList[idx]);
				stateList[idx] = cloned;
				// после клонирования самого состояния
				// нужно заменить переход с предыдущего на клонированное
				s[prev][w[idx-1]] = cloned;
				idx++;
				confIdx++;
			}
		}
		//добавить	суффикс
		addSuffix(w, stateList);
		// заменить состояния строки теми, что есть в реестре. 
		//Если их нет, то добавить в реестр
		replaceOrRegister(w, nodeList);
	 }
void replaceOrRegister(String^ w, array<int>^ stateList) 
{
	int	stateIdx = stateList->Length - 1;
	int	wordIdx = w->Length- 1;

	// обходим состояния строки с конца
	while (stateIdx > 0) 
	{
		int	state = stateList[stateIdx];
		// получить из реестра состояние, равное state
		int	regState = registerGet(state); 
		if (regState == state) 
		{ 
			// если в реестре state уже есть, то переходим к предыдущему
			continue;  
		} 
		else if	(regState == -1) 
		{
			// если состояния в реестре нет, то добавим его в реестр
			registerAdd(state);
		} 
		else
		{ 
			// основная часть, когда в реестре есть состояние, равное state
			int	in = w[wordIdx];
			// 	корректируем переход
			s[stateList[stateIdx - 1]][in] = regState; 
			// заменяем состояние в пути обхода
			stateList[stateIdx] = regState; 
			// удаляем замененное состояние и	з автомата
			removeState(state);  
		}
		
		wordIdx--;
		stateIdx--;
		}
	}

// вычислить префикс строки в автомате
// и вернуть последовательность (путь) состояний
array<int>^ prefix(String^ w)
{
    array<int>^ stateList;
    // сохраняем и начальное состояние в пути обхода префикса
    stateList[0] = 0;
    int current = 0;

	for(int i = 0; i < w->Length; i++) {
        int next = s[current][w[i]];

        // если перехода нет, то выход
        if(next == -1)
            break;

        stateList[i+1] = next;
    }
    
    return stateList;
}

// добавить суффикс к заданному состоянию 
// и добавить состояния префикса к stateList
int findConfluence(array<int>^ stateList) 
{
    // получить последнее состояние из пути обхода префикса
	int current = stateList[stateList->Length- 1];

	String^ w;
	for(int i = stateList->Length - 1; i < w->Length; i++) {
        // добавляем новое состояние в автомат
        int newState = addState();
        // добавить новый переход
        array <int>^ s[current][w[i]] = newState;
        current = newState;
        // сохраним состояние в пути обхода
        stateList[i + 1] = current;
    }

    // установка признака финальности для s[current]
    setFinal(current);
}

// добавить новую строку в trie
void add(String^ w) {
    // найти максимальный общий префикс
    int[] prefixStates = prefix(w);
    // добавить оставшийся суффикс в автомат
    addSuffix(w, prefixStates)
}
*/
void OperationFromWords::WriteCompressedTree()
{

}

void OperationFromWords::WriteFinaleMachine()
{

}