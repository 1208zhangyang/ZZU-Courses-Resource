#include"manage_system_head.h" 
//��¼��ע���˻� 
void RandomCode(char Rcode[]){
    int i;
    srand((unsigned int)time(NULL));

    for(i=0; i<3; ++i){
        Rcode[i]=rand()%10+'0';
    }
    Rcode[i]='\0';
}


void register2(void){
	 result = fopen("result.txt", "r");
	 recall = fopen("recall.txt", "r");
    if((recall)!=NULL && (result)!=NULL){       
       	printf("\t\t��ע�ᣬ���¼:\n"); 
       	 fclose(recall);
       	  fclose(result);
		return;
    }
    else{
    	 result = fopen("result.txt", "w");
    	 recall = fopen("recall.txt", "w");
        printf("�������˺�(20����ĸ��������):____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%s", account);
        fprintf(recall,"%s\n",account); //�������ַ������recall�ļ���
        printf("\n����������(20����ĸ��������):____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
        scanf("%s", password);
        fprintf(result,"%s",password); //�������ַ������result�ļ���
        
		 fclose(recall);
          fclose(result);
        return;
    }
}


void login(){
	char rc[5]; //�����
    int count=0, i=0; //count����¼��������Ĵ���
    char RealAccount[20];
    char RealPassword[20];

//    decode();

    FILE *recall=fopen("recall.txt", "r");
    FILE *result=fopen("result.txt", "r");

    fscanf(recall,"%s",RealAccount);
    printf("%s\n", RealAccount);
    fscanf(result,"%s",RealPassword);//��ȡ��ʵ���˻������룬������֤
    printf("%s\n", RealPassword);
    fclose(recall);
    fclose(result);
//   remove("recall.txt"); 
//	 remove("recall.txt");
//	//����ļ�����֤�˻�������İ�ȫ

    printf("�������˺�(20����ĸ��������):____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", account);
    do
    {
        if((strcmp(account, RealAccount))==0){
            printf("\n�˻�������ȷ��\n");
            printf("\n����������(20����ĸ��������):____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            scanf("%s", password);
            do
            {
                count++;
               if((strcmp(password, RealPassword))==0){
               		printf("\n������ȷ��\n");
              	    RandomCode (rc);
		            printf ("��֤��: %s\n", rc);
		            printf("��������֤�룺"); 
		            scanf("%s", rcode);
		           do{
		           		if(strcmp(rcode, rc)==0)
						{
								system("cls");
						 	  	printf("\t��¼�ɹ���\n");
//								 printf("================================================\r");
//					      	  for(i=0;i<TIME;i++)//��̬������� 
//					      	  {
//					       		     printf("<");
//					       		     Sleep(TIME);//�ӳ�TIME����
//					        	}
//					      	  printf("\n");
							return; 
						}
						else{
							
		           			  printf("\n����������������룡\n");
		               	 	  printf("��������֤�룺");
		                      scanf("%s", rcode);
		            
						}
		              
		            }while(strcmp(rc, rcode)!=0); 
			   }
           	
               else{
              	 
               		 printf("\n�����������������\n");
               		 scanf("%s", password);
                	if(sizeof(password)>(20* sizeof(char))){
                   		 printf("\n��ʾ����������볤�ȳ���20��\n");
               		 }
			   }
			   
            }while (((strcmp(password, RealPassword))!=0)&& count<=3 );
         	printf("����������࣬���Ժ����ԣ�");
        }
		else{
			 printf("\n�˻����ƴ�������������\n");
        	scanf("%s", account);	
		}	
           
    }while ((strcmp(account, RealAccount))!=0);
}


//��ʼ������� 
int print(){
	int n;
	system("cls");	//����clrscr()
	system("color F0");//color F������ɫ��0�Ǻ�ɫ 
	
	printf("\n\n");
	printf("\t*******************************************\n");
	printf("\t*                                         *\n");
	printf("\t*      ---------------------------        *\n");
	printf("\t*-----|   ��ӭʹ��ѧ������ϵͳ    |-------*\n");
	printf("\t*      ---------------------------        *\n");
	printf("\t*                                         *\n");
	printf("\t*              1.ע��/��¼                *\n");
	printf("\t*              0.�˳�                     *\n");
	printf("\t*                                         *\n");
	printf("\t*                              ����ţ������ *\n");
	printf("\t*******************************************\n");	
	printf("\t\t��ѡ��1 or 0:");
	scanf("%d", &n);
//	getchar();
	return n;
}

int menu(int m){
	int select;	
	if(m==1){
		system("cls");	
		
		printf("\t*******************************************\n");
		printf("\t*                                         *\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*-----|   ��ӭʹ��ѧ������ϵͳ    |-------*\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*                                         *\n");
		printf("\t*              1.�½��ļ�                 *\n");
		printf("\t*              2.�ɼ�����                 *\n");
		printf("\t*              3.������¼                 *\n");
		printf("\t*              4.׷�Ӽ�¼                 *\n");
		printf("\t*              5.�޸ļ�¼                 *\n");
		printf("\t*              6.ɾ����¼                 *\n");
		printf("\t*              7.�����ļ�                 *\n");
		printf("\t*              0.�˳�                     *\n");
		printf("\t*                                         *\n");
		printf("\t*******************************************\n");	
		
		do{
			printf("\n\t\t��ѡ��(0~7)...");
			scanf("%d", &select);
			getchar();//����ѡ����
		}while(select<0||select>13);//ѡ�����0~13֮������
		return select; //����ѡ������������ݸú���������Ӧ�ĺ���
	}
	else if(m==2){
		system("cls");
		printf("\t*******************************************\n");
		printf("\t*                                         *\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*-----|   ��ӭʹ�óɼ�����ϵͳ    |-------*\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*                                         *\n");
		printf("\t*              1.�½��ļ�                 *\n");
		printf("\t*              2.��ʾ����                 *\n");
		printf("\t*              3.��ʾ����                 *\n");
		printf("\t*              4.�������                 *\n");
		printf("\t*              5.��ʾ�ɼ�                 *\n");
		printf("\t*              0.����                     *\n");
		printf("\t*                                         *\n");
		printf("\t*******************************************\n");	
		
		do{
			printf("\n\t\t ��ѡ��(0~5)...");
			scanf("%d", &select);
			getchar();//����ѡ����
		}while(select<0||select>5);
		return select; //����ѡ������������ݸú���������Ӧ�ĺ���
	}
	else if(m==3){
		system("cls");
		printf("\t*******************************************\n");
		printf("\t*                                         *\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*-----|   ��ӭʹ�ÿγ̹���ϵͳ    |-------*\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*                                         *\n");
		printf("\t*              1.�½��ļ�                 *\n");
		printf("\t*              2.�Ͽ�˳��                 *\n");
		printf("\t*              3.�γ̰���                 *\n");
		printf("\t*              0.����                     *\n");
		printf("\t*                                         *\n");
		printf("\t*******************************************\n");	
			
		do{
			printf("\n\t\t ��ѡ��(0~3)...");
			scanf("%d", &select);
			getchar();//����ѡ����
		}while(select<0||select>3);
		return select; //����ѡ������������ݸú���������Ӧ�ĺ���
	}	
	else if(m==4){
		system("cls");
		printf("\t*******************************************\n");
		printf("\t*                                         *\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*-----|   ��ӭʹ�óɼ�����ϵͳ    |-------*\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*     ********** ��ʾ�ɼ�**********       *\n");
		printf("\t*      1.80<=�ɼ�<=100                    *\n");
		printf("\t*      2.60<=�ɼ�<80                      *\n");
		printf("\t*      3.�ҿ�                             *\n");
		printf("\t*      0.����                             *\n");
		printf("\t*                                         *\n");
		printf("\t*******************************************\n");	
			
		do{
			printf("\n\t\t ��ѡ��(0~3)...");
			scanf("%d", &select);
			getchar();//����ѡ����
		}while(select<0||select>3);
		return select; //����ѡ������������ݸú���������Ӧ�ĺ���
	} 
	else if(m==5){
		printf("\n\n");
		printf("\t*******************************************\n");
		printf("\t*                                         *\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*-----|   ��ӭʹ��ѧ������ϵͳ    |-------*\n");
		printf("\t*      ---------------------------        *\n");
		printf("\t*                                         *\n");
		printf("\t*              1.ѧ������                 *\n");
		printf("\t*              0.�˳�                     *\n");
		printf("\t*                                         *\n");
		printf("\t*                              ����ţ������ *\n");
		printf("\t*******************************************\n");	
		do{
			printf("\n\t\t ��ѡ��(0~1)...");
			scanf("%d", &select);
			getchar();//����ѡ����
		}while(select<0||select>1);
		return select; //����ѡ������������ݸú���������Ӧ�ĺ���
		
	}
}
 		
//ѧ����¼�ļ����� 
Student *init_s(){
	Student *head, *p, *last, *R;	//���彨��ѧ����¼�Ĺ���ָ��
	Student s;
	char c; 		//�������c��Ϊѡ���Ƿ��½��ļ�����ʾ���� 
	FILE *fp;
	char fname[20];		//������ļ�����ַ�洢���ַ����� 
	int i;
	system("cls");
	printf("�Ƿ��½��ļ�������ѧ����¼(y/n)?_\b");
	c=getchar();
	getchar(); 
	if(c=='Y'||c=='y'){	//�����y�����½��ļ� 
		printf("�����ļ�����(������20���ַ�):____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%s", fname);	//�����ļ���
		if((fp=fopen(fname, "w"))==NULL){	//�ļ���ʧ��
			printf("�޷����ļ�\n");
			return NULL;	//������������
		}
		do{	//������ѧ����Ϣ������� �������Ϊ1������¼��
			printf("����ѧ��(������10�����֣�����0����):__________\b\b\b\b\b\b\b\b\b\b");
			
			scanf("%d", &s.snum);
			while(sizeof(s.snum)>10*sizeof(int)){
				printf("����������������룡\n");
				printf("����ѧ��(������10�����֣�����0����):__________\b\b\b\b\b\b\b\b\b\b");
			
				scanf("%d", &s.snum); 
			} 
			getchar();//�����س������Ա�������һ������ 
			if((s.snum != 0)){		//���ѧ�Ų���0����ô���������� 
				printf("��������(������20����ĸ):__________\b\b\b\b\b\b\b\b\b\b");
				scanf("%s", s.name);
				
				while(sizeof(s.name)>20*sizeof(char)){
					printf("����������������룡\n");
					printf("��������(������20����ĸ):__________\b\b\b\b\b\b\b\b\b\b");
			
					scanf("%s", s.name);
				} 
				
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
			else{	//�������Ϊ0 ,�������� 
				break;
			}
		}while(1);
		fclose(fp);
	}
	head=(Student*)malloc(sizeof(Student));
	//��������ʼ����������ͷ���
	head->next=NULL;
	last=head;
	printf("\n�������ļ������Դ��ļ�:____________________\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	scanf("%s", fname);
	fp=fopen(fname, "r");  //��ѧ���ļ� 
	if(fp==NULL){
		printf("\n �޷����ļ�\n");
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
	return head;	//���ض����ļ���ָ��
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
}

//�ɼ�����ϵͳʵ��
void input_g(Student *head , Cour *hg){ // �ɼ�¼�� 
	Student *p, *R;
	float x1, x2, x3;
	p=head->next;	//ָ����Ԫ���
	system("cls");
	while(p){
		printf("�����һѧ�ڵ����ųɼ����Կո�ָ���:");
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
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
} 

//����ÿһ��Ŀ��ƽ���ɼ�
void ave_g(Student *head){	 
	Student *p, *q, *R;	
	int i, n=0;		//�������nͳ��ÿ�ſγ̲ο������� 
	float sa=0;		//�������sa����γ̵�ƽ��ֵ 
	system("cls");
	q=head->next;
	char *ch[3]={"��ѧ","Ӣ��","C����"}; 
	//������Ԫ������Ϣ 
	//�趨ָ���������������ĳ�����ĵ�ַ���Է��ʿγ���Ϣ 
	for(i=0; i<M; i++){	//����M�ſγ� 
		sa=0;	//ÿһ�ſγ̼���ǰ������ʼ�� 
		n=0;	 
		p=head->next;	//pָ����Ԫ���
		while(p){		//����ÿ��ѧ���ĸ��ſγ�  
			n++;	//ͳ�� 
			sa+=p->score[i].sc;	//�γ�ֵ�ۼ� 
			
			printf("%f", sa ); 
			
			p=p->next;
		}
		sa=sa/n;	//����ƽ��ֵ 
		printf("%s��ƽ������ %.2f\n", ch[i], sa);
		//����γ�ƽ��ֵ 
		//q->score[i]���ʳɼ��������е�i ��Ԫ�أ�
		//q->score[i].cp����ʳɼ���¼�е�ָ����
		//q->score[i].cp->cname ���ʶ����е�cname��Ա��Ϣ�� 
	}
	getchar();
	
		while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
		while(q){//�ͷ����н��Ŀռ� 
		R=q;
		q=q->next;
		free(R);
	}
}


//�ɼ����� 
void sort_g(Student *head){
	Student *p, *q, *r, *u , *R;	//��������Ĺ���ָ�� 
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
//	flag=1;
	save_s(head);
	getchar();
	
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
		while(q){//�ͷ����н��Ŀռ� 
		R=q;
		q=q->next;
		free(R);
	}
		while(r){//�ͷ����н��Ŀռ� 
		R=r;
		r=r->next;
		free(R);
	}
		while(u){//�ͷ����н��Ŀռ� 
		R=u;
		u=u->next;
		free(R);
	}
}

//����ͳ�Ƴɼ��ֲ���� 
//��ͳ�Ƶĸ�����������Ƴɺ��������ò˵������������ 
void class_1(Student *h){	//���ڵ���80�ֵļ�¼ 
	Student *p, *R;	//���幤��ָ�� 
	int i;
	p=h->next;	//ָ����Ԫ��� 
	system("cls");
	printf("|--ѧ��--|--����--|----��Ŀ----|----�ɼ�----|\n");
	//�������ͷ
	 
	while(p!=NULL){	//�����ʲ�Ϊ�� 
		for(i=0; i<M; i++){	//����ÿһ��ѧ��ÿ�ſεĳɼ� 
			if(p->score[i].sc>=80){	//�ɼ����ڵ���80 
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼ 
		}
		printf("\n\n�������������...");
		getchar();
	}
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
}

void class_2(Student *h){
	Student *p, *R;
	int i;
	p=h->next;
	system("cls");
	printf("|--ѧ��--|--����--|----��Ŀ----|----ѧ��----|\n");
	
	while(p!=NULL){
		for(i=0; i<M; i++){
			if(p->score[i].sc>=60&&p->score[i].sc<=79){
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼
		}
		printf("\n\n������������� ...");
		getchar();
	}
	
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
}

void class_3(Student *h){
	Student *p, *R;
	int i;
	p=h->next;
	system("cls");
	printf("|--ѧ��--|--����--|----��Ŀ----|----ѧ��----|\n");

	while(p!=NULL){
		for(i=0; i<M; i++){
			if(p->score[i].sc<60){
				printf("|%4d|%15s|%15s|%.2f\n\n", p->snum, p->name, p->score[i].cp->cname, p->score[i].sc);
			}
			p=p->next;	//ָ����һ����¼
		}
		printf("\n\n������������� ...");
		getchar();
	}
	
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
} 

//�ɼ��������� 
void filt_g(Student *head){
	int select;

	while(1){	//�������ɸѡ���� 
		system("cls");
		select=menu(4);	//���÷���ɸѡ�˵� 
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
	Student *p, *R;
	system("cls");
	p=head->next;	//ָ����Ԫ��� 
	printf("\n\n*****************************************************\n");
	//�������ͷ 
	printf("|   ѧ��   |    ��   ��    |�γ�1|�γ�2|�γ�3|�� ��|�ȼ�|\n\n");
	while(p!=NULL){	//�����еĽ�㲻Ϊ�� 
		printf(FORMAT, DATA);	//�����Ӧ����Ϣ 
		p=p->next;		//ָ����� 
	}
	printf("\n\n*****************************************************");
	getchar();
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
}

//ѧ����¼�ı��� 
void save_s(Student *head){
	FILE *fp;
	Student *p, *R;
	char bname[30];
//	printf("���뱣���¼���ļ���:");
//	scanf("%s", bname);
	fp=fopen("student.txt", "wt");	//��ֻд��ʽ���ļ� 
	if(fp==NULL){	//���ļ�ʧ�� 
		printf("\n ���ļ�����!\n");
		return;
	}
	p=head->next;	//��ǰ��������������д���ڴ� 
	while(p){
		fwrite(p, sizeof(Student), 1, fp);
		//ÿ��дһ����¼��һ���ڵ㵽�ļ� 
		p=p->next;
	}
	fclose(fp);
	while(p){//�ͷ����н��Ŀռ� 
		R=p;
		p=p->next;
		free(R);
	}
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
		printf("\n ��ѧ��������!\n");
		getchar();
		return NULL; 
	}
	system("cls");
	printf("\n  1.ͨ��ѧ�Ų���  2.ͨ���������� \n");
	printf("  ��ѡ��[1,2]  ");
	scanf("%d", &select);
	getchar();
	switch(select){
		case 1:
			printf("����ѧ��:");
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
			printf("����ѧ������:");
			scanf("%s", str);
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
		printf("����ѧ��(����0����):");
		p=(Student *) malloc(sizeof(Student));
		scanf("%d", &p->snum);
		getchar();
		
		while(check(head, p->snum)&& p->snum != 0){
			//ѧ�Ų�����ͬʱѧ�Ų�Ϊ�գ�������ѯ
			printf("����ѧ��:");
			scanf("%d", &p->snum);
			getchar() ;
		}
		
		if(p->snum==0){	//����Ϊ0�����˳���� 
			printf("��������������������...\n");
			break;
//			scanf("%d", &p->snum );
//			getchar(); 
		}
		else{	//������ 
			printf("����ѧ������:");
			scanf("%s", p->name);
			printf("�����һѧ�ڵĳɼ�:");
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
//	flag=1;		//���ı�� 
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
		printf("\n û��ѧ����¼!\n");
		return NULL;
	}
	system("cls");
	printf("\n   1. ͨ��ѧ��ɾ��   2. ͨ������ɾ��\n");
	printf("��ѡ��[1, 2]:");
	scanf("%d", &select);
	if(select==1){	//����ѧ�Ų��� 
		printf("����ѧ��\n"); 
		scanf("%d", &num);
		r = head;
		p = head->next;		//rΪ�м����������ͷ��� 
		while(p && p->snum!=num){
			r=p;
			p=p->next;
		} 
		
		if(p){
			r->next=p->next;
//			flag=1;
			free(p);
			printf("\n ɾ���ɹ�!\n");
			getchar();
		}
		else{
			printf("\n �޷��ҵ�!\n");
			getchar();
		}
	}
	else if(select==2){		//�Ȱ�������ѯ���ü�¼
		printf("����ѧ������:");
		scanf("%s", str);	//����������Ϣ 
		r=head;
		p=head->next;	//���ҳ�ʼ�� 
		while(p&&strcmp(p->name, str)!=0){		 //ѭ���Ƚϲ��Ҽ�¼ 
			r=p;		//�������ַ 
			p=p->next;	//���ָ����� 
		}
		if(p){
			r->next=p->next;	//��p��ָ����������ȥ�� 
//			flag=1;
			free(p);	//�ͷ��ڴ�ռ� 
			printf("\n ɾ���ɹ�!\n");
			getchar();	
		}
		else
		printf("\n �޷��ҵ�.\n");
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
	printf("�޸�ѧ����¼...\n");
	printf("���������޸���Ϣ��ѧ����ѧ��:\n");
	scanf("%d", &num);
	getchar();
	p=head->next;
	while(p && p->snum!=num){	//�����Ƿ���� 
		p=p->next;
	} 
	if(p){		//��p��=NULL�����Ѿ��ҵ���� 
		printf("����ѧ������:");
		scanf("%s", p->name);
		printf("�����һѧ�ڳɼ�:");
		scanf("%f%f%f", x1, x2, x3);
		p->score[0].sc=x1;
		p->score[2].sc=x2;
		p->score[2].sc=x3;
		p->sum=x1+x2+x3;
		print_g(head);		//�޸ĺ����Ϣ��ʾ 
//		flag=1;		//�ı��¼�����ı�� 
		getchar(); 
	}
	else{
		printf("�޷��ҵ��ļ�!\n");
		getchar();
	}
} 
	

//�γ���Ϣ��Ľ��� 
void init_c(Course *g){
	//�γ���Ϣ��ṹ�Ľ����Լ��γ�¼����ߴ򿪣�����ԭʼ��¼�ļ�
	FILE *fp;	//	�趨ָ�뱣��γ���Ϣ�ļ���ַ 
	char fname[20]; 
	int i, j, k, n;
	Cnode *s=NULL;
	
	system("cls") ;
	
	printf("����γ���Ϣ \n");
	printf("|NO.  |Course | Credit|\n");
	
	for(i=0; i<M; i++){
		scanf("%d %s", &(g[i]->cnum), g[i]->cname);
//		g[i]->indegree=0;
		g[i]->first=NULL; //��ն��㵥����ָ�� 
		
	}
	
	printf("����γ�����:");
	scanf("%d", &n);
	getchar();
	//������� 
	printf("\n����γ���Ϣ:\n");
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
	printf("�ѿγ���Ϣ���浽�ļ���Ȼ���\n");
	gets(fname);
	getchar();
	if((fp=fopen(fname,"wb"))==NULL){
		//open the file
		printf("�ļ��޷���\n");
		exit(0);
	}
	for(i=0;i<M;i++){
		fwrite(g+i, sizeof(Cour), 1, fp);
		//save the record into the file
	}
	fclose(fp);
} 
