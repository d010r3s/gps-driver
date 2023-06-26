#include "gps.h"

#define PORT 10240

int demon() {
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

        latitude = get_latitude();
        longitude = get_longitude();
        altitude = get_altitude();
        fprintf(data, "%f\n%f\n%f\n", latitude, longitude, altitude);
        fclose(data);

        sleep(1);
        FILE *logs = fopen("logs.txt", "a");
        long int ttime;
        ttime = time(NULL);
        if (mode == 1) {
            if (altitude > 1000) {
                fprintf(logs, "%s: the object is higher than 1km\n", ctime(&ttime));
            } else {
                fprintf(logs, "%s: the object is lower than 1km\n", ctime(&ttime));
            }
        } else if (mode == 2) {
            if (latitude > 50.0 && longitude < 50.0) {
                fprintf(logs, "%s: idk something\n", ctime(&ttime));
            } else {
                fprintf(logs, "%s: something else ig\n", ctime(&ttime));
            }
    }
       // cleanup(data);
        fclose(logs);
    }
    
    // close(sockfd);
}
