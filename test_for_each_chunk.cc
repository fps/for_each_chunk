#include "for_each_chunk.h"

#include <vector>
#include <iostream>

#include <boost/bind.hpp>
#include <boost/function.hpp>

void print(std::vector<int>::iterator begin, std::vector<int>::iterator end) 
{
	std::cout << "chunk" << std::endl;
	
	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		std::cout << "an element: " << (*it) << std::endl;
	}
}

int main() 
{
	std::vector<int> v;
	
	for (unsigned int index = 0, max = 1010; index < max; ++index) 
	{
		v.push_back(index);
	}
		
		
	for_each_chunk(v.begin(), v.end(), 100, print);
	
#if 0
	//! C++-11 Style with lambdas
	for_each_chunk
	(
		v.begin(), 
		v.end(), 
		100, 
		[](std::vector<int>::iterator begin, std::vector<int>::iterator end) 
		{
			std::cout << "hah" << std::endl; 
			for (std::vector<int>::iterator it = begin; it != end; ++it) 
			{
				std::cout << *it << std::endl;
			}
		}
	);
#endif
}