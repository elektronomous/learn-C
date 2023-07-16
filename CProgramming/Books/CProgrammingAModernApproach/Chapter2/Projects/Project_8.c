#include <stdio.h>

#define YEAR_TO_MONTH 12


int main(void) {
    float loan, interestRate, monthlyPayment;

    printf("Enter amount of loan: ");
    if (scanf("%f", &loan) != 1)
        return 1;
    
    printf("Enter interest rate: ");
    if (scanf("%f", &interestRate) != 1)
        return 1;
    
    printf("Enter monthly payment: ");
    if (scanf("%f", &monthlyPayment) != 1)
        return 1;
    
    // calculate the loan after interest
    float loanPlusInterest = loan + (loan * (interestRate / 100 / YEAR_TO_MONTH));
    // decrease by the payment
    printf("Ballance remaining after first payment: $%.2f\n", loanPlusInterest - monthlyPayment);
    // get the current loanPlusInterest
    loanPlusInterest = loanPlusInterest - monthlyPayment;

    // calculate the loan after interest again
    loanPlusInterest = loanPlusInterest + (loanPlusInterest * (interestRate / 100 / YEAR_TO_MONTH));
    // decrease by the payment
    printf("Ballance remaining after second payment: $%.2f\n", loanPlusInterest - monthlyPayment);
    // get the current loanPlusInterest
    loanPlusInterest = loanPlusInterest - monthlyPayment;

    // calculate the loan after interest again
    loanPlusInterest = loanPlusInterest + (loanPlusInterest * (interestRate / 100 / YEAR_TO_MONTH));
    // decrease by the payment
    printf("Ballance remaining after second payment: $%.2f\n", loanPlusInterest - monthlyPayment);

    return 0;
}