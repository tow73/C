#include <stdio.h>
#include <conio.h> //문자처리 함수 사용을 위해
void main()
{
	char c;
	printf("Enter characters(^Z for exit):\n");
	while ((c = fgetc(stdin)) != EOF)
	{
		if (isupper(c))
			fputc(tolower(c), stdout);
		else
			fputc(toupper(c), stdout);
	}
}