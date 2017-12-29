#include "karakter.h"
#include <vector>
#ifndef ALGO_HOMEWORK3_LIST_H
#define ALGO_HOMEWORK3_LIST_H
using  namespace std;
class bookList{
    vector<bookCharacter> booklist;
public:
    char findValuebyKey(unsigned long key);
    void addtoList(bookCharacter book);
    bookList();

};
#endif //ALGO_HOMEWORK3_LIST_H
