#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenamiento.h"

int main (int argc, char **argv){
    pthread_t id[10];
    int i, error;
    char strTemp[10][100];

    for( i=0; i<argc-1; i++){
        error = pthread_create(&(id[i]), NULL, ordenarArchivoHiloSistema, (void *)argv[i+1]);
        if (error != 0){
            printf("can't create thread :[%s]\n", strerror(error));
        }else if( error == 0 ){
            printf("Thread created successfully\n");
        }
    }

    for( i=0; i<argc-1; i++){
        pthread_join(id[i], (void *)strTemp[i]);
    }
    return 0;
}


