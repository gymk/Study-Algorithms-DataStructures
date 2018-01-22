#ifndef __MY_QUEUE_SIZE_FIXED_HPP__
    #define __MY_QUEUE_SIZE_FIXED_HPP__

template <typename T>
class CMyQueue
{
    public:
        CMyQueue(unsigned int ui32MaxNodes)
        {
            m_ui32MaxNodes = ui32MaxNodes;
            m_pstList = new T[ui32MaxNodes];
            m_i32Head = m_i32Tail = 0;
            m_i32NoOfNodesInQueue = 0;
        }
        ~CMyQueue()
        {
            if(nullptr != m_pstList)
            {
                delete [] m_pstList;
            }
        }
    
    public:
        bool isEmpty(void) { return(m_i32NoOfNodesInQueue == 0); }
        bool isFull(void) { return(m_i32NoOfNodesInQueue == (int)m_ui32MaxNodes); }

        void Enqueue(T tNewItem)
        {
            if(isFull())
                return;    // TO DO : ReDesign : This should never happen, caller should ensure queue has enough free buckets
            m_pstList[m_i32Tail++] = tNewItem;
            m_i32Tail %= m_ui32MaxNodes;  // TO DO : Clarify : Is it ok to have mod over signed and unsigned?
            ++m_i32NoOfNodesInQueue;
        }

        T Dequeue(void)
        {
            T item;
            
            if(isEmpty())
                return item;    // TO DO : ReDesign : This should never happen, caller should ensure queue has items

            item = m_pstList[m_i32Head++];
            m_i32Head %= m_ui32MaxNodes;  // TO DO : Clarify : Is it ok to have mod over signed and unsigned?
            --m_i32NoOfNodesInQueue;

            return item;
        }
    
    private:
        unsigned int m_ui32MaxNodes;
        int m_i32Head;
        int m_i32Tail;
        int m_i32NoOfNodesInQueue;
        T * m_pstList;
};

#endif /* !__MY_QUEUE_SIZE_FIXED_HPP__ */