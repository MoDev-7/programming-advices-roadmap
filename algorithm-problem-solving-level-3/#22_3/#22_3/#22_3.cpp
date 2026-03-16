#include <iostream>
using namespace std;
void printFibonacciUsingRecurssion(int number, int x0, int x) {
    int fibonacci = 0;
    if (number > 0) {
        fibonacci = x + x0;
        x0 = x;
        x = fibonacci;
        cout << fibonacci << " ";
        printFibonacciUsingLoop(number - 1, x0, x);
    }
}
int main() {
    printFibonacciUsingLoop(10, 1, 0);
}