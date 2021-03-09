import threading
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = "127.0.0.1"
port = 50

s.connect((host, port))

def send():
    try:
        while True:
            message = input("enter your message: ")
            print(message)
            if message == "":
                continue
            s.sendall(message.encode('ascii'))
            socket.setdefaulttimeout(5)
            try:
                print(s.recv(1024))
            except socket.timeout:
                pass
    except:
        s.send("closing")
        s.close()



threading.Thread(target=send).start()

