
struct Fila{
    char columna[6][100];
};

struct Tabla{
    struct Fila fila[1000];
    int tam;
};

struct TablaMerge{
   char*** filas;
   int tam;
};

struct Fila crearFila(char *linea);
struct Tabla importarTabla(FILE* ptr_file) ;
struct Tabla importarTablaHilo(char nombreArchivo[]);
struct TablaMerge importarTablaMerge(char* argc[], int argv, int tamTotal) ;
struct Tabla ordenarTabla( struct Tabla tabla );
void exportartabla( struct Tabla tabla, char *nombreArchivo );
void exportartablaMerge( struct TablaMerge tabla, char *nombreArchivo );
void *ordenarArchivoHilo(void *param);
int ordenarArchivo(char nombreArchivo[]);
void imprimirTabla( struct Tabla tabla );
void imprimirTablaMerge( struct TablaMerge tabla );
void ssort(struct TablaMerge arr, struct TablaMerge arrAux, int lo, int hi);
void mmerge(struct TablaMerge arr, struct TablaMerge arrAux, int lo, int mid, int hi);
int fileTam(char *nombreArchivo);
void crearFilaMerge(char linea[], char** retorno);
int compare(char columnas1[6][100], char columnas2[6][100] );
void removeSubstring(char *s,const char *toremove);

#include "ordenamiento.c"
