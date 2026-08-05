#include<stdio.h>
#include<string.h>
void main(){
	int i=0,j=0,n,pos;
	char a[20],b[100],ch;
	printf("enter the string:\n");
	scanf("%s",a);
	n=strlen(a);
	printf("enter the position to insert the character:\n");
	scanf("%d",&pos);
	while(pos<1||pos>n+1)
	{
	printf("invalid position,enter again:");
	scanf("%d",&pos);
	}
	getchar();
	printf("enter the character to stuff:\n");
	ch=getchar();
	b[0]='d';b[1]='i';b[2]='e';b[3]='s';b[4]='t';b[5]='x';j=6;
	for(i=0;i<n;i++){
	if(i==pos-1)
	{
		b[j++]='d';b[j++]='i';
		b[j++]='e';
		b[j++]=ch;
		b[j++]='d';b[j++]='i';b[j++]='e';
	}
	if(a[i]=='d'&&a[i+1]=='i'&&a[i+2]=='e'){
	b[j++]='d';b[j++]='i';b[j++]='e';
	}
	b[j++]=a[i];
	}
	if(pos == n+1)
	{
		b[j++]='d';b[j++]='i';b[j++]='e';
		b[j++]=ch;
		b[j++]='d';b[j++]='i';b[j++]='e';
	}
		b[j++]='d';b[j++]='i';b[j++]='e';
		b[j++]='e';b[j++]='t';b[j++]='x';b[j]='\0';
	printf("\nframe after stuffing: \n%s\n",b);
}
	
