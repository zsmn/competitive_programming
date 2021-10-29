#include <bits/stdc++.h>

using E = int;

class Node {
 public:
  E value;
  Node* next;

  explicit Node() : next(nullptr) {
  }

  explicit Node(E e, Node* node = nullptr) : value(e), next(node) {
  }
};

class Queue {
  int size;
  Node* front;
  Node* rear;
  Node header;

 public:
  Queue() {
    front = rear = &header;
    size = 0;
  }

  ~Queue() {
    clear();
  }

  void clear() {
    while (front->next != nullptr) {
      Node* aux = front->next;
      front->next = front->next->next;
      delete aux;
      --size;
    }

    rear = front;
  }

  void enqueue(E e) {
    rear->next = new Node(e);
    rear = rear->next;
    ++size;
  }

  int dequeue() {
    if (!size) {
      throw std::runtime_error("The queue is empty!\n");
    }

    E e = front->next->value;

    Node* aux = front->next;
    front->next = front->next->next;
    delete aux;
    --size;

    if (front->next == nullptr) {
      rear = front;
    }

    return e;
  }

  int frontValue() {
    if (front == rear) {
      throw std::runtime_error("The queue is empty!\n");
    }

    return front->next->value;
  }

  int length() const {
    return size;
  }
};