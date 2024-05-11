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

// Function to print the menu
void print_menu() {
    printf("Enter 1 to convert from mph to km/h\n");
    printf("Enter 2 to convert from km/h to mph\n");
    printf("Enter 3 to calculate time from distance and speed\n");
    printf("Enter your choice: ");
}

// Function to get the user's choice
int get_choice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

// Function to get the speed in mph
float get_mph_speed() {
    float speed;
    printf("Enter the speed in mph: ");
    scanf("%f", &speed);
    return speed;
}

// Function to get the speed in km/h
float get_kmh_speed() {
    float speed;
    printf("Enter the speed in km/h: ");
    scanf("%f", &speed);
    return speed;
}

// Function to get the distance in miles
float get_miles_distance() {
    float distance;
    printf("Enter the distance in miles: ");
    scanf("%f", &distance);
    return distance;
}

// Function to get the distance in kilometers
float get_kilometers_distance() {
    float distance;
    printf("Enter the distance in kilometers: ");
    scanf("%f", &distance);
    return distance;
}

// Function to print the result of the conversion or calculation
void print_result(float result, float original, float converted) {
    printf("%.2f %s is equal to %.2f %s\n", original, "mph", converted, "km/h");
}

// Function to handle the user's choice
void handle_choice(int choice) {
    float speed, distance, time;

    if(choice == 1) {
        speed = get_mph_speed();
        float converted_speed = convert_mph_to_kmh(speed);
        print_result(speed, "mph", converted_speed);
    } else if(choice == 2) {
        speed = get_kmh_speed();
        float converted_speed = convert_kmh_to_mph(speed);
        print_result(speed, "km/h", converted_speed);
    } else if(choice == 3) {
        printf("Enter 1 for U.S. measurements (miles and hours)\n");
        printf("Enter 2 for international measurements (kilometers and hours)\n");
        int unit_choice;
        scanf("%d", &unit_choice);

        if(unit_choice == 1) {
            distance = get_miles_distance();
            speed = get_mph_speed();
            time = calculate_time(distance, speed);
            printf("It would take %.2f hours to travel %.2f miles at a speed of %.2f mph\n", time, distance, speed);
        } else if(unit_choice == 2) {
            distance = get_kilometers_distance();
            speed = get_kmh_speed();
            time = calculate_time(distance, speed);
            printf("It would take %.2f hours to travel %.2f kilometers at a speed of %.2f km/h\n", time, distance, speed);
        } else {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } else {
        printf("Invalid choice. Please enter 1, 2 or 3.\n");
    }
}

int main() {
    print_menu();
    int choice = get_choice();
    handle_choice(choice);

    return 0;
}