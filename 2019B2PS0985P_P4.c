#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
/*Structure for the train*/
struct train
{
	char trainno[20];
	char destination[20];
	int cost;
	int seatsleft;
}b;
/*Structure for the ticket*/
struct ticket
{
    char passname[15];
    int pnrno;
    int seatno;
}c;

int seat = 50;
/*Declaring all the functions used in the program*/
void trainlist();
int enquiry();
void ticketdetails();
void train_ticket();
void old_record();
void cancel();
void decrement_seat_no(char destinationto[]);
void increment_seat_no(char destinationto[]);

void main()
{
	int ch;
  	do{
		//Program Menu
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\n");
		printf("\t Train Ticket Booking ");     //Menu Driven Railway Booking System
		printf("\n");
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\nEnter >1< To View All Trains");
		printf("\nEnter >2< To Inquire about Trains");
		printf("\nEnter >3< To Book Tickets");
		printf("\nEnter >4< To View All Transactions");
        printf("\nEnter >5< To find passenger details");
		printf("\nEnter >6< To Cancel Train Ticket");
		printf("\nEnter >0< To Exit ");
		/*Taking input for the choice selected*/
		printf("\nEnter your Choice ::");
		scanf("%d",&ch);
		system("clear");

		switch (ch)
		{
			case 1 :
				trainlist();                      //Calls the Function to view all Trains
				break;
			case 2:
				enquiry();                      //Calls the Function to inquire about the Trains
				break;
			case 3:
				train_ticket();                 //Calls the Function to book a ticket
				break;
			case 4:
				old_record();                   //Calls the Function to view all Booked Tickets
				break;
			case 5:
                ticketdetails();                //Calls the Function to view the details of a particular ticket
				break;
			case 6:
			    cancel();                       //Calls the Function to cancel a ticket
				break;
			case 0:
				exit(0);                        //Exit the program
				break;
			default:
				printf("Wrong choice !");
				break;
		}
 	}while(ch!=0);
}

int enquiry()                   //Function to inquire about the Trains
{
	struct train b;
	FILE *fp;
	char ch[20];
	char source[20];
	printf("Enter Source :");
	scanf("%s",source);
	printf("Enter Destination :");
	scanf("%s",ch);
	if(strcmp(source,"Delhi"))
    {
        printf("No Trains available");
        return 0;
    }
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
			fscanf(fp,"%s %s %d %d",b.trainno,b.destination,&b.cost,&b.seatsleft);          //Reads formatted input from the pointer fp pointing to "data.txt"
			if(strcmp(b.destination,ch) == 0)                                               //Compares the input destination with the available destinations
			{
				printf("\n Record Found\n");
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
				printf("\n\t\tSeats Left::%d",b.seatsleft);
				break;
			}
		}
	}
	fclose(fp);
}
void ticketdetails()                //Function to view the details of a particular
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
		while(!feof(qp))
		{
			fscanf(qp,"%s %s %s %d %d",c.passname,b.trainno,b.destination,&b.cost,&c.pnrno);         //Reads formatted input from the pointer qp pointing to "booking.txt"
			if(strcmp(c.passname,temp) == 0)                                                        //Compares the input name with the Booked names
			{
				printf("\n Record Found\n");
				printf("\n\t\tPassenger Name::%s",c.passname);
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
				printf("\n\t\tPnr No::%d",c.pnrno);
				break;
			}
		}
	}
	fclose(qp);
}
void trainlist()                  //Function to view all Trains
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
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
			printf("%c",ch);                        //  Printing the entire content of "data.txt" having the train details.
	}
	fclose(fp);
	}
