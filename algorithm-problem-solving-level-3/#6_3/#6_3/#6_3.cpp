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
int main() {
	int array[3][3];
	fillMatrixWithOrdderdNumbers(array, 3, 3);
	printMatrix(array, 3, 3);
}