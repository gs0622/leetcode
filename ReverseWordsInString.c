#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[128], *delim=" ", tmp[128][64];
    while (gets(str)) {
        char *token, ans[128]={};
        int i=0, j;
        token = strtok(str, delim);
        if (token) strcpy(&tmp[i++][0], token);
        while (token) {
            token = strtok(NULL, delim);
            if (token) strcpy(&tmp[i++][0], token);
        }
        for (j=i-1; j>=0; j--) {
            strcat(ans, &tmp[j][0]);
            if (j>0) strcat(ans, " ");
        }
        printf("%s\n", ans);
    };
    return 0;
}