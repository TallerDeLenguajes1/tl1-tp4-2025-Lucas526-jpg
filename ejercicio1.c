#include <stdio.h>
#include <stdlib.h>

struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
};

struct Nodo{
Tarea T;
Nodo *Siguiente;
};

int main(){
    return 0;
}
