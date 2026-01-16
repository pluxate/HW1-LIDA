// HW1-LIDA.cpp
// Grant Davis, Zach Allen, Thomas Fleming, Raiden ?

#include <iostream>

using namespace std;
int main() {
    dsa::array_list<int> left;
    left.push_back(13);
    left.push_back(10);
    left.push_back(28);
    left.push_back(33);
    left.push_back(99);
    left.push_back(76);
    left.push_back(15);
    left.push_back(13);
    left.push_back(75);
    left.push_back(87);
    std::cout << "Display in the form of index:value" << std::endl;
    std::cout << left << std::endl;
    dsa::array_list<int> right;
    right.push_back(13);
    right.push_back(-3);
    right.push_back(28);
    right.push_back(0);
    right.push_back(99);
    right.push_back(76);
    right.push_back(2);
    right.push_back(13);
    right.push_back(0);
    right.push_back(87);
    std::cout << "Display in the form of index:value" << std::endl;
    std::cout << right << std::endl;
    // intersection unsorted list:
    std::cout << "Intersection of unsorted list: " << std::endl;
    std::cout << left.intersection_unsorted(left, right) << std::endl;
    std::cout << "Union of unsorted list: " << std::endl;
    std::cout << left.union_unsorted(left, right) << std::endl;
    // sort the lists
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    // display the sorted lists in the form index:value
    std::cout << "Left" << std::endl;
    std::cout << left << std::endl;
    std::cout << "Right" << std::endl;
    std::cout << right << std::endl;
    // intersection sorted list:
    std::cout << "Intersection of sorted list: " << std::endl;
    std::cout << left.intersection_sorted(left, right) << std::endl;
    std::cout << "Union of sorted list: " << std::endl;
    std::cout << left.union_sorted(left, right) << std::endl;
}
