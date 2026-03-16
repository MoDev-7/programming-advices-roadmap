#include <iostream>
using namespace std;
short numberOfDigits(int number) {
    short count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}
short firstDigit(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return (short)number;
}
string readTwoDigits(int number, string zeroToNine[], string tenToNineteen[], string tenToNinety[]) {
    string text = "";
    short digits = numberOfDigits(number);
    if (number == 0)
        return text;
    else if (digits == 1)
        text += zeroToNine[number] + " ";
    else {
        short digit1 = firstDigit(number), digit2 = number - (digit1 * 10);
        if (number <= 19) {
            text += tenToNineteen[digit2] + " ";
        }
        else {
            if (digit2 == 0) {
                text += tenToNinety[digit1] + " ";
            }
            else {
                text += tenToNinety[digit1] + " " + zeroToNine[digit2] + " ";
            }
        }
    }
    return text;
}
string readThreeDigit(int number, string zeroToNine[], string tenToNineteen[], string tenToNinety[]) {
    short digits = numberOfDigits(number);
    string text = "";
    if (number == 0)
        return text;
    switch (digits) {
    case 1:
        return readTwoDigits(number, zeroToNine, tenToNineteen, tenToNinety);
    case 2:
        return readTwoDigits(number, zeroToNine, tenToNineteen, tenToNinety);
    case 3: {
        short digit1 = firstDigit(number);
        text += zeroToNine[digit1] + " hundred ";
        number -= digit1 * 100;
        text += readTwoDigits(number, zeroToNine, tenToNineteen, tenToNinety);
    }
    }
    return text;
}
string readNumber(int number, string zeroToNine[], string tenToNineteen[], string tenToNinety[], string ThousandsToMillions[]) {
    string text = "";
    int arrayOfThreeDigits[3];
    for (short i = 0; i < 3; i++)
    {
        arrayOfThreeDigits[i] = number % 1000;
        number /= 1000;
    }
    for (short i = 2; i >= 0; i--)
    {
        if (arrayOfThreeDigits[i] != 0)
            text += readThreeDigit(arrayOfThreeDigits[i], zeroToNine, tenToNineteen, tenToNinety) + ThousandsToMillions[i] + " and ";
    }
    return text.erase(text.length() - 5, text.length());
}
int main()
{
    string zeroToNine[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string tenToNineteen[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string tenToNinety[] = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string ThousandsToMillions[] = { "", "thousands", "millions" };
    int number;
    cin >> number;
    cout << readNumber(number, zeroToNine, tenToNineteen, tenToNinety, ThousandsToMillions) << endl;
}
