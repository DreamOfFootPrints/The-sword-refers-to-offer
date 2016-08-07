#include<iostream>
using namespace std;
#include<vector>


vector<int> multiply(const vector<int>& A) 
{
	int size = A.size();
	vector<int> res;
	res.resize(size);
	res[0] = 1;
	for (int i = 1; i < size; i++)
	{
		res[i] = res[i - 1] * A[i-1];
	}
	int tmp = 1;
	for (int i = size - 2; i >= 0; i--)
	{
		tmp *= A[i + 1];
		res[i] *= tmp;
	}

	return res;
}