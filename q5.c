#include <stdio.h>
#include <string.h>

int main() {
    char productCode[20]; // Assuming a maximum length of 20 for the product code
    char warehouse[4];    // Assuming a maximum length of 3 for the warehouse code
    char productID[10];    // Assuming a maximum length of 9 for the product ID
    char qualifiers[10];   // Assuming a maximum length of 9 for the qualifiers

    // Get input from the user
    printf("Enter MMOC product code: ");
    scanf("%s", productCode);

    // Find the position of the first digit and the first letter after the digits
    int digitPos = 0;
    while (productCode[digitPos] != '\0' && !isdigit(productCode[digitPos])) {
        digitPos++;
    }

    int letterPos = digitPos;
    while (productCode[letterPos] != '\0' && !isalpha(productCode[letterPos])) {
        letterPos++;
    }

    // Extract components using strcpy and strncpy
    strncpy(warehouse, productCode, digitPos);
    warehouse[digitPos] = '\0';

    strncpy(productID, productCode + digitPos, letterPos - digitPos);
    productID[letterPos - digitPos] = '\0';

    strcpy(qualifiers, productCode + letterPos);

    // Display the report
    printf("Warehouse: %s\n", warehouse);
    printf("Product: %s\n", productID);
    printf("Qualifiers: %s\n", qualifiers);

    return 0;
}
