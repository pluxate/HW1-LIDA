// array_list.h
// Team ZTRG

#pragma once

#include <cstddef>
#include <iostream>

namespace dsa {
template <typename T> class array_list {
  public:
    array_list() { this->m_items = nullptr; }
    ~array_list() {}

    size_t size() { return this->m_size; }
    size_t count() { return this->m_count; }
    T pleasegetthisspecificthinghereatindexof(const size_t &x) {
        return this->m_items[x];
    }

    T push_back(const T &x) {

        // empty list
        if (this->m_items == nullptr) {
            this->m_items = new T[this->m_initialSize];
            this->m_items[0] = x;

            this->m_size = this->m_initialSize;
            this->m_count = this->m_initialSize;

            return x;
        }

        // expand
        if (this->m_count >= this->m_size) {
            const size_t newSize = this->m_size *= 2;
            T *newItems = new T[newSize];
            for (size_t i = 0; i < this->m_size; i += 1) {
                newItems[i] = this->m_items[i];
            }

            delete[] this->m_items;
            this->m_items = newItems;

            this->m_size = newSize;
            this->m_count += 1;

            this->m_items[this->m_count - 1] = x;
            return x;
        }

        // just input
        this->m_items[this->m_count] = x;
        this->m_count += 1;
        return x;
    }

    T *begin() { return &this->m_items[0]; }
    T *end() { return &this->m_items[this->m_count]; }

    array_list intersection_unsorted(array_list &left,
                                     const array_list &right) {
        //
        return left;
    }

    array_list intersection_sorted(array_list &left, const array_list &right) {
        //
        return left;
    }

    array_list unique_unsorted(array_list &left, const array_list &right) {
        //
        return left;
    }

    array_list unique_sorted(array_list &left, const array_list &right) {
        //
        return left;
    }

    friend std::ostream &operator<<(std::ostream &out, array_list &arraylist) {
        size_t i = 0;
        for (; i < arraylist.count(); i++) {
            out << i << ":"
                << arraylist.pleasegetthisspecificthinghereatindexof(i) << " ";
        }
        for (; i < arraylist.size(); i++) {
            out << i << ":" << "nil" << " ";
        }
        out << "\n";
        return out;
    }

  private:
    T *m_items = nullptr;
    size_t m_size = 0;
    size_t m_count = 0;
    size_t m_initialSize = 1;
};
} // namespace dsa
