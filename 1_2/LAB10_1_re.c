struct customer {
	char name[40];
	int age;
};
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
int main(void)
{
	int i;

	struct customer aCustomer = { "�ڼ���", 36 };
	struct customer* cp = &aCustomer;

	printf("Name = %s, Age = %d\n", cp->name, cp->age);

	struct customer cArray[2] = { {"�嵿��", 38}, {"��ҿ�", 38} };

	cp = cArray;
	for (i = 0; i < 2; i++) {
		printf("Name = %s, Age = %d\n", cp->name, cp->age);
		cp++;
	}
}