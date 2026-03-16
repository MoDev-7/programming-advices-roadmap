#include <iostream>
using namespace std;
int getRandomNumber(int from, int to) {
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void fillMatrixWithRandomNumber(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = getRandomNumber(1, 10);
        }
    }
}
void printMatrix(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d ", 2, array[i][j]);
        }
        cout << endl;
    }
}
bool checkDiagonals(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        if (array[i][i] != 1)
            return false;
    }
    return true;
}
bool check(int array[3][3], short rows, short cols) {
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j) {
                if (array[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}
void checkMatrixIdentity(int array[3][3], short rows, short cols) {
    if (checkDiagonals(array, 3, 3) && check(array, 3, 3))
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main() {
    srand((unsigned)time(NULL));
    int array[3][3];
    fillMatrixWithRandomNumber(array, 3, 3);
    printMatrix(array, 3, 3);
    cout << endl;
    /*int arr[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };*/
    checkMatrixIdentity(array, 3, 3);
}