#include"20150120_sims.h"

//stu_info
void trim_space(char *src)
{
	int fast_index, last_index ;
	for(fast_index = 0, last_index = -1 ; src[fast_index] != 0 ;fast_index++)
	{
		if(!isspace(src[fast_index]))
		{
			src[++last_index] = src[fast_index];
		}else 
		{
			if(last_index != -1 && !isspace(src[last_index]) )
			{
				src[++last_index] = ' ';
			}
		}
	}
	src[++last_index] = 0;
}//去空格
void system_init(char *config, pACCOUNT *pphead_acc, pSTU *pphead_stu)
{
	FILE* fp_config, *fp_account, *fp_stu ;
	char line[LINE_LEN] ;
	pACCOUNT pnew, pcur, ppre ;
	pSTU pnew_stu, pcur_stu, ppre_stu ;

	fp_config = fopen(config, "r");
	if(fp_config == NULL)
	{
		printf("open config fail!\n");
		system("pause");
		exit(1); 
	}
	memset(line, 0, sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);////////////////open1
	line[strlen(line) - 1] = 0;

	fp_account = fopen(line, "r");
	if(fp_account == NULL)
	{
		printf("open account fail!\n");
		system("pause");
		exit(1); 
	}
	while(memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_account) != NULL)
	{
		pnew = (pACCOUNT)calloc(1, sizeof(ACCOUNT));
		sscanf(line,"%s%s%d", pnew ->m_name, pnew ->m_passwd, &pnew ->m_role);

		pcur = *pphead_acc ;
		ppre = NULL ;
		while(pcur && strcmp(pcur ->m_name, pnew ->m_name) < 0)
		{
			ppre = pcur ;
			pcur = pcur ->m_next ;
		}
		if(ppre == NULL)
		{
			pnew ->m_next = *pphead_acc ;
			*pphead_acc = pnew ;
		}else 
		{
			pnew ->m_next = pcur ;
			ppre ->m_next = pnew ;
		}
	}
	fclose(fp_account);

