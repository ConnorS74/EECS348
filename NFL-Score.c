#include <stdio.h>
int main() {
    void FG(int points, int combination[3]) {
        int plays = 0;
        while (3*plays <= points) {
            if ((points - 3*plays)%2 == 0) {
                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", combination[0], combination[1], combination[2], plays, (points - 3*plays)/2);
            }
            plays++;
        }
    }
    void TD(int points, int combination[2]) {
        int plays = 0;
        int instance[3] = {combination[0], combination[1], 0};
        while (6*plays <= points) {
            instance[2] = plays;
            FG(points - 6*plays++, instance);
        }
    }
    void TDFG(int points, int conversions) {
        int plays = 0;
        int instance[2] = {conversions, 0};
        while (7*plays <= points) {
            instance[1] = plays;
            TD(points - 7*plays++, instance);
        }
    }
    void TDcon(int points) {
        int plays = 0;
        while (8*plays <= points) {
            TDFG(points - 8*plays, plays);
            plays++;
        }
    }
    int points;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &points);
        if (points == 0 || points == 1) {
            break;
        }
        TDcon(points);
        printf("\n");
    }
    return 0;
}