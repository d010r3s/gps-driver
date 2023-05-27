#ifndef GPS_DRIVER_H
#define GPS_DRIVER_H

int gps_driver_init();
void cleanup();
int data(float* latitude, float* longitude, float* altitude);
int set_mode(int mode);

#endif
