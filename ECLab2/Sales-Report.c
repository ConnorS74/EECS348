#include <stdio.h>
#include <string.h>
int main()
{
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float sales[12];
    for (int i = 0; i < 12; i++) {
        scanf("%f", &sales[i]);
    }
    void print_month(char month[]) {
        printf("%s", month);
        for (int i = strlen(month); i < 10; i++) {
            printf(" ");
        }
    }
    void minimum() {
        int minimum = 0;
        for (int i = 1; i < 12; i++) {
            if (sales[i] < sales[minimum]) {
                minimum = i;
            }
        }
        printf("Minimum sales: $%.2f (%s)\n", sales[minimum], months[minimum]);
    }
    void maximum() {
        int maximum = 0;
        for (int i = 1; i < 12; i++) {
            if (sales[i] > sales[maximum]) {
                maximum = i;
            }
        }
        printf("Maximum sales: $%.2f (%s)\n", sales[maximum], months[maximum]);
    }
    void average() {
        float average = 0;
        for (int i = 0; i < 12; i++) {
            average += sales[i];
        }
        average /= 12;
        printf("Average sales: $%.2f\n", average);
    }
    void partial_average(int start, int end) {
        float average = 0;
        for (int i = start; i <= end; i++) {
            average += sales[i];
        }
        average /= (end - start + 1);
        print_month(months[start]);
        printf("- ");
        print_month(months[end]);
        printf("$%.2f\n", average);
    }
    void sorter() {
        float dupe[12];
        memcpy(dupe, sales, sizeof dupe);
        int maximum = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++){
                if (dupe[j] > dupe[maximum]) {
                    maximum = j;
                }
            }
            print_month(months[maximum]);
            printf("$%.2f\n", dupe[maximum]);
            dupe[maximum] = 0;
        }
    }
    void sales_report() {
        printf("Monthly sales report for 2022:\n\n");
        printf("Month     Sales\n\n");
        for (int i = 0; i < 12; i++) {
            print_month(months[i]);
            printf("$%.2f\n", sales[i]);
        }
        printf("\n\n");
    }
    void sales_summary() {
        printf("Sales summary:\n\n");
        minimum();
        maximum();
        average();
        printf("\n\n");
    }
    void SMMAR() {
        printf("Six-Month Moving Average Report:\n\n");
        for (int i = 0; i < 7; i++) {
            partial_average(i, i + 5);
        }
        printf("\n\n");
    }
    void ranked_report() {
        printf("Sales Report (Highest to Lowest):\n\n");
        printf("  Month     Sales  \n\n");
        sorter();
    }
    sales_report();
    sales_summary();
    SMMAR();
    ranked_report();
    return 0;
}