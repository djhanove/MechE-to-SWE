/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;


public class Percolation {
    private boolean[] open; // bool array to keep track of site occupancy
    private final int n; // # of rows and cols
    private final int gridSize; // n x n
    private final WeightedQuickUnionUF quf;
    private int openSiteCount = 0;

    private int xyTo1D(int y, int x) // fxn to convert xy coords to an idx
    {
        // row col idx are 1 based, not zero. Knowing gridsize, write a function which translates
        // the paired point to a 1D idx
        return n * (y - 1) + x - 1;
    }

    private void dimCheck(int row, int col) {
        if (row <= 0 || row > n || col <= 0 || col > n)
            throw new IllegalArgumentException("row index i out of bounds");
    }

    public static void main(String[] args) {
        Percolation perc = new Percolation(3);
        perc.open(1, 2);
        perc.open(2, 2);
        perc.open(2, 3);
        perc.open(3, 3);
        boolean c = perc.isFull(1, 1);
        StdOut.println(c);
    }

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int dim) {
        if (dim <= 0)
            throw new IllegalArgumentException("Dimensions must be greater than zero");
        n = dim;
        gridSize = n * n;
        // init Quick Union object w/ grid size + 2 for an extra top/bottom layer (easier to checkif it percolates)
        quf = new WeightedQuickUnionUF(gridSize + 2);
        open = new boolean[gridSize]; // grid is initially fully occupied (does not percolate)

    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        dimCheck(row, col); // validate dimensions
        int idx = xyTo1D(row, col);
        if (!open[idx]) {
            open[idx] = true;
            openSiteCount++;
            // check if space to right is occupied and we are not off the grid, create union if not
            if (idx + 1 <= gridSize - 1) {
                if (col < n && open[idx + 1])
                    quf.union(idx, idx + 1);
            }
            // check if space to left is occupied and we are not off the grid, create union if not
            if (idx - 1 >= 0) {
                if (col > 1 && open[idx - 1])
                    quf.union(idx, idx - 1);
            }
            // check if space above is occupied, create union if not
            if (idx - n >= 0) {
                if (open[idx - n])
                    quf.union(idx, idx - n);
            }
            else {
                // In first row, connect to virtual top
                quf.union(gridSize, idx);
            }
            // check if space below is occupied, create union if not
            if (idx + n <= gridSize - 1) {
                if (open[idx + n])
                    quf.union(idx, idx + n);
            }
            else {
                // in last row, connect to virtual bottom
                quf.union(gridSize + 1, idx);
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        dimCheck(row, col);
        int idx = xyTo1D(row, col);
        return open[idx];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        dimCheck(row, col);
        int idx = xyTo1D(row, col);
        return quf.connected(gridSize, idx);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return openSiteCount;
    }

    // does the system percolate?
    public boolean percolates() {
        return quf.connected(gridSize, gridSize + 1);
    }
}
