#include "gps.h"

float latitude, longitude, altitude;
float min = 1.0;
float max = 3000.0;

void cleanup(FILE *file) {
    printf("performing cleanup...\n");
    ftruncate(fileno(file), 0);
    sleep(1);
}
int gps_driver_init() {
    printf("start...\n");
    srand(time(0));
    sleep(1); 
    return 0;
}
float get_latitude() {
    latitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    return latitude;
}
float get_longitude() {
    longitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    return longitude;
}
float get_altitude() {
    altitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    return altitude;
}
