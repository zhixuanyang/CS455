/*  Name: Zhixuan Yang
 *  USC NetID: yangzhix
 *  CS 455 Fall 2021
 *
 *  See ecListFuncs.h for specification of each function.
 *
 */

#include <string>
#include <cassert>
// for istringstream
#include <sstream>

#include "ecListFuncs.h"

using namespace std;

// *********************************************************
// Node constructors: do not change
Node::Node(int item) { 
   data = item;
   next = NULL;
}

Node::Node(int item, Node *n) {
   data = item;
   next = n;
}
// *********************************************************


ListType buildList(const string & listString) {
   istringstream tempStream(listString);
   int value;
   bool headNodeCreated = true;
   ListType headNode; //head of the 
   ListType followingNode;
   while (tempStream >> value) {
      if (headNodeCreated == true) {
         headNode = new Node(value, NULL);
         followingNode = headNode;
         headNodeCreated = false;
      } else {
         followingNode -> next = new Node(value, NULL);
         followingNode = followingNode -> next;
      }
   }
   if (headNodeCreated == true) {
      return NULL;
   }
   return headNode;
}



string listToString(ListType list) {
   string result = "(";
   Node *p = list;
   while (p != NULL) {
      result = result + to_string(p -> data) + " ";
      p = p -> next;
   }
   if (result.length() == 1) {
      result = result + ")";
   } else {
      result[result.length() - 1] = ')';
   }
   return result;
}


void insertAt(ListType & list, int index, int value) {
   if (index == 0) {
      ListType newHead = new Node(value, list);
      list = newHead;
   } else {
      Node *p = list;
      for (int i = 0; i < index - 1; i++) {
         p = p -> next;
      }
      ListType currentTail = p -> next;
      ListType newNode = new Node(value, currentTail);
      p -> next = newNode;
   }
}


ListType partitionBy(ListType & list, int number) {
   Node *validHead = NULL;
   Node *validTail = NULL;
   Node *nonValidHead = NULL;
   Node *nonValidTail = NULL;
   Node *p = list;
   while (p != NULL) {
      if (p -> data < number) {
         if (validHead == NULL) {
            validHead = p;
            validTail = validHead;
         } else {
            validTail -> next = p;
            validTail = validTail -> next;
         }
      } else {
         if (nonValidHead == NULL) {
            nonValidHead = p;
            nonValidTail = nonValidHead;
         } else {
            nonValidTail -> next = p;
            nonValidTail = nonValidTail -> next;
         }
      }
      p = p -> next;
   }
   if (validTail != NULL) {
      validTail -> next = NULL;
   }
   if (nonValidTail != NULL) {
      nonValidTail -> next = NULL;
   }
   list = nonValidHead;
   return validHead;
}


