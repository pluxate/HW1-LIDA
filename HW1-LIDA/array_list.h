// Team ZTRG

#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>

template <typename T> class array_list {
  public:
    array_list() { std::cout << "array list created" << '\n'; }
    ~array_list() { std::cout << "array list destroyed" << '\n'; }

    size_t size() { return m_size; }
    size_t count() { return m_count; }
    T specificthinghere(size_t x) { return m_items[x]; }


    friend std::ostream& operator<<(std::ostream &out, array_list& arraylist) {
        size_t i = 0;
        for (; i < arraylist.count(); i++) {
            out << i << ":" << arraylist.specificthinghere(i) << " ";
        }
        for (; i < arraylist.size(); i++) {
            out << i << ":" << "nil" << " ";
        }
        out << "\n";
        return out;
    }

  private:
    T m_items[1];
    size_t m_size = 1;
    size_t m_count = 0;
};
