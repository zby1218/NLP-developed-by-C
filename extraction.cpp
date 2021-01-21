
//	@名称：extraction.c				   
//	@描述：用于gbk汉字编码的3-gram全角文字提取器    
//	@目的：从一段话中仅提取全角数据并以3-gram形式输出          
						   


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
//以3-gram输出即一行输出三个文字，一个文字2字节，共六个字节 
#define N 6	

//	@名称：invert
//	@用途：反转flag
int invert(int flag){
	if(flag == TRUE){
		return FALSE;
	}
	return TRUE;
} 

//	@名称：put3gram
//	@用途：以3-gram形式输出文字
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

 
//	@名称：is2byte函数   			 
//  @用途：判断是否为全角文字的第一个字节 	
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
			put3gram(ch);
			put3gram(getchar());
		}
	}
	
	return 0;
} 

