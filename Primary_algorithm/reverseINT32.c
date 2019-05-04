#include <stdio.h>

int reverse(int x) {
    if (x == 0)
        return 0;
    int revX = 0;
    int digit = 0;
    int max = 0X7FFFFFFF, min = 0X80000000;
    
    while(x != 0){
        digit = x % 10;
        x /= 10;
        if (revX > max / 10 || (revX == max / 10 && digit > 7))
            return 0;
        if (revX < min / 10 || (revX == min / 10 && digit < -6))
            return 0;
        revX = revX * 10 + digit;
    }
    return revX;
}

int main(void){
    int num = -123;

    printf("%d",reverse(num));

    return 0;
}