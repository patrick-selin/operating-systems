#include<stdio.h>
#include<stdlib.h>

int main() {
    int disk_locations[10];
    int head = 10;  // Starting position of the disk head
    int total_movement = 0;

    printf("Enter disk locations to service (10 values between 0-199): ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &disk_locations[i]);

        if (disk_locations[i] < 0 || disk_locations[i] > 199) {
            printf("Invalid disk location: %d. Please enter a value between 0 and 199.\n", disk_locations[i]);
            return 1;
        }
    }
    printf("\n");
  
    for (int i = 0; i < 10; i++) {
        int current_location = disk_locations[i];
        printf("Sector %d\n", current_location);

        total_movement += abs(current_location - head);
        head = current_location;
    }
    printf("Total Disk Head Movement: %d\n", total_movement);

    return 0;
}
