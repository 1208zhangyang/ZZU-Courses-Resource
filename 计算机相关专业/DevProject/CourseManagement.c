#include<stdio.h>	/*��׼�������*/
#include<stdlib.h>	/*��Ļ������������system"cls"*/
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#include"manage_system_head.h"
//�γ���Ϣ��Ľ��� 
void init_c(Course *g){
	//�γ���Ϣ��ṹ�Ľ����Լ��γ�¼����ߴ򿪣�����ԭʼ��¼�ļ�
	FILE *fp;	//	�趨ָ�뱣��γ���Ϣ�ļ���ַ 
	char fname[20]; 
	int i, j, k, n;
	Cnode *s=NULL;
	
	system("cls") ;
	
	printf("input the course information. \n");
	printf("|NO.  |Course | Credit|\n");
	
	for(i=0; i<M; i++){
		scanf("%d %s", &(g[i]->cnum), g[i]->cname);
		g[i]->indegree=0;
		g[i]->first=NULL; //��ն��㵥����ָ�� 
		
	}
	
	printf("input number of course information :");
	scanf("%d", &n);
	getchar();
	//������� 
	printf("\n input information of course:\n");
	//����ÿһ������ıߵĵ����� 
	for(k=0; k<n; k++){
		scanf("%d%d", &i, &j);
		getchar();
		s=(Cnode *)malloc(sizeof(Cnode));
		//Ϊ�������н�����ռ�
		s->num=j;
		//����γ��Ⱦ��������±� 
		s->next=g[i]->first; 
		//ͷ�巨����������
		g[i]->first=s;	
	} 
	printf("save the course to file, open the file.\n");
	gets(fname);
	getchar();
	if((fp=fopen(fname,"wb"))==NULL){
		//open the file
		printf("the file can not open.\n");
		exit(0);
	}
	for(i=0;i<M;i++){
		fwrite(g+i, sizeof(Cour), 1, fp);
		//save the record into the file
	}
	fclose(fp);
} 
	
//the order of all courses
void sort_c(Course *g){
	int ts=0;
	int i, j, top=1;
	//�趨top����ջ��Ԫ�ص��±꣬����Ϊջ��ָ�� 
	Cnode *p;
	system("cls");
	for(i=0; i<M; i++){		
	//ѭ����¼ÿ���������� 
		p=g[i]->first;	//pָ��ÿ������ĵ������ͷ��� 
		while(p){
			//����ÿ��������ڽ������������ 
			g[p->num]->indegree++;
			p=p->next;
		} 
	} 
	for(i=0; i<M; i++){
		//���ĳ����������Ϊ0�� ��ô�Ѷ������������Ϊջ
		if(g[i]->indegree==0){
			g[i]->indegree=top;
			top=1;
		} 
	}
	
	printf("the course arrangement:\n");
	while(top!=-1){	
	//��������������ջ��ָ�벻��-1 
	//��ջ��Ԫ�ز���
		j=top;
		top=g[top]->indegree; 
		printf("  %s \n", g[j]->cname);
		//�������Ϊ0�ĵ�
		topsort[ts++]=j;
		p=g[j]->first;
		while(p){
			//ѭ����������
			//�������������Ϊ�Ⱦ������Ľ������ 
			i=p->num;
			g[i]->indegree==0;
			if(g[i]->indegree==0){
				//���Ϊ0��������ջ
				g[i]->indegree=top;
				top=i;
			}
			p=p->next;
		} 
		getchar();
		 
	} 
}

//ÿѧ�ڿγ��Ͽΰ��� 
void plan_c(Course *g){
		int s=0;
		//�������������ѧ�� 
		char fname[20];
		FILE *fp;
		int i, j, k=0;
		system("cls");
		printf("open the course, input the filename \n");
		gets(fname);
		if((fp=fopen(fname,"rb"))==NULL){
			//���ļ��������ʧ���򷵻� 
			printf("the file can not open .\n");
			return;
		} 
		for(i=0; i<M; i++){
			fread(g+i, sizeof(Cour), 1, fp);
			//���ļ��ж����γ���Ϣ 
		}
		sort_c(g);
		//���� 
		for(i=0; i<M; i++){
			//����ѧ�ֺ� 
			s+=g[i]->credit; 
		} 
		s=s/4;
		j=1;
		for(i=0; i<M; i++){
			//ƽ���������ѧ�� 
			k+=g[topsort[i]]->credit;
			//��������γ̵�ѧ��
			if(k<=s){
			//���С��ƽ��ֵ����ô����γ���Ϣ 
				printf("the %d term course:", j);
				//ѡ��ѧ�ڵĿγ�
				printf("  %d  %s\n", g[topsort[i]]->cnum, g[topsort[i]]->cname); 
			} 
			else{
				//ѧ�ִ���ƽ��ֵ
				j++;
				k=0; 
			}
		}
		getchar();
		getchar();
		fclose(fp);
	}

