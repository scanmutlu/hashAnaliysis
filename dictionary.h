#include "karakter.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class dict {
private:
    unsigned long size;
    bookCharacter **hashTable;
public:
    dict(unsigned long size);
    ~dict();
    unsigned long hashing(unsigned long k);
    unsigned long probing(unsigned long k, int i);
    int insertion(bookCharacter *book);
    char lookup(unsigned long key);
};




