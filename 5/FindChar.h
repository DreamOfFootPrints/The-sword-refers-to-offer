#include<iostream>
using namespace std;
#include<string.h>

bool FindChar(char* pInputString, char* pChar)
{
	if (pInputString == NULL)
		return false;

	int size = strlen(pInputString);
	int map[256] = { 0 };
	for (int i = 0; i < size; i++)
		map[pInputString[i]]++;
	for (int i = 0; i < size; i++)
	{
		if (map[pInputString[i]] == 1)
		{
			*pChar = pInputString[i];
			return true;
		}
	}
	*pChar = '.';
	return false;
}


int main()
{
	char str[1024] = { 0 };
	char ret = 0;
	while (scanf("%s", str) != EOF)//这样可以循环输入，scanf的用法值得研究
	{
		if (FindChar(str, &ret))
			cout << ret << endl;//printf("%s\n",ret);
	}
	return 0;
}