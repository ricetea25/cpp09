

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

void fordJohnsonDeque(std::deque<int>& arr);

std::vector<size_t> generateJacobsthal(size_t n);

#endif