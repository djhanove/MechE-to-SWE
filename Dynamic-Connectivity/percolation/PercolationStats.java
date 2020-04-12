/* *****************************************************************************
 *  Name:
 *  Date:
 *  Description:
 **************************************************************************** */

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private final int trials;
    private final int gridDim;
    private double[] iterations;
    private double avg = 0;
    private double dev = 0;
    private double confHi = 0;
    private double confLo = 0;
    private final double conf95 = 1.96;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int tests) {
        if (n <= 0 || tests <= 0)
            throw new IllegalArgumentException("row index i out of bounds");
        trials = tests;
        gridDim = n;
        iterations = new double[trials];

        runSimulation();
    }

    private void runSimulation() {
        for (int i = 1; i <= trials; i++) {
            Percolation perc = new Percolation(gridDim);
            while (!perc.percolates()) {
                perc.open(StdRandom.uniform(1, gridDim + 1), StdRandom.uniform(1, gridDim + 1));
            }
            iterations[i - 1] = perc.numberOfOpenSites() / Math.pow(gridDim, 2);
        }
        avg = mean();
        dev = stddev();
        confLo = confidenceLo();
        confHi = confidenceHi();
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(iterations);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        if (trials == 1) return Double.NaN;
        dev = StdStats.stddev(iterations);
        return dev;
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return avg - (conf95 * dev) / Math.sqrt(trials);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return avg + (conf95 * dev) / Math.sqrt(trials);
    }


    // test client (see below)
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int p = Integer.parseInt(args[1]);

        PercolationStats percStats = new PercolationStats(n, p);
        StdOut.printf("mean = %f\n", percStats.avg);
        StdOut.printf("stddev = %f\n", percStats.dev);
        StdOut.printf("95%% confidence interval = %f, %f\n", percStats.confLo, percStats.confHi);
    }

}
