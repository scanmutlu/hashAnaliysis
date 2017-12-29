#include <iostream>
#include "karakter.h"

bookCharacter::bookCharacter(int p, int l, int i, char k) {
    pageNo = p;
    lineNo = l;
    indexNo = i;
    karakter = k;
}
unsigned long bookCharacter::createUniqKey() {
    return pageNo*10000 + lineNo * 100 + indexNo;

}
char &bookCharacter::getValue() {
    return karakter;
}

void bookCharacter::change_char(char k) {
    karakter=k;
}

bookCharacter::bookCharacter() {
    pageNo = 0;
    lineNo = 0;
    indexNo = 0;
    karakter = 0;
}
bookCharacter::~bookCharacter() {

}