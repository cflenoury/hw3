#include <iostream>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[]){
	//Create a stack - check its size, it should be empty
	Stack<int> stack1;

	cout << "Size: " << stack1.size() << endl << "Empty? " << stack1.empty() << endl;

	//Add something to the stack - size should increase, it should no longer be empty
	stack1.push(1);

	cout << "Size: " << stack1.size() << endl << "Empty? " << stack1.empty() << endl;

	for (int i = 2; i <= 10; i ++){
		stack1.push(i);
	}

	cout << "Size: " << stack1.size() << endl << "Empty? " << stack1.empty() << endl;

	//Check what is on top of the stack
	cout << "This is on top: " << stack1.top() << endl;

	//Remove the item from the top of the stack
	for (int i = 0; i < 3; i++){
		stack1.pop();
	}

	cout << "This is on top: " << stack1.top() << endl;
	cout << "Size: " << stack1.size() << endl << "Empty? " << stack1.empty() << endl;
	
}