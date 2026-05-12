// EJEMPLO PRACTICO: OPENMP EN C++

#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    const int size = 10;
    std::vector<int> vector_a(size, 5);
    std::vector<int> vector_b(size, 10);
    std::vector<int> resultado(size, 0);

    std::cout << "Iniciando suma de vectores con OpenMP..." << std::endl;

    // BUCLE PARALELO CON OPENMP
    // La directiva #pragma indica al compilador que divida
    // las iteraciones del bucle for entre los hilos disponibles.
    
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        resultado[i] = vector_a[i] + vector_b[i];
        
        #pragma omp critical
        {
            std::cout << "Hilo " << omp_get_thread_num() 
                      << " calculo el indice " << i 
                      << " (Resultado: " << resultado[i] << ")" << std::endl;
        }
    }

    std::cout << "\nProcesamiento con OpenMP finalizado." << std::endl;
    return 0;
}