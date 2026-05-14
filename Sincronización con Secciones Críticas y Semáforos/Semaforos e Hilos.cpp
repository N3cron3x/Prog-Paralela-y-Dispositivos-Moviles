#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>

int variable_compartida = 0;
sem_t semaforo_sincronizacion;

// Seccion critica protegida mediante semaforos para evitar condiciones de carrera
void tarea_hilo() {
    for (int i = 0; i < 1000; ++i) {
        sem_wait(&semaforo_sincronizacion);
        variable_compartida++;
        sem_post(&semaforo_sincronizacion);
    }
}

int main() {
    sem_init(&semaforo_sincronizacion, 0, 1);
    std::vector<std::thread> hilos;

    for (int i = 0; i < 5; ++i) {
        hilos.push_back(std::thread(tarea_hilo));
    }

    for (auto& hilo : hilos) {
        hilo.join();
    }

    std::cout << "Hilos ejecutados: 5" << std::endl;
    std::cout << "Incrementos por hilo: 1000" << std::endl;
    std::cout << "Valor final esperado: 5000" << std::endl;
    std::cout << "Valor final de la variable compartida: " << variable_compartida << std::endl;
    
    sem_destroy(&semaforo_sincronizacion);
    return 0;
}