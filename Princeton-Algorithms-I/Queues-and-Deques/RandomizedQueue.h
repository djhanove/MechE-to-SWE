#include <iostream>
#include <stdlib.h>
#include <time.h>


template <typename Item>
class RandomizedQueue {

    private:
     Item *elems;
     int length;
     int count;
     
    public:
     RandomizedQueue<Item>();
     ~RandomizedQueue();
     bool isEmpty();
     int size();
     void resize(int cap);
     void enqueue(Item item);
     Item dequeue();
     Item sample();
};