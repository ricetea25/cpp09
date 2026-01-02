

#include "PmergeMe.hpp"
#include <iomanip>

// void fordJohnsonVector(std::vector<int>& arr);

// // int main(int argc, char** argv) 
// // {
// //     std::vector<int> vec;
// //     std::deque<int> deq;
    
// //     // Parse arguments into both containers
// //     for (int i = 1; i < argc; i++) 
// //     {
// //         int val = atoi(argv[i]);
// //         vec.push_back(val);
// //         deq.push_back(val);
// //     }
    
// //     // Display before
// //     std::cout << "Before: ";
// //     for (size_t i = 0; i < vec.size(); i++) 
// //         std::cout << vec[i] << " ";
// //     std::cout << std::endl;
    
// //     // Time and sort with vector
// //     clock_t start = clock();
// //     PmergeMe::sortVector(vec);
// //     clock_t end = clock();
// //     double vectorTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
// //     // Time and sort with deque  
// //     start = clock();
// //     PmergeMe::sortDeque(deq);
// //     end = clock();
// //     double dequeTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    
// //     // Display after
// //     std::cout << "After: ";
// //     for (size_t i = 0; i < vec.size(); i++) 
// //         std::cout << vec[i] << " ";
// //     std::cout << std::endl;
    
// //     std::cout << "Time with vector: " << vectorTime << " us" << std::endl;
// //     std::cout << "Time with deque: " << dequeTime << " us" << std::endl;
    
// //     return 0;
// // }


// double getCurrentTime() 
// {
//     return static_cast<double>(std::clock()) / CLOCKS_PER_SEC;
// }

// // Function to print vector
// void printVector(const std::vector<int>& vec, const std::string& label) 
// {
//     std::cout << label;
//     for (size_t i = 0; i < vec.size(); i++) 
//     {
//         std::cout << vec[i];
//         if (i + 1 < vec.size())
//             std::cout << " ";
//     }
//     std::cout << std::endl;
// }

// // Function to validate a single number
// bool isValidNumber(const std::string& str) 
// {
//     if (str.empty()) 
//     {
//         std::cerr << "Error: Empty argument" << std::endl;
//         return false;
//     }
    
//     // Check each character is digit
//     for (size_t i = 0; i < str.size(); i++) 
//     {
//         if (!isdigit(str[i])) 
//         {
//             std::cerr << "Error: Invalid character in '" << str << "'" << std::endl;
//             return false;
//         }
//     }
    
//     // Check if number is within int range
//     char* endptr;
//     long num = std::strtol(str.c_str(), &endptr, 10);
    
//     if (*endptr != '\0') 
//     {
//         std::cerr << "Error: Invalid number format '" << str << "'" << std::endl;
//         return false;
//     }
    
//     if (num <= 0) 
//     {
//         std::cerr << "Error: Number must be positive: '" << str << "'" << std::endl;
//         return false;
//     }
    
//     if (num > INT_MAX) 
//     {
//         std::cerr << "Error: Number too large: '" << str << "'" << std::endl;
//         return false;
//     }
    
//     return true;
// }

// // Function to check if vector is sorted
// bool isSorted(const std::vector<int>& vec) 
// {
//     for (size_t i = 1; i < vec.size(); i++) 
//     {
//         if (vec[i - 1] > vec[i])
//             return false;
//     }
//     return true;
// }

// int main(int argc, char** argv) 
// {
//     // Check for arguments
//     if (argc < 2) 
//     {
//         std::cerr << "Error: Please provide positive integers to sort" << std::endl;
//         std::cerr << "Usage: ./PmergeMe 3 5 9 7 4" << std::endl;
//         std::cerr << "       ./PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`" << std::endl;
//         return 1;
//     }
    
//     // Parse and validate all arguments
//     std::vector<int> numbers;
    
//     for (int i = 1; i < argc; i++) 
//     {
//         std::string arg = argv[i];
        
//         if (!isValidNumber(arg))
//             return 1;
            
//         char* endptr;
//         long num = std::strtol(arg.c_str(), &endptr, 10);
//         numbers.push_back(static_cast<int>(num));
//     }
    
//     // Display before sorting
//     std::cout << "Before: ";
//     printVector(numbers, "");
    
//     // Make a copy for sorting
//     std::vector<int> sorted = numbers;
    
//     // Time the sorting
//     double startTime = getCurrentTime();
//     void fordJohnsonVector(sorted);
//     double endTime = getCurrentTime();
//     double elapsedTime = (endTime - startTime) * 1000000; // Convert to microseconds
    
//     // Display after sorting
//     std::cout << "After:  ";
//     printVector(sorted, "");
    
