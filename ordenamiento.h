

struct Fila{
    char columna[6][100];
};

struct Tabla{
    struct Fila fila[100];
    int tam;
};

struct TablaMerge{
   char* fila[6][100];
};

struct Fila crearFila(char *linea);
struct Tabla importarTabla(char nombreArchivo[]);
struct Tabla ordenarTabla( struct Tabla tabla );
void exportartabla( struct Tabla tabla, char *nombreArchivo );
void *ordenarArchivo(void *param);
void imprimirTabla( struct Tabla tabla );
void removeSubstring(char *s,const char *toremove);

#include "ordenamiento.c"
