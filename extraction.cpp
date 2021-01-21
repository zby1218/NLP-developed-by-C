
//	@���ƣ�extraction.c				   
//	@����������gbk���ֱ����3-gramȫ��������ȡ��    
//	@Ŀ�ģ���һ�λ��н���ȡȫ�����ݲ���3-gram��ʽ���          
						   


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
//��3-gram�����һ������������֣�һ������2�ֽڣ��������ֽ� 
#define N 6	

//	@���ƣ�invert
//	@��;����תflag
int invert(int flag){
	if(flag == TRUE){
		return FALSE;
	}
	return TRUE;
} 

//	@���ƣ�put3gram
//	@��;����3-gram��ʽ�������
void put3gram(int ch){
	static char queue[N] = "     ";
	static int flag = FALSE;
	int i;
	for(i = 0;i < N - 1;i++){
		queue[i] = queue[i+1];
	}
	queue[N - 1] = ch;
	if(flag == TRUE){
	
		for(i = 0;i < N;i++){
			putchar(queue[i]);
		
		}
			putchar('\n');
	}
	flag = invert(flag); 
	
}

 
//	@���ƣ�is2byte����   			 
//  @��;���ж��Ƿ�Ϊȫ�����ֵĵ�һ���ֽ� 	
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
			put3gram(ch);
			put3gram(getchar());
		}
	}
	
	return 0;
} 

