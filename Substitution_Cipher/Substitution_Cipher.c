#include <stdio.h>
#include <stdlib.h>

#include <conio.h>
 
int main() {
 
	char *message,*emessage,*dmessage;
 
	int i,j=0,k,key,temp;
 
	clrscr();
 
	printf("\nEnter the key\n");
 
	scanf("%d",&key);
 
	key=key%26;
 
	printf("\nEnter message\n");
 
	fflush(stdin);
 
	gets(message);
 
	for (i=0;message[i]!=NULL;i++)
 
	  message[i]=tolower(message[i]);
 
	for (i=0;message[i]!=NULL;i++) {
 
		//printf("%c ",message[i]);
 
		if(message[i]==' ')
 
		    emessage[j++]=message[i]; else {
 
			if(message[i]>=48 && message[i]<=57) {
 
				temp=message[i]+key;
 
				if(temp>57)
 
				         emessage[j++]=48+(temp-58); else
 
				         emessage[j++]=temp;
 
			} else {
 
				if(message[i]>=97 && message[i]<=123) {
 
					temp=message[i]+key;
 
					if(temp>122)
 
					             emessage[j++]=97+(temp-123); else
 
					             emessage[j++]=temp;
 
				} else
 
				              emessage[j++]=message[i];
 
			}
 
			// printf("%c ",emessage[j]);
 
		}
 
	}
 
	emessage[j]='\0';
 
	printf("\n\n\nEncrypted message is\n\n");
 
	for (i=0;emessage[i]!=NULL;i++)
 
	  printf("%c",emessage[i]);
 
	//  printf("\n end");
 
	for (i=0,j=0;emessage[i]!=NULL;i++) {
 
		if(emessage[i]==' ')
 
		     dmessage[j++]=emessage[i]; else {
 
			if(emessage[i]>=48 && emessage[i]<=57) {
 
				temp=emessage[i]-key;
 
				if(temp<48)
 
				         dmessage[j++]=58-(48-temp); else
 
				         dmessage[j++]=temp;
 
			} else {
 
				if(emessage[i]>=97 && emessage[i]<=123) {
 
					temp=emessage[i]-key;
 
					if(temp<97)
 
					           dmessage[j++]=123-(97-temp); else
 
					           dmessage[j++]=temp;
 
				} else
 
				          dmessage[j++]=emessage[i];
 
			}
 
		}
 
	}
 
	dmessage[j]='\0';
 
	printf("\n\n\nRetrieved message is\n\n");
 
	for (i=0;dmessage[i]!=NULL;i++)
 
	  printf("%c",dmessage[i]);
 
	getch();
 
	return(0);
 
}