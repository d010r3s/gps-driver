#include "gps.h"

float latitude, longitude, altitude;
float min = 1.0;
float max = 3000.0;
void cleanup() {
    printf("performing cleanup...\n");
    sleep(1);
}
int gps_driver_init() {
    printf("start...\n");
    sleep(1); 
    return 0;
}
float get_latitude() {
    srand(time(0));
    latitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    sleep(1);
    return latitude; 
}
float get_longitude() {
    srand(time(0));
    longitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    sleep(1);
    return longitude;
}
float get_altitude() {
    srand(time(0));
    altitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    sleep(1);
    return altitude;
}
void process_coordinates(float latitude, float longitude, float altitude, int mode) {
    printf("mode: %d\n", mode);

    if (mode == 1) {
        if (altitude > 1000) {
            printf("the object is higher than 1km\n");
        } else {
            printf("the object is lower than 1km\n");
        }
    } else if (mode == 2) {
        if (latitude > 50.0 && longitude < 50.0) {
            printf("idk something\n");
        } else {
            printf("something else ig\n");
        }
    }
}
