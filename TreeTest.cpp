/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree test1;
  ariel::Tree test2;
  ariel::Tree test3;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (test1.size(), 0)
  .CHECK_EQUAL (test2.size(), 0)
  .CHECK_EQUAL (test3.size(), 0)

  .CHECK_OK    (test1.insert(12))
  .CHECK_OK    (test1.insert(7))
  .CHECK_EQUAL (test1.size() , 2)
  .CHECK_EQUAL (test1.contains(12), true)
  .CHECK_OK    (test1.remove(12))
  .CHECK_EQUAL (test1.contains(12), false)
  .CHECK_EQUAL (test1.contains(13), false)

  .CHECK_THROWS(test1.remove(7))
  .CHECK_EQUAL (test1.size() ,0)

  .CHECK_OK    (test2.insert(9))
  .CHECK_EQUAL (test2.root(), 9)
 
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
