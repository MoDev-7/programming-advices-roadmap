#include <iostream>
#include <string>
#include <cstdlib>

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
string fourCapitalLetter() {
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
void fillArray(string array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = generate1Key();
    }
}
void printArray(string array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
    {
        cout <<"array [" << i << "] = " << array[i] << endl;
    }
    cout << endl;
}


int main()
{
    string array[100];
    int arrayLength = readNum("enter array length");
    srand((unsigned)time(NULL));
    fillArray(array, arrayLength);
    printArray(array, arrayLength);
}