void train_ticket()                 //Function to book a ticket
{
	struct train b;
	struct ticket c;
	FILE *fp;
	FILE *ufp;
	FILE *rp;
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
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
			printf("%c",ch);
	}
	fclose(fp);
	printf("\n Enter the destination :");
	scanf("%s",dest);
	rp=fopen("booking.txt","r");
	c.pnrno=0;                       //Initializing PNR to 0
	if(getc(rp)!=EOF)
	{
		while(getc(rp) != EOF)      //This loop is to find the PNR of the last booking and store the information corresponding to that booking.
		{
			fscanf(rp,"%s %s %s %d %d",c.passname,b.trainno,b.destination,&b.cost,&c.pnrno);        //Reads formatted input from the pointer qp pointing to "booking.txt".
			if(getc(rp) == EOF)
			{
				break;
			}                                              //The extracted PNR is the PNR of the previous booking i.e it will be the largest Booked PNR of a passenger.
		}
	}
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
		while(getc(fp) != EOF)                  //This loop find the information of the train corresponding to the input destination and display them.
		{
			fscanf(fp,"%s %s %d %d",b.trainno,b.destination,&b.cost,&b.seatsleft);
			if(strcmp(b.destination,dest) == 0)
			{
				printf("\n Record Found\n");
				printf("\n\t\tTrain No ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket::%d",b.cost);
				printf("\n\t\tseatsleft:%d",b.seatsleft);
				break;
			}
		}
		if(b.seatsleft==0)              //The booking is not possible if no seats are left.
		{
			printf("\t\tsorry this train appears to be full.\nplease another train or try another day ");
			exit(0);
		}
	}
	printf("\n* Fill Details  *");
	printf("\n Enter your Name :");
	scanf("%s",c.passname);
	printf("\n\t\tBooking Confirmed");
	printf("\n\t\tName : %s",c.passname);
	c.pnrno=(c.pnrno+1);                         //    Incrementing the PNR to assign to the new Passenger.
	printf("\n\t\tpr no: %d",c.pnrno);
	printf("\n\t\tDestination : %s",b.destination);
	printf("\n\t\tTrain Amount : %d",b.cost);
	fclose(fp);
	ufp=fopen("booking.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %s %s %d %d\n",c.passname,b.trainno,b.destination,b.cost,c.pnrno);      //  Writing the Passenger data to "booking.txt"
		decrement_seat_no(dest);                       //  Calling Function to decrement the Seat No of the Booked Train.
		printf("\n Booking Done");
	}
	printf("\n");
	fclose(ufp);
	fclose(rp);
}
void old_record()                      //   Function to view all Booked Tickets
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
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
			printf("%c",ch);                        //  Printing the Entire content of  "booking.txt"
	}
	fclose(fp);
}
void cancel()                       //  Function to cancel a ticket
{
	FILE *fptr2;
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
		while(getc(qp) != EOF)              //Loop to find the passenger details to be deleted.
		{
			fscanf(qp,"%s %s %s %d %d",c.passname,b.trainno,b.destination,&b.cost,&c.pnrno);    //Reading the Passenger details using the qp pointing to "booking.txt"
			if(strcmp(c.passname,newname) == 0)                                 //Comparing the name with the passenger name to be deleted.
			{
				printf("\n Record Found\n");                             //Printing the passenger details corresponding to the passenger name to be deleted.
				printf("\n\t\tPassenger Name::%s",c.passname);
				printf("\n\t\tTrainno ::%s",b.trainno);
				printf("\n\t\tDestination ::%s",b.destination);
				printf("\n\t\tPrice of ticket ::%d",b.cost);
				printf("\n\t\tPnr NO::%d",c.pnrno);
				break;
			}
		}
		rewind(qp);
		printf("\nAre you sure you want to delete the booking\n1.Yes\n2.No\n");
		scanf("%d",&value);
		printf("\nRefund Amount:%d",(b.cost)/2);           //   Printing the Refund Amount with 50% deduction.
		if(value==1)
		{
			fptr2 = fopen(temp, "w");    /* Temporary file for writing to */
			if (!fptr2)
			{
				printf("Could not open Temporary file.\n");
				fclose(qp);

			}
			while (!feof(qp))
			{
				fgets(str, MAX, qp2);            // Storing each line in str variable pointed by qp2 pointing to "booking.txt"
				fscanf(qp,"%s %s %s %d %d",c.passname,b.trainno,b.destination,&b.cost,&c.pnrno);   //Reading the passenger details in the "booking.txt" file pointed by qp pointing to booking.txt file
				if (!feof(qp))
				{
					if (strcmp(c.passname,newname) != 0)       // Comparing passenger name with the name to be deleted.
					{
						fprintf(fptr2, "%s", str);            //  Writing Passenger details stored in str to the temporary file except the passenger to be deleted.
					}
					else
					{
						increment_seat_no(b.destination);     //Calling the function to increment seat no corresponding to the destination of the passenger.
					}
				}
				strcpy(str, "\0");           //To empty the str variable at the end of each loop for new entries to be checked.
			}
			fclose(qp);
			fclose(qp2);
			fclose(fptr2);
			remove("booking.txt");            //   Deleting the old booking file followed by
			rename(temp, "booking.txt");      //   Renaming the temporary file to "booking.txt".
		}
	}
}
void decrement_seat_no(char destinationto[25])      //Function to decrement the seat for each booking corresponding to the destinatjon.
{
	FILE *fptr2;
	char temp[] = "temp.txt";
	struct ticket f;
	struct train e;
	FILE *qp;
	FILE *qp2;
	qp =fopen("data.txt","r");
	qp2 =fopen("data.txt","r");
	if(qp == NULL)
	{
		printf("File does not found !");
		exit(1);
	}
	else
	{
			fptr2 = fopen(temp, "w"); /* Temporary file for writing to */
			if (!fptr2)
			{
				printf("Could not open Temporary file.\n");
				fclose(qp);

			}
			while (!feof(qp))                       //Looping to Find the train details for decrementing the Seat No.
			{
				fscanf(qp,"%s %s %d %d",e.trainno,e.destination,&e.cost,&e.seatsleft);      //  Reading the train details from data.txt pointed by qp pointer
				if (!feof(qp))
				{
					if (strcmp(e.destination,destinationto)== 0)        //  Comparing the passenger destination with the destination from data.txt.
					{
						e.seatsleft--;                                  //  Decrementing the seats left corresponding to the booking destination
					}
					fprintf(fptr2,"%s %s %d %d\n",e.trainno,e.destination,e.cost,e.seatsleft );     //  Writing the updated train details to the temporary file.
				}
			}                   //Updating the seat left corresponding to only the booking destination.
			fflush(qp);         //Emptying the buffer opened by FILE pointed by qp.
			fflush(qp2);        //Emptying the buffer opened by FILE pointed by qp2.
			fclose(qp);
			fclose(qp2);
			fclose(fptr2);
			remove("data.txt");          //  Deleting the data.txt
			rename(temp,"data.txt");    //  Renaming temporary file to data.txt.
	}
}
void increment_seat_no(char destinationto[25])          //Function to incrementing the seat for each booking corresponding to the destinatjon
{
	FILE *fptr3;
	char temp[] = "temp2.txt";
	struct ticket f;
	struct train e;
	FILE *qp4;
	FILE *qp5;
	qp4 =fopen("data.txt","r");
	qp5 =fopen("data.txt","r");
	if(qp4 == NULL)
	{
		printf("file does not found !");
		exit(1);
	}
	else
	{
			fptr3 = fopen(temp, "w"); /* Temporary file for writing to */
			if (!fptr3)
			{
				printf("Could not open Temporary file.\n");
				fclose(qp4);

			}
			while (!feof(qp4))              //Looping to Find the train details for incrementing the Seat No.
			{
				fscanf(qp4,"%s %s %d %d",e.trainno,e.destination,&e.cost,&e.seatsleft);         //  Reading the train details from data.txt pointed by qp4 pointer
				if (!feof(qp4))
				{
					if (strcmp(e.destination,destinationto)== 0)        //  Comparing the passenger destination with the destination from data.txt.
					{
						e.seatsleft++;                                  //  Incrementing the seats left corresponding to the booking destination
					}
					fprintf(fptr3,"%s %s %d %d\n",e.trainno,e.destination,e.cost,e.seatsleft );     //  Writing the updated train details to the temporary file.
				}
			}                        //Updating the seat left corresponding to only the booking destination.
			fflush(qp4);             //Emptying the buffer opened by FILE pointed by qp4.
			fflush(qp5);            //Emptying the buffer opened by FILE pointed by qp5.
			fclose(qp4);
			fclose(qp5);
			fclose(fptr3);
			remove("data.txt");          //  Deleting the data.txt
			rename(temp,"data.txt");    //  Renaming temporary file to data.txt.

	}
}
