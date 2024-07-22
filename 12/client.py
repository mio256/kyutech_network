import socket

# サーバのIPアドレスとポート番号
SERVER_IP = '131.206.37.50'
SERVER_PORT = 50000


def receive_file(filename, conn):
    with open(filename, 'wb') as file:  # Open file in binary mode
        while True:
            data = conn.recv(80)
            if not data:
                break
            try:
                file.write(data)  # Write raw bytes to the file
            except Exception as e:
                print(f"Error writing data: {e}")
            if data.decode(errors='ignore') == "exit_send":  # Decode with error handling
                break
    print(f"File {filename} received successfully")


def start_client():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((SERVER_IP, SERVER_PORT))
        print(f"Connected to server {SERVER_IP}:{SERVER_PORT}")

        student_id = input("Enter your student ID (8 characters): ")
        client_socket.sendall(student_id.encode())

        filename = f"{student_id}-copy.txt"
        receive_file(filename, client_socket)


if __name__ == "__main__":
    start_client()
