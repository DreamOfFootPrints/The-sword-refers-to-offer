#include<iostream>
using namespace std;
#include<vector>

//
//BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）
//小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。完美的递归定义 : ) 。


bool Process(const vector<int>& sequence, int left, int right)
{
	if (left >= right)//这步需要学习
		return true;

	int index = left;
	int tmp = 0;;
	while (index < right&&sequence[index] < sequence[right])
		index++;
	while (index<right&&sequence[index]>sequence[right])
		index++;
	tmp = index;
	if (index < right) return false;
	return Process(sequence, left, tmp - 1) && Process(sequence, tmp ,right-1);
}


bool VerifySquenceOfBST(vector<int> sequence) 
{
	int size = sequence.size();
	if (size == 0)
		return false;
	return Process(sequence, 0, size - 1);

}