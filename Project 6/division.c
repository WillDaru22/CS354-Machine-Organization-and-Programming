////////////////////////////////////////////////////////////////////////////////
// Main File:        division.c
// This File:        division.c
// Other Files:      
// Semester:         CS 354 Fall 2019
//
// Author:           William Wilson
// Github:	     WillDaru22
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   fully acknowledge and credit all sources of help,
//                   other than Instructors and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of
//                   of any information you find.
//////////////////////////// 80 columns wide ///////////////////////////////////
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int input1;
int input2;
int quo;
int rem;
int divcnt;
char inputc[100];

void handler_SIGFPE() {  //SIGFPE handler for divide by zero
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %d\n", divcnt);
    printf("The program will be terminated.\n");
    exit(0);
}

void handler_SIGINT() {  //SIGINT handler for ^C
    printf("\nTotal number of operations successfully completed: %d\n", divcnt);  //extra new line added before print so that console is clean to look at with ^C
    printf("The program will be terminated.\n");
    exit(0);
}

int main(int argc, char* argv[]) {
    struct sigaction sad;
    memset(&sad, 0, sizeof(sad));  //zeroes out struct sad
    sad.sa_handler = handler_SIGFPE;
    if(sigaction(SIGFPE, &sad, NULL) != 0) {
        printf("ERROR binding SIGFPE handler.\n");
	exit(1);
    }
    struct sigaction sai;
    memset(&sai, 0, sizeof(sai));  //zeroes out struct sai
    sai.sa_handler = handler_SIGINT;
    if(sigaction(SIGINT, &sai, NULL) != 0) {
        printf("ERROR binding SIGINT handler.\n");
	exit(1);
    }
    while(1) {
        printf("Enter first integer: ");
        fgets(inputc,100,stdin);  //gets first input
        input1 = atoi(inputc);  //parses first input
	printf("Enter second integer: ");
	fgets(inputc,100,stdin);  //gets second input
	input2 = atoi(inputc);  //parses second input
	quo = input1/input2;  //divides to find the quotient
	rem = input1 % input2;  //finds the remainder
	printf("%d / %d is %d with a remainder of %d\n",input1,input2,quo,rem);
        divcnt++;
    }
    
}
