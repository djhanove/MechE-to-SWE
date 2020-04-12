#include <stdlib.h>
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *prev, *next;
};

template <typename T>
class Deque {
    private:
     Node<T>* first;
     Node<T>* last;
     int count;
     

    public:
     Deque(){
         first = NULL;
         last = NULL;
         count = 0;
     };
     ~Deque(){
         last = NULL;
         Node<T>* current = first;
         while(current != NULL) {
            Node<T>* next = current->next;
            delete current;
            current = next;    
        }
     };
     bool isEmpty();
     int size();
     void addFirst(T item);
     void addLast(T item);
     T removeFirst();
     T removeLast();

};