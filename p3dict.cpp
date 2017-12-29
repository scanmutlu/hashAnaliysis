#include "dictionary.h"
#include <cmath>

dict::dict(unsigned long size) {
    hashTable = new bookCharacter*[size];
}

/*unsigned long dict::hashing(unsigned long k) {
    unsigned long temp = floor((131071 * k * 0.618));
    return temp % 131071;
}*/
unsigned long dict::hashing(unsigned long key){
    return (unsigned long)(floor(131071 * key * 0.618)) % 131071;
};

unsigned long dict::probing(unsigned long k, int i) {
    return (k + 7*i + 3 * i*i)%131071 ;
}

dict::~dict() {
    delete[] hashTable;
}
int dict::insertion(bookCharacter *book) {
    unsigned long key =  book->createUniqKey();
    unsigned long keyHash = hashing(key);
    unsigned long index = keyHash;
    int x = 1;
    while(hashTable[index]!=NULL){
        index = (probing(keyHash,x));
        x++;
    }
    hashTable[index] = book;
    return x;
}

char dict::lookup(unsigned long key) {

    unsigned long keyHash = hashing(key);
    unsigned long index = keyHash;
    int x = 1;
    while (hashTable[index]->createUniqKey() != key){
        index = probing(keyHash,x);
        x++;
    }
    return hashTable[index]->getValue();
}