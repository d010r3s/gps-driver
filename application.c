#include "gps.h"
#include <stdio.h>

int main() {
    gps_driver_init();
    process_coordinates(float latitude, float longitude, float altitude, int mode);

    while (1) {
        printf("gps tracker\n");
        printf("1. start\n");
        printf("2. stop\n");
        printf("3. exit\n");
        printf("enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sleep(1);
                printf("Tracking started.\n");
                break;
            case 2:
                sleep(1);
                printf("Tracking stopped.\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
