import socket

# Configuración del socket del servidor en el puerto 5000
servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servidor.bind(('localhost', 5000))
servidor.listen(1)
print("Servidor Socket escuchando en el puerto 5000...")

try:
    while True:
        conexion, direccion = servidor.accept()
        # Recepción de los datos del cliente (máximo 1024 bytes)
        datos = conexion.recv(1024).decode('utf-8')
        if datos:
            print(f"Mensaje recibido del cliente: '{datos}'")
            conexion.send("Confirmación: Mensaje recibido exitosamente por el servidor.".encode('utf-8'))
        conexion.close()
except KeyboardInterrupt:
    print("\nApagando servidor socket.")
finally:
    servidor.close()