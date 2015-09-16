#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    char columna[6][100];
};

struct Tabla{
    struct Fila fila[100];
    int tam;
};

struct Fila crearFila(char *linea);
struct Tabla importarTabla(char nombreArchivo[]);
struct Tabla ordenarTabla( struct Tabla tabla );
void exportartabla( struct Tabla tabla, char *nombreArchivo );
void ordenarArchivo(char nombreArchivo[]);
void imprimirTabla( struct Tabla tabla );

int main (int argc, char **argv){
    char s[100] = "log1";
    ordenarArchivo(s);
    return 0;
}

/*
void *importarTabla(void *param){
    //Declaraciones
    char *nombreArchivo;
    Struct Tabla tabla;

    nombreArchivo = (char*)param;
    //importar tabla
    tabla = obtenerTabla(nombreArchivo );
    77imprimirTabla(tabla);
    //ordenar tabla
    ordenarTabla(tabla);
    //reescribir archivo
    exportartabla(tabla, nombreArchivo);
}
*/

void ordenarArchivo(char nombreArchivo[]){
    struct Tabla tabla;
    tabla = importarTabla(nombreArchivo );
    ordenarTabla(tabla);
    exportartabla(tabla, nombreArchivo);
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

struct Tabla importarTabla(char nombreArchivo[]){
    FILE *ptr_file;
    char buf[1000];
    struct Tabla tabla;

    ptr_file =fopen(nombreArchivo, "r");

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
