#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

typedef struct{
Tarea T;
struct Nodo *Siguiente;
}Nodo;

Nodo *crearListaVacia();
Nodo *crearNodo(int *id);
void insertarNodo(Nodo **start,Nodo *nodo,int *id);
Nodo *cargarTarea(Nodo *Tarea,int *id);
// void buscarNodo(Nodo **start,int dato);

int main(){
    int TareaIdIncrement=1000;
    Nodo *TareasPendientes=crearListaVacia();
    Nodo *TareasRealizadas=crearListaVacia();
    Nodo *tarea1=crearNodo(&TareaIdIncrement);
    Nodo *tarea2=crearNodo(&TareaIdIncrement);
    Nodo *tarea3=crearNodo(&TareaIdIncrement);
    //printf("El nuevo nodo tiene el dato: %d",nodo1->numero);
    return 0;
}

Nodo *crearListaVacia(){
    return NULL;
}

Nodo *cargarTarea(Nodo *Tarea,int *id){
    char aux[100];
    fgets(aux,100,stdin);
    aux[strcspn(aux,"\n")]=0;
    Tarea->T.Descripcion=(char *)malloc((strlen(aux)+1)*sizeof(char));
    strcpy(Tarea->T.Descripcion,aux);
    Tarea->T.TareaID=(*id)++;
    return Tarea;
}

Nodo *crearNodo(int *id){
    Nodo *NuevoNodo=(Nodo *)malloc(sizeof(Nodo));
    NuevoNodo=cargarTarea(NuevoNodo,id);
    NuevoNodo->Siguiente=NULL;
    return NuevoNodo;
}

void insertarNodo(Nodo **start,Nodo *nodo,int *id){
    nodo->Siguiente=*start;
    *start=nodo;
}
// void buscarNodo(Nodo **start,int dato){
//     Nodo *aux= *start;
//     while (aux && aux->numero!=dato)
//     {
//         aux=aux->siguiente;
//     }
//     if (aux)
//     {
//         printf("Nodo encontrado, el dato es: %d",aux->numero);
//     }else
//     {
//         puts("Nodo no encontrado");
//     }  
// }