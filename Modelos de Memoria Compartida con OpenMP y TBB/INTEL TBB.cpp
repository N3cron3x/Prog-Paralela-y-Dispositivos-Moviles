// EJEMPLO PRACTICO: INTEL TBB EN C++

#include <iostream>
#include <vector>
#include <tbb/tbb.h>

int main() {
    const int size = 10;
    std::vector<int> vector_a(size, 5);
    std::vector<int> vector_b(size, 10);
    std::vector<int> resultado(size, 0);

    std::cout << "Iniciando suma de vectores con Intel TBB..." << std::endl;

    // BUCLE PARALELO CON TBB
    // tbb::parallel_for recibe un rango y una funcion lambda.
    // TBB gestiona dinamicamente la asignacion de tareas (Task Stealing)
    // a los diferentes nucleos del procesador de forma automatica.

    tbb::parallel_for(tbb::blocked_range<int>(0, size),
        [&](const tbb::blocked_range<int>& rango) {
            
            for (int i = rango.begin(); i != rango.end(); ++i) {
                resultado[i] = vector_a[i] + vector_b[i];
            }
            
        });

    std::cout << "Procesamiento con Intel TBB finalizado exitosamente." << std::endl;

    std::cout << "Muestra del indice 0: " << resultado[0] << std::endl;

    return 0;
}