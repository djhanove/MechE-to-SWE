import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {

    private Item[] arr;
    private int count;


    // construct an empty randomized queue
    public RandomizedQueue() {
        arr = (Item[]) new Object[2]; // Init new object w/ 2 entries
        count = 0;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return count == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        return count;
    }

    private void resize(int cap) {
        Item[] temp = (Item[]) new Object[cap]; // Init new object w/ argument capacity
        for (int i = 0; i < count; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) throw new IllegalArgumentException();
        if (count == arr.length) {
            resize(arr.length * 2); // double the size of the array when full
        }
        arr[count++] = item;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        int rand = StdRandom.uniform(0, count);
        Item oldItem = arr[rand];
        arr[rand] = arr[count - 1];
        arr[count - 1] = null;
        count--;
        if (count > 2 && count == arr.length / 4) {
            resize(arr.length / 2); // half the size of the array when array is 25% full
        }
        return oldItem;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        int rand = StdRandom.uniform(0, count);
        return arr[rand];
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new LinkedIterator();
    }

    private class LinkedIterator implements Iterator<Item> {
        private Item[] current; // copy of arr so that multiple iterators can exist
        private int j = 0; // idx tracker

        public LinkedIterator() {
            copy();
            StdRandom.shuffle(current);
        }

        private void copy() {
            current = (Item[]) new Object[count];
            for (int i = 0; i < count; i++) {
                current[i] = arr[i];
            }
        }

        public boolean hasNext() {
            return j < count;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            return current[j++];
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        int n = 5;
        RandomizedQueue<Integer> rq = new RandomizedQueue<Integer>();
        rq.enqueue(57);
        StdOut.println(rq.size());
        rq.dequeue();
        StdOut.println(rq.isEmpty());
        StdOut.println(rq.isEmpty());
        rq.enqueue(289);
        rq.dequeue();
        StdOut.println(rq.isEmpty());
        rq.enqueue(342);


    }

}
