#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#define M 3	//����γ���Ŀ 
#define FORMAT "|%6d|%15s|%.2f|%.2f|%.2f|%.2f|%d|\n"	//���ѧ����Ϣ�ĸ�ʽ 
#define DATA p->snum, p->name, p->score[0].sc, p->score[1].sc, p->score[2].sc, p->sum, p->rank

int flag=0;
int topsort[M];
//�������飬������������Ժ�γ��������еĴ洢λ�� 

typedef struct cnode{ //����ѡ�ε��Ⱦ��������
	int num;	   	//ѡ��ǰӦ��ѧϰ�Ŀγ�˳��
	struct cnode *next;		//��һ�����
}Cnode;

typedef struct{		//����γ���Ŀ
	int cnum;		//�γ̺�
	char cname[20];	//�γ�����
	int credit;		//ѧ��
	int indegree;	//
	Cnode *first;	//�����ͷ���
}Cour;				//����γ���Ŀ���ݽṹ

typedef Cour Course[M];

typedef struct{	//����ɼ����ݽṹ
	Cour *cp;	//ָ��γ̵�ָ��
	float sc;	//�ÿγ̵ĳɼ�
}Score; 		//�ɼ����ݽṹ

typedef struct snode{	//�����ʾѧ�����
	int snum;			//ѧ��
	char name[20];		//����
	Score score[M];		//�ɼ�
	float sum;			//�ܷ�
	float average;		//	ƽ����
	int rank;			//����
	struct snode *next;	//��һ������ַ
}Student; 				//ѧ���ɼ����ݽṹ

//�γ̹���ʵ��
void init_c(Course *);	/*�γ����ݽṹ�����Լ��γ�¼���򿪣�
						����γ�ԭʼ��¼���ļ�*/
void sort_c(Course *);	/*���пγ̵��Ͽ�˳��*/
void plan_c(Course *); 	/*ÿѧ���Ͽΰ���*/

//�ɼ�����ϵͳʵ��
void input_g(Student *, Cour *);	//�ɼ�¼��
void ave_g(Student*);		//�ɼ��ܺͼ���
void sort_g(Student*); 		//�ɼ�����ͬʱ���������ļ�
void filt_g(Student*);		//�ɼ���������
void print_g(Student*);	//�ɼ����
void gotoxy(int x,int y);    //����ƶ�����

//ѧ������ϵͳ
Student *init_s();		//ѧ����¼��ʼ������һ�ν������棬Ҳ���Դ�
void manag_s();			//ѧ���ɼ�����
int sear_s(Student *);	//ѧ����¼��ѯ
Student *appe_s(Student *);//ѧ����¼���
Student *modi_s(Student*);//ѧ����¼�޸�
Student *dele_s(Student*);//ѧ����¼ɾ��
void save_s(Student *);//ѧ����¼����


//#include<stdio.h>
//#include<string.h>
//#include<windows.h>
//#include<stdlib.h>
//#include<malloc.h>
//����ƶ�����  �ο��������� 
//void gotoxy(int x,int y)   
//{
//    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
//    HANDLE    hConsoleOut;
//    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
//    csbiInfo.dwCursorPosition.X = x;
//    csbiInfo.dwCursorPosition.Y = y;
//    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
//}

