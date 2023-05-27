#include <stdio.h>
#include <unistd.h>
#include "gps.h"

int main() {
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    while (1) {
        float latitude, longitude, altitude;
        if (data(&latitude, &longitude, &altitude) != 0) {
            printf("Error\n");
            continue; 
        }
        printf("Coordinates:\n");
        printf("Latitude: %f\n Longitude: %f\n Altitude: %f\n", latitude, longitude, altitude);
        sleep(1);
        if (mode == 1) {
            printf("Mode 1:\n");
            if (altitude > 1000) {
                printf("Altitude is higher than 1km\n");
            //
            }
            else {
            printf("Altitude is lower than 1km\n");
            //
            }
        }
        else if (mode == 2) {
            printf("Mode 2:\n");
            if (latitude > 50.0 && longitude < 50.0) {
                printf("Idk something\n");
            // 
            }
            else {
                printf("Something else ig\n");
            //
            }
        }
    }
    cleanup();
    return 0;
}
