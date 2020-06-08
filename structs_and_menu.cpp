#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bookaticket();
int findmaxpnrno();
 struct train
    {
	char source[50];
	char dest[50];
	int train_num;
	int seats_left;
    };
struct ticket
   {
   char passenger_name[50];
   int pnr;
   int train_num;

   };


int main ()
{
   

 printf ("\t\t=================================================\n");
 for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|        -----------------------------          |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|       TRAIN TICKET RESERVATION SYSTEM         |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|        -----------------------------          |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|              	 CREATED BY                     |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|        Abhijith, Snehil and Pranshu           |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t|                                               |\n");
  for(int i=0;i<=33126000;i++);
  printf ("\t\t=================================================\n\n\n");
  for(int i=0;i<=63126000;i++);






  // login();
  int menu_choice, choice_return;


  printf ("\n\t\t=================================\n");
  printf ("\t\t    TRAIN RESERVATION SYSTEM");
  printf ("\n\t\t=================================");
  printf ("\n\t\tPress 1 to Reserve A Ticket");
  printf ("\n\t\t------------------------");
  printf ("\n\t\tPress 2 to View All Available Trains");
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
      // reservation function
      printf ("\t\tchoice 1 selected");
      bookaticket();
      break;
    case 2:
      // viewdetails function
      printf ("\t\tchoice 2 selected");

      break;

    case 3:
      //cancel function
      printf ("\t\tchoice 3 selected");

      break;
    case 4:

      printf ("\t\tchoice 4 selected");
      break;

    default:
      printf
	("\n\t\tInvalid choice. Please selecct something between 1 and 4 or I will come to kill you");
      break;
    }

  return (0);
}
void bookaticket()
{
    int buffer;char buff[40];
    FILE *fp,*gp;
    fp=fopen("textfileB","a+");
    struct ticket a;
    printf("enter the number of seats to be booked");
    scanf("%d",&x);
    printf("Enter the train number");
    fgets(buffer,10,stdin);
    //use the enquiry function from the question 5
    //check if x is less than the available seats
    if(x</*available no of seats*/)
    {

    printf("enter the boarding point");
    printf("enter the destination point");
    int prno=findmaxpnrno();
    for(int i=0;i<x;i++)
       {
         printf("Enter the name of the passenger");
         fgets(buff[i][40],40,stdin);
         hisprno=++prno;
         fputs(buffer,fp);//input all the data into the file.
         fputs(buff[i][40],fp);
         fputs(hisprno,fp);
         //decrease the number of seats left by 1
       }
    }
    else
        printf("sorry seats are already booked check another train");

}
int findmaxpnrno()
{    file fp;
     fp=fopen("textfileB","r");

     //textfileB is having the list of all the tickets booked so far
     //now we have to read through the text file and find the biggest pnr no so far
     //return that pnr no
    return prnmax;
}
