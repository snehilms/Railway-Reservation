/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int
main ()
{
    struct train{
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
  printf ("\t\t|        Abhijeet, Snehil and Pranshu           |\n");
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
