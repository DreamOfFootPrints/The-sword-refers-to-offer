#include<iostream>
using namespace std;
#include<vector>
void _PrintEdge(vector<vector<int> > matrix, vector<int>& res, int tR, int tC, int dR, int dC)
{
	if (tR == dR)//一定时候一行和一列的特殊情况
	{
		for (int j = tC; j <= dC; j++)
			res.push_back(matrix[tR][j]);
	}
	else if (tC == dC)
	{
		for (int i = tR; i <= dR; i++)
			res.push_back(matrix[i][tC]);
	}
	else
	{
		for (int j = tC; j < dC; j++)
			res.push_back(matrix[tR][j]);

		for (int i = tR; i < dR; i++)
			res.push_back(matrix[i][dC]);

		for (int j = dC; j > tC; j--)
			res.push_back(matrix[dR][j]);

		for (int i = dR; i > tR; i--)
			res.push_back(matrix[i][tC]);
	}

}

vector<int> printMatrix(vector<vector<int> > matrix)
{
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> res;

	if (rows == 0 && cols == 0)
		return res;
	int tR = 0, tC = 0;
	int dR = rows - 1, dC = cols - 1;
	while (tR <= dR&&tC <= dC)//这个地方一定是两个判断条件
	{
		_PrintEdge(matrix, res, tR, tC, dR, dC);
		tR++, tC++, dR--, dC--;
	}
	return res;

}
//
//
//void _PrintEdge(vector<vector<int> > matrix, vector<int>& res, int tR, int tC, int dR, int dC)
//{
//	
//	for (int j = tC; j < dC; j++)
//	{
//		res.push_back(matrix[tR][j]);
//		cout << matrix[tR][j] << " ";
//	}
//
//	for (int i = tR; i < dR; i++)
//	{
//		res.push_back(matrix[i][dC]);
//		cout << matrix[i][dC] << " ";
//	}
//
//	for (int j = tC; j > tC; j--)
//	{
//		res.push_back(matrix[dR][j]);
//		cout << matrix[dR][j];
//	}
//
//	for (int i = dR; i > tR; i--)
//	{
//		res.push_back(matrix[i][tR]);
//		cout << matrix[i][tC];
//	}
//}
//
//vector<int> printMatrix(vector<vector<int> > matrix)
//{
//	int rows = matrix.size();
//	int cols = matrix[0].size();
//	vector<int> res;
//
//	if (rows == 0 && cols == 0)
//		return res;
//	int tR = 0, tC = 0;
//	int dR = rows - 1, dC = cols - 1;
//	while (tR <= dR)
//	{
//		_PrintEdge(matrix, res, tR, tC, dR, dC);
//		tR++, tC++, dR--, dC--;
//	}
//	return res;
//
//}
//
//
//
