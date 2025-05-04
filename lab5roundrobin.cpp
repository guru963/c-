#include <stdio.h>
#include <stdlib.h>
#include "robin.h"

int main(){
    roundrobin l;
    
        int choice, value, timeSlice;
    do {
        printf("\nRound Robin Scheduling Menu\n");
        printf("1. Insert Process\n");
        printf("2. Execute Processes\n");
        printf("3. Display Process Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter burst time of process: ");
                scanf("%d", &value);
                l.insertprocess(value);
                break;
            case 2:
                printf("Enter time slice: ");
                scanf("%d", &timeSlice);
                l.executeprocess(timeSlice);
                break;
            case 3:
                l.display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;

}