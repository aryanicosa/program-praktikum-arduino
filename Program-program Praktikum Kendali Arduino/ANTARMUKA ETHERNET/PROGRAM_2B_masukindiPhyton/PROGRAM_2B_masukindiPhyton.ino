import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('192.168.1.10', 10002)
sock.bind(server_address)
sock.listen(1)

try:
    white true:
        print('Menunggu koneksi...')
        connection, client_address = sock.accept()
        print('Koneksi dari %s:%d' % client_address)
        try:
          while true:
            data = connection.recv(1)
            sys.stdout.write(data)
            if data:
              connection.sendall()data.upper())
            else:
              print('no more data, closing connection.')
              break
        finally:
          connection.close()
except KeyboardInterrupt:
  print('exiting')
finally:
  sock.shutdown(socket.SHUT_RDWR)
  sock.close()