//read the students mag
	memset(line, 0, sizeof(line));
	fgets(line, LINE_LEN, fp_config);//open222222
	line[strlen(line) - 1] = 0;
	fclose(fp_config);

	fp_stu = fopen(line, "r");
	if(fp_stu == NULL)
	{
		printf("open stu fail!\n");
		system("pause");
		exit(1); 
	}

	while(memset(line, 0, sizeof(line)), fgets(line, LINE_LEN, fp_stu) != NULL)
	{
		pnew_stu = (pSTU)calloc(1, sizeof(STU));

		trim_space(line);

		sscanf(line,"%d%s %c%4f%4f%4f%4f%4f", &pnew_stu ->m_id, pnew_stu ->m_name, &pnew_stu->m_gender, &pnew_stu->m_socres[0],&pnew_stu->m_socres[1],&pnew_stu->m_socres[2],&pnew_stu->m_socres[3],&pnew_stu->m_socres[4]);

		pcur_stu = *pphead_stu ;
		ppre_stu = NULL ;
		while(pcur_stu && pcur_stu ->m_id < pnew_stu ->m_id)
		{
			ppre_stu = pcur_stu ;
			pcur_stu = pcur_stu ->m_next ;
		}
		if(ppre_stu == NULL)
		{
			pnew_stu ->m_next = *pphead_stu ;
			*pphead_stu = pnew_stu ;
		}else 
		{
			pnew_stu ->m_next = pcur_stu ;
			ppre_stu ->m_next = pnew_stu ;
		}
	}
	fclose(fp_stu);

}//录入文件 和学生信息
int role_confirm(pACCOUNT phead_acc)
{
	int cnt = 0 ,index;
	pACCOUNT pcur ;
	char usr_name[NAME_LEN] ;
	char usr_passwd[PWD_LEN] = {0};
	while(cnt < CONFIRM_CNT)
	{
		system("cls");
		printf("请输入用户名 :");
		fflush(stdin);
		fgets(usr_name, NAME_LEN, stdin);
		usr_name[strlen(usr_name) - 1] = 0 ;
		printf("请输入密码 :");
		fflush(stdin);
		for(index=0; ; index++)
		{
		   usr_passwd[index] = getch();

		   if(usr_passwd[index] == 13)
		      {
				  break;
		      }
		   printf("*");
		}
		usr_passwd[strlen(usr_passwd) - 1] = '\0' ;

		pcur = phead_acc ;
		while(pcur)
		{
			if(strcmp(usr_name, pcur ->m_name) == 0 && strcmp(usr_passwd, pcur ->m_passwd) == 0)
			{
				break ;
			}
			pcur = pcur ->m_next ;
		}
		if(pcur)
		{
			return pcur ->m_role;
		}else 
		{
			cnt ++ ;	
		}



	}
	return -1;
}//权限设置
int show_system_menu(int role)
{
	int select ;
	int flag = 0 ;
	while(!flag)
	{
		system("cls");
		if(role == 1)
		{
			//printf("1.");
			printf("********************************************************************************");
			printf("********     ***          *         *      *               ***　　　　**********");
			printf("********　　*             *        *  *   *  *            *           **********");
			printf("********      ***         *       *    * *    *            ***        **********");
			printf("********         *        *      *      *      *               *      **********");
			printf("********     ****         *     *               *          ****       **********");
			printf("********************************************************************************");
			printf("\n");
			printf("\n");
			printf("                                  主菜单                                        ");
			printf("--------------------------------------------------------------------------------");
			printf("                   %s\n", M1);
			printf("                   %s\n", M2);
			printf("                   %s\n", M3);
			printf("                   %s\n", M4);
			printf("                   %s\n", M5);
			printf("                   %s\n", M6);
			printf("                   %s\n", M7);
			printf("                   %s\n", M8);
			printf("                   %s\n", M9);
		}else 
		{
			printf("********************************************************************************");
			printf("********     ****         *         *     *              ****　 　  　**********");
			printf("********　　*             *        * *   * *            *             **********");
			printf("********      ***         *       *   * *   *             ***         **********");
			printf("********         *        *      *     *     *               *        **********");
			printf("********     ****         *     *             *          ****         **********");
			printf("********************************************************************************");
			printf("\n");
			printf("\n");
			printf("                                 学生菜单                                       ");
			printf("--------------------------------------------------------------------------------");
			printf("                  %s\n", M1);
			printf("                  %s\n", M9);
		}
		printf("select  a number:");
		fflush(stdin);
		select = getchar();
		if(role == 1)
		{
			if( '1' <= select && select <= '9')
			{
				flag = 1 ;
			}
		}else 
		{
			if(select == '1' || select == '9')
			{
				flag = 1 ;
			}
		}

	}
	return select - '0';
}//显示主界面
int show_search_menu(int role)
{
	int search ;
	int flag = 0 ;
	while(!flag)
	{
		system("cls");
		printf("********************************************************************************");
		printf("********     ****  search   ***  students  ****  information  ****    **********");
		printf("********************************************************************************");
		printf("\n");
		printf("\n");
		printf("                                 学生信息查找                                   ");
		printf("--------------------------------------------------------------------------------");
		printf("                  %s\n",S1);
		printf("                  %s\n",S2);
		printf("                  %s\n",S3);
		printf("select  a number:");
		fflush(stdin);
		search = getchar();
		
		if( '1' <= search && search <= '3')
		{
			flag = 1 ;
		}
		
		

	}
	return search - '0';
}

