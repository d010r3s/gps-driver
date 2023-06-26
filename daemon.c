#include "gps.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PORT 10240

int main() {
    int mode;
    char modess[100];
    
    if (gps_driver_init() != 0) {
        printf("Error\n");
        return 1;
    }

    FILE *config = fopen("config.txt", "r");
    if (config == NULL) {
        printf("Error opening config.txt\n");
        return 1;
    }
    fscanf(config, "%d", &mode);
    fclose(config);

    while (1) {
        float latitude, longitude, altitude;
        
        FILE *data = fopen("data.txt", "w");
        if (data == NULL) {
            printf("Error opening data.txt\n");
            return 1;
        }
        latitude = get_latitude();
        longitude = get_longitude();
        altitude = get_altitude();
        fprintf(data, "%f %f %f\n", latitude, longitude, altitude);
        fclose(data);
        
        FILE *modes = fopen("modes.txt", "r");
        if (modes == NULL) {
            printf("Error opening modes.txt\n");
            return 1;
        }
        fscanf(modes, "%s", modess);
        fclose(modes);
        
        modes = fopen("modes.txt", "w");
        if (modes == NULL) {
            printf("Error opening modes.txt\n");
            return 1;
        }
        if (modess[0] == '1') {
            fprintf(modes, "tracking started. enter mode in config (1-2)");
        }
        else if (modess[0] == '2') {
            fprintf(modes, "tracking stopped.");
        }
        fclose(modes);

        sleep(1);
        
        FILE *logs = fopen("logs.txt", "a");
        if (logs == NULL) {
            printf("Error opening logs.txt\n");
            return 1;
        }
        long int ttime;
        ttime = time(NULL);
        
        if (mode == 1) {
            if (altitude > 1000) {
                fprintf(logs, "%s: the object is higher than 1km\n", ctime(&ttime));
            } else {
                fprintf(logs, "%s: the object is lower than 1km\n", ctime(&ttime));
            }
        } else if (mode == 2) {
            if (latitude > 50.0 && longitude < 50.0) {
                fprintf(logs, "%s: idk something\n", ctime(&ttime));
            } else {
                fprintf(logs, "%s: something else ig\n", ctime(&ttime));
            }
        }
        
        fclose(logs);
    }
    
    return 0;
}

