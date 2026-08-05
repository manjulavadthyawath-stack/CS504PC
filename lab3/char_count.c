//character count
#include<stdio.h>
#include<string.h>
char data[20][20];
int n;
int main(){
	int i,j,ch;
	char temp[20][30];
	printf("enter no. of frames:");
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		printf("frame %d:",i);
		fgets(data[i],sizeof(data[i]),stdin);
		data[i][strcspn(data[i],"\n")] ='\0';
	}
	for(i=1;i<=n;i++){
	int len = strlen(data[i]);
	temp[i][0] = len+'0';
	temp[i][1] = '\0';
	strcat(temp[i],data[i]);
	}
	printf("\n\t\t At sender:\n");
	printf("Data as frames:\n");
	for(i=1;i<n;i++){
		printf("frame %d",i);
		puts(temp[i]);
	}
	printf("Data Transmitted:");
	for(i=1;i<=n;i++){
		printf("%s",temp[i]);
	}
	//at the reciever
	printf("\n\t\t At the Reciever:\n");
	printf("Data recieved");
	for(i=1;i<=n;i++){
		ch = temp[i][0]-'0';
		for(j=0;j<ch;j++){
			data[i][j] = temp[i][j+1];
		}
		data[i][j] = '\0';
	}	
	printf("\n data after removing count charecters:");
	for(i=1;i<=n;i++){
		printf("%s",data[i]);
	}
	printf("\n\n data in frame form:\n");
	for(i=1;i<=n;i++){
		printf("frame %d",i);
		puts(data[i]);
	}
	return 0;
}
