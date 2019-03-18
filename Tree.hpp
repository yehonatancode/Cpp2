#include <iostream>
using std::cout, std::endl;


namespace ariel{


	class Tree       
{
          public:

          void print();
          void insert(int key);
          void remove(int key);
          void inorder_print();
          bool contains(int key);
          int root();
          int parent(int key);
          int left(int key);
          int right(int key);
          int size();
};

}
