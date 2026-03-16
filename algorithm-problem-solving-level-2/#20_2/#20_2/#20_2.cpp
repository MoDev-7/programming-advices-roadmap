#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
enum characterType { smallLetter = 1, capitalLetter = 2, specialCharacter = 3, digit = 4 };
int randomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
char randomCharacter(characterType charType) {
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
int main()
{
    srand((unsigned)time(NULL));
    cout << randomCharacter(characterType::smallLetter) << endl;
    cout << randomCharacter(characterType::capitalLetter) << endl;
    cout << randomCharacter(characterType::specialCharacter) << endl;
    cout << randomCharacter(characterType::digit) << endl;
}
