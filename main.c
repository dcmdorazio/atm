/* Cody D'Orazio
 * Professor Ojaj
 * Programming Language Lab 1
 * 20 February 2020
 * */

#include <stdio.h>
#include <stdlib.h>

int pin = 3014;
int choice;
int curbalance = 5000;
int withdrawAmount = 0;
int deposited = 0;
int amountWithdrawn = 0;
int pinGuess = 0;
//int withdrawAmount = 0;
int transactions = 0;
//int deposited = 0;
int dailyDeposit = 0; // this will allow only 3 deposits once integrated.


char name[5] = {'N', 'a', 'n', 'a', '\0'};

/* TODO: Finish adding the pointers into the voided methods below for the equations to work properly. */
void balance();

void withdraw();

void deposit();

void quit();

void newBalance(int *balance);
void newDeposit(int *deposit);
void newWithdrawnAmount (int *withdrawnAmount);


int main(void) {
    printf("Enter your pin -> \n");
    do {
        if (pinGuess != pin  && pinGuess !=0) {
            printf("Wrong pin. Please try again.\n");
        }

        scanf_s("%d", &pinGuess,3);
    } while (pinGuess != pin);
    printf("Welcome %s\n", name);
    do {
        printf("\nPlease make a selection.\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Cash\n");
        printf("3. Deposit Cash\n");
        printf("4. Quit\n");
        printf("***********************************************\n");
        printf("What would you like to do?\t");
        scanf_s("%d", &choice, 20);

        /* Switch and cases. */
        switch (choice) {
            case 1:
                balance();
                break;

            case 2:
                withdraw();
                break;

            case 3:
                deposit();
                break;

            case 4:
                quit();
                break;

            default:
                printf("Invalid selection. Please try again!");
        }

    } while (choice != 4);
}

/* Case 1*/
void balance() {

    printf("\nYour current balance is: $%d\n", newBalance);

}   // End of balance() function

/* Case 2*/
void withdraw() {
    do {
        /* This if statement not allow Nana to withdraw if she has reached her daily limit. */
        if (amountWithdrawn > 1000 || withdrawAmount > 1000) {
            printf("You have reached your withdraw limit for the day!\n");
        }
        /* This if statement will deny a withdraw if it is not in quantities of 20. */
        if (withdrawAmount % 20 != 0) {
            printf("Please try again, you can only withdraw in amounts of $20\n");
        }
        /* This if statement will deny a withdraw if there are insufficient funds in the account. */
        if (withdrawAmount > curbalance) {
            printf("You do not have enough funds in your account.\n");
        }

        printf("How much would you like to withdraw?\n");
        scanf_s("%d", &withdrawAmount, 16); /* Added 16 for the size of the 4 bit array. */

    } while (amountWithdrawn > 1000 || withdrawAmount % 20 != 0 || withdrawAmount > curbalance ||
             withdrawAmount > 1000);
    //withdrawAmount == *newWithdrawnAmount();
    curbalance -= amountWithdrawn;
    amountWithdrawn += withdrawAmount;

    ++transactions;
}   // End of withdraw() function

/* Case 3*/
void deposit() {

    do {
        if (deposited > 10000) {
            printf("You have reached your deposit limit for the day!\n");
        }
        printf("How much would you like to deposit?\n");
        scanf_s("%d", &deposited);
    } while (deposited > 10000);  // Deposit limit for the day
    curbalance += deposited;    // Current balance = current balance + deposited
     ++transactions;

}   // End of deposit() function

/* Case 4*/
void quit() {
    printf("You have completed %d transactions\n", transactions);
    printf("Have a nice day!\n");


    exit(0);
}   //End of quit() function