import xmlrpc.client

# Conexión al proxy del servidor RPC local
servidor_remoto = xmlrpc.client.ServerProxy('http://localhost:8000/')

try:
    numero_usuario = int(input("Ingrese un número entero para calcular su cuadrado vía RPC: "))
    # Invocación transparente de la función remota del servidor
    resultado = servidor_remoto.calcular_cuadrado(numero_usuario)
    print(f"Resultado devuelto por el servidor RPC: El cuadrado de {numero_usuario} es {resultado}")
except Exception as e:
    print(f"Error en la llamada al procedimiento remoto: {e}")