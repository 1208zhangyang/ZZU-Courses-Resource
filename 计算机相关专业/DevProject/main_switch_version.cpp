#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>	/*��̬��ַ���亯��*/
#include<string.h>	/*�ַ�������*/
#include<windows.h> /*����gotoxy(x, y)����*/
#include"manage_system_head.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	char *m1[]={
		"*****Student Management System*****\n",
		//����˵��ַ�������
		"1.Init list\n",
		//��ʼ������ѧ���ļ��д�ѧ����¼
		"2.Score management\n",
		//ѧ���ɼ����� 
		"3.Search record(s)\n",
		//�����������Ҽ�¼
		"4.Append a record to list\n",
		//���ļ���׷�Ӽ�¼
		"5.Modify a record to list\n"
		//�޸ļ�¼
		"6.Delete a record from list\n",
		//�ӱ���ɾ����¼
		"7.Save the file\n",
		//���������еļ�¼���浽�ļ���
		"0.Exit\n",
		//���������� 
	};
	
	char *m2[]={"*****Score Manegement System*****\n",
		//����ɼ�����˵��ַ������� 
		"1.Init list\n",
		//��ʼ����¼��ѧ���ɼ����ɼ��ļ� 
		"2.Average of each subject\n",
		//ÿ��ѧ���ܳɼ����� 
		"3.Sort and order\n",
		//�����ܳɼ����� 
		"4.Filter score\n",
		//���շ����η������ 
		"5.Display number and score\n",
		//���ѧ���ɼ� 
		"0.Return \n"
		//����ѧ������˵� 
	};
	
	char *m3[]={"*****Course Manegement System*****\n",
		//����γ̹���˵��ַ������� 
		"1.Init list\n",
		//��ʼ���������������ѧ�γ̱�
		"2.Sort of course\n",
		//���пγ��Ͽ�˳�� 
		"3.Plan\n",
		//ÿ��ѧ�ڿγ̰��� 
		"0.Return\n"
		//���������� 
	} ;
	
	Student *head =NULL;
	//ѧ���ļ���Ϣ�ڴ��д洢Ϊ����
	Course hc;
	//�γ���Ϣ�洢Ϊͼ
	FILE *fp, fpc;
	//�ļ�ָ��
	int s1, s2, s3;
	//����ѡ��������
	char ch;
	//���棨y, Y, n, N��
	system("cls");
	//����
	
	//������,���������¼���棬��һ�ο����������룬֮���Ҫ��������ſ��Ե�¼
	//������������ļ���Ҫ���ܣ��������� 
	//�������������������Ĺ���
	int i,password=123456;
	printf("================================================\r");	
	for(i=0;i<50;i++)
	{
		printf("<");
		Sleep(50);//�ӳ�500����==0.5��
	}
	printf("\n���������ϵͳ����:\n");
	do
	{
		scanf("%d",&password);
		if(password!=123456)
			printf("\n�����������������\n");
		else
			printf("\n������ȷ����ȴ�...\n");
		
	}while(password!=123456);
	printf("================================================\r");	
	for(i=0;i<50;i++)
	{
		printf("<");
		Sleep(50);//�ӳ�500����==0.5��
	}

	while(1){
		//��ʼ�������������ܣ����Թ���ѧ���ɼ��Ϳγ̼�¼�Լ��˳�����
		system("cls");
		//���� 
		s1=print(); 
		//���ÿ�ʼ�������
		switch (s1){
			case 1:{
				while(1){
				system("cls");
				s2=menu(m1, 9);
				if(s2==0){
					//�������������޸���δ���д����򽫴˱�־Ϊ1
					printf("\n Whether save the modified record to file?(y/n):");
					scanf("%c", &ch);
					if(ch=='y'||ch=='Y'){
						save_s(head); 
					}
					printf("the student system qiut.\n");
					break;
				}
				switch(s2){
					//�˵�ѡ������ 
					case 1:head=init_s();
					break;
					//�����½����ߴ��ļ����ݵ��ڴ� 
					case 2:
						while(1){
							//ѭ���Ĺ����ǽ���ɼ�������� 
							system("cls");
							s3=menu(m2, 7);
							//���óɼ�����˵�
							if(s3==0){
								break;
							} 
							//����0��ʾ���
							
							switch(s3){
								//�ɼ�����˵�����ѡ��
								case 1:input_g(head, hc);
								break;
								//¼��ÿ�ſεĳɼ��Ϳγ���Ϣ
								case 2:ave_g(head);
								break;
								//�������ƽ����
								case 3:sort_g(head);
								break;
								//Ϊ�ɼ�����
								case 4:filt_g(head);
								break;
								//����ɼ�ɸѡ
								case 5:print_g(head);
								break;
								//����ɼ� 
							} 
						}
						break;
					case 3:
						sear_s(head);
						//����ĳ��ѧ���ĳɼ�
					case 4:
						head=appe_s(head);
						break;
						//׷�Ӽ�¼
					case 5:
						head=modi_s(head);
						break;
						//�޸ļ�¼
					case 6:
						head=dele_s(head);
						break;
						//ɾ����¼
					case 7:
						save_s(head);
						break;
						//���浽�ļ� 
					}
				}
			}break;
			
			case 2:{
				//ѡ��2����γ̹������
				{
					while(1){
						//ѭ������γ� 
						system("cls");
						s2=menu(m3, 5);
						//���ÿγ̹���˵�
						if(s2==0){
							system("cls");
							break;
						} 
						
						witch(s2){
						case 1:
							init_c(&hc);
							break;
						//¼��γ̼�¼
						
						case 2:
							sort_c(&hc);
							break;
						//�γ̽��Ȱ���
						case 3:
							plan_c(&hc);
							break; 
						//ÿ��ѧ�ڿγ���Ϣ 
						}
					}
				} break;
			}
			
			case 3:{
				{
					//����0��ʾ�˳����ϵͳ 
					system("cls");
					printf("Press any key to exit.");
					getchar();
					exit(0); 
				}break;
			}
			
		  }
		} 
	};
	return 0;
}
