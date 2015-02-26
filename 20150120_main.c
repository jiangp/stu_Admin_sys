#include"20150120_sims.h"
int main(int argc, char* argv[])
{
	int a;
	pACCOUNT account_list = NULL;
	pSTU stu_list = NULL ;
	int role;

	int select;
	int search_id;
	char search_name[NAME_LEN];
	pSTU stu_add_infor=NULL;
	system_init(argv[1], &account_list, &stu_list);

	if( (role = role_confirm(account_list) )== -1)
	{
		printf("fail to login\n");
		system("pause");
		return 0 ;
	}
	while(system("cls"),(select = show_system_menu(role)) != 9)
	{
		if(role == 1)
		{
			switch(select)
			{
			case 1: 
				{
					while(fflush(stdin),(select=show_search_menu(role))!=3)
					{
						if(select==2)
						{
							system("cls");
				            printf("Enter seach_id : ");
							
							fflush(stdout);
				            fflush(stdin);
							scanf("%d",&search_id);
							search_usr_infor_by_id(&stu_list,search_id);
							fflush(stdin);
				            getchar();
			        
						}else if(select==1)
						{
							system("cls");
				            printf("Enter seach name : ");
							fflush(stdout);
				            fflush(stdin);
							gets(search_name);
							search_usr_infor_by_name(&stu_list,search_name);
				            getchar();
				         //   getchar();

						}else
						{
							search_usr_infor_by_id(&stu_list,0);
							getchar();
				          //  getchar();
						}
					}
				}
				break;
			case 2:  
				{
					system("cls");
				    printf("add student information:\n");
                    add_usr_infor(argv[1],&stu_list);
					getchar();
				//	getchar();

				}
				break;
			case 3: 
				
				    system("cls");
					printf(" update stu infor: ");
					fflush(stdout);
					fflush(stdin);
					scanf("%d", &search_id);
					update_usr_infor(argv[1],&stu_list,search_id);
					getchar();
				//	getchar();
				break;
			case 4: 
				
			        system("cls");
					printf("Enter delete id: ");
					fflush(stdout);
					fflush(stdin);
				//	if( (scanf("%d", &search_id) == 1) )
				//	{
				    	scanf("%d", &search_id);
						delete_usr_infor(argv[1],&stu_list,search_id);
						fflush(stdin);
						getchar();
					//	getchar();
			//		}
				break;
			case 5:  
				system("cls");
			    printf("Enter seach account name : ");
				fflush(stdout);
				fflush(stdin);
				gets(search_name);           
				search_account_infor_by_name(&account_list,search_name);
				getchar();
				break;
			case 6: 
				system("cls");
			    printf("Enter add account name: ");
				add_account_infor(argv[1],&account_list);
				getchar();
				break;
			case 7:  
				system("cls");
				fflush(stdout);
				fflush(stdin);
				printf("Enter update account name:");
				gets(search_name);
				update_account_infor(argv[1],&account_list,search_name);
				getchar();
				break;
			case 8: 
				system("cls");
				fflush(stdout);
				fflush(stdin);
				printf("Enter delete account name:");
				gets(search_name);
				delete_account_infor(argv[1],&account_list,search_name);
				getchar();
				break;
			case 9: 
				printf("exit");
				break;
			}
		}else
		{
			switch(select)
			{
			case 1: 
				 {
					while(fflush(stdin),(select=show_search_menu(role))!=3)
					{
						if(select==2)
						{
							system("cls");
				            printf("Enter seach_id : ");
							
							fflush(stdout);
				            fflush(stdin);
							scanf("%d",&search_id);
							search_usr_infor_by_id(&stu_list,search_id);
							fflush(stdin);
				            getchar();
				      
						}else if(select==1)
						{
							system("cls");
				            printf("Enter seach name : ");
							fflush(stdout);
				            fflush(stdin);
					    	gets(search_name);
							search_usr_infor_by_name(&stu_list,search_name);
							fflush(stdin);
				            getchar();
				        

						}else
						{
							search_usr_infor_by_id(&stu_list,0);
							getchar();
				            getchar();
						}
					}
				}
				break;
			case 9: 
				printf("return");
				break;
			}
		}
	}

	system("pause");
	return 0 ;
}