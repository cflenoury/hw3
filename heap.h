#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> items;

  //void printHeap();

	void heapify(int idx);

	void trickleUp(int loc);

  int m;

  PComparator c;

	void swap(T &a, T &b);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T, PComparator>::swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return items[0];//Return first item in unerlying vector (after the empty placeholder at idx 0)

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }

  items[0] = items.back(); //Erase the value of the top item in the heap to be the last item in the heap
  items.pop_back();//Erase the last item in the heap
  heapify(0); // a.k.a. trickleDown()
  //printHeap();
}

/*template <typename T, typename PComparator>
void Heap<T,PComparator>::printHeap(){
  for(int i = 0; i < items.size(); i++){
    std::cout << items[i] << " ";
  }
  std::cout << std::endl;
}*/

///Make this generic based on comparator & m
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx){
  if( idx*m+1 > (int)items.size()-1 ) return;//Return if its a leaf node (has no children - only check for first child because the heap is complete)
  
  int bestChild = m*idx+1; // start w/ first child

  for(int i = 2; i <= m; i++){//Find best child amongst all children
    
    if( idx*m + i <= (int)items.size() ){//Check for next child

      int nChild = idx*m + i;
      
      if(c(items[nChild],items[bestChild])){//Assign the best child to bestChild variable
        bestChild = nChild;
      }

    }
  }  

  //std::cout << "The best child is " << items[bestChild] <<std::endl;

  if(c(items[bestChild], items[idx])){//If the parent is worse than its child
    Heap<T, PComparator>::swap(items[idx], items[bestChild]);//Swap the items
    heapify(bestChild);//Recursive call on bestChild idx (which is now the parent value)
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return items.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return (int)items.size() == 0;
}

//Constructor with initilization list
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m(m), c(c) {}

//Destructor should just call base class destructor (by default) to deallocate memory
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  items.push_back(item);//Add item to the back of the vector
  trickleUp(items.size()-1);//Trickle up starting from the last item in the vector
	
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleUp(int loc)
{
  int parent = (loc-1)/m;//Find parent

  											//Maybe change the below code
  while(parent >= 0 && c(items[loc],items[parent]) )
  { 
    Heap<T, PComparator>::swap(items[parent], items[loc]);
    loc = parent;
    parent = (loc-1)/m;
  }
}

#endif