void search_usr_infor_by_id(pSTU *infor, int psearch_id)
{
	pSTU pcur = *infor;
	char line[1024];	
	while(pcur)
	{
		if(pcur->m_id == psearch_id)
		{
			printf("\n");
			printf("ID  name     sex   socers1      2        3      4        5\n");
			sprintf(line, " %-3d%-10s%-3s     %4.1f    %4.1f     %4.1f    %4.1f      %4.1f\n",pcur->m_id,pcur->m_name,&pcur->m_gender,pcur->m_socres[0],pcur->m_socres[1],pcur->m_socres[2],pcur->m_socres[3],pcur->m_socres[4]);
			puts(line);
			break;
		}
		if(pcur->m_next == NULL)
		{
			printf("sorry id error\n");
			break;
		}
		pcur = pcur->m_next;
	}
}
void search_usr_infor_by_name(pSTU *infor, char *psearch_name)
{
	pSTU pcur = *infor;
	char line[1024];
	while(pcur)
	{
		if(strcmp(pcur->m_name, psearch_name) == 0)
		{
			printf("\n");
			printf("ID  name      sex socers  1      2       3      4       5\n");
			sprintf(line, " %-3d%-10s  %-3s      %4.1f   %4.1f    %4.1f   %4.1f    %4.1f\n", pcur->m_id, pcur->m_name, &pcur->m_gender, pcur->m_socres[0], pcur->m_socres[1], pcur->m_socres[2], pcur->m_socres[3], pcur->m_socres[4]);
			puts(line);
			break;
		}
		pcur = pcur->m_next;
		if(pcur == NULL)
		{
			printf("sorry name error");
			break;
		}
		
	}
}

