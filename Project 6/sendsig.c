////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        sendsig.c
// Other Files:      intdate.c
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
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: <signal type> <pid>\n");
	exit(0);
    }
    int id = atoi(argv[2]);  //parses PID input
    int sig;
    if(strcmp(argv[1], "-i") == 0) { //checks for matching signal input 
        sig = 2;
    }
    else if(strcmp(argv[1], "-u") == 0) {  //checks for matching signal input
        sig = 10;
    }
    else {
        printf("Please use -i or -u\n");  //prints if incorrect signal input used
        exit(0);
    }
    if(kill(id, sig)!= 0) {  //sends signal to pid and checks that it completes sucessfully
        printf("Error sending signal\n");
	exit(0);
    }
    return 0;
}
