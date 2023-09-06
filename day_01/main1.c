#include <stdio.h>

int main() {
    FILE *file;
    char filename[] = "input.txt"; // Replace with the name of your input file
    int expenseArray[1000]; // Adjust the array size as needed
    int numExpenses = 0; // Variable to keep track of the number of expenses
    int num1, num2; // Variables to store the two numbers with the desired sum
    int targetSum = 2020; // The sum you want to find

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the list of expenses from the file
    while (fscanf(file, "%d", &expenseArray[numExpenses]) == 1) {
        numExpenses++;
    }

    // Close the file
    fclose(file);

    // Find two expenses that sum to the target sum
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = i + 1; j < numExpenses; j++) {
            if (expenseArray[i] + expenseArray[j] == targetSum) {
                num1 = expenseArray[i];
                num2 = expenseArray[j];
                break; // Exit the loops when a pair is found
            }
        }
    }

    // Check if a pair with the target sum was found
    if (num1 + num2 == targetSum) {
        printf("The two expenses with the sum of %d are: %d and %d\n", targetSum, num1, num2);
        printf("The product of the two expenses is: %d\n", num1 * num2);
    } else {
        printf("No pair with the sum of %d was found.\n", targetSum);
    }

    return 0;
}
