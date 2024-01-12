#include <stdio.h>

// Define the structure
struct Example {
    int a;
    int b;
    int c;
};

int main() {
    // Declare and initialize the structure
    struct Example myStruct = {12, 25, 18};

    // Declare a pointer to the structure and point it to the initialized structure
    struct Example *ptr = &myStruct;

    // Update values of a, b, and c by incrementing them by 10 using the pointer
    ptr->a += 10;
    ptr->b += 10;
    ptr->c += 10;

    // Display the updated values
    printf("Updated value of a: %d\n", ptr->a);
    printf("Updated value of b: %d\n", ptr->b);
    printf("Updated value of c: %d\n", ptr->c);

    return 0;
}
