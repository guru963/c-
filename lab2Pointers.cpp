#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void palindrome(int *n) ;
void perfect(int *n);
int power(int *a, int *b);
void armstrong(int *n);

int main() {
    int *choice;
    choice=(int *)malloc(1*sizeof(int));
    *choice = 1;

    while (*choice) {
        int *n;
        n = (int *)malloc(sizeof(int));
        printf("Enter the number");
        scanf("%d",n);
        printf("Enter your choice 1)Palindrome 2)Armstrong 3)Perfect 4)Exit\n");
        int *c;
        c = (int *)malloc(sizeof(int));
        scanf("%d", c);

        if (*c == 1) {
            palindrome(n);
        } else if (*c == 2) {
            armstrong(n);
        } else if (*c == 3) {
            perfect(n);
        } else if (*c == 4) {
            printf("Exit\n");
            break;
        } else {
            printf("Error\n");
        }
    }
}

void palindrome(int *n) {
    int *temp;
    temp = (int *)malloc(sizeof(int));
    int *rev;
    rev = (int *)malloc(sizeof(int));
    int *rem;
    rem = (int *)malloc(sizeof(int));
    int *ori;
    ori = (int *)malloc(sizeof(int));

    *temp = *n;
    *ori = *n;
    *rev = 0;
    *rem = 0;

    while ((*temp) > 0) {
        *rem = (*temp) % 10;
        *rev = (*rev) * 10 + (*rem);
        (*temp) = (*temp) / 10;
    }

    if ((*ori) == (*rev)) {
        printf("It is a palindrome number \n");
    } else {
        printf("It is not a palindrome number \n");
    }
}

void perfect(int *n) {
    int *sum;
    int *i;
    i = (int *)malloc(sizeof(int));
    sum = (int *)malloc(sizeof(int));

    *sum = 0;
    for (*i = 1; *i <= ((*n) / 2); (*i)++) {
        if ((*n) % (*i) == 0) {
            *sum = *sum + *i;
        }
    }

    if (*sum == *n) {
        printf("It is a perfect number \n");
    } else {
        printf("It is not a perfect number \n");
    }
}

int power(int *a, int *b) {
    int *i;
    int *t;
    t = (int *)malloc(sizeof(int));
    *t = *a;

    i = (int *)malloc(sizeof(int));
    for (*i = 0; (*i) < (*b) - 1; (*i)++) {
        *a = *a * *t;
    }
    return *a;
}

void armstrong(int *n) {
    int *digits;
    int *sum;
    int *ori;
    int *rem;
    int *temp;
    

    temp = (int *)malloc(sizeof(int));
    digits = (int *)malloc(sizeof(int));
    sum = (int *)malloc(sizeof(int));
    ori = (int *)malloc(sizeof(int));
    rem = (int *)malloc(sizeof(int));

    *rem = 0;
    *digits = 0;
    *sum = 0;
    *ori = *n;
    *temp = *n;

    while ((*temp) > 0) {
        (*temp) = (*temp) / 10;
        (*digits) = (*digits) + 1;
    }

    while ((*ori) > 0) {
        *rem = *ori % 10;
        *sum = *sum + power(rem, digits);
        *ori = *ori / 10;
    }

    if (*sum == *n) {
        printf("It is an armstrong number \n");
    } else {
        printf("It is not an armstrong number \n");
    }
}

