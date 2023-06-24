#include "gps.h"

int main() {
    gps_driver_init();
    int mode;
    while (1) {
        printf("gps tracker\n");
        printf("1. start tracking\n");
        printf("2. stop tracking\n");
        printf("3. exit\n");
        printf("enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sleep(1);
                printf("tracking started. enter mode in config (1-2).\n");
                // demon();
                break;
            case 2:
                sleep(1);
                printf("tracking stopped.\n");
                break;
            case 3:
                printf("exiting...\n");
                system("killall -9 file1");
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}
