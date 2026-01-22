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
    T get(const size_t &x) { return this->m_items[x]; }

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

            this->m_items[this->m_count] = x;
            this->m_count += 1;
            return x;
        }

        // just input
        this->m_items[this->m_count] = x;
        this->m_count += 1;
        return x;
    }

    T *begin() { return &this->m_items[0]; }
    T *end() { return &this->m_items[this->m_count]; }

    array_list<T> intersection_unsorted(const array_list<T> &left,
                                        const array_list<T> &right) {
        //
        for (size_t i = 0; i < left.size(); i += 1) {
            for (size_t j = 0; j < right.size(); j += 1) {
                if (left.get(i) == right.get(j)) {
                }
            }
        }
        return left;
    }

    array_list<T> intersection_sorted(const array_list<T> &left,
                                      const array_list<T> &right) {
        //
        return left;
    }

    array_list<T> union_unsorted(const array_list<T> &left,
                                 const array_list<T> &right) {
        const size_t maxSize = (left.m_size + right.m_size);
        T *newItems = new T[maxSize];
        size_t newItemsCount = 0;

        for (size_t i = 0; i < left.m_count; i += 1) {
            const T &leftItem = left.m_items[i];
            bool duplicateFound = false;

            for (size_t j = 0; j < newItemsCount; j += 1) {
                const T &newItem = newItems[j];
                if (leftItem == newItem) {
                    duplicateFound = true;
                    break;
                }
            }

            if (!duplicateFound) {
                newItems[newItemsCount] = leftItem;
                newItemsCount += 1;
            }
        }

        for (size_t i = 0; i < right.m_count; i += 1) {
            const T &rightItem = right.m_items[i];
            bool duplicateFound = false;

            for (size_t j = 0; j < newItemsCount; j += 1) {
                const T &newItem = newItems[j];
                if (rightItem == newItem) {
                    duplicateFound = true;
                    break;
                }
            }

            if (!duplicateFound) {
                newItems[newItemsCount] = rightItem;
                newItemsCount += 1;
            }
        }

        array_list<T> newList;
        for (size_t i = 0; i < newItemsCount; i += 1) {
            auto item = newItems[i];
            newList.push_back(item);
        }

        return newList;
    }

    array_list<T> union_sorted(const array_list<T> &left,
                               const array_list<T> &right) {
        //
        return left;
    }

    friend std::ostream &operator<<(std::ostream &out,
                                    const array_list &arraylist) {
        size_t i = 0;
        for (; i < arraylist.m_count; i++) {
            out << i << ":" << arraylist.m_items[i] << " ";
        }
        for (; i < arraylist.m_size; i++) {
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
