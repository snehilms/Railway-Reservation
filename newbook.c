
#include<stdio.h>
#include<stdlib.h>
struct train
{
	char trainno[20];
	char destination[20];
	int cost;
}b;

int seat = 50 ;

void insert_details();
void viewAll();
void find();
void train_ticket();
void old_record();
void main()
{
	 int ch;
 	do{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");
	printf("\t Train Ticket training ");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\nEnter >1< To Insert Trains");
   	printf("\nEnter >2< To View All Trains");
	printf("\nEnter >3< To Find Trains");
	printf("\nEnter >4< To train Tickets");
	printf("\nEnter >5< To View All Transactions");
   	printf("\nEnter >0< To Exit ");

   	printf("\nEnter your Choice ::");
   	scanf("%d",&ch);
	   system("cls");

   	switch (ch)
   	{
    		case 1 :
    		insert_details();
   		break;
		case 2:
    		viewAll();
   		break;

		case 3:
    		find();
   		break;

		case 4:
		train_ticket();
		break;

		case 5:
		old_record();
		break;

    		case 0:
    		exit(0);
    		break;

    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);

}

void insert_details()
{
	FILE *fp;
	struct train b;
	printf("Enter Trainno :- ");
	scanf("%s",b.trainno);
	printf("Enter  name :- ");
	printf("Enter destination:- ");
	scanf("%s",b.destination);
	printf("Enetr Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s  %s %d \n",b.trainno,b.destination,b.cost);
		printf("Recorded Successfully");
	}
		printf("\n");
	fclose(fp);
	system("cls");
}
void find()
{
	struct train b;
	FILE *fp;
	char ch[20];
	printf("Enter Destination :");
	scanf("%s",ch);

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %d",b.trainno,b.destination,&b.cost);
			if(strcmp(b.destination,ch) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
			}
		}
	}
	fclose(fp);
}
void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
}
void train_ticket()
{
 struct train b;
	FILE *fp;
	FILE *ufp;
	char name[20];
	char ch;
	char dest[20];

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);

	printf("\n Enter the destination :");
	scanf("%s",dest);

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %d",b.trainno,b.destination,&b.cost);
			if(strcmp(b.destination,dest) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tTrain No ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket::%d",b.cost);
			}
		}

	}
	printf("\n* Fill Details  *");
	printf("\n Enter your Name :");
	scanf("%s",name);
    printf("\n\t\ttraining Confirmed");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tDestination : %s",b.destination);
	printf("\n\t\tTrain Amount : %d",b.cost);

	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %s %d\n",name,b.trainno,b.destination,b.cost);
		printf("\n training Done");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);
}

void old_record()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		system("cls");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);


}


