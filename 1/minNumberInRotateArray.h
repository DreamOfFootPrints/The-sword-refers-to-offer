#include<iostream>
using namespace std;
#include<vector>

int minNumberInRotateArray(vector<int> rotateArray)
{
	if (rotateArray.empty())
		return 0;

	int left = 0;
	int right = rotateArray.size() - 1;
	while (left<right)
	{
		if (right - left == 1)
			break;
		int mid = (right&left) + (right | left) >> 1;
		if ((rotateArray[left] == rotateArray[mid]) && (rotateArray[mid] == rotateArray[right]))
		{
			while (left < mid)
			{
				if (rotateArray[left] < rotateArray[mid])
				{
					return rotateArray[left];
				}
				else if (rotateArray[left] < rotateArray[mid])
				{
					left = mid;
					break;
				}
				else
				{
					left++;
				}
			}
		}

		if (rotateArray[left] <= rotateArray[mid])//这个地方是有玄机的
		{
			left = mid;
		}
		else if (rotateArray[right]>=rotateArray[mid])
		{
			right = mid;
		}

	}
	return rotateArray[left] < rotateArray[right] ? rotateArray[left] : rotateArray[right];
}