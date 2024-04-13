#include <iostream>
#include <thread>
#include <cstring>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

constexpr int PORT = 8080;
constexpr int MAX_CLIENTS = 5;

void clientHandler(SOCKET clientSocket) {
    char buffer[1024] = {0};
    int valread;

    while ((valread = recv(clientSocket, buffer, 1024, 0)) > 0) {
        std::cout << "Message from client: " << buffer << std::endl;
        send(clientSocket, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
    }

    std::cout << "Client disconnected" << std::endl;
    closesocket(clientSocket);
}

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    sockaddr_in address;
    int addrlen = sizeof(address);

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(serverSocket, (sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "Bind failed" << std::endl;
        return -1;
    }

    if (listen(serverSocket, MAX_CLIENTS) == SOCKET_ERROR) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    while (true) {
        if ((clientSocket = accept(serverSocket, (sockaddr *)&address, &addrlen)) == INVALID_SOCKET) {
            std::cerr << "Accept failed" << std::endl;
            return -1;
        }

        std::cout << "New connection established" << std::endl;

        std::thread clientThread(clientHandler, clientSocket);
        clientThread.detach();
    }

    WSACleanup();
    return 0;
}
