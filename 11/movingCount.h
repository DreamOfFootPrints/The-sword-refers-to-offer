#include<iostream>
using namespace std;



int NumSum(int i)
{
	int sum = 0;
	while (i!=0)
	{
		sum += i%10;
		i /= 10;
	}
	return sum;
}


 int Process(int i, int j, int rows, int cols, int** record, int threshold) {
	if (i < 0 || i >= rows || j < 0 || j >= cols || NumSum(i) + NumSum(j)  > threshold || record[i][j] == 1) return 0;
	record[i][j] = 1;
	return Process(i - 1, j, rows, cols, record, threshold)
		+ Process(i + 1, j, rows, cols, record, threshold)
		+ Process(i, j - 1, rows, cols, record, threshold)
		+ Process(i, j + 1, rows, cols, record, threshold)
		+ 1;
}


int movingCount(int threshold, int rows, int cols) {
	int** record = new int*[rows]; //记录是否已经走过
	for (int i = 0; i < rows; i++)
		record[i] = new int[cols]();
	return Process(0, 0, rows, cols, record, threshold);
}