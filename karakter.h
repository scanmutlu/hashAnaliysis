#ifndef ALGO_HOMEWORK3_KARAKTER_H
#define ALGO_HOMEWORK3_KARAKTER_H
class bookCharacter{
    int pageNo;
    int lineNo;
    int indexNo;
    char karakter;
public:
    unsigned long createUniqKey();
    bookCharacter(int p,int l,int i,char k);
    char & getValue();
    void change_char(char k);
    bookCharacter();
    ~bookCharacter();
};
#endif //ALGO_HOMEWORK3_KARAKTER_H


