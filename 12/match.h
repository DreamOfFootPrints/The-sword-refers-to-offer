#include<iostream>
using namespace std;

/*
˼·��ֻ�е�ģʽ�����ַ���ͬʱ����\0���ſ�����Ϊ������ƥ�䡣
��ƥ���У�����ÿ��λ��ƥ����Է�Ϊ�������
1������Ӧλƥ��||ģʽ��Ϊ.&&�ַ�������\0��&&ģʽ����һλ��*
2������Ӧλƥ��||ģʽ��Ϊ.&&�ַ�������\0��&&ģʽ����һλ����*
3����Ӧλ��ƥ��&&��ģʽλ��Ϊ.||�ַ�����\0��
��Ӧ1����ӡ���Ϊ*ȡ0��*ȡ1��*>=2���������
*ȡ0��Ӧ������ǰƥ��λ������Ѱ��patter����һ��ƥ��λ��str���䣬pattern+2
*ȡ1��Ӧ��ǰƥ��λ��һ�γɹ�ƥ�䣬str+1��pattern+2
*ȡ>=2��Ӧһ�γɹ�ƥ�䣬����ƥ���ַ�������һλ�Ƿ�ƥ�䣬str+1��pattern����
����ȡ�򡣼�ֻҪ��һ�������ƥ��ɹ���Ϊ�ַ�������ƥ��ɹ��ġ�
��Ӧ2���൱��һ�γɹ�ƥ�䣬str+1��pattern+1
��Ӧ3��ƥ��ʧ�ܣ�ֱ�ӷ���false
*/
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == NULL || pattern == NULL)
			return false;
		return matchCore(str, pattern);
	}
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if (*str != '\0'&&*pattern == '\0')
			return false;
		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.'&&*str != '\0'))
				return matchCore(str + 1, pattern + 2)//ʹ��һ�� 
				|| matchCore(str + 1, pattern) //�ظ�
				|| matchCore(str, pattern + 2);//һ�ζ���ʹ��
			else
				return matchCore(str, pattern + 2);
		}
		if (*str == *pattern || (*pattern == '.'&&*str != '\0'))
			return matchCore(str + 1, pattern + 1);
		return false;
	}
};