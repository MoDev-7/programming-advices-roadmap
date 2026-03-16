#include <iostream>
using namespace std;
void printFibonacciUsingLoop(int number) {
    cout << "1 ";
    int fibonacci = 0;
    int x = 1, x0 = 0;
    for (int i = 0; i < number - 2; i++)
    {
        fibonacci = x + x0;
        x0 = x;
        x = fibonacci;
        cout << fibonacci << " ";
    }
}
int main() {
    printFibonacciUsingLoop(10);
}