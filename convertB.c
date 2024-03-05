#include <stdio.h>

int main() {
    char choice;
    float speed, result;

    printf("Do you want to convert from mph to km/h (m) or km/h to mph (k)? ");
    scanf(" %c", &choice);

    printf("Enter the speed: ");
    scanf("%f", &speed);

    if(choice == 'm' || choice == 'M') {
        result = speed * 1.60934;
        printf("%.2f mph is equal to %.2f km/h\n", speed, result);
    } else if(choice == 'k' || choice == 'K') {
        result = speed / 1.60934;
        printf("%.2f km/h is equal to %.2f mph\n", speed, result);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}