import threading
import socket
import time

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = ""
port = 50
s.bind((host, port))
s.listen(5)
print("waiting for clients")

def receive_message():
    while True:
        print(addr)
        msg = c.recv(1000000)
        if msg.decode('ascii') == "close":
            c.close()

        print(msg.decode('ascii'))
        c.sendall(msg.decode('ascii').encode('ascii'))

    s.close()

while True:
    c, addr = s.accept()
    threading.Thread(target=receive_message).start()

s.close()

