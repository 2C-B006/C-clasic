#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	char rev[100];
	printf("chain: ");
	gets(s);
	int len = 0;
	for(int i = 0;s[len]!='\0';len ++){}
		len --;
		for(int i = len; i>=0;i--){
			rev[len - i]= s[i];
		rev[len+1]='\0';	
		
	}printf("%s\n%s\n",s,rev);
	
}
