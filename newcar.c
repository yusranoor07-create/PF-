#include <stdio.h>

int main(void) {
    int choice;
    char rentChoice;
    int available[5] = {1, 1, 1, 1, 1}; // 1 = available, 0 = rented
    char fullname[50][50];  // i = row , j = col             
    int rentedDays[5] = {0, 0, 0, 0, 0};
    char carCodes[5] = {'A', 'B', 'C', 'D', 'E'};

    while (1) {
        printf("*********************************\n");
        printf("    Welcome To Car Rental System   \n");
        printf("*********************************\n");
        printf("----------System Menu------------\n");
        printf("1) View Available Cars\n");
        printf("2) Return Car\n");
        printf("3) View Rented Cars\n");
        printf("4) Exit\n");
        printf("\n******************************\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // view available cars
            printf("\n----------Available Cars------------\n");
            printf("-------------------------------------\n");
            
            for (int i = 0; i < 5; i++) 
              {
				if (available[i] == 1)
				 {
                    if (i == 0) printf("- ALTO     - 5000/day - Code: A\n");
                    if (i == 1) printf("- CITY     - 7000/day - Code: B\n");
                    if (i == 2) printf("- VITZ     - 6000/day - Code: C\n");
                    if (i == 3) printf("- COROLLA  - 10000/day - Code: D\n");
                    if (i == 4) printf("- CIVIC    - 12000/day - Code: E\n");
                }
            }
            printf("-------------------------------------\n");
            printf("\nWant to Rent a Car? (Y/N, X for Back): ");
            scanf(" %c", &rentChoice);

            if (rentChoice == 'X' || rentChoice == 'x') {
                continue;  //return to main menu
            }

            if (rentChoice == 'Y' || rentChoice == 'y') {
                char code;
                int car_index = -1;  //selected car ka position in the arrays
                int days, amount, inp_amount;

                printf("Please enter car code to proceed: ");
                scanf(" %c", &code);

                // Determine which car and cost
                if ((code == 'A' || code == 'a') && available[0]) 
				{
                    available[0] = 0;  
                     car_index = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    rentedDays[0] = days;
                    amount = 5000 * days;
                } 
				else if ((code == 'B' || code == 'b') && available[1]) 
				{
                    available[1] = 0;
                    car_index = 1;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    rentedDays[1] = days;
                    amount = 7000 * days;
                } 
				else if ((code == 'C' || code == 'c') && available[2])
				 {
                    available[2] = 0;
                    car_index = 2;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    rentedDays[2] = days;
                    amount = 6000 * days;
                } 
				else if ((code == 'D' || code == 'd') && available[3])
				 {
                    available[3] = 0;
                    car_index = 3;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    rentedDays[3] = days;
                    amount = 10000 * days;
                }
				 else if ((code == 'E' || code == 'e') && available[4])
				  {
                    available[4] = 0;
                    car_index = 4;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    rentedDays[4] = days;
                    amount = 12000 * days;
                } 
				else 
				{
                    printf("Invalid Car Code or Car already rented!\n");
                    continue;
                }

                // Take customer full name
                printf("Enter your Full Name: ");
                scanf(" %[^\n]", fullname[car_index]);

                printf("Total rent = %d\n", amount);
                printf("Enter amount = ");
                scanf("%d", &inp_amount);

                if (inp_amount == amount) {
                    printf("\nPayment Successful! Car rented successfully.\n");
                    
                    printf("-------------------------------------\n");
                    printf("        RENTAL RECEIPT               \n");
                    printf("-------------------------------------\n");
                    printf("Customer Name: %s\n", fullname[car_index]);  //2D array me specific car ke index ke liye customer name store kar raha hai.
//                                                                       Example: agar car_index = 0 ? ALTO ke liye user ka name store hoga.
                    printf("Car Code: %c\n", code);
                    printf("Days Rented: %d\n", days);
                    printf("Total Amount Paid: %d PKR\n", amount);
                    printf("-------------------------------------\n");
                } 
				else {
                    printf("Payment Failed! Please pay exact amount.\n");
                    // revert availability
                    if (car_index != -1) 
					available[car_index] = 1;
                }
            }

        } 
		else if (choice == 2)
		 {
            char code;
            printf("Enter Car Code to Return (A-E) or X for Back: ");
            scanf(" %c", &code);

            if (code == 'X' || code == 'x') 
			{
			continue;}
		

            if ((code == 'A' || code == 'a') && available[0] != 1)
			 {
                available[0] = 1;
                printf("ALTO returned successfully!\n\n");
                
            } 
			else if ((code == 'B' || code == 'b') && available[1] != 1) 
			{
                available[1] = 1;
                printf("CITY returned successfully!\n\n");
                
            }
			 else if ((code == 'C' || code == 'c') && available[2] != 1) 
			 {
                available[2] = 1;
                printf("VITZ returned successfully!\n\n");
                
            } 
			else if ((code == 'D' || code == 'd') && available[3] != 1) 
			{
                available[3] = 1;
                printf("COROLLA returned successfully!\n\n");
                
            } 
			else if ((code == 'E' || code == 'e') && available[4] != 1) 
			{
                available[4] = 1;
                printf("CIVIC returned successfully!\n\n");
            } 
			else {
                printf("Invalid Car Code or Car was not rented!\n\n");
            }

        } 
		else if (choice == 3) 
		{ 
            printf("\n-------------- Rented Cars --------------\n");
            int found = 0;
            for (int i = 0; i < 5; i++) {
                if (available[i] == 0) {
                    found = 1;
                    printf("Car Code: %c\n", carCodes[i]);
                    printf("Rented By: %s\n", fullname[i]);
                    printf("Days: %d\n", rentedDays[i]);
                    printf("---------------------------------\n");
                }
            }
            if (found == 0) 
			{
                printf("No cars are currently rented.\n");
            }

        } 
		else if (choice == 4)
		 { 
            printf("Exiting... Goodbye!\n");
            break;
        } 
		else {
            printf("Invalid Choice! Try again.\n");
        }
    }

    return 0;
}

