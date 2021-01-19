/***********************************************/
/*                 extraction.c				   */	
/*			用于gbk汉字编码的全角文字提取器    */
/*			从一段话中仅提取全角数据           */
/*           								   */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0 

/****************************************/
/*				is2byte函数   			*/ 
/*    判断是否为全角文字的第一个字节 	*/
/****************************************/
int is2byte(int ch){
	if(ch > 0xa0){
		return TRUE;	/*2字节文字（全角）*/
	}
	else
		return FALSE;	/*1字节文字（半角）*/ 
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
