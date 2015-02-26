#ifndef __SIMS__
#define __SIMS__
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#define PWD_LEN 10
#define NAME_LEN 20
#define LINE_LEN 512
#define CONFIRM_CNT 3
#define M1 "1.search students information"
#define M2 "2.add    students information"
#define M3 "3.update students information"
#define M4 "4.delete students information"
#define M5 "5.search user  account"
#define M6 "6.add    user  account"
#define M7 "7.update user  account"
#define M8 "8.delete user  account"
#define M9 "9.exit"

#define S1 "1.search by  name"
#define S2 "2.search by  id"
#define S3 "3.return above"
typedef struct stu_accout_tag
{
	char m_passwd[PWD_LEN];
	char m_name[20];
	int  m_role ;
	struct stu_accout_tag* m_next ;
}ACCOUNT, *pACCOUNT;
typedef struct stu_info_tag
{
	int m_id ;
	char m_name[NAME_LEN];
	char m_gender ;
	float m_socres[5] ;
	struct stu_info_tag* m_next ;
}STU, *pSTU;

void system_init(char* config, pACCOUNT* pphead_acc, pSTU* pphead_stu) ;
int role_confirm(pACCOUNT phead_acc);
int show_system_menu(int role);
int show_search_menu(int role);
void search_usr_infor_by_id(pSTU *infor,int psearch_id);
void search_usr_infor_by_name(pSTU *infor,char *psearch_name);
void add_usr_infor(char* config,pSTU *infor);
void update_usr_infor(char* config,pSTU* infor,int search_id);
void delete_usr_infor(char* config,pSTU* infor,int search_id);
void search_account_infor_by_name(pACCOUNT *head, char *psearch_name);
void add_account_infor(char* config,pACCOUNT *head);
void update_account_infor(char* config,pACCOUNT *head,char *psearch_name);
void delete_account_infor(char* config,pACCOUNT *head,char *psearch_name);
#endif