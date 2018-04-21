
#include <iostream>
#include "Header.h"

using namespace std;

#define ALPHABET_SIZE           26
#define INVALID_ALPHABET_INDEX  (ALPHABET_SIZE+1)
#define ALPHABET_TERMINATOR     INVALID_ALPHABET_INDEX

template <typename ALPHABET_TYPE, typename DATA_TYPE_PTR>
struct tagTTrieNode
{
	ALPHABET_TYPE           m_split_char;
	DATA_TYPE_PTR           m_Data;
	struct tagTTrieNode *   m_pLeft;
	struct tagTTrieNode *   m_pRight;
	struct tagTTrieNode *   m_pMiddle;

	tagTTrieNode()
	{
		m_pLeft = m_pRight = m_pMiddle = nullptr;
		m_Data = nullptr;
	}
};

template <typename ALPHABET_TYPE, typename DATA_TYPE_PTR>
class CTTrie
{
	typedef struct tagTTrieNode<ALPHABET_TYPE, DATA_TYPE_PTR> TTRIE_NODE;
	typedef struct tagTTrieNode<ALPHABET_TYPE, DATA_TYPE_PTR> * TTRIE_NODE_PTR;
	typedef void (*TrieVisitFunc) (DATA_TYPE_PTR pvData);

public:
	CTTrie(ALPHABET_TYPE alpbhabetTerminator)
	{
		m_AlpbhabetTerminator = alpbhabetTerminator;
		m_stRoot.m_split_char = alpbhabetTerminator;
        m_ui32NoOfNodesInTree = 0;
        m_ui32TreeDepth = 0;
	}
	~CTTrie()
	{
	    cout << "Total no. of nodes in Tree: " << m_ui32NoOfNodesInTree << endl;
	    cout << "Total memory consumd: " << (m_ui32NoOfNodesInTree * sizeof(TTRIE_NODE))<< endl;
	    cout << "Tree Depth : " << m_ui32TreeDepth << endl;
		DeleteTree();
	}

public:
	DATA_TYPE_PTR Insert(const ALPHABET_TYPE * pStr, DATA_TYPE_PTR pData)
	{
		//MESAURE_FUNC_EXECUTION_TIME;
		if ((nullptr == pStr) || (*pStr == m_AlpbhabetTerminator) || (nullptr == pData))
			return nullptr;

		TTRIE_NODE_PTR pRoot = &m_stRoot;
        unsigned int ui32Depth = 0;

		while (*pStr != m_AlpbhabetTerminator)
		{
			if (pRoot->m_split_char == *pStr)
			{
				pRoot = pRoot->m_pMiddle;
				pStr++;
			}
			else if (pRoot->m_split_char == m_AlpbhabetTerminator)
			{
				pRoot->m_pMiddle = new TTRIE_NODE;
				if (nullptr == pRoot->m_pMiddle)
					return nullptr;
				pRoot->m_split_char = *pStr;
				pRoot = pRoot->m_pMiddle;
				pRoot->m_split_char = m_AlpbhabetTerminator;
				pStr++;
                m_ui32NoOfNodesInTree++;
			}
			else if (*pStr < pRoot->m_split_char)
			{
				if (nullptr == pRoot->m_pLeft)
				{
					pRoot->m_pLeft = new TTRIE_NODE;
					if (nullptr == pRoot->m_pLeft)
						return nullptr;
					pRoot = pRoot->m_pLeft;
					pRoot->m_split_char = m_AlpbhabetTerminator;
                    m_ui32NoOfNodesInTree++;
				}
				else
					pRoot = pRoot->m_pLeft;
			}
			else
			{
				if (nullptr == pRoot->m_pRight)
				{
					pRoot->m_pRight = new TTRIE_NODE;
					if (nullptr == pRoot->m_pRight)
						return nullptr;
					pRoot = pRoot->m_pRight;
					pRoot->m_split_char = m_AlpbhabetTerminator;
                    m_ui32NoOfNodesInTree++;
				}
				else
					pRoot = pRoot->m_pRight;
			}
            ++ui32Depth;
		}

        if(ui32Depth > m_ui32TreeDepth)
            m_ui32TreeDepth = ui32Depth;

		pRoot->m_Data = pData;

		return pData;
	}

