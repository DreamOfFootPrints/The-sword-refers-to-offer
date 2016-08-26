#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

vector<string> vec;

void Process(string& str,int index)
{
	if (index == str.size())
		vec.push_back(str);
	{
		for (int i = index; i < str.size(); i++)
		{
			if (i != index&&str[i] == str[index])
				continue;

				std::swap(str[index], str[i]);
				Process(str, index + 1);
				std::swap(str[index], str[i]);

		}
	}
}

vector<string> Permutation(string str) 
{
	if (str.size() == 0) return vec;
	Process(str, 0);
	sort(str.begin(), str.end());
	return vec;
}

//���Ʒ��������Ǹ��ݱ��˵ĸ�д��
//class Solution{
//public:
//	vector<string> Permutation(string str) {
//		//�����õݹ�����
//		vector<string> array;
//		if (str.size() == 0)
//			return array;
//		Permutation(array, str, 0);
//		sort(array.begin(), array.end());
//		return array;
//	}
//
//	void Permutation(vector<string> &array, string str, int begin)//������beginλ�����п�����
//	{
//		if (begin == str.size() - 1)
//			array.push_back(str);
//		for (int i = begin; i <= str.size() - 1; i++)
//		{
//			if (i != begin && str[i] == str[begin])//���ظ��ַ�ʱ������
//				continue;
//			swap(str[i], str[begin]);//��i==beginʱ��ҲҪ���������������ַ���
//			//��i!=beginʱ���Ƚ�����ʹ��beginλȡ����ͬ�Ŀ����ַ����ٱ���������ַ�
//			Permutation(array, str, begin + 1);//���������������ַ���
//
//			swap(str[i], str[begin]);//Ϊ�˷�ֹ�ظ������������Ҫ��begin����Ԫ�����»�����
//
//			/*������˵��abca����Ϊʲôʹ��������swap����
//			����ʱ��a��b������������
//			����ʱ��a��c��������������ʹ��һ��swapʱ����b��c������
//			����ʱ��a��a��������
//			*/
//		}
//	}
//};
//
