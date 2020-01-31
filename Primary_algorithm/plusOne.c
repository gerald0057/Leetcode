#include <stdio.h>
#include <stdlib.h>

// int* plusOne(int* digits, int digitsSizes, int* returnSize){
//     if (digitsSizes < 1) return NULL;

//     int* result = (int*)malloc(sizeof(int) * (digitsSizes + 1));
//     if (result == NULL) return NULL;
//     *returnSize = 0;

//     int i = digitsSizes - 1;

//     while (digits[i] == 9 && i > -1){
//         result[i + 1] = 0;
//         --i;
//         ++*returnSize;
//     }
//     if (i > -1){
//         result[i + 1] = digits[i] + 1;
//         ++*returnSize;
//         result[0] = 0;
//         --i;

//         while(i > -1){
//             result[i + 1] = digits[i];
//             --i;
//             ++*returnSize;
//         }
//     }        
//     else{
//         result[0] = 1;
//         ++*returnSize;
//     }

//     if (result[0] == 0){
//         int* mmycpy = result;
//         ++result;
//     } 

//     return result;
// }

int* plusOne(int* digits, int digitsSizes, int* returnSize){
    if (digitsSizes < 1) return NULL;
    *returnSize = 0;

    int i = digitsSizes - 1;
    if (digits[i] != 9){
        ++digits[i];
        *returnSize = digitsSizes;

        return digits;
    }
    else
    {
        while(digits[i] == 9){
            digits[i] = 0;
            --i;
            if (i < 0){
                int* newdig = (int*)malloc(sizeof(int) * (digitsSizes + 1));
                newdig[0] = 1;
                for (i = 1; i < digitsSizes + 1; ++i)
                    newdig[i] = 0;
                *returnSize = ++digitsSizes;
                
                return newdig;
            }            
        }
        *returnSize = digitsSizes;
        ++digits[i];

        return digits; 
    }
}

int main(void){
    int arr[] = {8,9,9,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int returnSize = size;

    int* ans = plusOne(arr, size, &returnSize);

    int i = 0;
    for (; i < returnSize; ++i){
        printf("%d ", ans[i]);
    }

    return 0;
}