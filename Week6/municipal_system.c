#include <stdio.h>
#include <string.h>

// Set to small values for quick testing in VS Code.
// Change to 50, 10, 20 before final submission.
#define NUM_SALARIES 5
#define NUM_BUDGETS 5
#define NUM_VEHICLES 5
#define REG_LENGTH 20

int main() {
    // ==========================================
    // PART A: EMPLOYEE SALARIES
    // ==========================================
    float salaries[NUM_SALARIES];
    float salaryTotal = 0.0f;
    float salaryAverage;
    float highestSalary, lowestSalary;
    float searchSalary;
    int salaryFound = 0;

    printf("=== PART A: EMPLOYEE SALARIES ===\n\n");
    
    for (int i = 0; i < NUM_SALARIES; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
        salaryTotal += salaries[i];
    }

    highestSalary = salaries[0];
    lowestSalary = salaries[0];

    printf("\n--- Captured Salaries ---\n");
    for (int i = 0; i < NUM_SALARIES; i++) {
        printf("Employee %d: NAD %.2f\n", i + 1, salaries[i]);

        if (salaries[i] > highestSalary) {
            highestSalary = salaries[i];
        }
        if (salaries[i] < lowestSalary) {
            lowestSalary = salaries[i];
        }
    }

    salaryAverage = salaryTotal / NUM_SALARIES;

    printf("\n--- Salary Summary ---\n");
    printf("Average Salary: NAD %.2f\n", salaryAverage);
    printf("Highest Salary: NAD %.2f\n", highestSalary);
    printf("Lowest Salary:  NAD %.2f\n", lowestSalary);

    printf("\nEnter salary to search for: ");
    scanf("%f", &searchSalary);

    for (int i = 0; i < NUM_SALARIES; i++) {
        if (salaries[i] == searchSalary) {
            printf("Salary NAD %.2f found at position %d.\n", searchSalary, i + 1);
            salaryFound = 1;
            break;
        }
    }
    if (!salaryFound) {
        printf("Salary NAD %.2f not found in records.\n", searchSalary);
    }


    // ==========================================
    // PART B: DEPARTMENT BUDGETS
    // ==========================================
    float budgets[NUM_BUDGETS];
    float budgetTotal = 0.0f;
    float budgetAverage;
    float tempBudget;

    printf("\n\n=== PART B: DEPARTMENT BUDGETS ===\n\n");

    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        budgetTotal += budgets[i];
    }

    budgetAverage = budgetTotal / NUM_BUDGETS;

    printf("\nTotal Municipal Budget:   NAD %.2f\n", budgetTotal);
    printf("Average Department Budget: NAD %.2f\n", budgetAverage);

    // Bubble Sort (Ascending)
    for (int i = 0; i < NUM_BUDGETS - 1; i++) {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                tempBudget = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = tempBudget;
            }
        }
    }

    printf("\n--- Department Budgets (Sorted Ascending) ---\n");
    for (int i = 0; i < NUM_BUDGETS; i++) {
        printf("Department Rank %d: NAD %.2f\n", i + 1, budgets[i]);
    }


    // ==========================================
    // PART C: VEHICLE REGISTRATION NUMBERS
    // ==========================================
    char registrations[NUM_VEHICLES][REG_LENGTH];
    char searchReg[REG_LENGTH];
    int regFound = 0;

    printf("\n\n=== PART C: VEHICLE REGISTRATIONS ===\n\n");

    for (int i = 0; i < NUM_VEHICLES; i++) {
        printf("Enter registration number for vehicle %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\n--- Vehicle Registrations List ---\n");
    for (int i = 0; i < NUM_VEHICLES; i++) {
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter registration number to search: ");
    scanf("%19s", searchReg);

    for (int i = 0; i < NUM_VEHICLES; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Vehicle registration '%s' found at slot %d.\n", searchReg, i + 1);
            regFound = 1;
            break;
        }
    }
    if (!regFound) {
        printf("Vehicle registration '%s' not found.\n", searchReg);
    }

    return 0;
}