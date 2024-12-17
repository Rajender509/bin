#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char data[50], stuff[80], destuff[80];
    int i, j, len, count, ch;

    do {
        printf("Enter the Choice 1.Stuff 2.Destuff 3.Exit :-- ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter the Frame: ");
                scanf("%s", data);
                len = strlen(data);
                j = 0; // Reset j for stuffing
                count = 0; // Reset count for stuffing
                
                for(i = 0; i < len; i++) {
                    if(data[i] == '1') {
                        count++;
                    } else {
                        count = 0;
                    }
                    stuff[j] = data[i];
                    j++;
                    if(count == 5) {
                        stuff[j] = '0'; // Stuff a '0' after five '1's
                        j++;
                        count = 0; // Reset count after stuffing
                    }
                }
                stuff[j] = '\0'; // Null-terminate the stuffed string
                printf("After Stuffing: %s\n", stuff);
                break;

            case 2:
                len = strlen(stuff);
                count = 0; 
                j = 0; // Reset j for destuffing
                
                for(i = 0; i < len; i++) {
                    if(stuff[i] == '1') {
                        count++;
                    } else {
                        count = 0;
                    }
                    destuff[j] = stuff[i];
                    j++;
                    if(count == 5) {
                        count = 0; // Reset count
                        i++; // Skip the stuffed '0'
                    }
                }
                destuff[j] = '\0'; // Null-terminate the destuffed string
                printf("After Destuffing: %s\n", destuff);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(ch < 4);

    return 0;
}
