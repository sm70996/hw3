#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
	std::vector<T> vecHeap;
	void heapify(int idx);
	void trickleup(int loc);  
	int m_; 
	PComparator c_; 
   
};

//constructor 
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m),c_(c)
{

}

//destructor
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}


// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  vecHeap.push_back(item);
	trickleup(vecHeap.size() - 1); 
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleup(int loc)
{
	if(loc > 0){
		int parent = (loc - 1) / m_; 
		while(parent >= 0 && c_(vecHeap[loc],vecHeap[parent])){
			std::swap(vecHeap[loc], vecHeap[parent]); 
			loc = parent; 
			parent = (loc-1)/m_; 
			if(parent < 0){
				break; 
			}
		}
	}
} 

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  if(vecHeap.empty()){
		return true; 
	}
  return false; 
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
	return vecHeap.size(); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  unsigned int child = idx * m_ + 1; 
	if(child >= vecHeap.size()){
		return; 
	}
	else{
		int numCompare = m_ - 1; 
		unsigned int currChild = child; 
		unsigned int bestChild = child; 
		while(numCompare > 0 && currChild <= vecHeap.size() - 1){
			currChild = currChild + 1; 
			if(c_(vecHeap[currChild], vecHeap[bestChild])){
				bestChild = currChild;
			}
			numCompare--; 
		}
		if(c_(vecHeap[bestChild], vecHeap[idx])){
			std::swap(vecHeap[bestChild], vecHeap[idx]); 
			heapify(bestChild); 
		}
	} 
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
    throw std::underflow_error("Topping empty heap"); 
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vecHeap[0];
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
    throw std::underflow_error("Popping empty heap"); 
  }
  vecHeap[0] = vecHeap.back(); 
	vecHeap.pop_back();
  heapify(0);
} 

#endif
