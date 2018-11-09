#include <stdio.h>
#include <string.h>
int isAnagram(char *s, char *t)
{
    int ss = strlen(s), st = strlen(t);
    if (ss != st) return 0;
    else {
        int i, cs[26] = {}, ct[26] = {};
        for (i = 0; i < ss; i++) {
            cs[s[i]-'a']++;
            ct[t[i]-'a']++;
        }
        for (i = 0; i < 26; i++)
            if (cs[i] != ct[i]) return 0;
    }
    return 1;
}

void test(char *s, char *t)
{
    printf("%s: %s: %s\n", s, t, isAnagram(s, t)? "true": "false");
}
int main(void)
{
    char s0[] = "anagram", t0[] = "nagaram";
    test(s0, t0);
    return 0;
}
