
//#include"manage_system_head.h" 
#include"func.h"
int main(void){
	int i;
	
	Student *head =NULL;//ѧ���ļ���Ϣ�ڴ��д洢Ϊ����
	char ch;	//�洢ѡ�������� 
	FILE *fp;	//�ļ�ָ��
	int s1, s2, s3;	//����ѡ��������
	
	system("cls");	//����
	
	while(1){
		//��ʼ�������������ܣ����Թ���ѧ���ɼ��Ϳγ̼�¼�Լ��˳�����
		system("cls");
		s1= print(); //���ÿ�ʼ�������,���ضԵ�¼��ע����˳���ѡ�� 
		if(s1==1){//�жϷ��ص�ѡ��
			register2(); 
			login();//�����¼�ɹ����Ϳ��Խ���ѡ��˵� 
			if(menu(5)){
				while(1){//���ѡ����ѧ������ 	 
					system("cls");
					s2=menu(1);
				    if(s2==0){
						//�������������޸���δ���д����򽫴˱�־Ϊ1
						printf("\n�Ƿ���޸ĺ�ļ�¼���浽�ļ���?(y/n):");
						scanf("%c", &ch);
						if(ch=='y'||ch=='Y'){
							save_s(head); 
						}
						printf("ѧ������ϵͳ�˳�.\n");
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
							s3=menu(2);
							//���óɼ�����˵�
							if(s3==0){
					
							break;
							} 
							//����0��ʾ���
							
							switch(s3){
								//�ɼ�����˵�����ѡ��
								case 1:input_g(head, ch);
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
						break; 
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
				
			} 
			else{
				exit(1);
			} 
		}
		else {
			//����0��ʾ�˳����ϵͳ 
			system("cls");
			printf("\t��������Ϳ����˳���\n\n");
			getchar();
			exit(0); 
			}
		}	
}
