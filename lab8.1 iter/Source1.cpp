#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	if (strlen(str) < 3)
		return 0;
	int k = 0;
	int number = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == ',')
			k++;
		if (k == 3)
		{
			number = i;
			break;
		}
	}
	return number;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 3)
		return str;
	char* tmp = new char[len * 2 + 1];
	
	tmp[0] = '\0';
	size_t i = 0;
	size_t t = 0;
	
		while (i < len)
		{
			tmp[t] = str[i];
			if (str[i] == ',')
			{
				tmp[t] = '*';
				t ++;
				tmp[t] = '*';
				
			}
			i++;
			t++;
			tmp[t] = '\0';
			
		}
	
	//strcpy(str, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "The number of the third comma " << Count(str)  << endl;
	char* dest = new char[151];
	dest = Change(str);
	//cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
