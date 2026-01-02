

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <climits>
// #include <ostream>


void fordJohnsonVector(std::vector<int>& arr);
void binaryInsertVector(std::vector<int>& main, int element);

void fordJohnsonDeque(std::deque<int>& arr);
void binaryInsertDeque(std::deque<int>& main, int element);

std::vector<size_t> generateJacobsthal(size_t n);
void sortVector(std::vector<int>& arr);
void sortDeque(std::deque<int>& arr);

#endif