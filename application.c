#include <stdio.h>
#include <time.h>
int main() {
    int mode;
    float altitude, latitude, longitude;
    while (1) {
        printf("gps tracker\n");
        printf("1. start tracking\n");
        printf("2. stop tracking\n");
        printf("3. get data\n");
        printf("4. get info\n");
        printf("5. exit\n");

        
        int choice;
        char tiime[256],info[256];
        while (1) {
        printf("enter your choice: ");
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
                sleep(1);
               // demon();
                FILE *data = fopen("data.txt", "r");
                fscanf(data, "%f %f %f", &latitude, &longitude, &altitude);
                printf("coordinates:\nlatitude: %f\nlongitude: %f\naltitude: %f\n", latitude, longitude, altitude);
                fclose(data);
            case 4:
                sleep(1);
                // demon();
                FILE *logs = fopen("logs.txt", "r");
                fscanf(logs, "%s%s", &tiime, &info);
                printf("%s%s", tiime, info);
                fclose(logs);
            case 5:
                printf("exiting...\n");
                system("killall -9 file1");
                return 0;
            default:
                printf("invalid choice\n");
        }
    }
    }
    return 0;
}
