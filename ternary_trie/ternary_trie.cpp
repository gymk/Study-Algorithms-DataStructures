

#include <iostream>

using namespace std;


#define ALPHABET_TERMINATOR     '\0'


template <typename ALPHABET_TYPE, typename DATA_TYPE_PTR>
struct tagTTrieNode
{
    ALPHABET_TYPE           m_split_char;
    DATA_TYPE_PTR           m_Data;
    struct tagTTrieNode *   m_pLeft;
    struct tagTTrieNode *   m_pRight;
    struct tagTTrieNode *   m_pMiddle;

    tagTTrieNode(ALPHABET_TYPE terminator)
    {
        m_split_char = terminator;
        m_pLeft = m_pRight = m_pMiddle = nullptr;
        m_Data = nullptr;
    }
};


template <typename ALPHABET_TYPE, typename DATA_TYPE_PTR>
class CTTrie
{
    typedef struct tagTTrieNode<ALPHABET_TYPE, DATA_TYPE_PTR> TTRIE_NODE;
    typedef struct tagTTrieNode<ALPHABET_TYPE, DATA_TYPE_PTR> * TTRIE_NODE_PTR;
public:
    CTTrie(ALPHABET_TYPE alpbhabetTerminator):m_stRoot(alpbhabetTerminator)
    {
        m_AlpbhabetTerminator = alpbhabetTerminator;
    }
    ~CTTrie()
    {
        DeleteTree();
    }

public:
    DATA_TYPE_PTR Insert(const ALPHABET_TYPE * pStr, DATA_TYPE_PTR pData)
    {
        if((nullptr == pStr) || (*pStr == m_AlpbhabetTerminator) || (nullptr == pData))
            return nullptr;

        TTRIE_NODE_PTR pRoot = &m_stRoot;

        while(pRoot && (*pStr != m_AlpbhabetTerminator))
        {
            if(pRoot->m_split_char == *pStr)
            {
                pRoot = pRoot->m_pMiddle;
                pStr++;
            }
            else if(pRoot->m_split_char == m_AlpbhabetTerminator)
            {
                pRoot->m_split_char = *pStr;

                pRoot->m_pMiddle = new TTRIE_NODE(m_AlpbhabetTerminator);
                pRoot = pRoot->m_pMiddle;
                pStr++;
            }
            else if(*pStr < pRoot->m_split_char)
            {
                if(nullptr == pRoot->m_pLeft)
                {
                    pRoot->m_pLeft = new TTRIE_NODE(m_AlpbhabetTerminator);
                }
                pRoot = pRoot->m_pLeft;
            }
            else
            {
                if(nullptr == pRoot->m_pRight)
                {
                    pRoot->m_pRight = new TTRIE_NODE(m_AlpbhabetTerminator);
                }
                pRoot = pRoot->m_pRight;
            }
        }

        if(pRoot)
        {
            pRoot->m_Data = pData;
            return pData;
        }

        return nullptr;
    }

    DATA_TYPE_PTR Search(const ALPHABET_TYPE * pStr)
    {
        if((nullptr == pStr) || (*pStr == m_AlpbhabetTerminator))
            return nullptr;

        TTRIE_NODE_PTR pRoot = &m_stRoot;
        for(;pRoot;)
        {
            if(*pStr == m_AlpbhabetTerminator)
            {
                return pRoot->m_Data;
            }

            if(pRoot->m_split_char == m_AlpbhabetTerminator)
            {
                return pRoot->m_Data;    // We have found the data
            }
            else if(pRoot->m_split_char == *pStr)
            {
                pRoot = pRoot->m_pMiddle;
                pStr++;
            }
            else if(*pStr < pRoot->m_split_char)
            {
                pRoot = pRoot->m_pLeft;
            }
            else if(*pStr > pRoot->m_split_char)
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

private:
    void DeleteTree(void)
    {
        if(nullptr != m_stRoot.m_pLeft)
            DeleteNode(m_stRoot.m_pLeft);
        if(nullptr != m_stRoot.m_pRight)
            DeleteNode(m_stRoot.m_pRight);
        if(nullptr != m_stRoot.m_pMiddle)
            DeleteNode(m_stRoot.m_pMiddle);
    }

    void DeleteNode(TTRIE_NODE_PTR pRoot)
    {
        if(nullptr != pRoot->m_pLeft)
            DeleteNode(pRoot->m_pLeft);
        if(nullptr != pRoot->m_pRight)
            DeleteNode(pRoot->m_pRight);
        if(nullptr != pRoot->m_pMiddle)
            DeleteNode(pRoot->m_pMiddle);
        delete pRoot;
    }

private:
    TTRIE_NODE      m_stRoot;
    ALPHABET_TYPE   m_AlpbhabetTerminator;
};

int main()
{
    CTTrie<char,char*>  ternary_trie('\0');
    const char * pStr;
    char * pOut;

    pStr = "Raja";    ternary_trie.Insert(pStr, (char*)pStr);
    pStr = "Rajan";    ternary_trie.Insert(pStr, (char*)pStr);
    pStr = "Rajesh";    ternary_trie.Insert(pStr, (char*)pStr);
    pStr = "Amesh";    ternary_trie.Insert(pStr, (char*)pStr);
    //pStr = "Ama";    ternary_trie.Insert(pStr, (char*)pStr);
    pStr = "Raja";    ternary_trie.Insert(pStr, (char*)"New_Raja");
    pStr = "elish";    ternary_trie.Insert(pStr, (char*)pStr);

    pStr = "Raja";
    pOut = ternary_trie.Search(pStr);
    if(pOut)
        cout << "Found " << pOut << endl;
    else
        cout << "Not Found " << pStr << endl;

    pStr = "Ama";
    pOut = ternary_trie.Search(pStr);
    if(pOut)
        cout << "Found " << pOut << endl;
    else
        cout << "Not Found " << pStr << endl;

    pStr = "Amesh";
    pOut = ternary_trie.Search(pStr);
    if(pOut)
        cout << "Found " << pOut << endl;
    else
        cout << "Not Found " << pStr << endl;

    pStr = "esh";
    pOut = ternary_trie.Search(pStr);
    if(pOut)
        cout << "Found " << pOut << endl;
    else
        cout << "Not Found " << pStr << endl;

    return 0;
}

