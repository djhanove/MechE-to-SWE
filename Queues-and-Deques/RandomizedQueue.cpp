#include "RandomizedQueue.h"

template <typename Item>
RandomizedQueue<Item>::RandomizedQueue() {
    elems = new Item[2]; // Init new object w/ 2 entries
    length = 2;
    count = 0;
}

template <typename Item>
RandomizedQueue<Item>::~RandomizedQueue(){}

// is the randomized queue empty?
template <typename Item>
bool RandomizedQueue<Item>::isEmpty() {
        return count == 0;
}

// return the number of items on the randomized queue
template <typename Item>
int RandomizedQueue<Item>::size() {
    return count;
}

// Dynamically resize the storage array using repeated doubling
template <typename Item>
void RandomizedQueue<Item>::resize(int cap) {
    Item* temp = new Item[cap]; // Init new object w/ argument capacity
    for (int i = 0; i < count; i++) {
        temp[i] = elems[i];
}
    elems = temp;
    length = cap;
}

// add the item
template <typename Item>
void RandomizedQueue<Item>::enqueue(Item item) {
    if (item == NULL) throw "Illegal Argument: NULL";
    if (count == length) {
        resize(length * 2); // double the size of the array when full
    }
    elems[count++] = item;
}

// remove and return a random item
template <typename Item>
Item RandomizedQueue<Item>::dequeue() {
    if (isEmpty()) 
        throw "Queue underflow";
    int random = rand() % count; // generate random number from 0:count
    Item oldItem = elems[random];
    elems[random] = elems[count - 1];
    elems[count - 1] = NULL;
    count--;
    if (count > 2 && count == length / 4) {
        resize(length / 2); // half the size of the array when array is 25% full
    }
    return oldItem;
}

    // return a random item (but do not remove it)
template <typename Item>
Item RandomizedQueue<Item>::sample() {
    if (isEmpty()) 
        throw "Queue underflow";
    int random = rand() % count;
    return elems[random];
}



int main(int argc, char ** argv){

    srand (time(NULL));
	RandomizedQueue<char> rq;

	std::cout << "Empty? " << rq.isEmpty() << std::endl;
	std::cout << "Size? " << rq.size() << std::endl;
	rq.enqueue('a');
	rq.enqueue('b');
	rq.enqueue('c');
	rq.enqueue('d');
	std::cout << "Empty? " << rq.isEmpty() << std::endl;
	std::cout << "Size? " << rq.size() << std::endl;
   	int i;

	std::cout << "sampling : " ;
	for(i = 0; i < rq.size()*2;i++){
		std::cout << rq.sample() << " ";
	}
	std::cout << std::endl;

	std::cout << "dequeue :  " << rq.dequeue() << std::endl;

	return 0;
}