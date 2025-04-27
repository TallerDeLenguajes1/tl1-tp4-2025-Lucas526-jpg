#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarea{
int TareaID;//Numérico autoincremental comenzando en 1000
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

typedef struct Nodo{
struct Tarea T;
struct Nodo *Siguiente;
}Nodo;

Nodo *crearListaVacia();
void interfazCarga(Nodo **tareasPend,int *id);
Nodo *crearTarea(int *id);
void insertarTarea(Nodo **tareasPend,Nodo *tarea);
void interfazTareasRealizadas(Nodo **tareasPend,Nodo **tareasFinalizadas);
void mostrarTareas(Nodo *tareasPend);

int main(){
    int id=1000;
    Nodo *tareasPendientes=crearListaVacia();
    Nodo *tareasCompletadas=crearListaVacia();
    interfazCarga(&tareasPendientes,&id);
    interfazTareasRealizadas(&tareasPendientes,&tareasCompletadas);
    return 0;
}

Nodo *crearListaVacia(){
    return NULL;
}
void interfazCarga(Nodo **tareasPend,int *id){
    int bandera;
    do
    {   
        Nodo *tarea=crearTarea(id);
        insertarTarea(tareasPend,tarea);
        puts("Desea ingresar una nueva tarea pendiente?(0/No,1/Si)");
        scanf("%d",&bandera);
        getchar();
    } while (bandera);
}
Nodo *crearTarea(int *id){
    char aux[100];
    Nodo *tarea=(Nodo *)malloc(sizeof(Nodo));
    tarea->Siguiente=NULL;
    puts("Ingrese la descripcion de la tarea");
    fgets(aux,100,stdin);
    aux[strcspn(aux,"\n")]=0;
    tarea->T.Descripcion=(char *)malloc((strlen(aux)+1)*sizeof(char));
    strcpy(tarea->T.Descripcion,aux);
    puts("Ingrese la duracion");
    scanf("%d",&tarea->T.Duracion);
    getchar();
    tarea->T.TareaID=(*id)++;
    return tarea;
}
void insertarTarea(Nodo **tareasPend,Nodo *tarea){
    tarea->Siguiente=*tareasPend;
    *tareasPend=tarea;
}
void interfazTareasRealizadas(Nodo **tareasPend,Nodo **tareasFinalizadas){
    Nodo *aux=*tareasPend;
    Nodo *ant=NULL;
    int id,bandera;
    do
    {
        puts("Ingrese el id de la tarea completada");
        scanf("%d",&id);
        getchar();
    while (aux && aux->T.TareaID==id)
    {
        ant=aux;
        aux=aux->Siguiente;
    }
    if (aux)
    {
        if (aux==(*tareasPend)){
            aux->Siguiente=*tareasFinalizadas;
            *tareasFinalizadas=aux;
            *tareasPend = aux->Siguiente;
        }else{
            aux->Siguiente=*tareasFinalizadas;
            *tareasFinalizadas=aux;
            *tareasFinalizadas=ant->Siguiente;
            ant->Siguiente=aux->Siguiente;
        }
        puts("Tarea movida con exito !");
    }else{
        puts("Tarea no encontrada");
    }
    puts("Quiere aginar otra tarea como completada?");
    scanf("%d",&bandera);
    getchar();
    } while (bandera);
}
void mostrarTareas(Nodo *tareasPend){
    Nodo *aux=tareasPend;
    while (aux)
    {
        printf("La descripcion es:%s\n",aux->T.Descripcion);
        printf("La duracion es:%d\n",aux->T.Duracion);
        printf("El ID de la tarea es:%d\n",aux->T.TareaID);
        aux=aux->Siguiente;
        printf("\n");
    }
}