#############################################################
ReadMe for assignment submitted by 2019B2PS0985P
Practical section number: P4
Assignment question attempted: 6.(Railway Reservation System for Migrant Labours)
#############################################################
Team:
1. 2019B2PS0985P	Snehil S Kumar
2. 2019B5PS0688P 	Abhijith M.B  
3. 2019B5PS0518P	Pranshu Khare
#############################################################
Description of how to run the code and observe the output: 
1. The c file is called 2019B2PS0985P_P4.c.
To compile the code enter gcc 2019B2PS0985P_P4.c in the terminal window.
For running the code enter ./a.out in the terminal window. 
2. It is a menu-driven application. 
3. The input files are booking.txt used for storing the passenger details and data.txt for storing the train list detail. 
4. On running the program a menu driven interface appears prompting to Enter the options for finding the available trains, enquiring for passenger details, booking a ticket
or cancelling the train tickets.

enquiry()---> Finds and Display the Train details(stored in data.txt) corresponding to the destination entered by the user.
ticketdetails()---> Finds and Display the Passenger details(booking.txt) corresponding to the Name entered by the user.
trainlist()---> Displays the entire list of Trains with their details(TrainNo,Destination,Source,TrainAmount,SeatsLeft)
train_ticket---> Booking the a ticket for a train corresponding to the destination entered by the user 
followed by the Name for booking and storing the Passenger details in booking.txt.  
old_record()---> Displays the list of All the Passenger Bookings from booking.txt.
cancel()---> Cancels the Entry from booking.txt corresponding to the Name entered by the user(This name should be the same as used while booking the ticket) 
The cancel function creates a temporary file for storing all the entries after cancellation except the entry to be deleted in temp.txt which is then renamed as booking.txt(the earlier booking.txt is removed)
decrement_seat_no(char [])---> Decrements the seat no on each new booking for a particular train and updates the data.txt with new seatsleft.
increment_seat_no(char [])---> Increments the seat no on each cancellation for a particular train and updates the data.txt with new seatsleft.

############################################################
Known Requirement of the code:
1. The Train Source and Destination should start with a Capital letter followed by small letters. (eg.Surat)---->Not a limitation but a Requirement.
2.Please write the names wherever asked as input in the same format as entered during booking of the ticket.
#############################################################
Contributions of the team members:
Snehil
Abhijith 
Pranshu 
#############################################################
