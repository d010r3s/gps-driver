#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "gps.h"

#define PORT 1

int main() {
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    int mode = 1;
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Bind socket to IP and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Socket bind failed");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 1) == -1) {
        perror("Listen failed");
        close(sockfd);
        return 1;
    }

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int clientfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
    if (clientfd == -1) {
        perror("Accept failed");
        close(sockfd);
        return 1;
    }

    close(sockfd);

    while (1) {
        float latitude, longitude, altitude;
        if (data(&latitude, &longitude, &altitude) != 0) {
            printf("Error\n");
            continue;
        }

        printf("Coordinates:\n");
        printf("Latitude: %f\nLongitude: %f\nAltitude: %f\n", latitude, longitude, altitude);
        sleep(1);
        process_coordinates(latitude, longitude, altitude, mode);
        char message[100];
        sprintf(message, "Latitude: %f, Longitude: %f, Altitude: %f\n", latitude, longitude, altitude);
        send(clientfd, message, strlen(message), 0);
    }

    cleanup();
    close(clientfd);
    return 0;
}
