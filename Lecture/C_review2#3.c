#include <stdio.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index)
{
	char tmp[8];
	strcpy(tmp, arr + index);
	arr[index] = ch;
	strcpy(arr + index + 1, tmp);
}

int Convertor(char x)
{
	int tmp = 0;
	tmp = x - 48;
	return tmp;
}

int main()
{
	char str[16];
	char ch;
	int i, len;
	scanf("%s", str);

	len = strlen(str);

	for (i = 0; i < len-1; i++)
	{
		if (Convertor(str[i]) % 2 == 1 && Convertor(str[i + 1]) % 2 == 1)
		{
			ch = '+';
			StringAdd(str, ch, i + 1);
			i++;
			len++;
		}
		else if (Convertor(str[i]) % 2 == 0 && Convertor(str[i + 1]) % 2 == 0)
		{
			ch = '*';
			StringAdd(str, ch, i + 1);
			i++;
			len++;
		}
	}
	printf("%s", str);
	

	return 0;
}
