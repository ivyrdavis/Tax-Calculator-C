#include <stdio.h>


    int main(){
        int filingStatus;
        printf("Enter 1-4 for filing status\n   1. Single\n   2. Married filing jointly\n   3. Married filing separately\n   4. Head of family\n What is your choice? ");
        scanf("%d", &filingStatus);
        while (filingStatus < 1 || filingStatus > 4){
            printf("Filing status must be 1-4.\n\n");
            printf("Enter 1-4 for filing status\n   1. Single\n   2. Married filing jointly\n   3. Married filing separately\n   4. Head of family\n What is your choice? ");
            scanf("%d", &filingStatus);
    }

    int dependents;
    printf("Enter number of dependents: ");
    scanf("%d", &dependents);
    if (dependents < 0) {
        dependents = 0;
    }

    int income;
    printf("Enter adjusted gross income: ");
    scanf("%d", &income);
    if (income < 0) {
        income = 0;
    }

    int itemizedDeduction;
    printf("Enter itemized deduction: ");
    scanf("%d", &itemizedDeduction);
    if (itemizedDeduction < 0) {
        itemizedDeduction = 0;
    }

    int federalTaxDeduction;
    printf("Enter federal tax deduction: ");
    scanf("%d", &federalTaxDeduction);
    if (federalTaxDeduction < 0) {
        federalTaxDeduction = 0;
    }

    int standardDeduction;
    int bracket;
     if (filingStatus != 3) {
        if (income < 26000) {
            if (filingStatus == 1) {
                standardDeduction = 3000;
            } else if (filingStatus == 2) {
                standardDeduction = 8500;
            } else if (filingStatus == 4) {
                standardDeduction = 5200;
            }
        } else if (income <= 35499) {
            bracket = (income - 26000) / 500 + 1;

            if (filingStatus == 1) {
                standardDeduction = 3000 - 25 * bracket;
            } else if (filingStatus == 2) {
                standardDeduction = 8500 - 175 * bracket;
            } else if (filingStatus == 4) {
                standardDeduction = 5200 - 135 * bracket;
            }
        } else if (income > 35499) {
            if (filingStatus == 1) {
                standardDeduction = 2500;
            } else if (filingStatus == 2) {
                standardDeduction = 5000;
            } else if (filingStatus == 4) {
                standardDeduction = 2500;
            }
        }
    } else if (filingStatus == 3) {
        if (income < 13000) {
            standardDeduction = 4250;
        } else if (income < 17750) {
            bracket = (income - 13000) / 500 + 1;
            standardDeduction = 4250 - 88 * bracket;
        } else if (income > 17750) {
            standardDeduction = 2500;
        }
    }


    int deduction = (itemizedDeduction > standardDeduction) ? itemizedDeduction : standardDeduction;

    int personalExemption = (filingStatus == 2 || filingStatus == 4) ? 3000 : 1500;

    int dependentExemption;
    if (income < 50001) {
        dependentExemption = 1000 * dependents;
    } else if (income < 100001) {
        dependentExemption = 500 * dependents;
    } else {
        dependentExemption = 300 * dependents;
    }

    int taxableIncome = income - (federalTaxDeduction + personalExemption + dependentExemption + deduction);
    if (taxableIncome < 0) {
        taxableIncome = 0;
    }

    double tax;
    if (filingStatus != 2) {
        if (taxableIncome > 3000) {
            tax = (0.02 * 500) + (0.04 * 2500) + ((taxableIncome - 3000) * 0.05);
        } else if (taxableIncome > 500) {
            tax = (0.02 * 500) + ((taxableIncome - 500) * 0.04);
        } else {
            tax = taxableIncome * 0.02;
        }
    } else {
        if (taxableIncome > 6000) {
            tax = (0.02 * 1000) + (0.04 * 5000) + ((taxableIncome - 6000) * 0.05);
        } else if (taxableIncome > 1000) {
            tax = (0.02 * 1000) + ((taxableIncome - 1000) * 0.04);
        } else {
            tax = taxableIncome * 0.02;
        }
    }

    tax = (int)(tax + 0.5); 

    printf("\nStandard deduction=%d\n", standardDeduction);
    printf("Personal exemption=%d\n", personalExemption);
    printf("Dependent exemption=%d\n", dependentExemption);
    printf("Taxable=%d\n", taxableIncome);
    printf("Tax is %.0f\n", tax);

    return 0;
}
    