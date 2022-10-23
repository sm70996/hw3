#include <iostream>
#include "heap.h"

int main()
{
	Heap<int> test; 

	test.push(4); 
	test.push(0); 
	test.push(1); 
	std::cout << "Size: " << test.size() << std::endl; 
	std::cout << test.empty() << std::endl;
	std::cout << test.top(); 
	test.pop(); 
	std::cout << test.top(); 
	test.pop(); 
	std::cout << test.top() << std::endl; 
	test.pop(); 
	std::cout << test.empty(); 


	return 0; 
}