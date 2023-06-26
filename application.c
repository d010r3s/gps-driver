#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdlib.h>
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
        char tiime[100],info[100],response[100];
        while (1) {
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sleep(1);
                // demon();
                FILE *modes = fopen("modes.txt", "w");
                fprintf(modes, "1");
                fclose(modes);
                modes = fopen("modes.txt","r");
                fscanf(modes, "%s\n", response);
                printf("%s", response);
                fclose(modes);
                break;
            case 2:
                modes = fopen("modes.txt", "w");
                // demon();
                fprintf(modes, "2");
                fclose(modes);
                modes = fopen("modes.txt", "r");
                fscanf(modes, "%s\n", response);
                sleep(1);
                printf("%s", response);
                break;
            case 3:
                sleep(1);
                
                FILE *data = fopen("data.txt", "r");
                // demon();
                fscanf(data, "%f %f %f", &latitude, &longitude, &altitude);
                printf("coordinates:\nlatitude: %f\nlongitude: %f\naltitude: %f\n", latitude, longitude, altitude);
                fclose(data);
                break;
            case 4:
                sleep(1);
                // demon();
                FILE *logs = fopen("logs.txt", "r");
                fscanf(logs, "%s%s", tiime, info);
                printf("%s%s", tiime, info);
                fclose(logs);
                break;
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
