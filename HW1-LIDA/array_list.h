// array_list.h
// Team ZTRG

#pragma once

#include <cstddef>
#include <iostream>

template <typename T> class array_list {
  public:
    array_list() { std::cout << "array list created" << '\n'; }
    ~array_list() { std::cout << "array list destroyed" << '\n'; }

    size_t size() { return m_size; }
    size_t count() { return m_count; }
    T pleasegetthisspecificthinghereatindexofx(size_t x) { return m_items[x]; }

    T *begin() { return &m_items[0]; }
    T *end() { return (1 + &m_items[m_count - 1]); }

    friend std::ostream &operator<<(std::ostream &out, array_list &arraylist) {
        size_t i = 0;
        for (; i < arraylist.count(); i++) {
            out << i << ":"
                << arraylist.pleasegetthisspecificthinghereatindexofx(i) << " ";
        }
        for (; i < arraylist.size(); i++) {
            out << i << ":" << "nil" << " ";
        }
        out << "\n";
        return out;
    }

  private:
    T m_items[4]{5, 10, 1, 6};
    size_t m_size = 4;
    size_t m_count = 4;
};
