#include "QuickUnionWeightedUF.h"

quickUnionWeightedUF::quickUnionWeightedUF(int N)
{
    dim = N;
    for(int i=0; i<N; i++)
    {
        id.push_back(i);
        size.push_back(1); // init sizes all to be 1 upon construction
    }
}

quickUnionWeightedUF::~quickUnionWeightedUF(){}

void quickUnionWeightedUF::unionPQ(int p, int q)
{
    if(root(p) == root(q))
        return; //Same parent
    if (size[root(p)] < size[root(q)])
    {
        // tree w/ p is smaller than tree w/ q
        // combine p into q
        id[root(p)] = root(q);
        size[root(q)] += size[root(p)];
    }
    else
    {
        // tree w/ q is smaller than tree w/ p
        // combine q into p
        id[root(q)] = root(p);
        size[root(p)] += size[root(q)];    
    }
}

bool quickUnionWeightedUF::find(int p, int q)
{
  return root(p) == root(q);  
}

int quickUnionWeightedUF::root(int i)
{
    /*
        traverse the tree, resetting the parent 
        until it does not change
    */
    while(i != id[i])
        i = id[i]; 
    return i;
}


int main()
{
    quickUnionWeightedUF test(9);
    test.unionPQ(1,2);
    test.unionPQ(1,3);
    test.unionPQ(5,6);
    test.unionPQ(3,4);
    test.unionPQ(3,6);

    std::cout<<"Are 3 and 4 connected? " << test.find(3,4) << std::endl;
    std::cout<<"Are 1 and 3 connected? " << test.find(1,3) << std::endl;
    std::cout<<"Are 3 and 5 connected? " << test.find(5,3) << std::endl;
}
