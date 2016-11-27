//
// Created by Jonathan Gerber on 11/27/16.
//

#ifndef CATCH_EG_RINGBUFFER_HPP
#define CATCH_EG_RINGBUFFER_HPP

#include <cstddef>
#include <vector>
#include <exception>

template<typename T>
class RingBuffer {
    size_t m_size, m_front, m_back;
    std::vector<T> m_storage;
public:
    RingBuffer(size_t capacity, T default_value )
            : m_size{0},
              m_front{0},
              m_back{0},
              m_storage(capacity, default_value )
    {}

    size_t size() const {
        return m_size;
    }

    T& first()  { return m_storage[m_front];}

    T& last()  {
        if(m_back == 0)
            return m_storage[m_storage.size()-1];
        return m_storage[m_back-1];
    }

    void push_back(T const& val ) {
        if (m_back == m_storage.size())
            m_back = 0;

        m_storage[m_back++] = val;

        if(m_size < m_storage.size()) {
            m_size++;
        } else {
            // if we have pushed back and our storage size is full, we need to shift
            // the start by 1
            m_front = ++m_front % m_storage.size();
        }
    }

    void push_back(std::initializer_list<T> values ) {
        for (auto&& value : values) {
            push_back( value );
        }
    }

    T pop_front() {
        if(m_size == 0) {
            throw std::underflow_error("Attempt to pop_front on an empty buffer");
        }
        m_size--;
        auto cur = m_front;
        m_front = (m_front+1) % m_storage.size();
        return m_storage[cur];
    }
};

#endif //CATCH_EG_RINGBUFFER_HPP
