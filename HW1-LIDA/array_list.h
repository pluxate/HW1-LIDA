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

    size_t size() const { return this->m_size; }
    size_t count() const { return this->m_count; }
    T get(const size_t &x) const { return this->m_items[x]; }

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

    T *begin() const { return &this->m_items[0]; }
    T *end() const { return &this->m_items[this->m_count]; }

    array_list<T> intersection_unsorted(const array_list<T> &left,
                                        const array_list<T> &right) {
        // usedItems tracks right sided compares
        // Find a match between left and right
        //   If usedItems[j] == false
        //     Then add the match to the new array and set the value as being
        //     unusable

        array_list<T> newList;
        bool *usedItems = new bool[right.m_size]{false};
        for (size_t i = 0; i < left.m_size; i += 1) {
            for (size_t j = 0; j < right.m_size; j += 1) {
                if (left.m_items[i] == right.m_items[j] && !usedItems[j]) {
                    usedItems[j] = true;
                    newList.push_back(left.m_items[i]);
                    break;
                }
            }
        }
        return newList;
    }

    array_list<T> intersection_sorted(const array_list<T> &left,
                                      const array_list<T> &right) {
        //
        return left;
    }

    array_list<T> union_unsorted(const array_list<T> &left,
                                 const array_list<T> &right) {
        // get all uniques by:
        // for item in left.items:
        // 	if item not in "uniques" list:
        //		uniques.append(item)
        //
        // then do the same thing with right.items, using same "uniques" list
        // finally construct a new array_list object and return

        // max size is if all items in both lists are unique, so sizes combined
        array_list<T> uniques;

        for (size_t i = 0; i < left.count(); i += 1) {
            const T &leftItem = left.get(i);
            bool duplicateFound = false;

            // if left item is not in the uniques list, add it
            // must use duplicateFound outside of for loop because
            // list starts off with 0 items, and it is false by default
            for (size_t j = 0; j < uniques.count(); j += 1) {
                const T &newItem = uniques.get(j);
                if (leftItem == newItem) {
                    duplicateFound = true;
                    break;
                }
            }

            // finally add
            if (!duplicateFound) {
                uniques.push_back(leftItem);
            }
        }

        // same thing as left list but with right instead
        // compare against the somewhat-filled "unique" list instead of an empty
        // list though
        for (size_t i = 0; i < right.count(); i += 1) {
            const T &rightItem = right.get(i);
            bool duplicateFound = false;

            for (size_t j = 0; j < uniques.count(); j += 1) {
                const T &newItem = uniques.get(j);
                if (rightItem != newItem) {
                    continue;
                }

                duplicateFound = true;
                break;
            }

            if (!duplicateFound) {
                uniques.push_back(rightItem);
            }
        }

        return uniques;
    }

    array_list<T> union_sorted(const array_list<T> &left,
                               const array_list<T> &right) {
        //
        return left;
    }

    friend std::ostream &operator<<(std::ostream &out,
                                    const array_list &arraylist) {
        size_t i = 0;
        for (; i < arraylist.count(); i++) {
            out << i << ":" << arraylist.get(i) << " ";
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
