#include <vector>
#include <iostream>

class quickUnionWeightedPCUF
{
    public:
        quickUnionWeightedPCUF(int N);
        ~quickUnionWeightedPCUF();
        void unionPQ(int p, int q);
        bool find(int p, int q);
        int root(int i);
    private:
        std::vector<int> id;
        std::vector<int> size;
        int dim;

};

