/* Cody D'Orazio
 * Professor Ojaj
 * Programming Language Lab 1
 * 20 February 2020
 * */

#include <stdio.h>
#include <stdlib.h>
int choice, pin, k;

char name[] = "nana";
int balance = 5000;
int pin = 3014;


int main() {

    switch(choice) {
        case 1: balance();
            break;

        case 2: withdraw();
        break;

        case 3: deposit();
            break;

        case 4: quit();
            break;

        default: printf("Please try again and select a number from 1 - 4");
    }

}

void balance() {
    printf("$%d", balance);

}

void withdraw() {


}

void deposit() {


}

int quit() {



    // exit(0);
}