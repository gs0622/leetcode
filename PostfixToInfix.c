#include <stdio.h>
#include <stdlib.h>
void postfix2infix(char **in, int n)
{
    int i, j, stack[32], ans=0, first=1;
    static char buf[128]={};
    if (!in) return;
    for (i=0,j=0;i<n;i++) {
        //printf("%d: %s\n", i, in[i]);
        switch (in[i][0]) {
        case '+': case '-': case '*': case '/':
            if (first) {
                if (in[i][0]=='+') ans = stack[j-2] + stack[j-1];
                if (in[i][0]=='-') ans = stack[j-2] - stack[j-1];
                if (in[i][0]=='*') ans = stack[j-2] * stack[j-1];
                if (in[i][0]=='/') ans = stack[j-2] / stack[j-1];
                sprintf(buf, "(%d %s %d)", stack[j-2], in[i], stack[j-1]);
                j-=2, first=0;
            }
            else {
                if (in[i][0]=='+') ans += stack[j-1];
                if (in[i][0]=='-') ans -= stack[j-1];
                if (in[i][0]=='*') ans *= stack[j-1];
                if (in[i][0]=='/') ans /= stack[j-1];
                sprintf(buf, "(%s %s %d)", buf, in[i], stack[j-1]), j-=1;
            }
        default:
            stack[j]=atoi(in[i]), j+=1;
            break;
        }
    }
    printf("[");
    for (i=0;i<n;i++) printf("\"%s\",%s", in[i], (i<n-1)? " ": "]");
    printf(" -> %s -> %d\n", buf, ans);
}
int main(void)
{
    //char *tokens[5] = {"2", "1", "+", "3", "*" };
    char *tokens[5] = {"4", "13", "5", "/", "+"};
    postfix2infix(tokens, 5);
    return 0;
}