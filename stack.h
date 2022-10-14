#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
    public:
        Stack();
        ~Stack();
        bool empty() const;
        size_t size() const;
        void push(const T& item);
        void pop();  // throws std::underflow_error if empty
        const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

//constructor
template <typename T>
Stack<T>::Stack(){}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
bool Stack<T>::empty() const{
	return std::vector<T>::empty();//Call the base class empty function
}

template <typename T>
size_t Stack<T>::size() const{
	return std::vector<T>::size();
}

template <typename T>
void Stack<T>::push(const T& item){
	std::vector<T>::push_back(item);//Add item to the end of the underlying array in the vector
}

template <typename T>
void Stack<T>::pop(){
    if(empty()){
        throw std::underflow_error("Stack is empty.");
    }
	std::vector<T>::pop_back();//Remove last item in vector (most recently added)
}

template <typename T>
const T& Stack<T>::top() const{
    if(empty()){
        throw std::underflow_error("Stack is empty.");
    }
	return std::vector<T>::back();//Retrieve item at the back of the underlying array in the vector
}

#endif