	DATA_TYPE_PTR Search(const ALPHABET_TYPE * pStr)
	{
		//MESAURE_FUNC_EXECUTION_TIME;
		if ((nullptr == pStr) || (*pStr == m_AlpbhabetTerminator))
			return nullptr;

		TTRIE_NODE_PTR pRoot = &m_stRoot;
		for (; pRoot;)
		{
			if (*pStr == m_AlpbhabetTerminator)
			{
				return pRoot->m_Data;
			}

			if (pRoot->m_split_char == m_AlpbhabetTerminator)
			{
				return pRoot->m_Data;    // We have found the data
			}
			else if (pRoot->m_split_char == *pStr)
			{
				pRoot = pRoot->m_pMiddle;
				pStr++;
			}
			else if (*pStr < pRoot->m_split_char)
			{
				pRoot = pRoot->m_pLeft;
			}
			else if (*pStr > pRoot->m_split_char)
			{
				pRoot = pRoot->m_pRight;
			}
			else    // *pStr == m_AlpbhabetTerminator
			{
				break;
			}
		}

		return nullptr;
	}

	void InOrderTraverse(TrieVisitFunc pfnVistiFunc)
	{
		MESAURE_FUNC_EXECUTION_TIME;
		cout << "{{{ In Order Start" << endl;
		DoInOrderTraverse(&m_stRoot, pfnVistiFunc);
		cout << "}} In Order End" << endl;
	}

	void PreOrderTraverse(TrieVisitFunc pfnVistiFunc)
	{
		MESAURE_FUNC_EXECUTION_TIME;
		cout << "{{{ Pre Order Start" << endl;
		DoPreOrderTraverse(&m_stRoot, pfnVistiFunc);
		cout << "{{{ Pre Order End" << endl;
	}

	void PostOrderTraverse(TrieVisitFunc pfnVistiFunc)
	{
		MESAURE_FUNC_EXECUTION_TIME;
		cout << "{{{ Post Order Start" << endl;
		DoPostOrderTraverse(&m_stRoot, pfnVistiFunc);
		cout << "{{{ Post Order End" << endl;
	}

private:
	void DoInOrderTraverse(TTRIE_NODE_PTR pstRoot, TrieVisitFunc & pvFunc)
	{
		if(nullptr == pstRoot)
			return;
		DoInOrderTraverse(pstRoot->m_pLeft, pvFunc);
		if (pstRoot->m_split_char == m_AlpbhabetTerminator)
			pvFunc(pstRoot->m_Data);
		DoInOrderTraverse(pstRoot->m_pMiddle, pvFunc);
		DoInOrderTraverse(pstRoot->m_pRight, pvFunc);
	}
	
	void DoPreOrderTraverse(TTRIE_NODE_PTR pstRoot, TrieVisitFunc & pvFunc)
	{
		if(nullptr == pstRoot)
			return;
		DoPreOrderTraverse(pstRoot->m_pMiddle, pvFunc);
		DoPreOrderTraverse(pstRoot->m_pLeft, pvFunc);
		DoPreOrderTraverse(pstRoot->m_pRight, pvFunc);
		if (pstRoot->m_split_char == m_AlpbhabetTerminator)
			pvFunc(pstRoot->m_Data);
	}
	
