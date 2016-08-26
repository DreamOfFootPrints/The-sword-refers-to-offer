#include<iostream>
using namespace std;
#include<string >

void scanDigits(char**string)
{
	while (**string != '\0'&&**string >= '0'&&**string <= '9')
	{
		++(*string);
	}
}
bool isExponential(char **string)
{
	if (**string != 'e'&&**string != 'E')
		return false;
	++(*string);
	if ((**string == '+') || (**string == '-'))
		++(*string);
	if (**string == '\0')
		return false;
	scanDigits(string);
	return (**string == '\0') ? true : false;
}
bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	if (*string == '+' || *string == '-')
		++string;
	if (*string == '\0')
		return false;
	bool numeric = true;
	//ɨ�赽���һ���������ֵ�λ��,stringָ��ָ���λ��
	scanDigits(&string);
	if (*string != '\0')
	{
		if (*string == '.')
		{
			++string;
			scanDigits(&string);
			if (*string == 'e' || *string == 'E')
				numeric = isExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
			numeric = isExponential(&string);
		else
			numeric = false;
	}
	//cout <<numeric<<"         "<< *string << endl;
	return numeric && *string == '\0';
}