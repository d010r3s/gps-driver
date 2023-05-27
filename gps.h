#ifndef GPS_DAEMON_H
#define GPS_DAEMON_H

#include <stdio.h>
#include "gps.h"

void process_coordinates(float latitude, float longitude, float altitude, int mode);

#endif
