
#include "PmergeMe.hpp"

// std::vector<Pair> createPairsVector(cont std::vector<int>& arr)
// {
// 	std::vector<Pair> pairs;

// 	for (size_t i = 0; i + 1 < arr.size(); i +=2)
// 	{

// 	}
// }

// jn = j(n -1) + 2*j(n-2)
std::vector<size_t> generateJacobsthalV(size_t n)
{
	std::vector<size_t> jacobsthal;
	std::vector<size_t> result;

	if (n == 0)
		return result;
	
	size_t a = 0;
	size_t b = 1;

	size_t sum = 1;
	// std::cout << "n: " << n << std::endl;
	while (n >= sum)
	{
		size_t next = b + 2 * a;
		jacobsthal.push_back(next);
		a = b;
		b = next;
		sum += next;
	}

	return jacobsthal;

}


std::deque<size_t> generateJacobsthalD(size_t n)
{
	std::deque<size_t> jacobsthal;
	std::deque<size_t> result;

	if (n == 0)
		return result;
	
	size_t a = 0;
	size_t b = 1;

	size_t sum = 1;
	// std::cout << "n: " << n << std::endl;
	while (n >= sum)
	{
		size_t next = b + 2 * a;
		jacobsthal.push_back(next);
		a = b;
		b = next;
		sum += next;
	}

	return jacobsthal;

}

template <typename T>
void printVector(const std::vector<T>& vect)
{
	for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
	std::cout << std::endl;
	return ;
}

template <typename T>
void printDeque(const std::deque<T>& deq)
{
	for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";
	std::cout << std::endl;
	return ;
}

//We sort the larger elements (first elements) recursively
//We insert the smaller elements (second elements) in a specific order
//The first pend element always goes at the front of main chain

void fordJohnsonVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	
	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return ;
	}

	std::vector<std::pair<int, int> > pairs;

	//if even oddNum would be -1 which is impossible input
	//if odd, oddNum would be the last number making it even, like sitting on the bench
	int oddNum = -1;
	if (arr.size() % 2 == 1)
		oddNum = arr.back();

	//first element of each pair will be larger than the second
	//larger will be part of main chain
	//smaller will be part of pend chain
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::pair<int, int>(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::pair<int, int>(arr[i + 1], arr[i]));
	}

	//sort pairs by first element
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
			{
				std::pair<int, int> temp = pairs[i];
				pairs[i] = pairs[j];
				pairs[j] = temp;
			}
		}
	}

	//push the larger into a vector
	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);


	fordJohnsonVector(largerElements);

	std::vector<int> mainChain = largerElements;
	// std::cout << "main: ";
	// printVector(mainChain);

	//pend is basically the smaller numbers
	std::vector<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	// std::cout << "pend: ";
	// printVector(pend);

	if (!pend.empty())
		mainChain.insert(mainChain.begin(), pend[0]);

	//u want to insert the smaller number based on the jacobsthel sequence
	if (pend.size() > 1)
	{
		std::vector<size_t> jacobOrder = generateJacobsthalV(pend.size() - 1);
		// std::cout << "jacob: ";
		// printVector(jacobOrder);
		

		size_t j = 0;
		for (size_t i = 0; i < jacobOrder.size(); i++)
		{
			size_t pendIndex = jacobOrder[i];
			size_t tmp;

			tmp = pendIndex;
			// std::cout << "tmp: " << tmp << std::endl;
			while (tmp > 0)
			{
				if ((tmp + j) > pend.size() - 1)
				{
					tmp--;
					continue;
				}
				// std::cout << "tmp + j: " << tmp + j << std::endl;
				int element = pend[tmp + j];
				// std::cout << "elem: " << element << std::endl;
				std::vector<int>::iterator pos = std::lower_bound(
					mainChain.begin(),
					mainChain.end(), element);
					mainChain.insert(pos, element);
				tmp--;
			}
			j = pendIndex + j;
		}
	}

	//if got odd number we add to the chain
	// std::cout << oddNum << std::endl;
	if (oddNum != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(
			mainChain.begin(), mainChain.end(), oddNum);
		mainChain.insert(pos, oddNum);
	}

	arr = mainChain;

}


void fordJohnsonDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	
	if (arr.size() == 2)
	{
		if (arr[0] > arr[1])
			std::swap(arr[0], arr[1]);
		return ;
	}

	std::deque<std::pair<int, int> > pairs;

	int oddNum = -1;
	if (arr.size() % 2 == 1)
		oddNum = arr.back();

	//first element of each pair will be larger than the second
	//larger will be part of main chain
	//smaller will be part of pend chain
	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] > arr[i + 1])
			pairs.push_back(std::pair<int, int>(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::pair<int, int>(arr[i + 1], arr[i]));
	}

	//sort pairs by first element
	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
			{
				std::pair<int, int> temp = pairs[i];
				pairs[i] = pairs[j];
				pairs[j] = temp;
			}
		}
	}

	//push the larger into a vector
	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);


	fordJohnsonDeque(largerElements);

	std::deque<int> mainChain = largerElements;
	// std::cout << "main: ";
	// printDeque(mainChain);

	//pend is basically the smaller numbers
	std::deque<int> pend;
	for (size_t i = 0; i < pairs.size(); i++)
		pend.push_back(pairs[i].second);

	// std::cout << "pend: ";
	// printDeque(pend);

	if (!pend.empty())
		mainChain.push_front(pend[0]);

	if (pend.size() > 1)
	{
		std::deque<size_t> jacobOrder = generateJacobsthalD(pend.size() - 1);
		// std::cout << "jacob: ";
		// printDeque(jacobOrder);
		

		size_t j = 0;
		for (size_t i = 0; i < jacobOrder.size(); i++)
		{
			size_t pendIndex = jacobOrder[i];
			size_t tmp;

			tmp = pendIndex;
			// std::cout << "tmp: " << tmp << std::endl;
			while (tmp > 0)
			{
				if ((tmp + j) > pend.size() - 1)
				{
					tmp--;
					continue;
				}
				// std::cout << "tmp + j: " << tmp + j << std::endl;
				int element = pend[tmp + j];
				// std::cout << "elem: " << element << std::endl;
				std::deque<int>::iterator pos = std::lower_bound(
					mainChain.begin(),
					mainChain.end(), element);
					mainChain.insert(pos, element);
				tmp--;
			}
			j = pendIndex + j;
		}
	}

	//if got odd number we add to the chain
	// std::cout << oddNum << std::endl;
	if (oddNum != -1)
	{
		std::deque<int>::iterator pos = std::lower_bound(
			mainChain.begin(), mainChain.end(), oddNum);
		mainChain.insert(pos, oddNum);
	}

	arr = mainChain;


}

// Use std::vector and std::deque because:

// They handle dynamic input sizes (runtime determined)
// They both support random access (needed for Ford-Johnson)
