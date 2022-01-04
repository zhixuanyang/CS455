// Name: Zhixuan Yang
// USC NetID: yangzhix
// CSCI 455 PA5
// Fall 2021


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below
/**
 * check whether the given key in the list or not.
 * @param list the input list
 * @param key the given key
 * @return return true if the given key is in the list, otherwise return false.
 */
bool containsKey(ListType &list, std::string key) {
   if (list == NULL) { //if list == NULL, which means there is no element in this list, so return false
      return false;
   }
   Node *p = list;
   while (p != NULL) { //loop through the whole list until we found the given key, and return true
      if (p -> key == key) {
         return true;
      }
      p = p -> next;
   }
   return false; // if did not find the given key, return false
}

/**
 * insert function, in which insert the given key and its value into the list.
 * @param list the input list
 * @param key the given key
 * @param value the given value
 * @return return false iff this key was already present, otherwise return true.
 */
bool insertList(ListType &list, std::string key, int value) {
   if (containsKey(list, key)) { //if the list does not contain the given key return false
      return false;
   }
   Node *newNode = new Node(key, value, list); //add new node into the list
   list = newNode;
   return true;
}

/**
 * remove function, in which remove the pair by the given key.
 * @param list the input list
 * @param key the given key
 * @return return false iff key wasn't present, otherwise return true.
 */
bool removeList(ListType &list, std::string key) {
   if (!containsKey(list, key)) { //if the given key is not in the list return false
      return false;
   }
   if (list -> next == NULL) { // if the list only has one element, delete it and list becomes null.
      delete list;
      list = NULL;
      return true;
   }
   if (list -> key == key) { // if the first key in the list is the given key, delete it, and list equals next element
      list = list -> next;
      return true;
   }
   Node *prev = list; // here I use two pointer to remove the element, one to store the previous element,
   Node *curr = list -> next;  // and another to represent the current node.
   while (curr -> next != NULL) {
      if (curr -> key == key) {
         prev -> next = curr -> next;
         delete curr;
         return true;
      }
      prev = curr;
      curr = curr -> next;
   }
   prev -> next = NULL; // if the last element is the one we want, delete it and the last element becoems NULL
   delete curr;
   return true;
}

/**
 * lookup function, in which return the value of the key-value pair by the given key.
 * @param list the input list
 * @param key the given key
 * @return returns the address of the value that goes with this key or NULL if key is not present.
 */
int *lookupList(ListType &list, std::string key) {
   if (!containsKey(list, key)) { //return NULL if the given key is not in the list.
      return NULL;
   }
   Node *p = list; //loop over the list until we found the given key, and return its value
   while (p != NULL) {
      if (p -> key == key) {
         return &(list -> value);
      }
      p = p -> next;
   }
   return NULL;
}

/**
 * print all the element in the given list.
 * @param list the input list
 */
void printAllList(ListType &list) {
   Node *p = list; // print out every single element in the list
   while (p != NULL) {
      cout << p -> key << " " << p -> value << endl;
      p = p -> next;
   }
}

/**
 * return the number of elements in the given list
 * @param list the input list
 * @return the number of elements in the given list
 */
int getSizeList(ListType &list) {
   int count = 0;
   Node *p = list;
   while (p != NULL) { //loop over the list, and count its number of elements
      count += 1;
      p = p -> next;
   }
   return count;
}