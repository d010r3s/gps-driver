#include "gps.h"

#define PORT 10240

int main() {
    int mode;
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    //int mode = 1;
    FILE *config = fopen("config.txt", "r");
    fscanf(config, "%d", &mode);
    fclose(config);
    printf("mode chosen: %d\n", mode);
    // int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // if (sockfd < 0) {
    //     perror("Socket creation failed");
    //     return 1;
    // }

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
        FILE *data = fopen("data.txt", "w");
        if (data == NULL) {
            printf("failed to open data file.\n");
            return 1;
        }

        printf("coordinates:\n");
        get_latitude(data);
        get_longitude(data);
        get_altitude(data);
        fclose(data);

        data = fopen("data.txt", "r");
        fscanf(data, "%f %f %f", &latitude, &longitude, &altitude);
        printf("latitude: %f\nlongitude: %f\naltitude: %f\n", latitude, longitude, altitude);
        fclose(data);

        sleep(1);
        process_coordinates(latitude, longitude, altitude, mode);
        cleanup(data);
    }
    
    // close(sockfd);
}
