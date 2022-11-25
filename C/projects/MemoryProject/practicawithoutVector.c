#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MEMORY_SIZE 10
#define MAX_PROCESOS 500

int contadorProceso = 0;
int totalActivos = 0;

typedef enum 
{
    ACTIVO,
    TERMINADO
} ESTADO;

typedef struct
{
	int id;
    char nombre[7];
    int desplazamiento;
    ESTADO estado;
    int direccion;
} PROCESO;

int crearProceso(int inicio, PROCESO tablaProcesos[], int activos[]);
int eliminarProceso(PROCESO tablaProcesos[], int activos[], int desplazamientoSO);
int numeroRandom(int i, int n);
void verMemoria(PROCESO tablaProcesos[], int activos[], int desplazamientoSO);
void verProcesos(PROCESO tablaProcesos[]);
int compactarMemoria(PROCESO tablaProcesos[], int activos[], int desplazamientoSO);

int main() {
    // asignamos memoria el 30% de memoria al SO
    int desplazamientoSO = (int)(((float) MEMORY_SIZE / 100.0) * 30.0);
    /*
        opcion: para la opcion que inserta el usuario
        posicionVacia: para marcar la posicion donde podemos ingresar el nuevo proceso
        activos[MEMORY_SIZE]: vector para listar los ids de los procesos activos
    */
    int opcion, posicionVacia = desplazamientoSO, activos[MAX_PROCESOS];
    // vector de tipo PROCESO para la tabla de procesos
    PROCESO tablaProcesos[MAX_PROCESOS];
    /* Este metodo es llamado una semilla o "SEED", genera los numeros randomicos segun 
        la hora del procesador, sino ponemos esta semilla los numeros
        aleatorios que generaremos siempre seran los mismos
    */ 
    srand(time(NULL));

    do {
       printf("\n%s\n%s\n%s\n%s\n%s\n%s\n",
        "1) Lanzar Proceso",
        "2) Terminar Proceso",
        "3) Compactar Memoria",
        "4) Ver Memoria",
        "5) Ver Tabla de Procesos",
        "0) Salir");
       scanf("%d", &opcion);


        switch (opcion)
        {
            case 1:
                posicionVacia = crearProceso(posicionVacia, tablaProcesos, activos);
                break;
            case 2:
                posicionVacia = eliminarProceso(tablaProcesos, activos, desplazamientoSO);
                break;
            case 3:
                posicionVacia = compactarMemoria(tablaProcesos, activos, desplazamientoSO);
                break;
            case 4:
            {
                verMemoria(tablaProcesos, activos, desplazamientoSO);
                break;
            }
            case 5:
                verProcesos(tablaProcesos);
                break;
            default:
                break;
        }

    } while(opcion != 0);
    return 0;
}

int crearProceso(int posicionVacia, PROCESO tablaProcesos[], int activos[]) {
    // el desplazamiento es un numero random entre 1 y el tamanio de la memoria
    int desplazamiento = numeroRandom(1, MEMORY_SIZE);
    int posicionFinal = posicionVacia + desplazamiento;

    // sin la posicion final del proceso es mayor al tamanio de la memoria no creamos el proceso
    if (posicionFinal > MEMORY_SIZE) {
        printf("\nMemoria insuficiente para iniciar proceso con desplazamiento %d.", desplazamiento);
        printf("\nMemoria disponible: %d", MEMORY_SIZE - posicionVacia);
        return posicionVacia;
    }

    contadorProceso++;
    printf("\nCreando Proceso [PR%d] con desplazamiento [%d]", contadorProceso, desplazamiento);

    // creamos el proceso para la tabla de procesos
    PROCESO proceso;
    proceso.id = contadorProceso;
    proceso.desplazamiento = desplazamiento;
    proceso.estado = ACTIVO;
    proceso.direccion = posicionVacia;
    // creamos el nombre proceso
    char nombreProceso[7] = "PR", num[4];
    // coonvertimos el id del proceso en string
    sprintf(num, "%d", contadorProceso);
    // concatenamos el "PR" con el id del proceso
    strcat(nombreProceso, num);
    // cambiamos el nombre del proceso del struct
    strcpy(proceso.nombre, nombreProceso);
    // insertamos en nuevo proceso en la tabla
    tablaProcesos[contadorProceso] = proceso;

    // agregamos el id en el vector de procesos activos
    activos[totalActivos] = contadorProceso;
    totalActivos++;
    // retornamos la siguiente posicion vacia
    return posicionVacia + desplazamiento;
}

