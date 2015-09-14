#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


struct Fila{
    string columna[6];
};

struct Fila crearFila(string linea);

int main (int argc, char **argv){
    string s = "fila1 fila2 fila3 fila4 fila5 fila6";
    struct Fila fila = crearFila(s);
    int c;
    for( c=0; c<6; c++ ){
        cout<<fila.columna[c]+"_";
    }
    return 0;
}

struct Fila crearFila(string linea){
    struct Fila fila;
    int i = 0;
    char *str = const_cast<char*>(linea.c_str());
    char *token, *strpos = str;
    while ((token=strsep(&strpos," ")) != NULL){
        string temp(token);
        fila.columna[i++] = temp;
    }
    return fila;
}
