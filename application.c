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
        char info[1024], response[1024];
        
        printf("enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                sleep(1);
                FILE *modes = fopen("modes.txt", "w");
                // demon();
                if (modes == NULL) {
                    printf("Error opening modes.txt\n");
                    return 1;
                }
                fprintf(modes, "1");
                fclose(modes);
                sleep(1);
                modes = fopen("modes.txt", "r");
                if (modes == NULL) {
                    printf("Error opening modes.txt\n");
                    return 1;
                }
                fgets(response, sizeof(response), modes);
                printf("%s", response);
                fclose(modes);
                break;
            case 2:
                // demon();
                modes = fopen("modes.txt", "w");
                if (modes == NULL) {
                    printf("Error opening modes.txt\n");
                    return 1;
                }
                fprintf(modes, "2");
                fclose(modes);
                sleep(1);
                modes = fopen("modes.txt", "r");
                if (modes == NULL) {
                    printf("Error opening modes.txt\n");
                    return 1;
                }
                fgets(response, sizeof(response), modes);
                printf("%s", response);
                fclose(modes);
                break;
            case 3:
                // demon();
                FILE *data = fopen("data.txt", "r");
                if (data == NULL) {
                    printf("Error opening data.txt\n");
                    return 1;
                }
                fgets(info, sizeof(info), data);
                printf("coordinates:%s:",info);
                fclose(data);
                break;
            case 4:
                FILE *logs = fopen("logs.txt", "r");
                if (logs == NULL) {
                    printf("Error opening logs.txt\n");
                    return 1;
                }
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
