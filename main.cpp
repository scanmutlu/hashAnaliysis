#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "dictionary.h"
#include "list.h"

using namespace std;
void writetofile(vector<bookCharacter> temp);

void writetofile(bookCharacter **table);
int main() {
    ifstream file("ds-set-input.txt");
    clock_t beginClk, endClk;
    clock_t listbegin, listend;
    double elapsedTime;
    double listTime;
    dict dict1(131071);
    bookList bookList1;
    vector<bookCharacter> lookupforList;
    int collision = 0;
    int counter = 0;
    double avarage;
    string line;


    /*Insertion Block-----------------------------------------------------------------------------------------*/
    while (getline(file,line))
    {

        string temp;

        int page,lineNo,index;
        string tempStr;
        char character;
        istringstream isStream(line);
        getline(isStream,temp,'\t');
        istringstream pageStr(temp);
        pageStr>>page;
        temp="";
        getline(isStream,temp,'\t');
        istringstream lineStr(temp);
        lineStr>>lineNo;
        temp="";
        getline(isStream,temp,'\t');
        istringstream indexStr(temp);
        indexStr>>index;
        temp="";
        getline(isStream,temp,'\n');
        character = temp.at(0);
        temp="";
        bookCharacter *tempBook = new bookCharacter(page,lineNo,index,character);

        //-----Insertion to list-------------
        listbegin = clock();
        bookList1.addtoList(*tempBook);
        listend = clock();
        listTime += double (listend-listbegin)/CLOCKS_PER_SEC;

        //-----Insertion to Dictionary-----------
        beginClk = clock();
        collision = dict1.insertion(tempBook);
        endClk = clock();
        elapsedTime += double (endClk-beginClk)/CLOCKS_PER_SEC;


        avarage += collision;
        if(counter == 1000) {
            cout << "Average number of collision(first 1,000) : ";
            cout << avarage / counter << endl;
        }
        if(counter == 10000) {
            cout << "Average number of collision(first 10,000) : ";
            cout << avarage / counter << endl;
        }
        if(counter == 100000) {
            cout << "Average number of collision(first 100,000) : ";
            cout << avarage / counter << endl;
        }
        counter++;
    }
    cout << "Average number of collision(overall) : ";
    cout << avarage / counter << endl;
    cout<< "(List) Insertion fnished afterI: ";
    cout<<listTime<< endl;
    cout<< "(Dictionary) Insertion fnished after: ";
    cout<<elapsedTime<<endl;





/* Lookup Block --------------------------------------------------------------------------------*/
    ifstream lookupFile("ds-set-lookup.txt");
    bookCharacter **lookupTable = new bookCharacter*[131071];
    counter = 0;
    elapsedTime = 0;
    while (getline(lookupFile,line))
    {
        string temp;
        int page,lineNo,index;
        string tempStr;
        char character;
        istringstream isStream(line);
        getline(isStream,temp,'\t');
        istringstream pageStr(temp);
        pageStr>>page;
        temp="";
        getline(isStream,temp,'\t');
        istringstream lineStr(temp);
        lineStr>>lineNo;
        temp="";
        getline(isStream,temp);
        istringstream indexStr(temp);
        indexStr>>index;
        temp="";
        character = ' ';
        bookCharacter *tempBook = new bookCharacter(page,lineNo,index,character);

        lookupTable[counter] = tempBook;
        lookupforList.push_back(*tempBook);
        //List Lookup ---------------------------------------------
        listbegin = clock();
        lookupforList[counter].change_char(bookList1.findValuebyKey(lookupforList[counter].createUniqKey()));
        listend = clock();
        //cout << lookupforList[counter].getValue();
        listTime += double (listend-listbegin)/CLOCKS_PER_SEC;


        //Dictionary Lookup-----------------------------------------
        beginClk = clock();
        lookupTable[counter]->change_char(dict1.lookup(lookupTable[counter]->createUniqKey()));
        endClk = clock();
        elapsedTime += double (endClk-beginClk)/CLOCKS_PER_SEC;
        //cout << lookupTable[counter]->getValue();
        counter++;
    }
    writetofile(lookupforList);
    writetofile(lookupTable);
    cout << "(List) Lookup fnished after : ";
    cout << listTime <<"seconds" << endl;
    cout << "(Dictionary) Lookup fnished after: ";
    cout<<elapsedTime << "seconds" << endl;

    return 0;
}

void writetofile(vector<bookCharacter> temp) {
    ofstream outfile;
    outfile.open("ds-set-list-output.txt");
    int size = temp.size();
    for (int i = 0; i < size; i++){
        outfile << i << '\t';
        outfile << temp[i].createUniqKey() << '\t';
        outfile << temp[i].getValue() << '\n';
    }
}

void writetofile(bookCharacter **temp) {
    ofstream outfile;
    outfile.open("ds-set-dict-output.txt");
    int size = 130868;
    for (int i = 0; i < size; i++){
        outfile << i << '\t';
        outfile << temp[i]->createUniqKey() << '\t';
        outfile << temp[i]->getValue() << '\n';
    }
}
