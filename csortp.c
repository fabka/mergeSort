
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>
#include "ordenamiento.h"

int main(int argv, char* argc[]){
    int status = 1, i;
    char indice;
    pid_t childPid;
    for(i = 1; i < argv-1; i++){
	if((childPid = fork()) < 0){
		perror("fork: ");
		exit(1);
	}
        if(childPid == 0){
		if(ordenarArchivo(argc[i]) == 1){
			perror("Child sort error: ");
			exit(1);
		}
		exit(0);
	}
    }
    for(i = 1; i < argv-1; i++){ wait(&status);}
    int tamTotal = 0;
    for(i = 1; i < argv-1; i++){
       tamTotal += fileTam(argc[i]);
    } 
    printf("tam: %d\n",tamTotal);
    exit(0);
}
