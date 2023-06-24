#ifndef GPS_DAEMON_H
#define GPS_DAEMON_H

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>
void process_coordinates(float latitude, float longitude, float altitude, int mode);
int gps_driver_init();
void cleanup(FILE *file);
void get_latitude(FILE *data); 
void get_longitude(FILE *data); 
void get_altitude(FILE *data);
//int demon();
#endif
