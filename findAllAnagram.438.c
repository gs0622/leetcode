#include <stdio.h>
#include <string.h>
static int buf[20100];
unsigned int sliding_window(char *s, int len)
{
    int i, cntmap[26] = {};
    unsigned int hash = 0;
    while (*s && len--) {
        cntmap[*s-'a']++;
        s++;
    }
    for (i = 0; i < 26; i++)
        hash = hash * 33 + cntmap[i];
    return hash;
}
int* findAnagrams(char* s, char* p, int* returnSize)
{
    int i, j, ss = strlen(s), sp = strlen(p);
    unsigned int hash_p = sliding_window(p, sp); 
    for (i = 0, j = 0; i < ss - sp + 1; i++) {
        unsigned int hash_s = sliding_window(&s[i], sp);
        //printf("%d: %u: %u\n", i, hash_p, hash_s);
        if (hash_p == hash_s)
            buf[j++] = i;
    }
    *returnSize = j; 
    return buf;
}

void test(char *s, char *p)
{
    int i, ret;
    int *a = findAnagrams(s, p, &ret);
    printf("%d: ", ret);
    for (i = 0; i < ret; i++)
        printf("%d", a[i]);
    printf("\n");
}
int main(void)
{
    char s0[] = "cbaebabacd", p0[] = "abc";
    char s1[] = "abab", p1[] = "ab";
    char s2[] = "aa", p2[] = "bb";
    char s3[] = "af", p3[] = "be";
    char s4[] = "aecbabedce", p4[] = "a";
    char s5[] = "abaacbabc", p5[] = "abc";
    
    test(s0, p0);
    test(s1, p1);
    test(s2, p2);
    test(s3, p3);
    test(s4, p4);
    test(s5, p5);
    return 0;
}
