#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 500000000

int main() {
    long long *arreglo = (long long *)malloc(SIZE * sizeof(long long));
    for (long long i = 0; i < SIZE; i++) {
        arreglo[i] = 1;
    }

    int hilos_test[] = {1, 2, 4, 8, 16};
    
    // Ejecucion iterativa para medir el tiempo con diferentes cantidades de hilos
    printf("Hilos\tTiempo(s)\tSuma\n");
    
    for (int j = 0; j < 5; j++) {
        int num_hilos = hilos_test[j];
        omp_set_num_threads(num_hilos);
        long long suma_total = 0;
        
        double inicio = omp_get_wtime();
        
        #pragma omp parallel for reduction(+:suma_total)
        for (long long i = 0; i < SIZE; i++) {
            suma_total += arreglo[i];
        }
        
        double fin = omp_get_wtime();
        printf("%d\t%f\t%lld\n", num_hilos, fin - inicio, suma_total);
    }

    free(arreglo);
    return 0;
}