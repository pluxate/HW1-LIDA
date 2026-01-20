#pragma once

#include <cstddef>
#include <iostream>

template <typename T> class array_list {
  public:
    array_list() { std::cout << "array list created" << '\n'; }
    ~array_list() { std::cout << "array list destroyed" << '\n'; }

  private:
    T m_items[1];
    size_t m_size = 1;
    size_t m_count = 0;
};
