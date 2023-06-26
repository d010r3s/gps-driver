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
        printf("1-2. start tracking with entering mode\n");
        printf("3. get data\n");
        printf("4. get info\n");
        printf("5. exit\n");

        int choice;
        char info[1024], response[1024];
        
        printf("enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sleep(1);
                FILE *config = fopen("config.txt","w");
                fprintf(config,"%d",choice);
                printf("started");
                fclose(config);
                break;
            case 2:
                sleep(1);
                config = fopen("config.txt","w");
                fprintf(config,"%d",choice);
                printf("started");
                fclose(config);
                break;
            case 3:
                FILE *data = fopen("data.txt", "r");
                fgets(info, sizeof(info), data);
                printf("coordinates: %s",info);
                fclose(data);
                break;
            case 4:
                FILE *logs = fopen("logs.txt", "r");
                fgets(info, sizeof(info), logs);
                printf("%s", info);
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
    
    return 0;
}
