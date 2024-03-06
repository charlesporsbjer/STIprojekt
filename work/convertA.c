#include <stdio.h>

int main() {
    int choice;
    float speed, converted_speed;

    printf("Enter 1 to convert from mph to km/h\n");
    printf("Enter 2 to convert from km/h to mph\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the speed: ");
    scanf("%f", &speed);

    if(choice == 1) {
        converted_speed = speed * 1.60934;
        printf("%.2f mph is equal to %.2f km/h\n", speed, converted_speed);
    } else if(choice == 2) {
        converted_speed = speed / 1.60934;
        printf("%.2f km/h is equal to %.2f mph\n", speed, converted_speed);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}