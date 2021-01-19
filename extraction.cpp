/***********************************************/
/*                 extraction.c				   */	
/*			����gbk���ֱ����ȫ��������ȡ��    */
/*			��һ�λ��н���ȡȫ������           */
/*           								   */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0 

/****************************************/
/*				is2byte����   			*/ 
/*    �ж��Ƿ�Ϊȫ�����ֵĵ�һ���ֽ� 	*/
/****************************************/
int is2byte(int ch){
	if(ch > 0xa0){
		return TRUE;	/*2�ֽ����֣�ȫ�ǣ�*/
	}
	else
		return FALSE;	/*1�ֽ����֣���ǣ�*/ 
}

int main(){
	int ch;
	while((ch = getchar())!=EOF){
		if(is2byte(ch) == TRUE){
			putchar(ch);
			putchar(getchar());
		}
	}
	
	return 0;
} 
