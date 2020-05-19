#include <vector>
#include <iostream>

class quickUnionUF
{
    public:
        quickUnionUF(int N);
        ~quickUnionUF();
        void unionPQ(int p, int q);
        bool find(int p, int q);
        int root(int i);
    private:
        std::vector<int> id;
        int dim;

};

