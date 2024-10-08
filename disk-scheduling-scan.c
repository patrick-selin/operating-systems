#include<stdio.h>
#include<stdlib.h>

#define MAX 199
#define MIN 0

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
  int disk_locations[10];
  int n = 10;
  int head = 10;
  int total_movement = 0;

  printf("Enter disk locations to service: \n");
  for (int i = 0; i < 10; i++) {
    scanf("%d", &disk_locations[i]);

}
printf("\n");
sort(disk_locations, n);

for (int i = 0; i < n; i++) {
    if (disk_locations[i] <= head) {
        printf("Sector %d\n", disk_locations[i]);
        total_movement += abs(disk_locations[i] - head);
        head = disk_locations[i];
    }
}

for (int i = 0; i < n; i++) {
    if (disk_locations[i] > head) {
        printf("Sector %d\n", disk_locations[i]);
        total_movement += abs(disk_locations[i] - head);
        head = disk_locations[i];
    }
}
printf("Total Disk Head Movement: %d\n", total_movement);

return 0;
}
