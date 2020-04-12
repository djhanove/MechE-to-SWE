#include "Deque.h"

template <typename T>
bool Deque<T>::isEmpty() {
    return first == NULL;
}

template <typename T>
int Deque<T>::size() {
    return count;
}

template <typename T>
void Deque<T>::addFirst(T item) {
    if(item == NULL) {
        throw "Illegal NULL Argument";
    }
    Node<T>* tempNode = new Node<T>;
    tempNode->data =  item;
    if (isEmpty()) // deque is empty
    {
        first = last = tempNode;
    }
    else
    {
        tempNode->next = first;
        first->prev = tempNode;
        first = tempNode;
        first->prev = NULL;
    }
    count++;   
}

template <typename T>
void Deque<T>::addLast(T item) {
    if(item == NULL) {
        throw "Illegal NULL Argument";
    }
    Node<T>* tempNode = new Node<T>;
    tempNode->data = item;
    if (isEmpty())
    {
        first = last = tempNode;
    }
    else
    {
        tempNode->prev = last;
        last->next = tempNode;
        last = tempNode;
        last->next = NULL;
    }
    count++;
}

template <typename T>
T Deque<T>::removeFirst() {
    if (isEmpty())
    {
        throw "No Element to Remove";
    }
    
    T tempItem = first->data;

    if (count == 1)
    {
        first = NULL;
        last = NULL;;
    }
    else
    {
        first = first->next;
        first->prev = NULL;       
        if(isEmpty())
        {
            last = NULL;
        }
    }
    count--;       
    return tempItem;
}

template <typename T>
T Deque<T>::removeLast() {
    if (isEmpty())
    {
        throw "No Element to Remove";
    }

    T tempItem = last->data;
    if (count == 1)
    {
        first = NULL;
        last = NULL;;
    }
    else
    {
        last = last->prev;
        last->next = NULL;
        if (isEmpty())
        {
            first = NULL;
        }
    }    
    count--;
    return tempItem;
}

int main() 
{ 
    Deque<int> dq; 
    std::cout << "Empty?: " << dq.isEmpty() << std::endl;
    dq.addFirst(1);

    std::cout << "Size: " << dq.size() << std::endl;
    std::cout << "Popped Front Element: " << dq.removeFirst() << std::endl;
    dq.addLast(10);
    dq.addLast(5);
    dq.addFirst(4);
    dq.addLast(3);
    std::cout << "Popped Front Element: " << dq.removeFirst() << std::endl;
    std::cout << "Popped Rear Element: " << dq.removeLast() << std::endl;
    dq.~Deque();

  
    return 0; 
} 