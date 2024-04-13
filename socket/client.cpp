#include <iostream>
#include <cstring>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

constexpr int PORT = 8080;
constexpr const char *SERVER_ADDRESS = "127.0.0.1";


int main() {
    WSADATA wsa;
    SOCKET sock;
    sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return -1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    serv_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    if (serv_addr.sin_addr.s_addr == INADDR_NONE) {
        std::cerr << "Invalid address" << std::endl;
        return -1;
    }

    if (connect(sock, (sockaddr *)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }

    std::cout << "Connected to server" << std::endl;

    while (true) {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);
        send(sock, message.c_str(), message.length(), 0);
        std::cout << "Message sent" << std::endl;

        int valread = recv(sock, buffer, 1024, 0);
        std::cout << "Server response: " << buffer << std::endl;
        memset(buffer, 0, sizeof(buffer));
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
