#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/

#include"manage_system_head.h"	 
//��ʼ������� 
int print(){
	int n;
	system("cls");	//����clrscr()
	printf("\n\n");
	printf("\t*******************************************\n");
	printf("\t*                                         *\n");
	printf("\t*                                         *\n");
	printf("\t*------Welcome To Academic System---------*\n");
	printf("\t*                                         *\n");
	printf("\t*         1.Student Management            *\n");
	printf("\t*         2.Course Management             *\n");
	printf("\t*         0.Exit Management               *\n");
	printf("\t*                                         *\n");
	printf("\t*                                         *\n");
	printf("\t*******************************************\n");	
	printf("\t\tNow please select 1,2 or 0:");
	scanf("%d", &n);
	getchar();
	return n;
}

int menu(char **m, int n){
	int i;
	int select;
	system("cls");		//clear screen
//	gotoxy(1,1); 	//move cursor
	//textcolor();	//TC only
//	gotoxy(19,2); 	//move cursor
//	putchar(0xc9);	//print ���ϽǱ߿�
//	for(i=1; i<44; i++)
//		putchar(0xcd); //����ϱ߿�ˮƽ��
//	putchar(0xbb);//������ϽǱ߿�
//	for(i=3;i<20;i++){
//		gotoxy(19,i);
//		putchar(0xba);//�����ֱ��
//		gotoxy(63,i);
//		putchar(0xba); //����Ҵ�ֱ��
//	}
//	gotoxy(19,20);
//	putchar(0xc8);// ������½Ǳ߿�
//	for(i=1;i<44;i++)
//		putchar(0xcd);//����±߿�ˮƽ��
//	putchar(0xbc);//������½Ǳ߿�
//	window(20,3,62,19);//������ʾ�˵����ڣ���С���ݲ˵��������
	system("cls");//clear screen
	for(i=0;i<n;i++){	//	������˵�����
//		gotoxy(8, i+4);
		printf("%s", m[i]);
	}
	//window(1,1,80,25);//�ָ�ԭ���ڴ�С
//	gotoxy(10,21);	//�ƶ����
	do{
		printf("\n\t\t  Enter your choice(0~%d) to continue...", n-2);
		scanf("%d", &select);
		getchar();//����ѡ����
	}while(select<0||select>n);//ѡ�����0~13֮������
	return select; //����ѡ������������ݸú���������Ӧ�ĺ���
}


