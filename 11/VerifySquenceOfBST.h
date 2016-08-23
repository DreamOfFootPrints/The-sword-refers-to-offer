#include<iostream>
using namespace std;
#include<vector>

//
//BST�ĺ������еĺϷ������ǣ�����һ������S�����һ��Ԫ����x ��Ҳ���Ǹ��������ȥ�����һ��Ԫ�ص�����ΪT����ôT���㣺T���Էֳ����Σ�ǰһ�Σ���������
//С��x����һ�Σ�������������x���������Σ����������ǺϷ��ĺ������С������ĵݹ鶨�� : ) ��


bool Process(const vector<int>& sequence, int left, int right)
{
	if (left >= right)//�ⲽ��Ҫѧϰ
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