#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#include"manage_system_head.h"
//ѧ����¼�ļ����� 
Student *init_s(){
	Student *head, *p, *last;	//���彨��ѧ����¼�Ĺ���ָ��
	Student s;
	char c; 		//�������c��Ϊѡ���Ƿ��½��ļ�����ʾ���� 
	FILE *fp;
	char fname[20];		//������ļ�����ַ�洢���ַ����� 
	int i;
	system("cls");
	printf("do you creat new file(y/n)?");
	c=getchar();
	getchar();
	if(c=='Y'||c=='y'){	//�����y�����½��ļ� 
		printf("input new student filename:");
		gets(fname);	//�����ļ���
		if((fp=fopen(fname, "wb"))==NULL){	//�ļ���ʧ��
			printf("can not open file.\n");
			return NULL;	//������������
		}
		do{	//������ѧ����Ϣ������� �������Ϊ1������¼��
			printf("input the student number:");
			scanf("%d", &s.snum);
			getchar();
			if((s.snum != -1)){		//���ѧ�Ų���-1����ô���������� 
				printf("input the name :");
				gets(s.name);
				getchar();	//get name
				for(i=0; i<M; i++){		//ͬʱ����ѧ��������Ϣ�ĳ�ʼ�� 
					s.score[i].cp=NULL;
					s.score[i].sc=0;
				}
				s.sum=0;	//�ܳɼ����
				s.rank=-1;
				s.next=NULL;
				fwrite(&s, sizeof(Student), 1, fp);	//�ѽ����ļ�¼д���ļ�
			}
			else{	//����������ʾΪ-1 ,�������� 
				break;
			}
		}while(1);
		fclose(fp);
	}
	head=(Student*)malloc(sizeof(Student));
	//��������ʼ����������ͷ���
	head->next=NULL;
	last=head;
	printf("\n open the student file, input the filename:");
	gets(fname);
	fp=fopen(fname, "rb");  //��ѧ���ļ� 
	if(fp==NULL){
		printf("\n Can not open file!\n");
		return NULL;
	}
	while(!feof(fp)){
		p=(Student *)malloc(sizeof(Student));	//�������
		if(fread(p, sizeof(Student ), 1, fp)==1){
			//һ�δ��ļ��ж�ȡһ��ѧ���ļ�¼
			p->next=NULL;	//β�巨��������
			last->next=p;
			last=p;
		}
	}
	fclose(fp);
	last->next=NULL;	//���һ�����ָΪ��
	return head;	//���ض������ݿ��ļ���ָ��
}

//ѧ����¼�ı��� 
void save_s(Student *head){
	FILE *fp;
	Student *p;
	char bname[30];
	printf("input the saving file name:");
	gets(bname);
	fp=fopen(bname, "wb");	//��ֻд��ʽ�򿪶������ļ� 
	if(fp==NULL){	//���ļ�ʧ�� 
		printf("\n open file error!\n");
		return;
	}
	p=head->next;	//��ǰ��������������д���ڴ� 
	while(p){
		fwrite(p, sizeof(Student), 1, fp);
		//ÿ��дһ����¼��һ���ڵ㵽�ļ� 
		p=p->next;
	}
	fclose(fp);
} 

//ѧ����¼��ѯ
int sear_s(Student *head){
	int select;	//1:����ѧ�Ų飬2�����������飬 ����; ���� 
	Student *p;
	int num;
	char str[30];
	int f=0;	//������¼�Ƿ��ҵ�����Ϊ�����ķ���ֵ 
	if(!head->next ){	//������Ϊ�� 
		system("cls");
		printf("\n The student don't exist!\n");
		getchar();
		return 0;
		//return NULL;
	}
	system("cls");
	printf("\n  1.Search by student number  2.Search by student name  \n");
	printf("   Please choose [1,2]  ");
	scanf("%d", &select);
	getchar();
	switch(select){
		case 1:
			printf("input the student number:");
			scanf("%d", &num);
			p=head->next;
			while(p){
				if(p->snum == num){	//���ҵ������ѧ�ŵ�ַ 
					printf("\n");
					printf(FORMAT, DATA);	//�����Ϣ 
					getchar();
					f=1;	//�������� ��������¼�Ƿ��ҵ� 
					break;
				}
				p=p->next;
			}
			getchar();
			break;	//����case ��֧ 
		case 2:
			printf("input the student name:");
			gets(str);
			p=head->next;
			while(p){
				if(strcmp(p->name, str) == 0){	//�����Ƚ� 
					f=1;	//���ı�־ 
					printf(FORMAT, DATA);
				}
				p=p->next;
			}
			break;
	}
	getchar();
	return f;
} 

//ѧ����¼��׷�ӣ����жϣ������ 

