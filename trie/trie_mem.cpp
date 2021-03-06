/*
* time ./a.out
*
* ALPHABET SET: 5 65 90 205 61 46 154 43 62 141 145 162 112 102 60 96 176 70 129 240 211 142 91 174 2 180 93 45 139 28 88 201
* Total no. of nodes in Trie: 0
* Total memory consumption: 0
*
*
* ALPHABET SET: 5 65 90 205 61 46 154 43 62 141 145 162 112 102 60 96 176 70 129 240 211 142 91 174 2 180 93 45 139 28 88 201
* Total no. of nodes in Trie: 595833
* Total memory consumption: 152533248
*
*
* real    0m0.257s
* user    0m0.221s
* sys     0m0.036s
*
*/

#include <iostream>
#include "Header.h"
#include <stdlib.h>

using namespace std;

#define ALPHABET_SIZE               254
#define INVALID_ALPHABET_INDEX      (ALPHABET_SIZE + 1)


typedef struct tagTrieNode * TRIE_NODE_PTR;
typedef struct tagTrieNode
{
	TRIE_NODE_PTR   m_pastNodeLinks[ALPHABET_SIZE];
} TRIE_NODE;

class CTrie
{
public:
public:
	CTrie()
	{
		ClearNode(&m_stRootNode);
		m_ui32TotalMemSize = 0;
		m_ui32TotalNodes = 0;
	}
	~CTrie()
	{
		DeleteNode(&m_stRootNode);
	}

public:
	void ClearNode(TRIE_NODE_PTR pstRootNode)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			pstRootNode->m_pastNodeLinks[i] = nullptr;
		}
	}
	void SetAlphbetInfo(unsigned char aui8Alphabets[ALPHABET_SIZE])
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			m_aui8Alphabets[i] = aui8Alphabets[i];
		}
	}
	int GetAlphabetIndex(unsigned char ui8Alphabet)
	{
		int index = INVALID_ALPHABET_INDEX;
		int i;

		for (i = 0; i < ALPHABET_SIZE; i++)
		{
			if (ui8Alphabet == m_aui8Alphabets[i])
				break;
		}

		if (i < ALPHABET_SIZE)
			index = i;

		return index;
	}
	TRIE_NODE_PTR AddNode(unsigned char ui8Alphabet)
	{
		return AddNode(&m_stRootNode, ui8Alphabet);
	}
	TRIE_NODE_PTR  AddNode(TRIE_NODE_PTR pstRootNode, unsigned char ui8Alphabet)
	{
		TRIE_NODE_PTR   pstNode = nullptr;
		int index = GetAlphabetIndex(ui8Alphabet);

		if (INVALID_ALPHABET_INDEX == index)
		{
			return pstNode;
		}

		if (nullptr == pstRootNode->m_pastNodeLinks[index])
		{
			pstNode = new TRIE_NODE;
			if (nullptr != pstNode)
			{
				ClearNode(pstNode);
				m_ui32TotalMemSize += sizeof(TRIE_NODE);
				m_ui32TotalNodes++;
			}
			pstRootNode->m_pastNodeLinks[index] = pstNode;
		}

		return pstRootNode->m_pastNodeLinks[index];
	}

	void DeleteNode(TRIE_NODE_PTR pstRootNode)
	{
		if (nullptr != pstRootNode)
		{
			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				if (nullptr != pstRootNode->m_pastNodeLinks[i])
				{
					DeleteNode(pstRootNode->m_pastNodeLinks[i]);
					delete pstRootNode->m_pastNodeLinks[i];
					pstRootNode->m_pastNodeLinks[i] = nullptr;
				}
			}
		}
	}

	void PrintStat(void)
	{
		//cout << endl << "ALPHABET SET: ";
		//for (int i = 0; i < ALPHABET_SIZE; i++)
		//{
		//	cout << (unsigned int)(m_aui8Alphabets[i]) << ' ';
		//}
		//cout << endl;
		cout << "Total no. of nodes in Trie: " << m_ui32TotalNodes << endl;
		cout << "Total memory consumption: " << m_ui32TotalMemSize << endl;
		cout << endl;
	}
private:
	TRIE_NODE       m_stRootNode;
	unsigned char   m_aui8Alphabets[ALPHABET_SIZE];
	unsigned int    m_ui32TotalMemSize;
	unsigned int    m_ui32TotalNodes;
};

void PrintCharsAsInt(unsigned char * pui8List, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << (unsigned int)(pui8List[i]) << ' ';
	}
	cout << endl;
}

int main(int argc, char * argv[])
{
	MESAURE_FUNC_EXECUTION_TIME;
	if (argc < 4)
	{
		cout << argv[0] << "<seed> <depth> <no.of.Entries>" << endl;
		return -1;
	}
	int seed = atoi(argv[1]);
	int depth = atoi(argv[2]);
	int entries = atoi(argv[3]);
	unsigned char   aui8Alphabets[ALPHABET_SIZE];
	unsigned char ** ppTestStrList;
	int     i, j;
	CTrie   trie;
	TRIE_NODE_PTR   pstNode;

	srand(seed);

	// Generate Alphabet Set - should be unique
	for (i = 0; i < ALPHABET_SIZE;)
	{
		aui8Alphabets[i] = rand() % 256;

		for (j = 0; j < i; j++)
		{
			if (aui8Alphabets[i] == aui8Alphabets[j])
			{
				break;
			}
		}

		if (i == j)
		{
			i++;
		}
	}

	trie.SetAlphbetInfo(aui8Alphabets);
	//trie.PrintStat();

	// Generate Sequences
	srand(seed);
	ppTestStrList = new unsigned char *[entries];

	for (i = 0; i < entries; i++)
	{
		ppTestStrList[i] = new unsigned char[depth];
		for (j = 0; j < depth; j++)
		{
			ppTestStrList[i][j] = aui8Alphabets[rand() % ALPHABET_SIZE];
		}
	}

	for (i = 0; i < entries; i++)
	{
		pstNode = trie.AddNode(ppTestStrList[i][0]);
		if (nullptr == pstNode)
		{
			cout << i << " Malloc Error 1\n";
			exit(-1);
		}
		for (j = 1; j < depth; j++)
		{
			pstNode = trie.AddNode(pstNode, ppTestStrList[i][j]);
			if (nullptr == pstNode)
			{
				cout << i << ' ' << j << " Malloc Error 2\n";
				exit(-1);
			}
		}
	}

	trie.PrintStat();

	for (i = 0; i < entries; i++)
	{
		delete[] ppTestStrList[i];
	}
	delete[] ppTestStrList;

	return 0;
}