void add_usr_infor(char *config, pSTU *infor)
{
	FILE* fp_config, *fp_write;

	char line[LINE_LEN];
	pSTU pnew,pcur,temp;
	pnew=(pSTU)calloc(1,sizeof(STU));
	fflush(stdin);
	printf("输入学生ID:");
	scanf("%d",&pnew->m_id);
    pcur=*infor;
	while(pcur&&pnew->m_id!=pcur->m_id)
	{
		pcur=pcur->m_next;
	}
	if(pcur)
	{
		printf("已经拥有该用户的信息！\n");
		printf("Enter返回上一层\n");
		getchar();
		return ;
	}
	printf("输入学生名字和性别：");
	scanf("%s %c",&pnew->m_name,&pnew->m_gender);
	printf("输入学生成绩：");
	scanf("%f%f%f%f%f",&pnew->m_socres[0] ,&pnew->m_socres[1],&pnew->m_socres[2],&pnew->m_socres[3],&pnew->m_socres[4]);	
	//添加结构体至链表
	pcur=*infor;
	pnew->m_next=pcur;
	*infor=pnew;	
	
	//打开文件
	fp_config = fopen(config, "r");
	memset(line, 0, sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);//读第一行地址
	memset(line,0,sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);//读第二行地址
	line[strlen(line) - 1] = 0;

	fp_write = fopen(line, "a");//打开文件写一行

	pcur=*infor;
	//while(pcur)
//	{
		memset(line,0,sizeof(line));
		sprintf(line, "%-3d%-10s%-3c%8.1f%8.1f%8.1f%8.1f%8.1f\n",pcur->m_id,pcur->m_name,pcur->m_gender,pcur->m_socres[0],pcur->m_socres[1],pcur->m_socres[2],pcur->m_socres[3],pcur->m_socres[4]);
		puts(line);
		fputs(line,fp_write);
//		temp=pcur;
//		pcur=pcur->m_next;
//		free(temp);
//	}
	fclose(fp_write);
	printf("增加成功！\n");

}
void update_usr_infor(char *config, pSTU *infor, int psearch_id)
{
	pSTU pcur=*infor,temp;
	int index;
	char line[LINE_LEN];
	FILE * fp_config, *fp_write;

	while(pcur)
	{ 
		pcur=pcur->m_next;
		if(pcur->m_id==psearch_id)
		{
			//输入更新内容
			printf("name: ");
			scanf("%s",&pcur->m_name);
			printf("sex: ");
			scanf("%s",&pcur->m_gender);
			printf("socers5: ");
			for(index=0;index<5;index++)
			{
				scanf("%f",&pcur->m_socres[index]);
			}
			//打开文件
			fp_config = fopen(config, "r");
			memset(line, 0, sizeof(line));
			fflush(stdin);
			fgets(line, LINE_LEN, fp_config);
			memset(line,0,sizeof(line));
			fflush(stdin);
			fgets(line, LINE_LEN, fp_config);
			line[strlen(line) - 1] = 0;

			fp_write = fopen(line, "w");

			pcur=*infor;
			while(pcur)
			{
				memset(line,0,sizeof(line));
				sprintf(line, "%-3d%-10s%-3c%8.1f%8.1f%8.1f%8.1f%8.1f\n",pcur->m_id,pcur->m_name,pcur->m_gender,pcur->m_socres[0],pcur->m_socres[1],pcur->m_socres[2],pcur->m_socres[3],pcur->m_socres[4]);
				//puts(line);
				fputs(line,fp_write);
				temp=pcur;
				pcur=pcur->m_next;
				free(temp);
			}
			printf("更新完毕！\n");
		    fflush(stdin);
			break;
		}
		else if(pcur==NULL)
		{
           printf("没有这个ID！\n");
		   fflush(stdin);
		   break;
		}	
	}
}
void delete_usr_infor(char *config, pSTU *infor, int psearch_id)
{
	pSTU pcur=*infor,temp,ppre=NULL;
	char line[LINE_LEN];
	FILE * fp_config, *fp_write;

	while(pcur&&pcur->m_id!=psearch_id)
	{
		ppre=pcur;
		pcur=pcur->m_next;
	}
		if(pcur == NULL)
		{
			printf("没有这个ID！\n");
		}
		else
		{
			
			if(ppre == NULL)
			{
				*infor=pcur->m_next;
				free(pcur);
			}else
			{
				ppre->m_next=pcur->m_next;
				free(pcur);
			}

			//写入
			fp_config = fopen(config, "r");
			memset(line, 0, sizeof(line));
			fflush(stdin);
			fgets(line, LINE_LEN, fp_config);
			memset(line,0,sizeof(line));
			fflush(stdin);
			fgets(line, LINE_LEN, fp_config);
			line[strlen(line) - 1] = 0;

			fp_write = fopen(line, "w");

			pcur=*infor;
			while(pcur)
			{
				memset(line,0,sizeof(line));
				sprintf(line, "%-3d%-10s%-3c%8.1f%8.1f%8.1f%8.1f%8.1f\n",pcur->m_id,pcur->m_name,pcur->m_gender,pcur->m_socres[0],pcur->m_socres[1],pcur->m_socres[2],pcur->m_socres[3],pcur->m_socres[4]);
				//puts(line);
				fputs(line,fp_write);
				temp=pcur;
				pcur=pcur->m_next;
				free(temp);
			}
			printf("删除完成！\n");
			
		}
	
}


