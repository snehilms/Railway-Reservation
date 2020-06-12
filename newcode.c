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
char enquirymenu(char *dest);
 void gettrainamt(int *amt,char desti);
int indexOf(FILE *fptr,  char *dest, int *line, int *col);
int main ()
{
 int menu_choice;      // login();
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
     printf ("\t\tchoice 1 selected");  // reservation function
     break;
   case 2:
     printf ("\t\tchoice 2 selected");    // viewdetails function
     enquiry();
     break;
   case 3:
     printf ("\t\tchoice 3 selected");  //cancel function
     break;
   case 4:
     printf ("\t\tchoice 4 selected");
     break;
   default:
     printf("\n\t\tInvalid choice. Please select something between 1 and 4 or I will come to kill you");
     break;
   }
 return (0);

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
 char enquirymenu(char *dest)
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
 char st[512];
 line=line+1;
 if (line != -1)
{
   for(end = loop = 0;loop<line;++loop){
   if(0==fgets(st, sizeof(st), fptr)){//include '\n'
       end = 1;//can't input (EOF)
       break;
   }
}
if(!end)
   printf("%s\n", st);
fclose(fptr);
return st;
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
int gettrainnum(char *ch);
int gettrainnum(char *ch)
{
    char *trainnum;
   trainnum=strstr(trainnum,1);
    return trainnum;
}
int count=0;
bookingmenu()
{
    count++;
    struct ticket b;
    struct train b1[30];
    char mobile[10];
    char *desti;
    FILE *frp;
    char *traindetail;
    char *ch;
    frp = fopen("booking.txt","a");
    if(frp == NULL)
	{
		printf("File not Found");
	}
    printf("Enter your Destination: ");
    scanf("%s\n",&desti);
    fflush(stdin);
    ch=enquirymenu(desti);
    int amt;
   gettrainamt(int &amt,desti);
   b.trainamt2=amt;
    traindetail=gettrainnum(ch);
    b.train_num2=traindetail;
    printf("Enter the passenger name: ");
    scanf("%s",&b.pass_name);
    fwrite(&b,sizeof(b),1,frp);
    fclose(frp);
	b.seat_no=count;
}
const char * pnrgenerate(char name,char mobile,int seatno)
{
    char newname[3];
    char pnr[8];
char newmobile[6];
    for(int i=0;i<3;i++)
    {
        newname =strcat(newname[i],name[i]);
        newmobile = strcat(newmobile[i],mobile[i]);
    }
    pnr = strcat(newname,newmobile);
    return pnr;
}
ticketdetails(char name2)
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

 gettrainamt(int *amt,char desti)
 {
     char store[4];
     int j=strlen(desti);

     for(int i=j-4;i>j-4;i--)
     {
         store= strcat(store,desti[i]);

     }
     amt = atoi(store);

 }

