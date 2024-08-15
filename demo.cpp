#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10


typedef struct {
    int room_number;
    char guest_name[50];
    int booked; 
} Room;
void initialize(Room rooms[], int n);
void displayRooms(Room rooms[], int n);
void bookRoom(Room rooms[], int n);
void cancelBooking(Room rooms[], int n);

int main() {
    Room rooms[MAX_ROOMS];
    initialize(rooms, MAX_ROOMS);

    int choice;
    do {
        printf("\nHotel Booking System\n");
        printf("1. Display available rooms\n");
        printf("2. Book a room\n");
        printf("3. Cancel booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, MAX_ROOMS);
                break;
            case 2:
                bookRoom(rooms, MAX_ROOMS);
                break;
            case 3:
                cancelBooking(rooms, MAX_ROOMS);
                break;
            case 4:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


void initialize(Room rooms[], int n) {
    for (int i = 0; i < n; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].guest_name, "None");
        rooms[i].booked = 0;
    }
}


void displayRooms(Room rooms[], int n) {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < n; i++) {
        if (rooms[i].booked == 0) {
            printf("Room %d\n", rooms[i].room_number);
        }
    }
}
void bookRoom(Room rooms[], int n) {
    int room_num;
    printf("\nEnter room number to book: ");
    scanf("%d", &room_num);

    if (room_num < 1 || room_num > n) {
        printf("Invalid room number!\n");
        return;
    }

    if (rooms[room_num - 1].booked == 1) {
        printf("Room %d is already booked!\n", room_num);
    } else {
        printf("Enter guest name: ");
        scanf("%s", rooms[room_num - 1].guest_name);
        rooms[room_num - 1].booked = 1;
        printf("Room %d booked successfully for %s\n", room_num, rooms[room_num - 1].guest_name);
    }
}


void cancelBooking(Room rooms[], int n) {
    int room_num;
    printf("\nEnter room number to cancel booking: ");
    scanf("%d", &room_num);

    if (room_num < 1 || room_num > n) {
        printf("Invalid room number!\n");
        return;
    }

    if (rooms[room_num - 1].booked == 0) {
        printf("Room %d is not booked!\n", room_num);
    } else {
        strcpy(rooms[room_num - 1].guest_name, "None");
        rooms[room_num - 1].booked = 0;
        printf("Booking for room %d cancelled successfully\n", room_num);
    }
}

