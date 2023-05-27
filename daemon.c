#include <stdio.h>
#include <unistd.h>
#include "gps.h"

int main() {
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    int mode = 1;

    while (1) {
        float latitude, longitude, altitude;
        if (data(&latitude, &longitude, &altitude) != 0) {
            printf("Error\n");
            continue; 
        }

        printf("Coordinates:\n");
        printf("Latitude: %f\n Longitude: %f\n Altitude: %f\n", latitude, longitude, altitude);
        sleep(1);

        process_coordinates(latitude, longitude, altitude, mode);
    }

    cleanup();
    return 0;
}
