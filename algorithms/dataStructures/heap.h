#include <bits/stdc++.h>

template <class T, class Cmp = std::less<T>>

class Heap {
  Cmp compare;

  // heap is 1-based indexed.
  std::vector<T> heap;

  // O(log(n))
  void heapify(int parentId) {
    int n = (int) heap.size() - 1;
    T aux = heap[parentId];
    bool isHeap = false;

    // not is heap and not is leaf because all internal nodes id are [1, n / 2].
    int j;
    while (not isHeap and 2 * parentId <= n) {
      j = 2 * parentId;
      if (j < n) { // there's right child
        if (compare(heap[j], heap[j + 1])) {
          ++j;
        }
      }
      // at this point of the code, j is equal to the index of lowest/highest (it depends if it's a
      // min/max heap) between the two nodes, if exists. If not, it always will be the left node.
      if (not(compare(aux, heap[j]))) {
        isHeap = true;
      } else {
        heap[parentId] = heap[j];
        parentId = j;
      }
    }
    heap[parentId] = aux;
  }

  // O(n)
  void bottomUp() {
    int n = (int) heap.size() - 1;
    for (int i = n / 2; i >= 1; i--) {
      // In each interaction the heapify process transforms the subtree in a heap.
      heapify(i);
    }
  }

  // O(log(n))
  void topDown() {
    heapify(1);
  }

 public:
  explicit Heap(Cmp cmp = Cmp()) : heap(1), compare(cmp) {
  }
  explicit Heap(std::vector<T> values, Cmp cmp = Cmp()) : compare(cmp) {
    heap.push_back(T());
    for (int i = 0; i < (int) values.size(); ++i) {
      heap.push_back(values[i]);
    }
    bottomUp();
  }

  // O(log(n))
  void push(T value) {
    heap.push_back(value);
    topDown();
  }

  // O(1)
  T topValue() const {
    if (heap.size() == 1) {
      throw std::runtime_error("The heap is empty.");
    }
    return heap[1];
  }

  // O(1)
  int size() const {
    if (heap.size() > 1) {
      return (int) heap.size() - 1;
    }
    return 0;
  }

  // O(log(n))
  T remove() {
    if (heap.size() == 1) {
      throw std::runtime_error("The heap is empty.");
    }
    int n = (int) heap.size() - 1;
    T value = heap[1];
    std::swap(heap[1], heap[n]);
    heap.pop_back();
    heapify(1);

    return value;
  }

  // O(n log(n))
  std::vector<T> heapsort() {
    std::vector<T> sortedArray;
    while (heap.size() > 1) {
      sortedArray.push_back(remove());
    }
    return sortedArray;
  }

  // O(n log(n))
  std::vector<T> removeAll() {
    return heapsort();
  }
};