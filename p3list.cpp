#include "list.h"

void bookList::addtoList(bookCharacter book) {
    booklist.push_back(book);
}
char bookList::findValuebyKey(unsigned long key) {
    unsigned long i;
    unsigned long index;
    for(i=0;i<booklist.size();i++){
        if(booklist[i].createUniqKey() ==key){
            index = i;
        }
    }
    return booklist[index].getValue();
}
bookList::bookList() {

}