//�򵥲�ѯ�����ļ����Ƿ���numѧ����ͬ�ļ�¼ 
int check(Student *head, int num){	
	Student *p;
	p=head->next;
	while(p&&p->snum != num)	//�����㲻�գ����αȽ����� 
		p=p->next;	//ָ����� 
	if(p)
		return 1;
	else 
		return 0;
} 

//ѧ����¼��� 
Student *appe_s(Student *head){
	Student *p, *r;	//ʵ����Ӳ�������ʱ�ṹ��ָ����� 
	int num;
	float x1, x2, x3;
	system("cls");
	r=head;
	while(r->next!=NULL){
		r=r->next;	//��ָ���Ƶ�����ĩβ��׼����Ӽ�¼ 
	}
	while(1){
		/*һ�ο������������¼��ֱ������ѧ��Ϊ-1ʱ�������¼�����Ӳ�����
		����ѧ�ţ���֤��ѧ��δ��ʹ�ã���ѧ��Ϊ-1�����˳���Ӽ�¼����		
		*/ 
		printf("input the student num(input -1 to finish):");
		p=(Student *) malloc(sizeof(Student));
		scanf("%d", &p->snum);
		getchar();
		
		while(check(head, p->snum)&& p->snum != -1){
			//ѧ�Ų�����ͬʱѧ�Ų�Ϊ�գ�������ѯ
			printf("input the student num:");
			scanf("%d", &p->snum);
			getchar() ;
		}
		
		if(p->snum==-1){	//����Ϊ-1�����˳���� 
			printf("the insert is over, press any key ...\n");
			scanf("%d", &p->snum );
			getchar();
		}
		else{	//������ 
			printf("input the student name:");
			gets(p->name);
			printf("input the first term score:");
			scanf("%f%f%f", &x1, &x2, &x3);
			p->score[0].sc=x1;	//��������Ϣ 
			p->score[1].sc=x2;
			p->score[2].sc=x3;
			p->sum=x1+x2+x3;
			p->next=NULL;
			r->next=p;		//���뵥������ 
			r=p; 
		}
	}
	flag=1;		//���ı�� 
	system("cls");
	print_g(head);	//��� 
	save_s(head);
	return head;
}

Student *dele_s(Student *head){
	int select;
	Student *p, *r;
	char str[30];
	int num;
	if(head->next){		//��������޷��� 
		system("cls");
		printf("\n No student record!\n");
		return NULL;
	}
	system("cls");
	printf("\n   1. Delete by number   2. Delete by name\n");
	printf("     please choose [1, 2]:");
	scanf("%d", &select);
	if(select==1){	//����ѧ�Ų��� 
		printf("input the student num:");
		scanf("%d", &num);
		r = head;
		p = head->next;		//rΪ�м����������ͷ��� 
		while(p && p->snum!=num){
			r=p;
			p=p->next;
		} 
		
		if(p){
			r->next=p->next;
			flag=1;
			free(p);
			printf("\n delete success!\n");
			getchar();
		}
		else{
			printf("\n Cannot find!\n");
			getchar();
		}
	}
	else if(select==2){		//�Ȱ�������ѯ���ü�¼
		printf("input the student name:");
		gets(str);	//����������Ϣ 
		r=head;
		p=head->next;	//���ҳ�ʼ�� 
		while(p&&strcmp(p->name, str)!=0){		 //ѭ���Ƚϲ��Ҽ�¼ 
			r=p;		//�������ַ 
			p=p->next;	//���ָ����� 
		}
		if(p){
			r->next=p->next;	//��p��ָ����������ȥ�� 
			flag=1;
			free(p);	//�ͷ��ڴ�ռ� 
			printf("\n delete success!\n");
			getchar();	
		}
		else
		printf("\n Cannot find.\n");
	}
	print_g(head);	//����޸���Ϣ 
	getchar();
	return head; 
} 

//ѧ����¼�޸�
Student *modi_s(Student *head){
	Student *p;
	float num;
	float x1, x2, x3;
	system("cls");
	printf("modify student recorder...\n");
	printf("input the student number that you want to modify:\n");
	scanf("%d", &num);
	getchar();
	p=head->next;
	while(p && p->snum!=num){	//�����Ƿ���� 
		p=p->next;
	} 
	if(p){		//��p��=NULL�����Ѿ��ҵ���� 
		printf("input the student name:");
		gets(p->name);
		printf("input the first term score:");
		scanf("%f%f%f", x1, x2, x3);
		p->score[0].sc=x1;
		p->score[2].sc=x2;
		p->score[2].sc=x3;
		p->sum=x1+x2+x3;
		print_g(head);		//�޸ĺ����Ϣ��ʾ 
		flag=1;		//�ı��¼�����ı�� 
		getchar(); 
	}
	else{
		printf("Cannot find record!\n");
		getchar();
	}
} 

