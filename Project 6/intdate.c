////////////////////////////////////////////////////////////////////////////////
// Main File:        intdate.c
// This File:        intdate.c
// Other Files:      sendsig.c
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int alarmtime = 3;  //time for alarm to go off
int usrftimes;  //times SIGUSR1 is received, f for first

void handler_SIGALRM() {  //signal handler for SIGALRM
//print PID and current time
    time_t timer;
    struct tm* timeinfo;

    time (&timer);
    timeinfo = localtime(&timer);
    printf("PID: ");
    printf("%ld",(long)getpid());
    printf(" | Current Time: %s", asctime(timeinfo));
//re-arm alarm for 3 seconds later
    alarm(alarmtime);
    return;
}

void handler_SIGUSR1() {  //signal handler for SIGUSR1
    printf("SIGUSR1 caught!\n");
    usrftimes++;
    return;
}

void handler_SIGINT() {  //signal handler for SIGINT
    printf("SIGINT received\n");
    printf("SIGUSR1 was received %d times. Exiting now\n", usrftimes);
    exit(0);
    return;
}

int main(int argc, char* argv[]) {
    struct sigaction saa;
    memset(&saa, 0, sizeof(saa)); //zeroes out struct saa
    saa.sa_handler = handler_SIGALRM;  //handles SIGALRM signal
    if(sigaction(SIGALRM, &saa, NULL) != 0) {  //error if null
        printf("ERROR binding SIGALRM handler.\n");
	exit(1);
    }
    struct sigaction sauf;
    memset(&sauf, 0, sizeof(sauf));  //zeroes out struct sauf
    sauf.sa_handler = handler_SIGUSR1;  //handles SIGUSR1 signal
    if(sigaction(SIGUSR1, &sauf, NULL) != 0) { //error if null
        printf("ERROR binding SIGUSR1 handler.\n");
	exit(1);
    }
    struct sigaction sai;
    memset(&sai, 0, sizeof(sai));  //zeroes out struct sai
    sai.sa_handler = handler_SIGINT;
    if(sigaction(SIGINT, &sai, NULL) != 0) {
        printf("ERROR binding SIGINT handler.\n"); //error if null
	exit(1);
    }
    printf("PID and time will be printed every 3 seconds\n");
    printf("Enter ^C to end the program\n");
    alarm(alarmtime);
    while(1){
    }
    return 0;  
}
