import socket
URL = input("Input URL")
address = socket.gethostbyname(URL)
print("Address of", URL, "is: ", address)

add = input("Enter Address")
url = socket.gethostbyaddr(add)
print("URL of", add, "is: ", url)