#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace System::IO;
using namespace System;

using namespace std;

const int CNT_COUNT_CHILD = 1000;
const int CNT_COUNT_WORD  = 10000;

public ref struct Node
{
	String^ key;
	int len;
	Node^ link;
	Node^ next;

	Node::Node(){}

	Node::Node(String^ x, int n) : len(n), link(nullptr), next(nullptr) 
	{ 
		key = x->Substring(0, x->Length);
	}
};

public ref class OperationFromWords
{
public:
	array <String^>^ m_arDictionary;
	Node^ m_nodeRootTree;
	array<Node^>^ m_arLeaf;

public:
	OperationFromWords();

	void ReadDictionaryFromFile();
	void BuildCompressedTree();
	void BuildFinaleMachine();
	void WriteCompressedTree();
	void WriteFinaleMachine();

	int CountGeneralLetter(String^ key, String^ word);
	int prefix(String^ x, int n, String^ key, int m); // ����� ����������� ������ �������� ����� x � key
	Node^ find(Node^ t, String^ x, int n); // ����� ����� x � ������ t
	void split(Node^ t, int k);
	Node^ insert(Node^ t, String^ x, int n);
	void join(Node^ t); // ������� ����� t � t->link
	Node^ remove(Node^ t, String^ x, int n); // �������� ����� x �� ������ t
	void OutputWordFromTree();
	//void RecoveryWord();

	void addMinWord(String^ w) ;
	void replaceOrRegister(String ^w, array<int>^ stateList) ;
	array<int>^ prefix(String^ w);
	int findConfluence(array<int>^ stateList);
	//void add(String^ w);
	void addSuffix(String^ w, array<int>^stateList);
};

