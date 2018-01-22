/*
 * Introduction to Algorithms
 * Problem 1. BFS/DFS
 *
 * Print BFS, DFS for below adj list starting from s:
 *
 * adj(s) = [a,c,d],
 * adj(a) = [],
 * adj(c) = [e, b],
 * adj(b) = [d],
 * adj(d) = [c],
 * adj(e) = [s],
 *
 * DFS ==> s a c d e b  (if we visit elements based on ascending order of vetex value)
 * My Implementation DFS ==> s a c e b d
*/

#include <iostream>
#include "../stack/my_stack_fixed.hpp"

using namespace std;

typedef struct tagVertex * VERTEXTPtr;
typedef struct tagEdge * EDGEPtr;
typedef struct tagEdge
{
    VERTEXTPtr  m_pstToVertex;
    EDGEPtr     m_pstNextEdge;
} EDGE;

typedef struct tagVertex
{
    char        m_val;
    bool        m_bVisited;
    EDGEPtr     m_pstEdges;
    VERTEXTPtr  m_pstNext;
} VERTEXT;

VERTEXTPtr gpstHead = nullptr;

VERTEXTPtr GetVertext(char val)
{
    VERTEXTPtr  pstVertex = gpstHead;
    
    while(pstVertex != nullptr)
    {
        if(pstVertex->m_val == val)
        {
            break;
        }

        pstVertex = pstVertex->m_pstNext;
    }

    if(nullptr == pstVertex)
    {
        pstVertex = new VERTEXT;

        pstVertex->m_val = val;
        pstVertex->m_pstEdges = nullptr;
        pstVertex->m_bVisited = false;

        pstVertex->m_pstNext = gpstHead;
        gpstHead = pstVertex;
    }

    return pstVertex;
}

void AddEdge(char from, char to)
{
    EDGEPtr     pstEdge;
    VERTEXTPtr  pstFromVertex = GetVertext(from);
    VERTEXTPtr  pstToVerTex = GetVertext(to);

    pstEdge = new EDGE;

    pstEdge->m_pstToVertex = pstToVerTex;
    pstEdge->m_pstNextEdge = pstFromVertex->m_pstEdges;
    pstFromVertex->m_pstEdges = pstEdge;
}

int GetTotalNoOfVertices(void)
{
    int i32NoOfVertices = 0;
    VERTEXTPtr  pstVertex = gpstHead;
    
    while(nullptr != pstVertex)
    {
        i32NoOfVertices++;
        pstVertex = pstVertex->m_pstNext;
    }

    return i32NoOfVertices;
}

void PrintGraph(void)
{
    VERTEXTPtr  pstVertex = gpstHead;
    EDGEPtr     pstEdge;

    while(nullptr != pstVertex)
    {
        cout << "Vertext : " << pstVertex->m_val;

        pstEdge = pstVertex->m_pstEdges;
        while(nullptr != pstEdge)
        {
            cout << " --> " << pstEdge->m_pstToVertex->m_val;
            pstEdge = pstEdge->m_pstNextEdge;
        }
        cout << "\n";

        pstVertex = pstVertex->m_pstNext;
    }
}

void ClearVisistedFlags(void)
{
    VERTEXTPtr  pstVertex = gpstHead;
    
    while(nullptr != pstVertex)
    {
        pstVertex->m_bVisited = false;
        pstVertex = pstVertex->m_pstNext;
    }
}

void print_dfs(VERTEXTPtr pstRootNode)
{
    ClearVisistedFlags();
    cout << "DFS: ";
    
    if(nullptr == pstRootNode)
    {
        cout << "Graph is empty...\n";
        return;
    }
    int i32NoOfVertices = GetTotalNoOfVertices();

    if(0 == i32NoOfVertices)
    {
        cout << "Graph is empty...\n";
        return;
    }
    
    CMyStack<VERTEXTPtr> stk(GetTotalNoOfVertices());
    VERTEXTPtr  pstVertex;
    EDGEPtr     pstEdge;
    bool abVisited[i32NoOfVertices];

    for(int i = 0; i < i32NoOfVertices; i++)
    {
        abVisited[i] = false;
    }

    stk.Push(pstRootNode);
    while(stk.isEmpty() == false)
    {
        pstVertex = stk.Pop();

        // if we have visited, skip this vertex
        if(pstVertex->m_bVisited)
            continue;

        // Mark this node as visited
        pstVertex->m_bVisited = true;
        
        // Do the visiting process
        cout << pstVertex->m_val << " ";

        // Add all the edges of this vertex
        pstEdge = pstVertex->m_pstEdges;
        while(nullptr != pstEdge)
        {
            stk.Push(pstEdge->m_pstToVertex);
            pstEdge = pstEdge->m_pstNextEdge;
        }
    }

    cout << "\n";
}

void print_bfs(VERTEXTPtr pstRootNode)
{
    ClearVisistedFlags();
    cout << "BFS: ";

    if(nullptr == pstRootNode)
    {
        cout << "Graph is empty...\n";
        return;
    }

    int i32NoOfVertices = GetTotalNoOfVertices();
    if(0 == i32NoOfVertices)
    {
        cout << "Graph is empty...\n";
        return;
    }

    //


    cout << "\n";
}

int main()
{
    PrintGraph();
    
    AddEdge('s', 'a');
    AddEdge('s', 'c');
    AddEdge('s', 'd');

    AddEdge('c', 'e');
    AddEdge('c', 'b');

    AddEdge('b', 'd');

    AddEdge('d', 'c');

    AddEdge('e', 's');

    PrintGraph();

    print_dfs(GetVertext('s'));
    
    return 0;
}