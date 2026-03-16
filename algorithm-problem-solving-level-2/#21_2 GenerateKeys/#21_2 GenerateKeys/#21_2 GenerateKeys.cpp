#include <iostream>
#include <string>
#include <cstdlib>
#include "m.h"

using namespace std;

enum characterType { smallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4 };

int readNum(string massege)
{

    cout << massege << endl;
    int num;
    cin >> num;
    return num;

}

int randomNumber(int from, int to) 
{

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
    
}

char randomCharacter(characterType charType) 
{

    switch (charType) {
    case characterType::smallLetter:
        return char(randomNumber(97, 122));
    case characterType::capitalLetter:
        return char(randomNumber(65, 90));
    case characterType::specialCharacter:
        return char(randomNumber(33, 47));
    case characterType::digit:
        return char(randomNumber(48, 57));
    }
}
string fourCapitalLetter(){
    string word = "";
    word += randomCharacter(characterType::capitalLetter);
    word += randomCharacter(characterType::capitalLetter);
    word += randomCharacter(characterType::capitalLetter);
    word += randomCharacter(characterType::capitalLetter);
    return word;
}
string generate1Key() {
    string key = fourCapitalLetter() + "-" + fourCapitalLetter() + "-" + fourCapitalLetter() + "-" + fourCapitalLetter();
    return key;

}
void printKeys(int num) {
    for (int i = 0; i < num; i++)
    {
       cout << "key[" << i+1 << "] : " << generate1Key() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    call::print();
    printKeys(readNum("enter number of keys"));
}
