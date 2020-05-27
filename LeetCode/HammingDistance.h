class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int dist = 0;

        // Count the number of bits set
        for (unsigned val = x ^ y; val > 0; val = val >> 1)
        {
            // If A bit is set, so increment the count
            if (val & 1)
                dist++;
            // Clear (delete) val's lowest-order bit
        }

        // Return the number of differing bits
        return dist;
        
    }
};
