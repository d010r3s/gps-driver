#ifndef GPS_DRIVER_H
#define GPS_DRIVER_H

int gps_driver_init();
void gps_driver_cleanup();
int gps_driver_get_data(float* latitude, float* longitude, float* altitude);
int gps_driver_set_mode(int mode);

#endif
