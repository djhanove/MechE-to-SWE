#include <iostream>

class DisjointSets {
public:
	int s[256];

	DisjointSets() { for (int i = 0; i < 256; i++) s[i] = -1; }

	int find(int i);
};

/* Modify the find() method below
 * to implement path compression
 * so that element i and all of
 * its ancestors in the up-tree
 * point to directly to the root
 * after find() completes.
 */
 
 
 /*
 function Find(x) is
    root := x
    while root.parent ≠ root
        root := root.parent

    while x.parent ≠ root
        parent := x.parent
        x.parent := root
        x := parent

  return root
  */

int DisjointSets::find(int i) {
  int root = i;
  while( s[root] != -1  ) {
    root = s[root];
  } 
  while(s[i] != root) {
    int parent = s[i];
    s[i] = root;
    i = parent;
  }
  return root;
}


int main() {
  DisjointSets d;

  d.s[1] = 3;
  d.s[3] = 5;
  d.s[5] = 7;
  d.s[7] = -1;

  std::cout << "d.find(3) = " << d.find(3) << std::endl;
  std::cout << "d.s(1) = " << d.s[1] << std::endl;
  std::cout << "d.s(3) = " << d.s[3] << std::endl;
  std::cout << "d.s(5) = " << d.s[5] << std::endl;
  std::cout << "d.s(7) = " << d.s[7] << std::endl;

  return 0;
}
