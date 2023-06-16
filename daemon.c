#include "gps.h"

#define PORT 10240

int demon() {
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

    // struct sockaddr_in server_addr;
    // server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // server_addr.sin_port = htons(PORT);

    // if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    //     perror("Connection failed");
    //     return 1;
    // }

    while (1) {
        float latitude, longitude, altitude;
        if (!get_longitude() && !get_altitude() && !get_latitude()) {
            printf("error\n");
            continue; 
        }

        printf("coordinates:\n");
        printf("latitude: %f\nlongitude: %f\naltitude: %f\n", get_latitude(), get_longitude(), get_altitude());
        sleep(1);
        process_coordinates(get_latitude(), get_longitude(), get_altitude(), mode);
        // send(sockfd, &latitude, sizeof(latitude), 0);
        // send(sockfd, &longitude, sizeof(longitude), 0);
        // send(sockfd, &altitude, sizeof(altitude), 0);
        cleanup();
        return 0;
    }


    // close(sockfd);
}
