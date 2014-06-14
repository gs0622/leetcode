#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void postfix2infix(char **in, int n)
{
    int i, j, stack[32], ans=0, first=1, isdigit;
    static char buf[128]={};
    if (!in) return;
    for (i=0,j=0;i<n;i++) {
        //printf("%d: %s: %d\n", i, in[i], j);
        switch (in[i][0]) {
        case '+': case '-': case '*': case '/':
            if (in[i][0]=='+') ans = stack[j-2] + stack[j-1];
            if (in[i][0]=='-') ans = stack[j-2] - stack[j-1];
            if (in[i][0]=='*') ans = stack[j-2] * stack[j-1];
            if (in[i][0]=='/') ans = stack[j-2] / stack[j-1];
            if (first) sprintf(buf, "(%d %s %d)", stack[j-2], in[i], stack[j-1]), first=0;
            else {
                char tmp[128];
                strcpy(tmp, buf);
                if (isdigit) sprintf(buf, "(%s %s %d)", tmp, in[i], stack[j-1]);
                else sprintf(buf, "(%d %s %s)", stack[j-2], in[i], tmp);
            }
            j-=2, stack[j++]=ans;
            isdigit=0;
            break;
        default:
            stack[j]=atoi(in[i]), j+=1;
            isdigit=1;
            break;
        }
    }
    printf("[");
    for (i=0;i<n;i++) printf("\"%s\",%s", in[i], (i<n-1)? " ": "]");
    printf(" -> %s -> %d\n", buf, ans);
}
int main(void)
{
    char *tokens1[5] = {"2", "1", "+", "3", "*" };
    char *tokens2[5] = {"4", "13", "5", "/", "+"};
    postfix2infix(tokens1, 5);
    postfix2infix(tokens2, 5);
    return 0;
}