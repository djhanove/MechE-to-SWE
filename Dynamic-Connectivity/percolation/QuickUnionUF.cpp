#include "QuickUnionUF.h"

quickUnionUF::quickUnionUF(int N)
{
    dim = N;
    for(int i=0; i<N; i++)
        id.push_back(i);
}

quickUnionUF::~quickUnionUF(){}

void quickUnionUF::unionPQ(int p, int q)
{
    //Set the id of q's root to the id of p's root.
    id[root(p)] = root(q);
}

bool quickUnionUF::find(int p, int q)
{
  return root(p) == root(q);  
}

int quickUnionUF::root(int i)
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
    quickUnionUF test(9);
    test.unionPQ(1,2);
    test.unionPQ(1,3);
    test.unionPQ(5,6);
    test.unionPQ(3,4);
    test.unionPQ(3,6);

    std::cout<<"Are 3 and 4 connected? " << test.find(3,4) << std::endl;
    std::cout<<"Are 1 and 3 connected? " << test.find(1,3) << std::endl;
    std::cout<<"Are 3 and 5 connected? " << test.find(3,5) << std::endl;
}