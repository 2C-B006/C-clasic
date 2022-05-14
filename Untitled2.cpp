#include <stdio.h>
#include <string.h>
int find_pos(char s[],char c){
		for(int i = 0;i<strlen(s);i++){
			if(s[i]==c){
				return i;
				
			}
		
		}
			return -1;
	}

int main(){
	char s[100];
	char s1[100];
	int len[100];
	printf("chain: ");
	gets(s);

	for(int i=0;i<strlen(s);i++){
		int pos = find_pos(s1,s[i]);
		long int m =strlen (s1);
		if(pos == -1){
			s1[m]=s[i];
			s1[m+1]='\0';
			len[s[i]]=1;
			continue;
		}
		if(len[s[i]]<5){
				int j;
			for( j = m; j > pos ;j--){
			
				s1[j]=s1[j-1];
			
			}	
			s1[m+1]='\0';
			s1[pos]=s[i];
			len[s[i]]++;
		}
	}
	for(int i = 0;i<strlen(s1);i++){
		if(len[s1[i]]>1){
			int pos = find_pos(s1,s1[i]);
			long int m = strlen(s1);
			int j;
			for( j = m+2;j>pos + len[s1[i]];j--){
				s1[j]=s1[j-2];
				
			}
				s1[j]='<';
				s1[j+1]='>';
				len[s1[i]]=0;
		}
	}

	
		printf("%s",s1);

	
}
	
