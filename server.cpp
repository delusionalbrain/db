#include <iostream>
#include <sys/socket.h> 
#include <netinet/in.h>
#include <unistd.h>
#include "parser.cpp"
#include "command.cpp"
using namespace std;

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;       
    addr.sin_port = htons(6379);     
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (sockaddr*)&addr, sizeof(addr));

    listen(serverSocket, 10);

    cout << "Server running on port 6379...\n";

    while (true) {

        int clientSocket = accept(serverSocket, nullptr, nullptr);
        cout << "Client connected!\n";

        char buffer[1024] = {};

        recv(clientSocket, buffer, sizeof(buffer), 0);

        cout << "Received: " << buffer << "\n";

        string response = "+OK\r\n";

        send(clientSocket, response.c_str(), response.size(), 0);

        close(clientSocket);
    }
    close(serverSocket);
}