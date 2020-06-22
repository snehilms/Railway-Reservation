#include<stdio.h>
#include<stdlib.h>
int toppnr=0;
#define MAX 256
struct train
{
	char trainno[20];
	char destination[20];
	int cost;
}b;
struct ticket
{
    char passname[15];
    int pnrno;
    int seatno;
}c;

int seat = 50;

void insert_details();
void viewAll();
void find();
void train_ticket();
void old_record();
int gettoppnr();
void main()

{//c.pnrno=0;

	 int ch;
 	do{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n");
	printf("\t Train Ticket training ");
	printf("\n");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\nEnter >1< To Insert Trains");
   	printf("\nEnter >2< To View All Trains");
   	printf("\nEnter >6< To find passenger details");
	printf("\nEnter >3< To Find Trains");
	printf("\nEnter >4< To Book Tickets");
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

		case 6:
            ticketdetails();
        case 7:
            cancel();
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
	printf("Enter Ticket Price:- ");
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
				break;
			}
		}
	}
	fclose(fp);
}
ticketdetails()
{
    struct ticket c;
    struct train b;
    FILE *qp;
    char temp[15];
    printf("Enter your name ::");
    scanf("%s",temp);

    qp =fopen("booking.txt","r");
    if(qp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while(getc(qp) != EOF)
		{
			fscanf(qp,"%s %s %s %d",c.passname,b.trainno,b.destination,&b.cost);
			if(strcmp(c.passname,temp) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tPassenger Name::%s",c.passname);
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
				break;
			}
		}
	}
	fclose(qp);

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
 struct ticket c;
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
				break;
			}
		}

	}

	c.pnrno=gettoppnr();

	printf("\n* Fill Details  *");
	printf("\n Enter your Name :");
	scanf("%s",c.passname);
    printf("\n\t\tBooking Confirmed");
	printf("\n\t\tName : %s",c.passname);
	c.pnrno=(c.pnrno+1);
	printf("\n\t\tpr no: %d",c.pnrno);
	printf("\n\t\tDestination : %s",b.destination);
	printf("\n\t\tTrain Amount : %d",b.cost);

	ufp=fopen("booking.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %s %d %d\n",c.passname,b.trainno,b.destination,b.cost,c.pnrno);
		printf("\n Booking Done");
	}
		printf("\n");
	fclose(ufp);
	fclose(fp);
}

void old_record()
{
	char ch;
	FILE *fp;
	fp = fopen("booking.txt","r");
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
int gettoppnr()
{
    FILE *fp;
int toppnr;
char ch[25],buffer[25];
fp=fopen("booking.txt","r");

if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
    {while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d %d",b.trainno,b.destination,buffer,&b.cost,&toppnr);
			if(getc(fp) == EOF)
			{
				//printf("\n Record Found\n");
				//printf("\n\t\tTrainno ::%s",b.trainno);
				//printf("\n\t\tDestination ::%s",b.destination);
				//printf("\n\t\tPrice of ticket ::%d",b.cost);
				break;
			}
		}
    }
    return toppnr;
}
void cancel()
 {
     FILE *fptr1, *fptr2;
        char str[MAX], temp[] = "temp.txt";
        int refund;

    struct ticket c;
    struct train b;
    FILE *qp;
    FILE *qp2;

    int value;
    char newname[15];
    printf("Enter your name ::");
    scanf("%s",newname);

    qp =fopen("booking.txt","r");
    qp2 =fopen("booking.txt","r");
    if(qp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while(getc(qp) != EOF)
		{
			fscanf(qp,"%s %s %s %d",c.passname,b.trainno,b.destination,&b.cost);
			if(strcmp(c.passname,newname) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tPassenger Name::%s",c.passname);
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
				break;
			}
		}
        rewind(qp);

		printf("\nAre you sure u want to delete the booking\n1.Yes\n2.No\n");
		scanf("%d",&value);
		if(value==1)
        {

        fptr2 = fopen(temp, "w"); /* Temporary file for writing to */
        if (!fptr2)
		{
                printf("Could not open Temporary file.\n");
                fclose(qp);
                return 0;
        }
             while (!feof(qp))
        {
            fgets(str, MAX, qp2);
            fscanf(qp,"%s %s %s %d",c.passname,b.trainno,b.destination,&b.cost);

            if (!feof(qp))
            {
                if (strcmp(c.passname,newname) != 0)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
           strcpy(str, "\0");
        }
        //typecasting
        //printf("\nRefund Amount:%d",b.cost/2);
        }
        fclose(qp);
        fclose(qp2);
        fclose(fptr2);
        remove("booking.txt");
        rename(temp, "booking.txt");
        }

 }