int eliminarProceso(PROCESO tablaProcesos[], int activos[], int desplazamientoSO) {
    // verificamos que existan procesos activos si existen recien podemos eliminar
    if (totalActivos > 0) {
        // traemos un index de posicion del vector de activos aleatorio 
        int indexRandom = numeroRandom(0, totalActivos -1); 
        // traemos el id del index aleatorio
        int id = activos[indexRandom];
        int i;

        printf("Eliminando proceso %s.", tablaProcesos[id].nombre);
        // cambiamos el estado del proceso
        tablaProcesos[id].estado = TERMINADO;
        tablaProcesos[id].direccion = -1;
        // activos[indexRandom] = activos[totalActivos -1];
        // recorremos el vector de activos
        for (i = indexRandom; i<totalActivos; i++) {
            activos[i] = activos[i+1];
        }
        totalActivos--;
        if (totalActivos > 0) {
            int idUltimoProceso = activos[totalActivos - 1];
            // retornamos la nueva posicion vacia
            return tablaProcesos[idUltimoProceso].direccion + tablaProcesos[idUltimoProceso].desplazamiento;
        } else {
            // si ya no existen procesos retornamos la posicion despues de la memoria del SO
            return desplazamientoSO;
        }
    } else {
        printf("No existen procesos");
        return desplazamientoSO;
    }
}

int compactarMemoria(PROCESO tablaProcesos[], int activos[], int desplazamientoSO) {
    // la posicion debe ser la que le sigue al desplazamiento del SO
    int i, proximaDireccion = desplazamientoSO;
    // iteraremos los activos
    for(i = 0; i < totalActivos; i++) {
        int idProceso = activos[i];
        // cambiamos la direccion por la nueva direccion mas sin espacios 
        tablaProcesos[idProceso].direccion = proximaDireccion;
        // llenamos el vector con la nuevo info
        int posicionFinal = proximaDireccion + tablaProcesos[idProceso].desplazamiento;
        // la siguiente posicion es donde nos quedamos en el anterior proceso
        proximaDireccion = posicionFinal;
    }
    printf("Memoria compactada");
    return proximaDireccion;
}

int numeroRandom(int min, int max) {
    return rand() % ((max + 1) - min) + min;   // Este está entre 'min' y 'max'
}

void repeat(char word[], int total) {
    int i;
    // Listamos el desplazamiento del sistema operativo
    for (i = 0; i < total; i++)  {
        printf("%s |", word);
    }
}

void verMemoria(PROCESO tablaProcesos[], int activos[], int desplazamientoSO) {
    repeat("SO", desplazamientoSO);
    int posicionMemoria = desplazamientoSO;
    int i;
    for(i = 0; i < totalActivos; i++) {
        PROCESO proceso = tablaProcesos[activos[i]];
        if(proceso.direccion != posicionMemoria) {
            repeat("", proceso.direccion - posicionMemoria);
        }
        repeat(proceso.nombre, proceso.desplazamiento);
        posicionMemoria = proceso.direccion + proceso.desplazamiento;
    }
    repeat("", MEMORY_SIZE - posicionMemoria);
}

void verProcesos(PROCESO tablaProcesos[]) {
    int i;
    for (i = 1; i <= contadorProceso; i++) 
    {
        printf("\n------- %s -------\nID:%d\nDesplazamiento:%d\nEstado:%s\nDireccion de memoria:%d\n",
        tablaProcesos[i].nombre,
        tablaProcesos[i].id,
        tablaProcesos[i].desplazamiento,
        (tablaProcesos[i].estado == ACTIVO) ? "ACTIVO" : "TERMINADO",
        tablaProcesos[i].direccion);
    }
}
