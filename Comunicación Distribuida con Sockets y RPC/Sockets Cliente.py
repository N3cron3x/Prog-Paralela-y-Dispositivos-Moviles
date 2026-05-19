import socket

# Conexión al servidor local en el puerto 5000
cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    cliente.connect(('localhost', 5000))
    mensaje = "Hola Servidor, solicitando comunicación distribuida."
    # Envío del mensaje codificado en bytes
    cliente.send(mensaje.encode('utf-8'))
    respuesta = cliente.recv(1024).decode('utf-8')
    print(f"Respuesta del servidor: {respuesta}")
except Exception as e:
    print(f"Error en la comunicación por socket: {e}")
finally:
    cliente.close()