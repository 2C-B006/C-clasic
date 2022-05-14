#include <stdio.h>
int main(){
	struct student{
	char name[100];
	int boy;
	int sex;
	};
	struct student list[100];
	int n,i;
	printf("student list: ");
	scanf("%d%*c",&n);
	for (i=0;i<n;i++){
		printf(" ho ten: ");
		gets(list[i].name);
		printf(" nam sinh ");
		scanf("%d%*c",&list[i].boy);
		printf("gioi tinh: ");
		scanf("%d%*c",&list[i].sex);
	}
	char sex[][30]={"- - -","nu","nam"};
	char title[][10]={"ho ten","nam sinh","gioi tinh"};
	for(int i = 0;i<3;i++){
		printf("%s  |",title[i]);
	}	printf("\n");
		for(int i=0;i<n;i++){
			printf("%s\t",list[i].name);
			printf("%d\t",list[i].boy);
			if(list[i].sex>=0 && list[i].sex <=2)
			{
			printf("%s\t",sex[list[i].sex]);				
			}
			
		}printf("\n");
	
}
	

