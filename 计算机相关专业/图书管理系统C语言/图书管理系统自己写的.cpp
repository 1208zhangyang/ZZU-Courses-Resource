#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define Maxn

void Add();
void Find();
void Delete();

int main(void)
{
	
	
	return 0;
}

void Add(){
	LIST *p1=NULL, *p2=NULL;
	p1=(LIST*)malloc(sizeof(LIST));
	printf("����������\n");
	scanf("%s", p1->bookname);
	printf("�����ţ�\n");
	scanf("%s", p1->num);
	printf("���뵥�ۣ�\n");
	scanf("%s", p1->price);
	printf("����ISBN��\n");
	scanf("%s", p1->ISBN);
	printf("��������磺\n");
	scanf("%s", p1->press);
	
	p1->next = NULL;
	
	if(head==NULL){
		head  (LIST*)malloc(sizeof(LIST));
		head ->next=p1;
	}
	else{
		for(p2=head; p2 ->next=NULL;p2=p2->next);
		p2->next=p1;
	}
	printf("�˼�¼�Լ��ɹ���ӣ�\n"); 
}

void Find(){
	LIST *p;
	char bookname[30],num[15];
	int i;
	printf("��������ҷ�ʽ��1.����������2.���ձ��\n");
	scanf("%d", &i);
	if(i==1){
		printf("������Ҫ���ҵ��鼮���ƣ�\n");
		scanf("%s", bookname);
		printf("����\t\t���\t\tISBN\t\t������\n");
		for(p=head->next; p!=NULL; p=p->next) {
			if(strcmp(p->num, num)==0)
				printf("%s\t%s\t%s\t%s\n",p->bookname,p->num,p->jprice,p->ISBN,p->press);
			else
				printf("��ѡ��1��2��������\n");
					
		}
	} 
}
