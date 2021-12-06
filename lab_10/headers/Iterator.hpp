#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "List.hpp"


    // Inner class iterator
    template <typename T>
    class iterator {
    friend class list;
    private:
      Node<T> *nodePtr;
      // The constructor is private, so only our friends
      // can create instances of iterators.
      iterator(Node<T> *newPtr) : nodePtr(newPtr) {}
    public:
      iterator() : nodePtr(nullptr) {} 

      // Overload for the comparison operator !=
      bool operator!=(const iterator& itr) const {
        return nodePtr != itr.nodePtr;
      } 

      // Overload for the dereference operator *
      T& operator*() const {
        return nodePtr->next->data;
      }

      // Overload for the postincrement operator ++
      iterator operator++(int) {
        iterator temp = *this;
        nodePtr = nodePtr->next;
        return temp;
      }
    iterator begin() const {
      return iterator(head);
    }
    
    iterator end() const {
      return iterator(tail);
    }
    
    iterator Insert(iterator position,const T& value) {
      Node<T>* newNode = new node<T>(value, position.nodePtr->next);
      if (position.nodePtr == tail) tail = newNode;
      position.nodePtr->next = newNode;
      return position;
    }

    iterator erase(iterator position) {
      Node<T> *toDelete = position.nodePtr->next;
      position.nodePtr->next = position.nodePtr->next->next;
      if (toDelete == tail) tail = position.nodePtr;
      delete toDelete;
      return position;
    }
  private:
    Node<T>* head;
    Node<T>* tail;
};


#endif
