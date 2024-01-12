#include <stdio.h>

// Define the structure
struct Example {
    int x;
    // You can add more members if needed
};

int main() {
    // Declare and initialize the structure
    struct Example myStruct = {89};

    // Declare and initialize pointers to the structure
    struct Example *p1 = &myStruct;
    struct Example *p2 = &myStruct;
    struct Example *p3 = &myStruct;

    // Display the value of x using p1
    printf("Value of x using p1: %d\n", p1->x);

    // Update the value of x to 100 using p3
    p3->x = 100;

    // Display the updated value of x using p1
    printf("Updated value of x using p1: %d\n", p1->x);

    return 0;
}
