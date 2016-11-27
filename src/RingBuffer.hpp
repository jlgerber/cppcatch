//
// Created by Jonathan Gerber on 11/27/16.
//

#ifndef CATCH_EG_RINGBUFFER_HPP
#define CATCH_EG_RINGBUFFER_HPP

#include <cstddef>
#include <vector>

template<typename T>
class RingBuffer {
    size_t m_size, m_front, m_back;
    std::vector<T> m_storage;
public:
    RingBuffer(size_t capacity )
            : m_size{0},
              m_front{0},
              m_back{0},
              m_storage(capacity, 0 )
    {}

    size_t size() const {
        return m_size;
    }

    void push_back(T const& val ) {
        m_storage[m_back++] = val;
        m_size++;
    }

    T pop_front() {
        m_size--;
        return m_storage[m_front++];
    }
};

#endif //CATCH_EG_RINGBUFFER_HPP
