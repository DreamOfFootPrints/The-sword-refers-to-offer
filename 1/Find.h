#include<iostream>
using namespace std;
#include<vector>

bool Find(vector<vector<int> > array, int target) 
{
	int rows = array.size();
	int cols = array[1].size();
	int i = 0, j = cols - 1;
	while((i < rows) && (j >= 0))
	{
		if (array[i][j] == target)
		{
			return true;
		}
		else if (array[i][j] < target)
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return false;
}


