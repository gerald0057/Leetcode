#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t getFigures(int num){
    if (num == 0) 
        return 1;
    int cnt = 0;
    while (num){
        num /= 10;
        ++cnt;
    }
    return cnt;
}

char* SayString(char* str){
    int count = 1;
    size_t size = 1;
    size_t partSize = 0;
    size_t storeSize = 0;
    char* temp = str;
    char num[2] = {"0"};
    char* cnt = NULL;
    char* retChar = NULL;
    //preset 1 bytes for retChar
    if (NULL == (retChar = (char*)malloc(sizeof(char) * size))){
        perror("error in malloc");
        exit(1);
    }
    *(retChar) = '\0';
    if(NULL == (cnt = (char*)malloc(sizeof(char) * size))){
        perror("error in malloc");
        exit(2);
    }

    while(*temp != '\0'){
        if (*temp == *(temp + 1))
            ++count;
        else{
            //getFigures(count) + 1 reserved memory for '\0'
            partSize = count > 10 ? getFigures(count) + 1 : 2;            
            if (partSize > storeSize){
                cnt = (char*)realloc(cnt, partSize);
                storeSize = partSize;
            }
            sprintf(cnt, "%d", count);
            num[0] = *(temp);
            //the memory used reserved for '\0' now is for: char num, because retChar  = '\0' at first
            size += partSize;
            retChar = (char*)realloc(retChar, size);
            strcat(retChar, cnt);
            strcat(retChar, num);
            count = 1;
        }
        ++temp;
    }

    free(cnt);
    cnt = NULL;
    return retChar;
}

char* countAndSay(int n) {
    if (n < 1)
        return NULL;    
    
    if (n == 1){
        char* retChar = NULL;
        if (NULL == (retChar = (char*)malloc(sizeof(char) * 2))){
            perror("error in malloc");
            exit(3);
        }
        memset(retChar, '\0', 2);
        *retChar = '1';
        return retChar;
    }

    char* loop = SayString("1");
    --n;
    int i = 1;        
    for (; i < n; ++i)
        loop = SayString(loop);

    return loop;
}

int main(void){
    char* loop = countAndSay(2);
    printf("%s", loop);

    free(loop);
    loop = NULL;

    return 0;
}