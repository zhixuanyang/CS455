// Name: Zhixuan Yang
// USC NetID: yangzhix
// CSCI 455 PA5
// Fall 2021


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.

// Note2: it's good practice to *not* put "using" statement in *header* files.  Thus
// here, things from std libary appear as, for example, std::string

#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H

#include <string>
  

struct Node {
   std::string key;
   int value;

   Node *next;

   Node(const std::string &theKey, int theValue);

   Node(const std::string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

/**
 * insert function, in which insert the given key and its value into the list.
 * @param list the input list
 * @param key the given key
 * @param value the given value
 * @return return false iff this key was already present, otherwise return true.
 */
bool insertList(ListType &list, std::string key, int value);

/**
 * remove function, in which remove the pair by the given key.
 * @param list the input list
 * @param key the given key
 * @return return false iff key wasn't present, otherwise return true.
 */
bool removeList(ListType &list, std::string key);

/**
 * lookup function, in which return the value of the key-value pair by the given key.
 * @param list the input list
 * @param key the given key
 * @return returns the address of the value that goes with this key or NULL if key is not present.
 */
int *lookupList(ListType &list, std::string key);

/**
 * print all the element in the given list.
 * @param list the input list
 */
void printAllList(ListType &list);

/**
 * return the number of elements in the given list
 * @param list the input list
 * @return the number of elements in the given list
 */
int getSizeList(ListType &list);

/**
 * check whether the given key in the list or not.
 * @param list the input list
 * @param key the given key
 * @return return true if the given key is in the list, otherwise return false.
 */
bool containsKey(ListType &list, std::string key);













// keep the following line at the end of the file
#endif
