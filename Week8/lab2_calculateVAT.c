#include <stdio.h>

float calculateVAT(float amount);

int main(void)
{
    float amount;

    printf("Enter amount: ");
    scanf("%f", &amount);

    printf("VAT: %.2f\n", calculateVAT(amount));

    return 0;
}

float calculateVAT(float amount)
{
    return amount * 0.15;
}