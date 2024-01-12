#include <stdio.h>

// Define the structure
struct Point {
    float x;
    float y;
    float z;
};

int main() {
    // Declare and initialize the structure
    struct Point myPoint = {1.2, 2.3, 6.7};

    // Declare a pointer to the structure and point it to the initialized structure
    struct Point *p = &myPoint;

    // Display the values using the pointer
    printf("x: %.2f\n", p->x);
    printf("y: %.2f\n", p->y);
    printf("z: %.2f\n", p->z);

    return 0;
}
