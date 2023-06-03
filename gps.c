#include "gps.h"
void cleanup() {
    printf("Performing cleanup...\n");
    sleep(1);
}
int gps_driver_init() {
    printf("Start...\n");
    sleep(1); 
    return 0;
}
int data(float* latitude, float* longitude, float* altitude) {
    *latitude = 1.;
    *longitude = 2.;
    *altitude = 3.;
    sleep(1);
    return 0; 
}
void process_coordinates(float latitude, float longitude, float altitude, int mode) {
    printf("Mode: %d\n", mode);

    if (mode == 1) {
        if (altitude > 1000) {
            printf("Altitude is higher than 1km\n");
        } else {
            printf("Altitude is lower than 1km\n");
        }
    } else if (mode == 2) {
        if (latitude > 50.0 && longitude < 50.0) {
            printf("Idk something\n");
        } else {
            printf("Something else ig\n");
        }
    }
}
