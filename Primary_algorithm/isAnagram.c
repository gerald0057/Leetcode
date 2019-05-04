#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t))
        return false;

    int i = 0;
    int s_index[26] = {0};
    int t_index[26] = {0};

    for (; s[i] != '\0', t[i] != '\0'; ++i){
        ++s_index[s[i] - 'a'];
        ++t_index[t[i] - 'a'];
    }
    
    for (i = 0; i < 26; ++i)
        if (s_index[i] != t_index[i])
            return false;

    return true;
}

int main(void){
    char s[] = {"anagram"};
    char t[] = {"nagaram"};

    printf("%s", isAnagram(s, t) == true ? "true" : "false");

    return 0;
}