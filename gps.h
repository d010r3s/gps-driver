#ifndef GPS_DAEMON_H
#define GPS_DAEMON_H

#include <stdio.h>

void process_coordinates(float latitude, float longitude, float altitude, int mode);
int gps_driver_init();
#endif
