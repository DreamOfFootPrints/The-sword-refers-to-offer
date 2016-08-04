#include<iostream>
using namespace std;


void replaceSpace(char *str, int length)
{
	if (str == NULL || length == 0)
		return;
	int len = 0, nb = 0;
	char* cur = str;
	while (*cur)
	{
		len++;
		if (*cur == ' ')
			nb++;
		cur++;
	}

	int last = len + 2 * nb+1;
	if (last > length)
		cout << "short" << endl;
	int pro = len + 1;
	int j = last;
	for (int i = pro; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
		else
		{
			str[j--] = str[i];
		}
	}

}