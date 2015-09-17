#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenamiento.h"

int main (int argc, char **argv){
    pthread_t id[10];
    int i, error;
    char strTemp[10][100];

    for( i=0; i<argc-3; i++){
        error = pthread_create(&(id[i]), NULL, ordenarArchivoHilo, (void *)argv[i+1]);
        if (error != 0){
            perror("Error en el hilo:");
        }else if( error == 0 ){
            printf("Thread created successfully\n");
        }
    }
    for( i=0; i<argc-3; i++){
        pthread_join(id[i], (void *)strTemp[i]);
    }
    int tamTotal = 0,j;
    for(i = 1; i < argc-2; i++){
       tamTotal += fileTam(argv[i]);
    } 	
    struct TablaMerge arr,arrAux;
    arrAux.filas = (char***)malloc(sizeof(char**)*tamTotal*600);
    for(i = 0; i < tamTotal; i++){
	arrAux.filas[i] = (char**)malloc(sizeof(char*)*6);
	for(j = 0; j < 6; j++){
		arrAux.filas[i][j] = (char*)malloc(sizeof(char)*100);
    	}
    }
    arr.tam = tamTotal;
    arr = importarTablaMerge(argv, argc-1, tamTotal);
    ssort(arr, arrAux, 0, tamTotal-1);
    exportartablaMerge(arr, argv[argc-2]);
    exit(0);
}


