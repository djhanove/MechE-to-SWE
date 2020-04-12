#include "QuickFindUF.h"

quickFindUF::quickFindUF(int N)
{
    dim = N;
    for(int i=0; i<N; i++)
        id.push_back(i);
}

quickFindUF::~quickFindUF(){}

void quickFindUF::unionPQ(int p, int q)
{

    for(int i=0; i<id.size(); i++)
    {
        if (id[i] == id[p])
        {
            id[i] = id[q];
        }
    }
}

bool quickFindUF::find(int p, int q)
{
  return id[p] == id[q];  
}


int main()
{
    quickFindUF test(9);
    test.unionPQ(1,2);
    test.unionPQ(1,3);
    test.unionPQ(5,6);
    std::cout<<"Are 3 and 4 connected? " << test.find(3,4) << std::endl;
    std::cout<<"Are 1 and 3 connected? " << test.find(1,3) << std::endl;
}