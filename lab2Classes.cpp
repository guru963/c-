#include <stdio.h>

class dimensions {
    int length;
    int breadth;
    int height;

public:
    dimensions(int l, int b, int h) {
        length = l;
        breadth = b;
        height = h;
    }

    void square() {
        printf("The area of the square is %d \n", length * length);
    }

    void cube() {
        printf("The volume of the cube is %d \n", length * length * length);
    }

    void rectangle() {
        printf("The area of the rectangle is %d \n", length * breadth);
    }

    void cuboid() {
        printf("The volume of the cuboid is %d \n", length * breadth * height);
    }
};

int main() {
    int choice = 1;
    int l, b, h;

    printf("Enter the length: ");
    scanf("%d", &l);

    printf("Enter the breadth: ");
    scanf("%d", &b);

    printf("Enter the height: ");
    scanf("%d", &h);

    while (choice) {
        printf("Enter your choice: 1) Square 2) Cube 3) Rectangle 4) Cuboid 5) Exit\n");
        int n;
        scanf("%d", &n);

        dimensions d(l, b, h);

        if (n == 1) {
            d.square();
        } else if (n == 2) {
            d.cube();
        } else if (n == 3) {
            d.rectangle();
        } else if (n == 4) {
            d.cuboid();
        } else if (n == 5) {
            printf("Exit\n");
            break;
        } else {
            printf("Error\n");
        }
    }

    return 0;
}
