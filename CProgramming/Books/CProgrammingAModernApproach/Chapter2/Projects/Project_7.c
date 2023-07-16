#include <stdio.h>



int main(void) {
    int dollar = 0;

    printf("Enter a dollar amount: ");
    if (scanf("%d", &dollar) != 1)
        return 1;
    
    // get the twenty bills
    int twentyBills = dollar / 20;
    // get the current amount after pay the twenty bills
    dollar = dollar - ((dollar / 20) * 20);

    // get the ten bills
    int tenBills = dollar / 10;
    // get the current amount after pay the ten bills
    dollar = dollar - ((dollar / 10) * 10);

    // get the five bills
    int fiveBills = dollar / 5;
    // get the current amount after you pay the five bills
    dollar = dollar - ((dollar / 5) * 5);

    // get the three bills
    int threeBills = dollar / 3;
    
    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $3 bills: %d\n", 
            twentyBills,
            tenBills,
            fiveBills,
            threeBills);

    return 0;

}