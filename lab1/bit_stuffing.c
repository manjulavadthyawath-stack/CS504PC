#include<stdio.h>
	void main(){
	int ip_frame[100],op_frame[200];
	int i,j = 0,n;
	int count = 0;
	printf("enter the frame length: ");
	scanf("%d",&n);
	printf("enter the input frame(0's and 1's only:\n");
	for(i=0;i<n;i++){
	scanf("%d",&ip_frame[i]);
	}
	for(i=0;i<n;i++){
	op_frame[j++] = ip_frame[i];
	if(ip_frame[i]==1){
	count++;
	if(count==5)
		{
		op_frame[i++]=0;
		count=0;
		}
	}
	else{
	count=0;
	}
	}
	printf("\n after bit stuffing the frame is:\n");
	for(i=0;i<j;i++)
	{
	printf("%d",op_frame[i]);
	}
	printf("\n");
	}

