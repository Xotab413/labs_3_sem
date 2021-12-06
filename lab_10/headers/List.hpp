#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
using namespace std;
template <typename T>
class List {
   public:
    List();
    ~List();
    void removeAt(int index);
    void pop_front();
    void pop_back();
    void push_back(T data);
    void push_front(T data);
    void insert(T data, int index);
    void clear();
    int GetSize() { return Size; }
    T& operator[] (const int index);

   private:
    template <typename T>
    class Node {
       public:
        Node *pNext;
        T data;
        Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> head;
};
#include "../src/List.inl"
#endif