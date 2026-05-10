import multiprocessing
import time

# FUNCION DE TAREA
def calcular_cuadrado(numero):
    time.sleep(1) 
    resultado = numero * numero
    print(f"Proceso {multiprocessing.current_process().name} calculo: {numero}^2 = {resultado}")
    return resultado

# BLOQUE PRINCIPAL
if __name__ == '__main__':
    numeros = [1, 2, 3, 4, 5, 6, 7, 8]
    
    print("Iniciando procesamiento secuencial...")
    inicio_secuencial = time.time()
    
    for n in numeros:
        calcular_cuadrado(n)
        
    fin_secuencial = time.time()
    
    print("\nIniciando procesamiento paralelo...")
    inicio_paralelo = time.time()
    
    # Crea un grupo de procesos basado en los nucleos de la CPU
    pool = multiprocessing.Pool(processes=multiprocessing.cpu_count())
    
    # Distribuye la tarea a traves del grupo de procesos
    resultados = pool.map(calcular_cuadrado, numeros)
    
    # Cierra el grupo y espera a que terminen los procesos
    pool.close()
    pool.join()
    
    fin_paralelo = time.time()
    
    print("\nResultados finales:", resultados)
    print(f"Tiempo de ejecucion secuencial: {fin_secuencial - inicio_secuencial:.2f} segundos")
    print(f"Tiempo de ejecucion paralelo: {fin_paralelo - inicio_paralelo:.2f} segundos")