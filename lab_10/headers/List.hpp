#include <iostream>
using namespace std;

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
template <typename T>
class List {
   public:
    List();
    ~List();

    void pop_front();
    void push_back(T data);
    void clear();
    int GetSize() { return Size; }
    T &operator[](const int index);
    void push_front(T data);
    void insert(T data, int index);
    void removeAt(int index);
    void pop_back();

   private:
    int Size;
    Node<T> *head;
};

template <typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template <typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = this->head;

        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template <typename T>
void List<T>::clear() {
    while (Size) {
        pop_front();
    }
}

template <typename T>
T &List<T>::operator[](const int index) {
    int counter = 0;
    if (index < 0)
        throw(1);
    Node<T> *current = this->head;

    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template <typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    Size++;
}

template <typename T>
void List<T>::insert(T data, int index) {
    if (index == 0) {
        push_front(data);
    } else {
        Node<T> *previous = this->head;

        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *newNode = new Node<T>(data, previous->pNext);

        previous->pNext = newNode;
        Size++;
    }
}

template <typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}

template <typename T>
void List<T>::pop_back() {
    removeAt(Size - 1);
}