#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ͼ��ṹ��
struct Book{		//ͼ��Ľṹ��
	char isbn[10];	//ͼ��ı��
	char name[20];	//ͼ�������
	int type;		//ͼ������� 1.����� 2.С˵�� 3.��־��
	int exist;		//ͼ���Ƿ񱻽��
}g_books[1000];

int g_count;	//��ǰͼ�������

//��ʾ�˵���������ѡ��Ĳ˵���
int ShowMenu()
{
	int num;
	system("cls");
	printf("--------------------ͼ���-----------------------\n");
	printf("\t\t1.���ͼ��\n");
	printf("\t\t2.�鿴ͼ��\n");
	printf("\t\t3.����ͼ��\n");
	printf("\t\t4.�黹ͼ��\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("--------------------��ѡ��-----------------------\n");
	while(scanf("%d", &num) != 1 || num < 0 || num > 4)
	{
		printf("��ѡ��Ĳ˵����󣡰����������ѡ��\n");
		system("pause");
		fflush(stdin);//������뻺����
	}
	return num;
}

//���ͼ��
void AddBook()
{
	printf("������ͼ��ı�ţ�");
	scanf(" %s", g_books[g_count].isbn);
	printf("������ͼ������֣�");
	scanf(" %s", g_books[g_count].name);
	printf("������ͼ������ͣ�1~3����");
	while(scanf("%d", &g_books[g_count].type) != 1
		|| g_books[g_count].type < 1 || g_books[g_count].type > 3)
	{
		printf("�Բ����������ͼ�����Ͳ���ȷ�����������룺");
		fflush(stdin);
	}
	g_books[g_count].exist = 1;
	++g_count;//��ͼ�����������һ��
	printf("ͼ����ӳɹ���\n");
}

//�鿴ͼ��
void ShowBooks()
{
	int i;
	printf("\n��ͼ�����������ͼ�鹩����ġ�\n");
	for(i = 0; i < g_count; ++i)
	{
		printf("ͼ���ţ�%-10s, ͼ�����֣�%-20s, ͼ�����ͣ�%d\n", 
			g_books[i].isbn, g_books[i].name, g_books[i].type);
	}
}

int main()
{
	int quit = 0;
	while(quit == 0)
	{
		switch(ShowMenu())
		{
			case 0:
			quit = 1;
			break;
			case 1:
//			printf("���ͼ�飡\n");
			AddBook();
			break;
			case 2:
//			printf("�鿴ͼ�飡\n");
			ShowBooks();
			break;
			case 3:
			printf("����ͼ�飡\n");
			break;
			case 4:
			printf("�黹ͼ��!\n");
			break;
		}
		system("pause");
	}
	
	return 0;
}
