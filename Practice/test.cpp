#include<stdio.h>
int main()
{
	int pos = -1;
	int flag = 1;
	char arr[1000];
	char ch;
	while (1)
	{
		ch = getchar();
		if (ch == '(')
		{
			pos++;
			arr[pos] = '(';
		}
		if (ch == '[')
		{
			pos++;
			arr[pos] = '[';
		}
		if (ch == '{')
		{
			pos++;
			arr[pos] = '{';
		}
		if (ch == ')')
		{
			if (arr[pos] == '(')
			{
				pos--;
			}
			else {
				flag = 0;
				break;
			}
		}
		
		if (ch == ']')
		{
			if (arr[pos] == '[')
			{
				pos--;
			}
			else {
				flag = 0;
				break;
			}
		}
		
		if (ch == '}')
		{
			if (arr[pos] == '{')
			{
				pos--;
			}
			else {
				flag = 0;
				break;
			}
		}
		if (ch == '@')
		{
			if (pos != -1)
			{
				flag = 0;
				break;
			}
			if (pos == -1)
			{
				break;
			}
		}
	}
	if (flag == 1)
	{
		printf("YES");
	}
	else {
		printf("NO");
	}
	
	return 0;
}