#include <vector>
#include <iostream>

class quickUnionWeightedUF
{
    public:
        quickUnionWeightedUF(int N);
        ~quickUnionWeightedUF();
        void unionPQ(int p, int q);
        bool find(int p, int q);
        int root(int i);
    private:
        std::vector<int> id;
        std::vector<int> size;
        int dim;

};

