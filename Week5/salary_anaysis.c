#include <stdio.h>

#define NUM_EMPLOYEES 50

int main() {
    float salary;
    float total = 0.0f;
    float highest = 0.0f;
    float lowest = 0.0f;
    float average;

    printf("=== MUNICIPAL EMPLOYEE SALARY ANALYSIS ===\n\n");

    for (int i = 1; i <= NUM_EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total = total + salary;

        // Initialize highest and lowest with the first employee's salary
        if (i == 1) {
            highest = salary;
            lowest = salary;
        }

        // Check for new highest salary
        if (salary > highest) {
            highest = salary;
        }

        // Check for new lowest salary
        if (salary < lowest) {
            lowest = salary;
        }
    }

    average = total / NUM_EMPLOYEES;

    printf("\n--- Salary Report ---\n");
    printf("Total Salary Expenditure: NAD %.2f\n", total);
    printf("Average Salary:           NAD %.2f\n", average);
    printf("Highest Salary:           NAD %.2f\n", highest);
    printf("Lowest Salary:            NAD %.2f\n", lowest);

    return 0;
}