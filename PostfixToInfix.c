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
static int vstack[16]={}, vtop=-1;
static char str[16][32], top=-1;
void p2i(char **in, int n)
{
    static char buf[128]={};
    if (n==0||!in) return;
    //printf("%d: %s\n", n, in[0]);
    switch (in[0][0]) {
    default:
        vstack[++vtop]=atoi(in[0]);
        p2i(in+1, n-1);
        break;
    case '+': case '-': case '*': case '/':
        {
            int ans, op1, op2, ch1, ch2;
            if (vtop<1) {
                fprintf(stderr, "not enough operands");
                exit(-1);
            }
            ch1 = (in-2)[0][0], ch2=(in-1)[0][0];
            //printf("%c %c -> ", ch1, ch2);
            op1=vstack[vtop-1], op2=vstack[vtop];
            if (in[0][0]=='+') ans = op1 + op2;
            if (in[0][0]=='-') ans = op1 - op2;
            if (in[0][0]=='*') ans = op1 * op2;
            if (in[0][0]=='/') ans = op1 / op2;
            if (ch1=='+'||ch1=='-'||ch1=='*'||ch1=='/') {
                //printf("ch1=%c\n", ch1);
                sprintf(str[top+1], "(%s %s %d)", str[top], in[0], op2), top+=1;
            } else if (ch2=='+'||ch2=='-'||ch2=='*'||ch2=='/') {
                //printf("ch2=%c\n", ch2);
                sprintf(str[top+1], "(%d %s %s)", op1, in[0], str[top]), top+=1;
            } else sprintf(str[++top], "(%d %s %d)", op1, in[0], op2);
            vtop-=2;
            //printf("%s\n", str[top]);
            vstack[++vtop] = ans;
            p2i(in+1, n-1);
            break;
        }
    }
    //printf("%d: %s vtop[%d]=%d str[%d]=%s\n", n, buf, vtop, vstack[vtop], top, str[top]);
}
int main(void)
{
    char *tokens1[5] = {"2", "1", "+", "3", "*" };
    char *tokens2[5] = {"4", "13", "5", "/", "+"};
    char *tokens3[7] = {"4", "13", "5", "/", "+", "1", "-"};
    //postfix2infix(tokens1, 5);
    //postfix2infix(tokens2, 5);
    p2i(tokens1, 5); printf("%s\n", str[top]), vtop=-1, top=-1;
    p2i(tokens2, 5); printf("%s\n", str[top]), vtop=-1, top=-1;
    p2i(tokens3, 7); printf("%s\n", str[top]), vtop=-1, top=-1;
    return 0;
}