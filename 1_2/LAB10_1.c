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

	struct customer aCustomer;
	strcpy(aCustomer.name, "�ڼ���");
	aCustomer.age = 36;

	printf("Name = %s, Age = %d\n", aCustomer.name, aCustomer.age);

	struct customer cArray[2];  //�迭 ������ �� ���� �����ص� ��
	strcpy(cArray[0].name, "�嵿��");
	cArray[0].age = 38;
	strcpy(cArray[1].name, "��ҿ�");
	cArray[1].age = 38;

	for (i = 0; i < 2; i++) {
		printf("Name = %s, Age = %d\n", cArray[i].name, cArray[i].age);
	}
}