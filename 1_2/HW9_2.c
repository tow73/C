#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char id[15];
	char start[3];
	int s, year;
	char *first, *second;
	char se[2];

	printf("주민등록번호 입력('-' 포함): ");
	gets(id);

	strncpy(start, id, 2);
	start[2] = '\0';
	s = atoi(start);

	if (s < 10)
		printf("당신은 190%d년도 생이군요\n", s);
	else
		printf("당신은 19%d년도 생이군요\n", s);


	year = 1900 + atoi(start);
	first = strtok(id, "-");
	second = strtok(NULL, " ");
	strncpy(se, second, 1);
	se[1] = '\0';
	
	if (se[0] == '1') {   //그냥 id[7] == '1' 이런 식으로 써도 됨
		printf("남자분이시군요\n");
		printf("평균 수명 77을 더하면 %d까지 산다고 계산됩니다.", year + 77);
	}
	else {
		printf("여자분이시군요\n");
		printf("평균 수명 84를 더하면 %d까지 산다고 계산됩니다.", year + 84);
	}

	return 0;
}