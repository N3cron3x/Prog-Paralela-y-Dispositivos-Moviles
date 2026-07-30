#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double generar_valor_aleatorio(void) {
    return (double) rand() / RAND_MAX * 100.0;
}

int main(int argc, char *argv[]) {
    int rank, num_procs, N;
    double suma_local = 0.0;
    double suma_total = 0.0;
    double promedio = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    srand((unsigned int) time(NULL) + rank * 100);

    if (rank == 0) {
        printf("Ingrese la cantidad de valores por proceso (N): ");
        fflush(stdout);
        scanf("%d", &N);
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < N; i++) {
        suma_local += generar_valor_aleatorio();
    }

    printf("Proceso %d genero %d valores con suma parcial %.4f\n", rank, N, suma_local);

    MPI_Reduce(&suma_local, &suma_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        promedio = suma_total / (N * num_procs);
    }

    MPI_Bcast(&promedio, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    printf("Proceso %d recibio el promedio total: %.4f\n", rank, promedio);

    MPI_Finalize();
    return 0;
}
