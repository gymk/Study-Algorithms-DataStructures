/* https://www.cse.cuhk.edu.hk/irwin.king/_media/teaching/csc2100b/tu4.pdf */

#include <stdio.h>
#include <stdlib.h>

typedef struct tagAVLNode NODE;
struct tagAVLNode
{
  int m_key;
  int m_data;
  int m_height;
  NODE * m_pstLeft;
  NODE * m_pstRight;
};

NODE * CreateNode(int key, int data)
{
  NODE * p = (NODE*) malloc(sizeof(*p));

  if(NULL != p)
  {
    p->m_key  = key;
    p->m_data = data;
    p->m_height = 1;
    p->m_pstLeft = NULL;
    p->m_pstRight = NULL;
  }

  return p;
}

void DeleteNode(NODE * pstRoot)
{
  if(NULL == pstRoot)
    return;

  DeleteNode(pstRoot->m_pstLeft);
  DeleteNode(pstRoot->m_pstRight);

  free(pstRoot);
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int GetHeight(NODE * pstNode)
{
  return (NULL == pstNode) ? 0 : pstNode->m_height;
}

void ReCalcHeight(NODE * pstNode)
{
  pstNode->m_height = 1 + max(GetHeight(pstNode->m_pstLeft), GetHeight(pstNode->m_pstRight));
}

NODE * RotateRight(NODE * pstParent)  // Also we can refer as pstPivot Node
{
  NODE * pstChild = pstParent->m_pstLeft; // Also we can refer as pstRotator Node

  pstParent->m_pstLeft = pstChild->m_pstRight;
  pstChild->m_pstRight = pstParent;

  ReCalcHeight(pstParent);
  ReCalcHeight(pstChild);

  return pstChild;  // Return current Root Node
}

NODE * RotateLeft(NODE * pstParent) // Also we can refer as pstPivot Node
{
  NODE * pstChild = pstParent->m_pstLeft; // Also we can refer as pstRotator Node

  pstParent->m_pstLeft = pstChild->m_pstLeft;
  pstChild->m_pstLeft = pstParent;

  ReCalcHeight(pstParent);
  ReCalcHeight(pstChild);

  return pstChild;  // Return current Root Node
}

NODE * BalancePivot(NODE * pstNode2BeBalanced)
{
  if(NULL == pstNode2BeBalanced)
    return pstNode2BeBalanced;

  if((GetHeight(pstNode2BeBalanced->m_pstLeft) - GetHeight(pstNode2BeBalanced->m_pstRight) == 2))  // Left-SubTree is taller
  {
    if(GetHeight(pstNode2BeBalanced->m_pstLeft->m_pstRight) > GetHeight(pstNode2BeBalanced->m_pstLeft->m_pstLeft))
      pstNode2BeBalanced->m_pstLeft = RotateLeft(pstNode2BeBalanced->m_pstLeft);
    return RotateRight(pstNode2BeBalanced);
  }
  else if((GetHeight(pstNode2BeBalanced->m_pstRight) - GetHeight(pstNode2BeBalanced->m_pstLeft)) == 2)  // Right-SubTree is taller
  {
    if(GetHeight(pstNode2BeBalanced->m_pstRight->m_pstLeft) > GetHeight(pstNode2BeBalanced->m_pstRight->m_pstRight))
      pstNode2BeBalanced->m_pstRight = RotateRight(pstNode2BeBalanced->m_pstRight);
    return RotateLeft(pstNode2BeBalanced);
  }

  return pstNode2BeBalanced;  // Node is already in balanced state, return same node as ROOT Node
}

NODE * InsertNode(NODE * pstRoot, int key, int data)
{
  if(NULL == pstRoot)
    return CreateNode(key, data);

  if(key < pstRoot->m_key)
    pstRoot->m_pstLeft = InsertNode(pstRoot->m_pstLeft, key, data);
  else if(key > pstRoot->m_key)
    pstRoot->m_pstRight = InsertNode(pstRoot->m_pstRight, key, data);
  else
    pstRoot->m_data = data;

  BalancePivot(pstRoot);

  return pstRoot;
}

NODE * SearchNode(NODE * pstRoot, int key)
{
  if(NULL == pstRoot)
    return pstRoot;

  if(key < pstRoot->m_key)
    return SearchNode(pstRoot->m_pstLeft, key);
  else if(key > pstRoot->m_key)
    return SearchNode(pstRoot->m_pstRight, key);
  else
    return pstRoot;
}

NODE * FindMin(NODE * pstRoot)
{
  while(pstRoot->m_pstLeft)
    pstRoot = pstRoot->m_pstLeft;
  return pstRoot;
}

NODE * FindMax(NODE * pstRoot)
{
  while(pstRoot->m_pstRight)
    pstRoot = pstRoot->m_pstRight;
  return pstRoot;
}

NODE * RemoveNode(NODE * pstRoot, int key)
{
  if(NULL == pstRoot)
    return pstRoot;

  if(key < pstRoot->m_key)
    pstRoot->m_pstLeft = RemoveNode(pstRoot->m_pstLeft, key);
  else if(key > pstRoot->m_key)
    pstRoot->m_pstRight = RemoveNode(pstRoot->m_pstRight, key);
  else  // We have found the NODE which need to be removed
  {
    NODE * pstLeft = pstRoot->m_pstLeft;
    NODE * pstRight = pstRoot->m_pstRight;

    if(
        (pstRoot->m_pstLeft == NULL)
        &&
        (pstRoot->m_pstRight == NULL)
        )
    {
      free(pstRoot);
      pstRoot = NULL;
      return pstRoot; // This is a LEAF node, no balancing at this place NOR height update
    }
    else if(pstRoot->m_pstLeft == NULL)
    {
      free(pstRoot);
      return pstRight;
    }
    else if(pstRoot->m_pstRight == NULL)
    {
      free(pstRoot);
      return pstLeft;
    }
    else  // Node has both Left and Right Children
    {
      NODE * pstNext;

      if(GetHeight(pstLeft) > GetHeight(pstRight))  // Left Sub-Tree depth is more, remove from that to reduce re-balancing
      {
        pstNext = FindMax(pstLeft);
        pstRoot->m_key = pstNext->m_key;
        pstRoot->m_data = pstNext->m_data;
        pstRoot->m_pstLeft = RemoveNode(pstLeft, pstNext->m_key);
      }
      else  // Eiether both tree depth are equal or Right Sub-Tree depth is more, remove from right sub-tree to reduce re-balancing
      {
        pstNext = FindMin(pstRight);
        pstRoot->m_key = pstNext->m_key;
        pstRoot->m_data = pstNext->m_data;
        pstRoot->m_pstRight = RemoveNode(pstRight, pstNext->m_key);
      }
    }
  }

  ReCalcHeight(pstRoot);
  return BalancePivot(pstRoot);
}

char IsBSTValid(NODE * pstRoot)
{
  if(NULL == pstRoot)
    return 1;

  char isValid = 1;

  if(NULL != pstRoot->m_pstLeft)
    isValid = isValid && (pstRoot->m_pstLeft->m_key < pstRoot->m_key);
  if(NULL != pstRoot->m_pstRight)
    isValid = isValid && (pstRoot->m_pstRight->m_key > pstRoot->m_key);

  return isValid && IsBSTValid(pstRoot->m_pstLeft) && IsBSTValid(pstRoot->m_pstRight);
}

int main(int argc, char * argv[])
{
  int a[] = {9, 5, 10, 1, 6, 11, 0, 2, -1};
  int len = sizeof(a) / sizeof(a[0]);
  NODE * pstRoot = NULL;

  for(int i = 0; i < len; i++)
  {
    pstRoot = InsertNode(pstRoot, a[i], a[i]);
    printf("After Insert[%d, %d], Valid - %d\n", i, a[i], IsBSTValid(pstRoot));
  }

  for(int i = 0; i < len; i++)
  {
    pstRoot = RemoveNode(pstRoot, a[i]);
    printf("After Delete[%d, %d], Valid - %d\n", i, a[i], IsBSTValid(pstRoot));
  }

  DeleteNode(pstRoot);
  return 0;
}
