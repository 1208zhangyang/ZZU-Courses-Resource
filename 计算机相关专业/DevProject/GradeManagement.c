#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#include"manage_system_head.h"

//�ɼ�����ϵͳʵ��
void input_g(Student *head , Cour *hg){ // �ɼ�¼�� 
	Student *p;
	float x1, x2, x3;
	p=head->next;	//ָ����Ԫ���
	system("cls");
	while(p){
		printf("input the first term score:");
		scanf("%f%f%f", &x1, &x2, &x3);  //¼��ÿ��ѧ����ѧ�ڳɼ�
		p->score[0].sc=x1;
		p->score[1].sc=x2;
		p->score[2].sc=x3;
		p->sum=x1+x2+x3;	//����ɼ��� 
		p->score[0].cp=hg;	//�ÿγ̵Ŀγ���Ϣ 
		p->score[0].cp=hg+1;
		p->score[0].cp=hg+2;
		p=p->next;		//ָ����� 
	} 
	save_s(head);
	getchar(); 
} 

//����ÿһ��Ŀ��ƽ���ɼ�
void ave_g(Student *head){	 
	Student *p, *q;	
	int i, n=0;		//�������nͳ��ÿ�ſγ̲ο������� 
	float sa=0;		//�������sa����γ̵�ƽ��ֵ 
	system("cls");
	q=head->next;	//�趨ָ���������������ĳ�����ĵ�ַ���Է��ʿγ���Ϣ 
	for(i=0; i<M; i++){	//����M�ſγ� 
		sa=0;	//ÿһ�ſγ̼���ǰ������ʼ�� 
		n=0;	 
		p=head->next;	//pָ����Ԫ���
		while(p){		//����ÿ��ѧ���ĸ��ſγ�  
			n++;	//ͳ�� 
			sa+=p->score[i].sc;	//�γ�ֵ�ۼ� 
			p=p->next;
		}
		sa=sa/n;	//����ƽ��ֵ 
		printf("%6s average %.2f\n", q->score[i].cp->cname, sa);
		//����γ�ƽ��ֵ �����б��ʽq->score[i].cp->cname�� q->score[i]���ʳɼ��������е�i ��Ԫ�أ�
		//�� q->score[i].cp����ʳɼ���¼�е�ָ����q->score[i].cp->cname ���ʶ����е�cname��Ա��Ϣ�� 
	}
	getchar();
}

//�ɼ����� 
void sort_g(Student *head){
	Student *p, *q, *r, *u;	//��������Ĺ���ָ�� 
	int re = 1;		//���������ʾ���μ��� 
	p=head->next ;	//ָ����Ԫ��� 
	head->next=NULL;	//�ÿ����� 
	while(p){	//��������δ��β��pΪ����ָ�� 
		r=head;	//����ͷ����ַ 
		q=head->next;
		while(q&&q->sum >= p->sum){	//��p��������� 
			r=q;
			q=q->next;
		}
		u=p->next;
		p->next=r->next;	//��p������������ 
		r->next=p;	//r��q��ǰ׺�� u���¸����������ָ�� 
		p=u;
	}
	p=head->next;	//ָ����Ԫ��� 
	while(p){	//���������е�ÿ����� 
		p->rank=re++;	//����ѧ����¼������ 
		p=p->next;
	}
	print_g(head);		//�����Ϣ 
	flag=1;
	save_s(head);
	getchar();
}

//����ͳ�Ƴɼ��ֲ���� 
//��ͳ�Ƶĸ�����������Ƴɺ��������ò˵������������ 
void class_1(Student *h){	//���ڵ���80�ֵļ�¼ 
	Student *p;	//���幤��ָ�� 
	int i;
	p=h->next;	//ָ����Ԫ��� 
	system("cls");
	printf("|--nubmber--|--name--|----subject----|----score----|\n");
	//�������ͷ
	 
	while(p!=NULL){	//�����ʲ�Ϊ�� 
		for(i=0; i<M; i++){	//����ÿһ��ѧ��ÿ�ſεĳɼ� 
			if(p->score[i].sc>=80){	//�ɼ����ڵ���80 
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼ 
		}
		printf("\n\npress any key ...");
		getchar();
	}
}

void class_2(Student *h){
	Student *p;
	int i;
	p=h->next;
	system("cls");
	printf("|--nubmber--|--name--|----subject----|----score----|\n");
	while(p!=NULL){
		for(i=0; i<M; i++){
			if(p->score[i].sc>=60&&p->score[i].sc<=79){
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼
		}
		printf("\n\npress any key ...");
		getchar();
	}
}

void class_3(Student *h){
	Student *p;
	int i;
	p=h->next;
	system("cls");
	printf("|--nubmber--|--name--|----subject----|----score----|\n");
	while(p!=NULL){
		for(i=0; i<M; i++){
			if(p->score[i].sc<60){
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼
		}
		printf("\n\npress any key ...");
		getchar();
	}
} 

//�ɼ��������� 
void filt_g(Student *head){
	int select;
	char *m[5]={
		"*********** Display **********",	//����˵��ַ������� 
		"1. .....80<= Record <= 100....",
		"2. .....60<= Record <  80.....",
		"3. .....No pass...............",
		"0. .....return................"};
	while(1){	//�������ɸѡ���� 
		system("cls");
		select=menu(m, 5);	//���÷���ɸѡ�˵� 
		if(select==0)
			break;
		switch(select){	//�����Ӳ˵����� 
			case 1:class_1(head); break;
			case 2:class_2(head); break;
			case 3:class_3(head); break; 
		}
	}
}

//�ɼ���� 
void print_g(Student *head){
	Student *p;
	system("cls");
	p=head->next;	//ָ����Ԫ��� 
	printf("\n\n******************Student*******************\n");
	//�������ͷ 
	printf("|No    |     name     |sc1|sc2|sc3|  sum  |rank|\n\n");
	while(p!=NULL){	//�����еĽ�㲻Ϊ�� 
		printf(FORMAT, DATA);	//�����Ӧ����Ϣ 
		p=p->next;		//ָ����� 
	}
	printf("\n\n******************END*******************");
	getchar();
}

