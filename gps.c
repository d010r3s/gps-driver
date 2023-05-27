#include "gps.h"
#include <stdio.h>
#include <unistd.h>

int gps_driver_init() {
printf("Start...\n");
    sleep(1); 
    return 0;
}

void free() {
   printf("Cleanup...\n");
    sleep(1);
}

int data(float* latitude, float* longitude, float* altitude) {
    *latitude = 1;
    *longitude = 2;
    *altitude = 3;
    sleep(1);
    return 0; 
}

int set_mode(int mode) {
    printf("Mode: %d\n", mode);
    sleep(1); 
    return 0; 
}
