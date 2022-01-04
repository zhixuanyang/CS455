/*  Name: Zhixuan Yang
 *  USC NetID: yangzhix
 *  CS 455 Sping 2021
 *  Extra credit assignment
 *
 *  ectest.cpp
 *
 *  a non-interactive test program to test the functions described in ecListFuncs.h
 *
 *    to run it use the command:   ectest
 *
 *  Note: this uses separate compilation.  You put your list code ecListFuncs.cpp
 *  Code in this file should call those functions.
 */


#include <iostream>
#include <string>

#include "ecListFuncs.h"

using namespace std;

void swap(Node * a, Node * b) {
   a = b;
   cout << a->data << " " << b->data << " ";
}
int main() {
   int a = 44;
   int *b; /* declaration of pointer b */
   b = &a;
   cout << b << endl;
   cout << &a << endl;
   cout << &b << endl;
   cout << **b << endl;
   cout << *b << endl;
}

