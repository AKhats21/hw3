#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T, typename PComparator = std::less<T>>
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
  ~Heap() {};

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
  int m_;
  PComparator comp_;
  std::vector<T> data;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
    : m_(m), comp_(c) {
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
    throw std::underflow_error("heap is empty");


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];




}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T, PComparator>::pop() 
{
    if (empty()) {
        throw std::underflow_error("heap is empty");
    }

    // Swap root with last element and remove last
    std::swap(data[0], data[data.size() - 1]);
    data.pop_back();

    // Heapify down
    std::size_t index = 0;
    while (true) {
        std::size_t first_child_index = m_ * index + 1; // First child index
        std::size_t last_child_index = m_ * index + m_; // Last child index
        std::size_t compared = index; // Assume current(compared) is the highest priority

        // Iterate through all children
        for (std::size_t child_index = first_child_index; child_index <= last_child_index && child_index < data.size(); ++child_index) {
            if (comp_(data[child_index], data[compared])) {
                compared = child_index;
            }
        }

        //Heap property is restored
        if (compared == index) {
            break;
        }

        // Swap and continue heapifying down
        std::swap(data[index], data[compared]);
        index = compared;
    }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) 
{
  //Push item to last index
  data.push_back(item);
  std::size_t index = data.size() - 1;

  //Heapify up
  while(index != 0){
    std::size_t parent_index = (index - 1) / m_;
    T& current = data[index];
    T& parent = data[parent_index];

    if (comp_(parent, current)){
      break;
    }
    std::swap(current, parent);
    index = parent_index;

  }

}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return data.size();
}


#endif

