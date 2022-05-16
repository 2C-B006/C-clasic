#include <stdio.h>

struct student{
	char name[50];
	int boy;
	int sex;
	};



char* line (char c,int len){
	 static char s[100]="=";
	for(int i=0;i<len;i++)
		s[i]= c;
		s[len]='\0';
		return s;

}
int strlen( char s[]){
	int len = 0;
	while(s[len]!=0){
		len++;
	}
	return len;
}
char* alignleft(char s[],int len){
	static char s1[1000];
	for(int i = 0;i<strlen(s);i++)
	s1[i]= s[i];
	for(int i=strlen(s);i<len;i++)
	s1[i]=32;
	s1[len]='\0';
	return s1;
}
//hàm căn giữa;
char* center (char s[],int len){
	int llen = len - strlen(s);
	llen/= 2;
	static char s_new[1000];
	for(int i = 0;i<llen;i++)
	s_new[i]= 32 ;//32 là khoang trang;
	for(int i = 0;i<strlen(s);i++)
	s_new[llen + i]=s[i];
	for(int i = llen + strlen(s);i<len;i++)
	s_new[i]=' ';
	s_new[len]='\0';
	return s_new;
	
	}
	
void printfline(char c){
		printf("+%s+",line(c,52));
		printf("%s+",line(c,10));
		printf("%s+",line(c,12));
		printf("\n");
	}
void printftitle(){
	char title [][10]={"ho ten ","nam sinh","gioi tinh"};
	printfline('=');
	printf("| %s ",center(title[0],50));
	printf("| %s ",center(title[1],8));
	printf("| %s |\n",center(title[2],10));
	printfline('=');
		
}	
void showall(struct student list[],int n){

char sex[][10]={"- - -","nu","nam"};
		printftitle();	
for(int i=0;i<n;i++){
		printf("| %s ",alignleft(list[i].name,50));
		printf("| %04d%3s",list[i].boy," ");
if(list[i].sex>=0 && list[i].sex <=2)
		{
		printf("  | %s |\n",center(sex[list[i].sex],10));				
		}
		printfline('-');
	}	printf("\n");
}
void savefile(struct student list[],int n){
	FILE *f;
	f = fopen("D:\\SL\\qlhs.txt","w");
	if(f ==NULL){
		printf("khong tao duoc file");
		return;
	}
	for(int i = 0;i<n;i++){
		fwrite(&list[i],sizeof(struct student),1,f);
		if(fwrite==0){
			printf("luu noi dung hs khong thanh cong");
			return;
		}
	}
	fclose(f);
}
void readfile(char filepath[]){
	FILE *f;
	f = fopen(filepath,"r");
	if(f==NULL){
		printf("file bi loi");
		return;
		
	}
	struct student list[1000];
	int i = 0;
	while(fread(&list[i],sizeof(struct student),1,f))
	i++;
	fclose(f);
	showall(list,i);
	
}

	
	
int main(){
	struct student list[100];
	int n,i;
	int luachon;
do{
		printf("=======menu========\n");
		printf("1 - load data.\n");
		printf("2 - nhap du lieu.\n");
		printf("3 - in danh sach thong tin.\n");	
		printf("4 - luu thong tin hoc sinh.\n");
		printf("5 - thoat.\n");
		printf("lua chon ?: ");
		
		scanf("%d",&luachon);
		printf("------------\n");
		
switch(luachon){
	case 1:
		readfile("D:\\SL\\qlhs.txt");
		break;
	case 2:
		printf("student list: ");
		scanf("%d%*c",&n);

	for (i=0;i<n;i++){
			printf(" ho ten: ");
			gets(list[i].name);
			printf(" nam sinh ");
			scanf("%d%*c",&list[i].boy);
			printf("gioi tinh: ");
			scanf("%d%*c",&list[i].sex);
			printf("------------\n");
}
		break;	
	case 3:
		showall(list,n);
		break;
	case 4:
		savefile(list,n);
		break;
	case 5:
		printf("END");
		return 0;
	}
}while(luachon);	

	
	showall(list,n);
	savefile(list, n);
	readfile("D:\\SL\\qlhs.txt");
	
	

}

	