	void DoPostOrderTraverse(TTRIE_NODE_PTR pstRoot, TrieVisitFunc & pvFunc)
	{
		if(nullptr == pstRoot)
			return;
		DoPostOrderTraverse(pstRoot->m_pLeft, pvFunc);
		DoPostOrderTraverse(pstRoot->m_pRight, pvFunc);
		if (pstRoot->m_split_char == m_AlpbhabetTerminator)
			pvFunc(pstRoot->m_Data);
		DoPostOrderTraverse(pstRoot->m_pMiddle, pvFunc);
	}
private:
	void DeleteTree(void)
	{
		//MESAURE_FUNC_EXECUTION_TIME;
		if (nullptr != m_stRoot.m_pLeft)
			DeleteNode(m_stRoot.m_pLeft);
		if (nullptr != m_stRoot.m_pRight)
			DeleteNode(m_stRoot.m_pRight);
		if (nullptr != m_stRoot.m_pMiddle)
			DeleteNode(m_stRoot.m_pMiddle);
	}

	void DeleteNode(TTRIE_NODE_PTR pRoot)
	{
		if (nullptr != pRoot->m_pLeft)
			DeleteNode(pRoot->m_pLeft);
		if (nullptr != pRoot->m_pRight)
			DeleteNode(pRoot->m_pRight);
		if (nullptr != pRoot->m_pMiddle)
			DeleteNode(pRoot->m_pMiddle);

		delete pRoot;
	}

private:
	TTRIE_NODE      m_stRoot;
	ALPHABET_TYPE   m_AlpbhabetTerminator;
    unsigned int    m_ui32NoOfNodesInTree;
    unsigned int    m_ui32TreeDepth;
};

void PrintCharsAsInt(char * pui8List, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << (unsigned int)(pui8List[i]) << ' ';
	}
	cout << endl;
}

void DataPrintFunc(char * pvData)
{
	cout << pvData << endl;
}

int main(int argc, char * argv[])
{
	MESAURE_FUNC_EXECUTION_TIME;
    if(argc < 4)
    {
        cout << argv[0] << "<seed> <depth> <no.of.Entries>" << endl;
        return -1;
    }
    int seed = atoi(argv[1]);
    int depth = atoi(argv[2]);
    int entries = atoi(argv[3]);
    char   aui8Alphabets[ALPHABET_SIZE];
	char ** ppTestStrList;
    char   * pui8Tmp;
    int     i, j;
	CTTrie<char, char*>  ternary_trie(ALPHABET_TERMINATOR);

    srand(seed);

    // Generate Alphabet Set - should be unique
    for(i = 0; i < ALPHABET_SIZE; )
    {
		aui8Alphabets[i] = (rand() % ALPHABET_SIZE) + 'a';

        for(j = 0; j < i; j++)
        {
            if(aui8Alphabets[i] == aui8Alphabets[j])
            {
                break;
            }
        }

        if(i == j)
        {
            i++;
        }
    }

    //PrintCharsAsInt(aui8Alphabets, ALPHABET_SIZE);

    // Generate Sequences
    srand(seed);

	ppTestStrList = new char *[entries];

    for(i = 0; i < entries; i++)
    {
		ppTestStrList[i] = new char[depth + 1];
		ppTestStrList[i][depth] = ALPHABET_TERMINATOR;
        for(j = 0; j < depth; j++)
        {
			ppTestStrList[i][j] = aui8Alphabets[rand() % ALPHABET_SIZE];
        }
    }

	for (i = 0; i < entries; i++)
	{
		ternary_trie.Insert(ppTestStrList[i], ppTestStrList[i]);
	}

	ternary_trie.InOrderTraverse(DataPrintFunc);
	ternary_trie.PreOrderTraverse(DataPrintFunc);
	ternary_trie.PostOrderTraverse(DataPrintFunc);

	{
		MESAURE_FUNC_EXECUTION_TIME;
		for (i = 0; i < entries; i++)
		{
			pui8Tmp = ternary_trie.Search(ppTestStrList[i]);
			if (nullptr == pui8Tmp)
			{
				cout << "[" << i << "] " << ppTestStrList[i] << " not found !!!" << endl;
				PrintCharsAsInt(ppTestStrList[i], depth);
			}
		}
	}

	for (i = 0; i < entries; i++)
	{
		delete[] ppTestStrList[i];
	}
	delete[] ppTestStrList;

	return 0;
}
