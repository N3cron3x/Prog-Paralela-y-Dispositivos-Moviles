from xmlrpc.server import SimpleXMLRPCServer

# Definición de la función matemática remota que calcula el cuadrado
def calcular_cuadrado(numero):
    print(f"Ejecutando procedimiento remoto para el número: {numero}")
    return numero * numero

# Inicialización del servidor RPC en el puerto 8000
servidor = SimpleXMLRPCServer(('localhost', 8000), allow_none=True)
servidor.register_function(calcular_cuadrado, "calcular_cuadrado")

print("Servidor RPC listo y escuchando en el puerto 8000...")
try:
    servidor.serve_forever()
except KeyboardInterrupt:
    print("\nApagando servidor RPC.")