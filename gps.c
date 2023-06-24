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
    sleep(1); 
    return 0;
}
void get_latitude(FILE *data) {
    srand(time(0));
    latitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    fprintf(data, "%f\n", latitude);
    sleep(1);
}
void get_longitude(FILE *data) {
    srand(time(0));
    longitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    fprintf(data, "%f\n", longitude);
    sleep(1);
}
void get_altitude(FILE *data) {
    srand(time(0));
    altitude = ((float)rand() / RAND_MAX) * (max - min) + min;
    fprintf(data, "%f\n", altitude);
    sleep(1);
}
void process_coordinates(float latitude, float longitude, float altitude, int mode) {
    long int ttime;
    ttime = time(NULL);
    if (mode == 1) {
        if (altitude > 1000) {
            printf("%s: the object is higher than 1km\n", ctime(&ttime));
        } else {
            printf("%s: the object is lower than 1km\n", ctime(&ttime));
        }
    } else if (mode == 2) {
        if (latitude > 50.0 && longitude < 50.0) {
            printf("%s: idk something\n", ctime(&ttime));
        } else {
            printf("%s: something else ig\n", ctime(&ttime));
        }
    }
}
