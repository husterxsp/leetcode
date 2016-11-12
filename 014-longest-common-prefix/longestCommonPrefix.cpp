#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char result[100] = "\0";
    int i = 0;
    if (strsSize == 0) {
        return "";
    }
    if (strsSize == 1) {
        return strs[0];
    }
    char tmp[100] = "\0";
    while (i < strlen(strs[0]) && i < strlen(strs[1])) {
        if (strs[0][i] == strs[1][i]) {
            strncpy(result, strs[0], i+1);
            i++;
        } else {
            break;
        }
    }
    for (int j = 2; j < strsSize; j++) {
        for (int k = 0; k < i; k++) {
            if (result[k] != strs[j][k]) {
                i = k;
                if(i == 0){
                    return "";
                }
                char tmp[10] = {"\0"};
                result = "\0";
                strcpy(result, "\0");
                printf("result: %s", result);
//                printf("%s\n", strncpy(tmp, strs[0], i));
//                result[0] = "\0";
                strncpy(result, strs[0], i);
                break;
            }
        }
    }
    return result;
}

int main(){
    char *strs[3] = {"abab", "aba", "abc"};
    printf("%s\n", longestCommonPrefix(strs, 3));
    return 0;
}