//stu_account
void search_account_infor_by_name(pACCOUNT *head, char *psearch_name)
{
	pACCOUNT pcur = *head;
	char line[1024];
	while(pcur)
	{
		if(strcmp(pcur->m_name,psearch_name) == 0)
		{
			printf("\n");
			memset(line, 0, 1024);
			printf("name       passwd     role\n");
			sprintf(line, "%-10s %-10s  %d\n",pcur->m_name, pcur->m_passwd, pcur->m_role);
			puts(line);
			break;
		}
		pcur = pcur->m_next;
		if(pcur == NULL)
		{
			printf("sorry name error");
			break;
		}
		
	}
}
void add_account_infor(char *config,pACCOUNT *head)
{
	FILE *fp_config, *fp_write;

	char line[LINE_LEN];
	pACCOUNT pnew,pcur,temp;
	pnew=(pACCOUNT)calloc(1, sizeof(ACCOUNT));
	fflush(stdin);
	scanf("%s", &pnew->m_name);
    pcur=*head;
	while(pcur && strcmp(pnew->m_name, pcur->m_name)!=0)
	{
		pcur = pcur->m_next;
	}
	if(pcur)
	{
		printf("已经拥有该账户的信息！\n");
		printf("Enter返回上一层\n");
		getchar();
		return ;
	}
	printf("输入密码：");
	scanf("%s", &pnew->m_passwd);
	printf("输入账户权限：");
	scanf("%d", &pnew->m_role);	
	//添加结构体至链表
	pcur = *head;
	pnew->m_next = pcur;
	*head = pnew;	
	
	//打开文件
	fp_config = fopen(config, "r");
	memset(line, 0, sizeof(line));
	fflush(stdin);
	fgets(line, LINE_LEN, fp_config);//读第1行地址
	line[strlen(line) - 1] = 0;

	fp_write = fopen(line, "a");//打开文件写一行

	pcur = *head;

	memset(line, 0, sizeof(line));
	sprintf(line, "%-10s%-10s%d\n", pcur->m_name, pcur->m_passwd, pcur->m_role);
	puts(line);
	fputs(line, fp_write);

	fclose(fp_write);
	printf("增加成功！\n");

}
void update_account_infor(char *config,pACCOUNT *head,char *psearch_name)
{
	pACCOUNT pcur = *head, temp;
	int index;
	char line[LINE_LEN];
	FILE *fp_config, *fp_write;

	while(pcur)
	{ 
		
		if(strcmp(pcur->m_name, psearch_name) == 0 )
		{
			//输入更新内容
			printf("name: ");
			scanf("%s", &pcur->m_name);
			printf("passwd: ");
			scanf("%s", &pcur->m_passwd);
			printf("role: ");
			scanf("%d", &pcur->m_role);
			
			//打开文件
			fp_config = fopen(config, "r");
			memset(line, 0, sizeof(line));
			fflush(stdin);
			fgets(line, LINE_LEN, fp_config);
			line[strlen(line) - 1] = 0;

			fp_write = fopen(line, "w");

			pcur = *head;
			while(pcur)
			{
				memset(line, 0, sizeof(line));
				sprintf(line, "%-10s%-10s%d\n", pcur->m_name, pcur->m_passwd, pcur->m_role);
				//puts(line);
				fputs(line, fp_write);
				temp = pcur;
				pcur = pcur->m_next;
				free(temp);
			}
			printf("更新完毕！\n");
		    fflush(stdin);
			break;
		}
		pcur = pcur->m_next;
		if(pcur == NULL)
		{
           printf("没有这个账户！\n");
		   fflush(stdin);
		   break;
		}	
	}
}
void delete_account_infor(char* config,pACCOUNT *head,char *psearch_name)
{
	pACCOUNT pcur = *head,temp,ppre = NULL;
	char line[LINE_LEN];
	FILE * fp_config, *fp_write;

	while(pcur && strcmp(pcur->m_name, psearch_name) != 0 )
	{
		ppre = pcur;
		pcur = pcur->m_next;
	}
		if(pcur == NULL)
		{
			printf("没有这个账户！\n");
			return ;
		}
		else
		{
			
			if(ppre == NULL)
			{
				*head = pcur->m_next;
				free(pcur);
			}else
			{
				ppre->m_next = pcur->m_next;
				free(pcur);
			}

			//写入
			fp_config = fopen(config, "r");
			memset(line, 0, sizeof(line));
			fflush(stdin);
			
			fgets(line, LINE_LEN, fp_config);
			line[strlen(line) - 1] = 0;

			fp_write = fopen(line, "w");

			pcur = *head;
			while(pcur)
			{
				memset(line, 0, sizeof(line));
				sprintf(line, "%-10s%-10s%d\n", pcur->m_name, pcur->m_passwd, pcur->m_role);
				//puts(line);
				fputs(line, fp_write);
				temp = pcur;
				pcur = pcur->m_next;
				free(temp);
			}
			printf("删除完成！\n");
			
		}
}