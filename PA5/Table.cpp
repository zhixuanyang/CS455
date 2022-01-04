// Name: Zhixuan Yang
// USC NetID: yangzhix
// CSCI 455 PA5
// Fall 2021

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

// for hash function called in private hashCode method defined below
#include <functional>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

/**
 * create an empty table, i.e., one where numEntries() is 0.
 * the hashSize will be the default value
 */
Table::Table() {
   hashSize = HASH_SIZE;
   table = new ListType[hashSize]();
   numofEntries = 0;
}

/**
 * create an empty table, i.e., one where numEntries() is 0.
 * the hashSize will be the given value
 * PRECONDITION: hSize >= 1
 */
Table::Table(unsigned int hSize) {
   hashSize = hSize;
   table = new ListType[hashSize]();
   numofEntries = 0;
}

/**
 * returns the address of the value that goes with this key or NULL if key is not present.
 * @param key the input key
 * @return the address of the value
 */
int * Table::lookup(const string &key) {
   unsigned int code = hashCode(key);
   return lookupList(table[code], key);
}

/**
 * remove a pair given its key return false iff key wasn't present
 * @param key the input key
 * @return return true if the pair is removed, otherwise return false
 */
bool Table::remove(const string &key) {
   unsigned int code = hashCode(key);
   bool result = removeList(table[code], key);
   if (result == true) {
      numofEntries -= 1;
      return true;
   }
   return false;
}

/**
 * insert a new pair into the table return false iff this key was already present
 * @param key the input key
 * @return return true if the pair is added successfully, otherwise return false
 */
bool Table::insert(const string &key, int value) {
   unsigned int code = hashCode(key);
   bool result = insertList(table[code], key, value);
   if (result == true) {
      numofEntries += 1;
      return true;
   }
   return false;
}

/**
 * number of entries in the table
 * @return number of entries in the table
 */
int Table::numEntries() const {
   return numofEntries;      // dummy return value for stub
}

/**
 * print out all the entries in the table, one per line.
 */
void Table::printAll() const {
   for (int i = 0; i < hashSize; i++) {
      printAllList(table[i]);
   }
}

/**
 * prints out info to let us know if we're getting a good distribution of values in the hash table.
 * @param out the ostream to print out the info
 */
void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << hashSize << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << getNonEmpty() << endl;
   out << "longest chain: " << getLongestChain() << endl;
}


// hash function for a string
// (we defined it for you)
// returns a value in the range [0, hashSize)
unsigned int Table::hashCode(const string &word) const {

   // Note: calls a std library hash function for string (it uses the good hash
   //   algorithm for strings that we discussed in lecture).
   return hash<string>()(word) % hashSize;

}


// add definitions for your private methods here
/**
 * the helper function to count the number of non-empty buckets in the table
 * @return number of non-empty buckets
 */
int Table::getNonEmpty() const{
   int size = 0;
   for (int i = 0; i < hashSize; i++) {
      if (table[i] != NULL) {
         size += 1;
      }
   }
   return size;
}

/**
 * the helper function to count the number of elements in the longest chain
 * @return the number of elements in the longest chain
 */
int Table::getLongestChain() const{
   int longest = 0;
   for (int i = 0; i < hashSize; i++) {
      if (getSizeList(table[i]) > longest) {
         longest = getSizeList(table[i]);
      }
   }
   return longest;
}

