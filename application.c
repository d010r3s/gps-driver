#include "gps.h"

int main() {
    gps_driver_init();
    while (1) {
        printf("gps tracker\n");
        printf("1. start tracking\n");
        printf("2. stop tracking\n");
        printf("3. exit\n");
        printf("enter your choice: ");
        
        int choice, mode;
        scanf("%d", &choice);
       
        switch (choice) {
            case 1:
                sleep(1);
                printf("tracking started. choose mode (1-2):\n");
                scanf("%d", &mode);
                demon();
            case 2:
                sleep(1);
                printf("tracking stopped.\n");
                break;
            case 3:
                cleanup();
                printf("exiting...\n");
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
