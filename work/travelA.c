#include <stdio.h>

// Function to convert mph to km/h
float convert_mph_to_kmh(float speed) {
    return speed * 1.60934;
}

// Function to convert km/h to mph
float convert_kmh_to_mph(float speed) {
    return speed / 1.60934;
}

// Function to calculate time from distance and speed
float calculate_time(float distance, float speed) {
    return distance / speed;
}

// Function to display the main menu
void display_main_menu() {
    printf("Enter 1 to convert from mph to km/h\n");
    printf("Enter 2 to convert from km/h to mph\n");
    printf("Enter 3 to calculate time from distance and speed\n");
    printf("Enter your choice: ");
}

// Function to handle the user's choice
void handle_choice(int choice, float speed, float distance) {
    if(choice == 1) {
        float converted_speed = convert_mph_to_kmh(speed);
        printf("%.2f mph is equal to %.2f km/h\n", speed, converted_speed);
    } else if(choice == 2) {
        float converted_speed = convert_kmh_to_mph(speed);
        printf("%.2f km/h is equal to %.2f mph\n", speed, converted_speed);
    } else if(choice == 3) {
        float time = calculate_time(distance, speed);
        printf("It would take %.2f hours to travel %.2f miles at a speed of %.2f mph\n", time, distance, speed);
    } else {
        printf("Invalid choice. Please enter 1, 2 or 3.\n");
    }
}

int main() {
    float speed, distance, time;
    int choice;

    display_main_menu();
    scanf("%d", &choice);

    if(choice == 1 || choice == 2) {
        printf("Enter the speed: ");
        scanf("%f", &speed);
        handle_choice(choice, speed, 0);
    } else if(choice == 3) {
        printf("Enter the distance in miles: ");
        scanf("%f", &distance);
        printf("Enter the speed in mph: ");
        scanf("%f", &speed);
        handle_choice(choice, speed, distance);
    } else {
        printf("Invalid choice. Please enter 1, 2 or 3.\n");
    }

    return 0;
}