#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#include <time.h>

#define M 3	//����γ���Ŀ 
#define TIME 50 //��ʱ����

#define FORMAT "|%10d|%15s|%.2f|%.2f|%.2f|%.2f|  %d |\n"	//���ѧ����Ϣ�ĸ�ʽ 
#define DATA p->snum, p->name, p->score[0].sc, p->score[1].sc, p->score[2].sc, p->sum, p->rank
//extern int menu(int m); 
//int flag=0;
int topsort[M];
//�������飬������������Ժ�γ��������еĴ洢λ�� 

typedef struct cnode{ //����ѡ�ε��Ⱦ��������
	int num;	   	//ѡ��ǰӦ��ѧϰ�Ŀγ�˳��
	struct cnode *next;		//��һ�����
}Cnode;

FILE *result, *source, *recall;

char account[25]={0};
char password[25]={0};//��������������˻�����

char rcode[5];
//��֤���������

typedef struct{		//����γ���Ŀ
	int cnum;		//�γ̺�
	char cname[20];	//�γ�����
	int credit;		//ѧ��
//	int indegree;	//
	Cnode *first;	//ͷ���
}Cour, Course[M];	//����γ���Ŀ���ݽṹ

//Course[0]={.cnum=1,
//	.cname="��ѧ",
//	.credit=5
//}
//Course[1]={.cnum=2,
//	.cname="Ӣ��",
//	.credit=5
//}
//Course[2]={.cnum=3,
//	.cname="C����",
//	.credit=5
//}
 Cour *hg, *hc;
typedef struct{	//����ɼ����ݽṹ
	Cour *cp;	//ָ��γ̵�ָ��
	float sc;	//�ÿγ̵ĳɼ�
}Score; 		//�ɼ����ݽṹ

typedef struct snode{	//�����ʾѧ�����
	int  snum;		//ѧ��
	char name[20];		//����
	Score score[M];		//�ɼ�
	float sum;			//�ܷ�
	float average;		//ƽ����
	int rank;			//����
	struct snode *next;	//��һ������ַ
}Student; 				//ѧ���ɼ����ݽṹ��Student�൱��struct snode��  

//���ܺͽ��� 
void RandomCode(char Rcode[]); 
void encode();
void decode();/*����*/
 
//����˵� 
int menu(int m);
int print(); 

//ע��͵�¼
void register2();
void login();
 
//�ɼ�����ϵͳ
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

