#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>

#define SUMSIZE 10 
#define N 4             // Elementos en la cola de producción

/******************************************************************************
*  Variables globales
******************************************************************************/
sem_t mutex;     // Se inicializa a 1
sem_t lleno;     // Se inicializa a 0
sem_t vacio;     // Se inicializa a N

int entrada = 0;
int salida = 0;
int buffer[N];
int contador = 0;

/******************************************************************************
*  Funciones
******************************************************************************/

// Productor
void *productor() {

    int item=1;

    printf("Iniciar productor...\n");
    while (item<=SUMSIZE) 
    {
         
         sem_wait(&vacio);
         sem_wait(&mutex);
              //printf("Productor - Posicion en el buffer... %d\n", entrada);
              buffer[entrada] = item;
              entrada = (entrada + 1) % N;
              
              printf("Productor produce item... %d\n", item);
     
         sem_post(&mutex);
         sem_post(&lleno);
        
         item = item + 1;
         //sleep(1);
    }
    
}

// Consumidor
void *consumidor() {
    int i=1;
    int mi_item;
   
    printf("Iniciar consumidor...\n");
    while (i<=SUMSIZE) 
    {
         sem_wait(&lleno);
         sem_wait(&mutex);
              //printf("Consumidor - Posicion en el buffer... %d\n", salida);
              mi_item = buffer[salida];
              salida = (salida + 1) % N;
              
              printf("Consumidor consume item... %d\n", mi_item);
         sem_post(&mutex);
         sem_post(&vacio);
         
         

         i = i + 1;
         sleep(2);
    }
   
}

/******************************************************************************
*  Programa principal
******************************************************************************/

int main() {
    pthread_t prodtid;
    pthread_t constid;
  
    // Iniciación de los semáforos
    sem_init(&mutex, 0, 1);
    sem_init(&lleno, 0, 0);
    sem_init(&vacio, 0, N);

//    printf("Iniciar productor: \n");
//    printf("Iniciar consumidor: \n");
  
    pthread_create(&prodtid, NULL, productor, NULL);
    pthread_create(&constid, NULL, consumidor, NULL);

    pthread_join(prodtid,NULL); 
    pthread_join(constid,NULL);
    // Destrucción de los semáforos
    sem_destroy(&mutex);
    sem_destroy(&lleno);
    sem_destroy(&vacio);
        
    return 0;
}

