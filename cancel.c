#include <stdio.h>
#include <string.h>

#define MAX 256

  int main() 
  {     
        int line, ctr = 0,ctr1 = 0;
        
char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX];
        char str[MAX], temp[] = "temp.txt";
        int refund;
		printf("\n\n Welcome to the Ticket Cancellation utility :\n");
		printf("-----------------------------------------\n"); 
		printf(" Input the file name to be opened :\n (Only for testing. To be set to the ticketlist file later.)");
		scanf("%s",fname);		
        
        /* Display available tickets */
          fptr1=fopen(fname,"r"); 
          ch=fgetc(fptr1); 
          printf(" Tickets booked till now\n"); 
           printf("%d) ",ctr1);
                      ctr1++;
          while(ch!=EOF) 
            { 
                printf("%c",ch);
                if(ch == 10)
                   {
                      printf("%d) ",ctr1);
                      ctr1++;
                   }  
                ch=fgetc(fptr1);
                
            }
        fclose(fptr1);
        /*Deletion starts*/
fptr1 = fopen(fname, "r");

        if (!fptr1) 
		{
                printf("Ticket list not found\n");
                return 0;
        }
        fptr2 = fopen(temp, "w"); /* Temporary file for writing to */
        if (!fptr2) 
		{
                printf("Could not open Temporary file.\n");
                fclose(fptr1);
                return 0;
        }
        printf(" Enter the Serial Number of the booking you want to cancel: ");
        scanf("%d", &line);
		line++;
        
        /* copy all contents to the temporary file except the specific line */
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != line) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		// remove the original file 
        rename(temp, fname); 	// rename the temporary file to original name
/* Display again */
   fptr1=fopen(fname,"r"); 
            ch=fgetc(fptr1); 
          printf("Your booking has been cancelled sucessfully.\n");
          printf("Tickets Booked till now:\n"); 
          while(ch!=EOF) 
            { 
                printf("%c",ch); 
                 ch=fgetc(fptr1); 
            }
        fclose(fptr1);
/* Laite */
        return 0;

  } 

