#include<stdio.h>
#include<stdlib.h>
#include"listadt.h"
int main(){
    merge l;
    int choice, value;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert in List 1\n");
        printf("2. Insert in List 2\n");
        printf("3. Merge both lists in sorted order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &value);
                l.createlist1(value);
                l.display1();
                break;
            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &value);
                l.createlist2(value);
                l.display2();
                break;
            case 3:
                printf("Merging lists...\n");
                l.mergelist();
                l.displaymerged();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
    


}