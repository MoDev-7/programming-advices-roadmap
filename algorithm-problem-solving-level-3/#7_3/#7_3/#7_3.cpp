#include <iostream>
using namespace std;
void fillMatrixWithOrdderdNumbers(int array[3][3], short rows, short cols) {
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			count++;
			array[i][j] = count;
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
void transposeMatrix(int array[3][3], int sposedArray[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sposedArray[i][j] = array[j][i];
		}
	}
}
int main() {
	int array[3][3];
	int sposedArray[3][3];
	fillMatrixWithOrdderdNumbers(array, 3, 3);
	printMatrix(array, 3, 3);
	transposeMatrix(array, sposedArray, 3, 3);
	printMatrix(sposedArray, 3, 3);
}