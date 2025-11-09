#include <stdio.h>
#include <string.h>

int main(void)
{
    int choice;
    char rentChoice;  
    int available[5] = {1, 1, 1, 1, 1}; // 1 = available, 0 = rented
    char name[50];

    while (1) 
    {
    	printf("*********************************\n");
        printf("    Welcome To Car Rental System   \n");
        printf("*********************************\n");
        printf("     System Menu     \n");
        
        printf("1) View Available Cars\n");
        printf("2) Return Car\n");
        printf("3) Exit\n");
        
       printf("\n******************************\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);


        if (choice == 1) // view available cars
        {
            printf("\nAvailable Cars\n");
              printf("-------------------------------------\n");
            if (available[0]) 
			printf("1) ALTO     - 5000/day - Code: A\n");
			
            if (available[1]) 
			printf("2) CITY     - 7000/day - Code: B\n");
			
            if (available[2]) 
			printf("3) VITZ     - 6000/day - Code: C\n");
			
            if (available[3]) 
			printf("4) COROLLA  - 10000/day - Code: D\n");
			
            if (available[4])
			 printf("5) CIVIC    - 12000/day - Code: E\n");
              printf("-------------------------------------\n");

            printf("\nWant to Rent a Car? (Y/N, X for Back): ");
            scanf(" %c", &rentChoice);

            if (rentChoice == 'X' || rentChoice == 'x') {
                continue; // back to main menu
            }

            if (rentChoice == 'Y' || rentChoice == 'y')
            {
                char code;
                
                printf("Enter your name : ");
                scanf("%s",name);
                printf("Please enter car code to proceed : ");
                scanf(" %c", &code);

                int days, amount, inp_amount;

                if (code == 'A' || code == 'a' && available[0]) {
                    available[0] = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    amount = 5000 * days;
                }
                else if ((code == 'B' || code == 'b') && available[1]) {
                    available[1] = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    amount = 7000 * days;
                }
                else if ((code == 'C' || code == 'c' )&& available[2]) {
                    available[2] = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    amount = 6000 * days;
                }
                else if ((code == 'D' || code == 'd' )&& available[3]) {
                    available[3] = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    amount = 10000 * days;
                }
                else if ((code == 'E' ||  code == 'e' )&& available[4]) {
                    available[4] = 0;
                    printf("Enter number of days: ");
                    scanf("%d", &days);
                    amount = 12000 * days;
                }
                else {
                    printf("Invalid Car Code or Car already rented!\n");
                    continue;
                }

                printf("Total rent = %d\n", amount);
                printf("Enter amount = ");
                scanf("%d", &inp_amount);

                if (inp_amount == amount) 
				{
                    
                    printf("\n Payment Successful! Car rented successfully.\n");
                    printf("-------------------------------------\n");
                    printf("        RENTAL RECEIPT               \n");
                    printf("-------------------------------------\n");
                    printf("Customer Name: %s\n", name);    
                    printf("Car Code: %c\n", code);
                    printf("Days Rented: %d\n", days);
                    printf("Total Amount Paid: %d PKR\n",amount);
                    printf("-------------------------------------\n");

                } else {
                    printf("Payment Failed! Please pay exact amount.\n");
                
                    if (code == 'A' || code == 'a') 
					available[0] = 1;
					
                    else if (code == 'B' || code == 'b') 
					available[1] = 1;
					
                    else if (code == 'C' || code == 'c') 
					available[2] = 1;
					
                    else if (code == 'D' || code == 'd')
					 available[3] = 1;
					 
                    else if (code == 'E' || code == 'e')
					 available[4] = 1;
                }
                
            }
        }
        else if (choice == 2) 
        {
            char code;
            printf("Enter Car Code to Return (A-E) or X for Back: ");
            scanf(" %c", &code);

            if (code == 'X' || code == 'x') {
                continue; 
            }

            if ((code == 'A' || code == 'a' ) && !available[0]) 
			{ available[0] = 1; 
			  printf("ALTO returned successfully!\n");
			 }
			
            else if ((code == 'B' || code == 'b') && !available[1])
			 { available[1] = 1;
			  printf("CITY returned successfully!\n");
			   }
			 
            else if ((code == 'C' || code == 'c') && !available[2]) 
			{ available[2] = 1; 
			 printf("VITZ returned successfully!\n"); 
			 }
			
            else if ((code == 'D' ||  code == 'd' )&& !available[3])
			 { available[3] = 1;
			   printf("COROLLA returned successfully!\n");
			    }
			 
            else if ((code == 'E'|| code == 'e') && !available[4])
			 { available[4] = 1; 
			  printf("CIVIC returned successfully!\n"); 
			  }
			 
            else {
                printf("Invalid Car Code or Car was not rented!\n");
                
            }
            
        }
        
        else if (choice == 3) 
        {
            printf("Exiting... Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid Choice! Try again.\n");
        
		}
	
    }
    

    return 0;
}

