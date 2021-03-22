#include <iostream>
using namespace std;

template <class T>
class ring
{
    private:
        int m_size;
        int m_pos;
        T* m_values;
    
    public:
        class iterator;

    public:
        iterator begin()
        {
            return iterator(0, *this);
        }

        iterator end()
        {
            return iterator(m_size, *this);
        }

        ring(int size):m_size(size),m_pos(0),m_values(NULL)
        {
            m_values = new T [size];
        }

        int size()
        {
            return m_size;
        }

        void add(T value)
        {
            m_values[m_pos++] = value;

            if(m_pos == m_size)
            {
                m_pos=0;
            }
        }

        T &get (int pos)
        {
            return m_values[pos];
        }

        ~ring()
        {
            delete [] m_values;
        }

};

template <class T>
class ring<T>::iterator
{
    private:
        int m_pos;
        ring my_ring;
    public:
        iterator(int pos, ring &para_ring):m_pos(pos),my_ring(para_ring)
        {

        }

    iterator &operator++(int a)
    {
        m_pos++;

        return *this;

    }
        
    iterator &operator++()
    {
        m_pos++;

        return *this;

    }

    T &operator*()
    {
        return my_ring.get(m_pos);
    }

    bool operator!=(const iterator &other)const
    {
        return m_pos != other.m_pos;
    }  

};