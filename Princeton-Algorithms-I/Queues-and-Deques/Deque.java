import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.NoSuchElementException;


public class Deque<Item> implements Iterable<Item> {

    private static class Node<Item> {
        private Item item;
        private Node<Item> next;
        private Node<Item> prev;
    }

    private Node<Item> first;
    private Node<Item> last;
    private int count;

    // construct an empty deque
    public Deque() {
        first = null;
        last = null;
        count = 0;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return first == null;
    }

    // return the number of items on the deque
    public int size() {
        return count;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) throw new IllegalArgumentException();
        if (count >= 1) {
            Node<Item> oldfirst = first;
            first = new Node<Item>();
            first.item = item;
            first.next = oldfirst;
            first.prev = null;
            oldfirst.prev = first;
            count++;
        }
        else {
            first = new Node<Item>();
            first.item = item;
            first.prev = null;
            first.next = null;
            last = first;
            count++;
        }
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null) throw new IllegalArgumentException();
        if (count >= 1) {
            Node<Item> oldlast = last;
            last = new Node<Item>();
            last.item = item;
            last.next = null;
            last.prev = oldlast;
            oldlast.next = last;
            count++;
        }
        else {
            last = new Node<Item>();
            last.next = null;
            last.prev = null;
            last.item = item;
            first = last;
            count++;
        }
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty()) throw new NoSuchElementException("Queue underflow");
        Item oldItem = first.item;
        if (count == 1) {
            first = null;
            last = null;
            count--;
        }
        else {
            first = first.next;
            first.prev = null;
            if (isEmpty()) last = null;   // to avoid loitering
            count--;
        }
        return oldItem;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue underflow");
        }
        Item oldItem = last.item;
        if (count == 1) {
            first = null;
            last = null;
        }
        else {
            last = last.prev;
            last.next = null;
        }
        count--;
        return oldItem;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new LinkedIterator(first);
    }

    private class LinkedIterator implements Iterator<Item> {
        private Node<Item> current;

        public LinkedIterator(Node<Item> first) {
            current = first;
        }

        public boolean hasNext() {
            return current != null;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        Deque<Integer> deck = new Deque<Integer>();
        deck.addFirst(1);
        deck.addFirst(2);
        StdOut.println(deck.removeLast());
        deck.addLast(3);
        deck.addFirst(4);
        StdOut.println(deck.isEmpty());
        Iterator<Integer> iter = deck.iterator();
        StdOut.printf("Does the deque have a next element %b", iter.hasNext());
        iter.next();
        StdOut.println();
        StdOut.println(deck.removeFirst());
        StdOut.println(deck.size());
        StdOut.println(deck.removeLast());
        StdOut.println(deck.removeLast());
        deck.addLast(100);

        StdOut.println(deck.removeLast());
    }

}
