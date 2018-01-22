#ifndef __MY_STACK_HPP__
    #define __MY_STACK_HPP__

template <typename T>
class CMyStack
{
    public:
        CMyStack(unsigned int ui32MaxNodes)
        {
            m_ui32MaxNodes = ui32MaxNodes;
            m_i32Top = 0;

            m_pstList = new T[ui32MaxNodes];
        }

        ~CMyStack()
        {
            if(nullptr != m_pstList)
            {
                delete [] m_pstList;
            }
        }

    public:
        bool isEmpty() { return (m_i32Top == 0); };
        bool isFull() { return (m_i32Top == (int)m_ui32MaxNodes); };

        void Push(T tNewItem)
        {
            if(isFull())
                return;

            m_pstList[m_i32Top++] = tNewItem;
        }

        T Pop(void)
        {
            T item = m_pstList[--m_i32Top];

            return item;
        }

    private:
        unsigned int    m_ui32MaxNodes;
        int             m_i32Top;
        T * m_pstList;
};

#endif /* !__MY_STACK_HPP__ */