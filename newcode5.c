/******************************************************************************
                           Online C Compiler.
               Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFFER_SIZE 1000
 struct train{
 char source[50];
 char dest[50];
 int train_num;
 int trainamt;
 int seats_left;
};
struct ticket
{
  char pass_name[50];
  int pnr;
  int train_num2;
  int trainamt2;
  int seat_no;
};
void enquiry(void);
char *enquirymenu(char *);
int bookingmenu();
void ticketdetails(char *name);
int indexOf(FILE *fptr,  char *dest, int *line, int *col);
int main ()
{
     int menu_choice;
    while(menu_choice!=4)
{
 printf ("\n\t\t=================================\n");
 printf ("\t\t    TRAIN RESERVATION SYSTEM");
 printf ("\n\t\t=================================");
 printf ("\n\t\tPress 1 to Book a new Ticket");
 printf ("\n\t\t------------------------");
 printf ("\n\t\tPress 2 to Enter the Enquiry Menu");
 printf ("\n\t\t------------------------");
 printf ("\n\t\tPress 3 to Cancel  your Reservation");
 printf ("\n\t\t------------------------");
 printf ("\n\t\tPress 4 to Exit");
 printf ("\n\t\t------------------------");
 printf ("\n\n\t\tEnter your choice:");
 scanf ("%d", &menu_choice);


 switch (menu_choice)
   {
   case 1:
     printf ("\t\tchoice 1 selected\n");
     bookingmenu();
     break;
   case 2:
     printf ("\t\tchoice 2 selected");
     enquiry();
     break;
   case 3:
     printf ("\t\tchoice 3 selected");
     break;
   case 4:
     printf ("\t\tchoice 4 selected");
     break;
   default:
     printf("\n\t\tInvalid choice. Please select something between 1 and 4 or I will come to kill you");
     break;
   }

}
return(0);
}
 char dest[15];
 void enquiry()
 {
   int option;
    printf("\n\t\t1.View all train list");
    printf("\n\t\t2.Enquire available trains\n");
    printf("\n\t\t3.Get Ticket Details\n");
    printf("\t\tEnter your choice:");
   scanf("%d",&option);
   switch(option){
     case 1:
      {
      FILE *fp;
    char str[100];
    fp= fopen("Trainlist.txt","r");
    if(fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    while(fgets(str,99,fp)!=NULL)
    {
        printf("%s",str);

    }
   fclose(fp);
     break;
      }
     case 2:
    {

    printf("\n\t\tEnter your destination:");
     scanf("%s",&dest);
     printf("\n\t\tTrainno        TrainSource      TrainDestination        Fare    Seatleft\n\t\t");
     enquirymenu(dest);

     break;
     default:
     printf("Enter only among the given values\n");
     break;
    }
     case 3:
        {
            char name[15];
            printf("\t\tEnter your name: ");
            scanf("%s",&name);
            ticketdetails(name);

        }
   }
 }
 char st[512];
 char *enquirymenu(char *dest)
{
   FILE *fptr;
   int line, col;
    fptr = fopen("Trainlist.txt", "r");
 if (fptr == NULL)
 {
     printf("Unable to open file.\n");
     printf("Please check you have read/write previleges.\n");
     exit(1);
 }
 indexOf(fptr, dest, &line, &col);
 rewind(fptr);
 int end, loop;

 line=line+1;
 if (line != -1)
{
   for(end = loop = 0;loop<line;++loop){
   if(0==fgets(st, sizeof(st), fptr)){
       end = 1;
       break;
   }
}
if(!end)
   {
    printf("%s", st);
    fclose(fptr);
   return st;
   }
}
 else
     {printf("'%s' does not exists.", dest);
 fclose(fptr);
     }

}
int indexOf(FILE *fptr, char *dest, int *line, int *col)
{
   char str[BUFFER_SIZE];
   char *pos;
   *line = -1;
   *col  = -1;
   while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
   {
       *line += 1;
       pos = strstr(str, dest);
       if (pos != NULL)
       {
           *col = (pos - str);
           break;
       }
   }
   if (*col == -1)
       *line = -1;
   return *col;
}


int count=0;
int bookingmenu()
{
    count++;
    struct ticket b;
    char destina[15];
    FILE *frp;
    char *traindetail;
    char *ch;
    printf("\t\tEnter your Destination: ");
    scanf("%s",&destina);
    ch=enquirymenu(destina);
    printf("\n\t\tEnter the passenger name: ");
    scanf("%s",&b.pass_name);
    int amt;
    char store[4]="";
    int j=strlen(st);
     for(int i=j-5;i<j;i++)
     {
         strcat(store,st+i);                  //strcat(store,&st[i]); This can also be used
     }
     amt = atoi(store);
    printf("%d\n",amt);
     b.trainamt2=amt;
    char trainnum[5]="";
    for(int i=0;i<5;i++)
    {
        strcat(trainnum,st+i);
    }
    int notrainnumber=atoi(trainnum);
    printf("%d\n",notrainnumber);
    b.train_num2=notrainnumber;
      frp = fopen("booking.txt","a");                //if i place the booking function here then it is fine but at the above location there is some issue
    if(frp == NULL)
	{
		printf("File not Found");
		exit(1);
	}
	else
        {
    fprintf(frp,"%s,%s,%d,%d",destina,b.pass_name,b.trainamt2,b.train_num2);
    printf("Booking Done");
	}
    fclose(frp);
	b.seat_no=count;

}

ticketdetails(char *name2)
{
    FILE *qtp;
    struct ticket a;
    qtp = fopen("booking.txt","r");
	if(qtp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
    		{
    		    while(getc(qtp) != EOF)
		{
			fscanf(qtp,"%s %d %d",a.pass_name,a.train_num2,&a.trainamt2);
			if(strcmp(a.pass_name,name2) == 0)
			{
			    printf("\n\t\tTICKET DETAILS");
				printf("\n\t\tPassenger Name ::%s",a.pass_name);
				printf("\n\t\tTrainNo ::%d",a.train_num2);
				printf("\n\t\t:Seat No:%d",a.seat_no);
				printf("\n\t\tPrice of ticket::%d",a.trainamt2);
			}
		}

}
}


