#include <vector>
#include <iostream>

class quickFindUF
{
    public:
        quickFindUF(int N);
        ~quickFindUF();
        void unionPQ(int p, int q);
        bool find(int p, int q);
    private:
        std::vector<int> id;
        int dim;
};

