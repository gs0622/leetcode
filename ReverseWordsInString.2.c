#include <stdio.h>
static char *strspace(char *s) /*input: string*/
{
    if (!s) return NULL;
    while (*s!='\0' && *s!=' ') ++s;
    return (*s=='\0')? NULL: s;
}
static void strrev(char *s, char *e) /*input: start & end*/
{
    if (!s || !e) return;
    while (s<e) {
        if (*s!=*e) *s^=*e, *e^=*s, *s^=*e;
        ++s, --e;
    }
}
static char *strend(char *s)
{
    if (!s) return NULL;
    while (*s) ++s;
    return s-1;
}
static void wordrev(char *s) /*input: string*/
{
    int i;
    char *p = s;
    if (!s) return;
    for (i=0;*p!='\0';++p,++i);
    --i; /*skip '\0'*/
    strrev(s, s+i);
    while (NULL!=(p=strspace(s))) strrev(s, p-1), s = p+1;
    strrev(s, strend(s));
}
int main(void)
{
    char str[128];
    while (gets(str)) {
        printf("before: %s\n", str);
        wordrev(str);
        printf("after : %s\n", str);
    };
    return 0;
}

