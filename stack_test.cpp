#include <iostream>
#include <string> 
#include "stack.h"

int main()
{

	Stack<int> mystack; 
	mystack.push(3); 
	mystack.push(1); 
	mystack.push(4); 
	std::cout << mystack.top() << std::endl; 
	std::cout << mystack.size() << std::endl; 
	mystack.pop(); 
	mystack.pop(); 
	mystack.pop(); 
	bool empty = mystack.empty(); 
	std::cout << empty << std::endl; 
	mystack.push(7); 
	std::cout << mystack.top() << std::endl; 
	empty = mystack.empty(); 
	std::cout << empty << std::endl; 
	mystack.pop(); 
	try{
		mystack.top(); 
	}
	catch (std::underflow_error& e){
		std::cerr << e.what() << std::endl; 
		//return -1; 
	} 
	
	Stack<char> me; 
	me.push('S'); 
	me.push('C'); 
	std::cout << me.size() << std::endl;
	std::cout << me.top();  
	me.pop();
	std::cout << me.top() << std::endl;  
	me.pop(); 
	try{
		me.pop(); 
	}
	catch (std::underflow_error& e){
		std::cerr << e.what() << std::endl; 
		//return -1; 
	} 

	return 0; 
}