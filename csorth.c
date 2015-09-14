#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Fila{
    char columna[6][100];
};

struct Tabla{
    struct Fila filas[100];
    int tam;
};

struct Fila crearFila(char *linea);
struct Tabla obtenerTabla(char nombreArchivo[]);
void ordenarArchivo(char nombreArchivo[]);
void imprimirTabla( struct Tabla tabla );

int main (int argc, char **argv){
    char s[100] = "log1";
    ordenarArchivo(s);
    return 0;
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

void ordenarArchivo(char nombreArchivo[]){
    //Declaraciones
    struct Tabla tabla = obtenerTabla( nombreArchivo );
    imprimirTabla(tabla);

    //Copiar contenido
    //organizar arreglo
    //reescribir archivo
}

struct Tabla obtenerTabla(char nombreArchivo[]){
    FILE *ptr_file;
    char buf[1000];
    struct Tabla tabla;	
    
    ptr_file =fopen(nombreArchivo, "r");

    int tam = 0;
    if (ptr_file){
        while (fgets(buf,1000, ptr_file)!=NULL)
            tabla.filas[tam++] = crearFila(buf);
	tabla.tam = tam;
        fclose(ptr_file);
    }
    return tabla;
}

void imprimirTabla( struct Tabla tabla ){
    int i, j;
    int tam = tabla.tam;
    for(i=0; i<tam; i++){
        for(j=0; j<6; j++ ){
	    printf("%s ",tabla.filas[i].columna[j]);
        }
        printf("\n");
    }
}
