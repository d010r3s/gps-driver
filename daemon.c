#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "gps.h"

#define PORT 1024

int main() {
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    int mode = 1;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    while (1) {
        float latitude, longitude, altitude;
        if (data(&latitude, &longitude, &altitude) != 0) {
            printf("Error\n");
            continue; 
        }

        printf("Coordinates:\n");
        printf("Latitude: %f\nLongitude: %f\nAltitude: %f\n", latitude, longitude, altitude);
        sleep(1);

        send(sockfd, &latitude, sizeof(latitude), 0);
        send(sockfd, &longitude, sizeof(longitude), 0);
        send(sockfd, &altitude, sizeof(altitude), 0);

        process_coordinates(latitude, longitude, altitude, mode);
    }

    cleanup();
    close(sockfd);
    return 0;
}
