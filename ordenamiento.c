#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ordenarArchivo(char nombreArchivo[]){
    int estado = 0;
    FILE* ptr_file = fopen(nombreArchivo, "r");
    if(ptr_file != NULL){
	estado = 1;
    	struct Tabla tabla;
    	tabla = importarTabla(ptr_file);
    	ordenarTabla(tabla);
    	exportartabla(tabla, nombreArchivo);
    }
    return estado;
}

struct Fila crearFila(char linea[]){
    struct Fila fila;
    char *stringp = linea;
    char *delim = " ";
    char *token;

    int i=0;
    while (stringp != NULL) {
        token = strsep(&stringp, delim);
    	if( strcmp(token, "") != 0  ){
    	    strcpy(fila.columna[i++], token);
    	}
    }
    return fila;
};

struct Tabla importarTabla(FILE *ptr_file){
    char buf[1000];
    struct Tabla tabla;
    int tam = 0;
    if (ptr_file){
        while (fgets(buf,1000, ptr_file)!=NULL)
            tabla.fila[tam++] = crearFila(buf);
	tabla.tam = tam;
        fclose(ptr_file);
    }
    return tabla;
}

struct Tabla ordenarTabla( struct Tabla tabla ){
    int i, j;
    for( i=1; i<tabla.tam; i++){
        for(j=0; j<tabla.tam-i; j++){
            //criterio 1
            if( strcmp(tabla.fila[j].columna[3], tabla.fila[j+1].columna[3]) > 0 ){
                struct Fila temp  = tabla.fila[j];
                tabla.fila[j] = tabla.fila[j+1];
                tabla.fila[j+1] = temp;
            }else if( strcmp(tabla.fila[j].columna[3], tabla.fila[j+1].columna[3]) == 0 ){
                //Criterio 2
                if( strcmp(tabla.fila[j].columna[4], tabla.fila[j+1].columna[4]) > 0 ){
                    struct Fila temp  = tabla.fila[j];
                    tabla.fila[j] = tabla.fila[j+1];
                    tabla.fila[j+1] = temp;
                }else if( strcmp(tabla.fila[j].columna[4], tabla.fila[j+1].columna[4]) == 0 ){
                    //Criterio 3
                    if( strcmp(tabla.fila[j].columna[5], tabla.fila[j+1].columna[5]) > 0 ){
                        struct Fila temp  = tabla.fila[j];
                        tabla.fila[j] = tabla.fila[j+1];
                        tabla.fila[j+1] = temp;
                    }
                }
            }
        }
    }
}

void exportartabla( struct Tabla tabla, char *nombreArchivo ){
    FILE *file = fopen(nombreArchivo, "w");
    int i, j;
    if (file != NULL){

        for( i=0; i<tabla.tam; i++ ){
            fprintf(file, "%8s %4s %8s %6s %8s %8s", tabla.fila[i].columna[0],
                tabla.fila[i].columna[1], tabla.fila[i].columna[2],
                tabla.fila[i].columna[3], tabla.fila[i].columna[4],
                tabla.fila[i].columna[5] );
        }
        fclose(file);
    }
}

void imprimirTabla( struct Tabla tabla ){
    int i, j;
    int tam = tabla.tam;
    for(i=0; i<tam; i++){
        for(j=0; j<6; j++ ){
	    printf("%s ",tabla.fila[i].columna[j]);
        }
    }
}
