#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char *s, char *p) {
    int i = 0, j = 0;
    char tmp[100] = "\0";
    char tmp1[100] = "\0";
    if (strlen(s) == 0) {
        if (strlen(p) % 2 != 0) {
            return false;
        }
        for (int k = 1; k < strlen(p); k += 2) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }
    if (p[j + 1] == '*') {
        if (s[i] == p[j] || p[j] == '.') {
            return isMatch(strcpy(tmp, s+1), p) || isMatch(s, strcpy(tmp, p+2));
        } else {
            return isMatch(s, strcpy(tmp, p+2));
        }
    } else {
        if (s[i] == p[j] || p[j] == '.') {
            return isMatch(strcpy(tmp, s+1), strcpy(tmp1, p+1));
        } else {
            return false;
        }
    }
    return true;
}


int main() {
    char *s = "a";
    char *p = "aa";
    printf("%d\n", isMatch(s, p));
    return 0;
}