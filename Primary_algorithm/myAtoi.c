#include <stdio.h>
#include <limits.h>

int myAtoi(char* str) {
    int retNum = 0;
    int i = 0;
    char symflag = 0;
    for (; str[i] != '\0'; ++i){
        if (str[i] == ' ' && symflag == 0)
            continue;
        else{
            if (str[i] == '+' && symflag == 0)
                symflag = 1;
            else if (str[i] == '-' && symflag == 0){
                symflag = -1;
            }
            else if (str[i] >= '0' && str[i] <= '9'){
                symflag = (symflag == -1) ? -1 : 1;
                //over flow judge here next time
                if (retNum > INT_MAX / 10 || ((retNum == INT_MAX / 10) && (str[i] - '0' > 7)))
                    return INT_MAX;
                if (retNum < (-1 * INT_MAX - 1) / 10 || ((retNum == (-1 * INT_MAX - 1) / 10) && (-1 * (str[i] - '0') < -8)))
                    return -1 * INT_MAX - 1;
                retNum = retNum * 10 + (str[i] - '0') * symflag;
            }
            else{
                if (retNum == 0)
                    return 0;
                else
                    return retNum;
            }       
        }        
    }

    return retNum;
}

int main(void){
    char str2num[] = {"-2147483649"};

    printf("%d\n", myAtoi(str2num));

    return 0;
}