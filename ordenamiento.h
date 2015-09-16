

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
struct Tabla importarTabla(FILE* ptr_file) ;
struct Tabla ordenarTabla( struct Tabla tabla );
void exportartabla( struct Tabla tabla, char *nombreArchivo );
int ordenarArchivo(char nombreArchivo[]);
void imprimirTabla( struct Tabla tabla );
void ssort(struct TablaMerge arr, struct TablaMerge arrAux, int lo, int hi);
void mmerge(struct TablaMerge arr, struct TablaMerge arrAux, int lo, int mid, int hi);
int fileTam(char *nombreArchivo);

#include "ordenamiento.c"
