#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* My_strcpy(char* dest, const char* src);
void menu();
//int main(void)
//{
//	char* (*pf)(char*, const char*) = My_strcpy;//����ָ�룬ָ��My_strcpy
//	char* (*pfArr[4])(char*, const char*) = { My_strcpy ,My_strcpy ,My_strcpy ,My_strcpy };//����ָ�����飬������4��Ԫ�أ��ܴ��4��My_strcpy�����ĵ�ַ
//	char arr1[10] = { "abcd" };
//	char arr2[10] = { "efj" };
//	//My_strcpy(arr1, arr2);//����
//	//(*pf)(arr1, arr2);//����ָ��
//	(*(pfArr+2))(arr1, arr2);
//	printf("%s", arr1);
//
//	return 0;
//}
char* My_strcpy(char* dest, const char* src)
{
	char* p = dest;
	while (*dest!='\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return p;
}
//������
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}
//int main(void)
//{
//	int input=0;
//	int x=0, y=0;
//	do
//	{
//		menu();
//		printf("Please select:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 0: printf("exit"); break;
//		case 1:
//			printf("Please entey x and y>");//��������������
//			scanf("%d%d", &x, &y);
//			printf("%d\n",Add(x,y)); break;
//		case 2:
//			printf("Please entey x and y>");//��������������
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y)); break;
//		case 3:
//			printf("Please entey x and y>");//��������������
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y)); break;
//		case 4:
//			printf("Please entey x and y>");//��������������
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y)); break;
//		default:
//			printf("Enter error."); break;
//		}
//	} while (input);
//	return 0;
//}
int main(void)//,ת�Ʊ��ú���ָ�����飬�ɷ�����ӹ��ܵ�
{
	int input = 0;
	int x = 0, y = 0;
	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div,Xor };//С���0��ʼ
	do
	{
		menu();
		printf("Please select:");
		scanf("%d", &input);
		if (input >= 1 && input <= 5)
		{
			printf("Please enter x and y:>");
			scanf("%d%d", &x, &y);
			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("Quit!\n");//�˴�����break����input=0���򲻻�ͨ��while���
		}
		else
		{
			printf("Please error!\n");
		}
	} while (input);
	return 0; 
}
void menu()
{
	printf("**********************************\n");
	printf("***** 1.add   2.sub  *************\n");
	printf("***** 3.mul   4.div  *************\n");
	printf("******5.xor   0.exit *************\n");
}