//     // Display timing
//     std::cout << std::fixed << std::setprecision(5);
//     std::cout << "Time to process a range of " << numbers.size() 
//               << " elements with std::vector : " << elapsedTime << " us" << std::endl;
    
//     // Verify the result is sorted
//     if (!isSorted(sorted)) 
//     {
//         std::cerr << "Error: Array is not sorted correctly!" << std::endl;
//         return 1;
//     }
    
//     // Optional: Compare with std::sort to verify
//     std::vector<int> stdSorted = numbers;
//     std::sort(stdSorted.begin(), stdSorted.end());
    
//     if (sorted != stdSorted) 
//     {
//         std::cerr << "Warning: Ford-Johnson result differs from std::sort!" << std::endl;
        
//         // Find first difference
//         for (size_t i = 0; i < sorted.size(); i++) 
//         {
//             if (sorted[i] != stdSorted[i]) 
//             {
//                 std::cerr << "First difference at index " << i 
//                           << ": Ford-Johnson=" << sorted[i] 
//                           << ", std::sort=" << stdSorted[i] << std::endl;
//                 break;
//             }
//         }
//         return 1;
//     }
    
//     std::cout << "Success! Array is correctly sorted." << std::endl;
    
//     return 0;
// }



#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip>

template <typename T>
bool isSorted(T& container) {
    for (size_t i = 0; i < container.size() - 1; i++) {
        if (container[i] > container[i + 1])
            return false;
    }
    return true;
}

template <typename Container>
void printContainer(const Container& c) {
    if (c.size() > 5) {
        // Print only first 5 elements for large containers
        for (size_t i = 0; i < 5; i++)
            std::cout << c[i] << " ";
        std::cout << "[...]";
    } else {
        for (size_t i = 0; i < c.size(); i++)
            std::cout << c[i] << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char *av[]) {
    if (ac < 2) {
        std::cerr << "Usage: " << av[0] << " <list of positive integers>" << std::endl;
        return 1;
    }
    
    // Parse input
    std::vector<int> vec;
    std::deque<int> deq;
    
    for (int i = 1; i < ac; i++) {
        int num = std::atoi(av[i]);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }
    
    // Print "Before:" (only if small enough)
    std::cout << "Before: ";
    printContainer(vec);
    
    // Time vector sort
    clock_t start_vec = clock();
    fordJohnsonVector(vec);
    clock_t end_vec = clock();
    double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000; // microseconds
    
    // Time deque sort
    clock_t start_deq = clock();
    fordJohnsonDeque(deq);
    clock_t end_deq = clock();
    double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000; // microseconds
    
    // Print "After:"
    std::cout << "After:  ";
    printContainer(vec);
    
    // Print timing results (must match subject format exactly!)
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " 
              << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;
    
    // Verify both are sorted
    if (isSorted(vec) && isSorted(deq)) {
        // std::cout << "SUCCESS! ✓" << std::endl;
        return 0;
    } else {
        std::cerr << "Error: Not sorted correctly!" << std::endl;
        return 1;
    }
}

// template <typename T>
// bool isSortedVect(std::vector<T>& vect)
// {
// 	for (size_t i = 0; i < vect.size() - 1; i++)
// 	{
// 		if (vect[i] > vect[i + 1])
// 			return false;
// 	}
// 	return true;
// }

// template <typename T>
// void printVector(const std::vector<T>& vect)
// {
// 	for (size_t i = 0; i < vect.size(); i++)
//         std::cout << vect[i] << " ";
// 	std::cout << std::endl;
// 	return ;
// }

// int main(int ac, char *av[])
// {
//     std::vector<int> numbers;
// 	for (int i = 1; i < ac; i++) {
//         numbers.push_back(std::atoi(av[i]));
//     }
// 	printVector(numbers);
//     // numbers.push_back(94);
//     // numbers.push_back(83);
//     // numbers.push_back(12);
//     // numbers.push_back(23);
//     // numbers.push_back(27);
//     // numbers.push_back(89);
//     // numbers.push_back(51);
//     // numbers.push_back(86);
//     // numbers.push_back(19);
//     // numbers.push_back(52);
    
//     std::cout << "Before: ";
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;
    
//     // Test your function
//     fordJohnsonVector(numbers);
    
//     std::cout << "After:  ";
//     for (size_t i = 0; i < numbers.size(); i++)
//         std::cout << numbers[i] << " ";
//     std::cout << std::endl;
    
//     // Verify
    
//     if (isSortedVect(numbers) && (numbers.size() == (size_t)(ac - 1)))
//         std::cout << "SUCCESS! ✓" << std::endl;
//     else
//         std::cout << "FAILED! ✗" << std::endl;
    
//     return 0;
// }