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
void *ordenarArchivo(void *param);
void imprimirTabla( struct Tabla tabla );

int main (int argc, char **argv){

    pthread_t id[10];
    int i, error;
    char strTemp[10][100];

    for( i=0; i<argc-1; i++){
        printf("Nombre archivo = %s\n", argv[i+1]);
        error = pthread_create(&(id[i]), NULL, ordenarArchivo, (void *)&argv[i+1]);
        if (error != 0)
            printf("can't create thread :[%s]\n", strerror(error));
        else if( error == 0 ){
            printf("Thread created successfully\n");
        }
    }

    for( i=0; i<argc-1; i++){
        pthread_join(id[i], (void **)&strTemp[i]);
    }
    return 0;
}

void *ordenarArchivo(void *param){
    printf("Entra\n");
    char* nombreArchivo = (char*)param;
    struct Tabla tabla;

    printf("Nombre archivo = %s\n",nombreArchivo);
    tabla = importarTabla(nombreArchivo );
    ordenarTabla(tabla);
    exportartabla(tabla, nombreArchivo);
}

/*void ordenarArchivo(char nombreArchivo[]){
    struct Tabla tabla;
    tabla = importarTabla(nombreArchivo );
    ordenarTabla(tabla);
    exportartabla(tabla, nombreArchivo);
}*/

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
