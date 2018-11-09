#include <stdio.h>
#include <string.h>
#include <assert.h>
#define TINY6 56800235584ULL
#define TINY7 3521614606208ULL
unsigned long long djb2(char *str)
{
	int c;
	unsigned long long hash = 5381;
	while (c = *str++) {
		/* hash * 33 + c */
		hash = (hash << 5) + hash + c;
	}
	return hash;
}

char *strrev(char *str)
{
	char *p = str, *q = str, c;
	while (*q) ++q; 
	for (--q/*skip '\0'*/; q>p; --q, ++p) {
		c = *p, *p = *q, *q = c;
	}
	return str;
}

static const char map[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void id2url(unsigned long long id, char *str)
{
	while (id) {
		*str++ = map[id % 62];
		id /= 62;
	}
	*str = '\0';
}

unsigned long long url2id(char *str)
{
	int c;
	unsigned long long id = 0;
	while (c = *str++) {
		unsigned long long digit = 0;
		if (c >= '0' && c <= '9') digit = c - '0'; 
		else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10; 
		else if (c >= 'A' && c <= 'Z') digit = c - 'A' + 36;
		else assert(0);
		id = id * 62 + digit;
	}
	return id;
}

unsigned long long url2id2(char *str) /*version-2*/
{
	int c;
	unsigned long long id = 0;
	while (c = *str++) {
		unsigned long long digit = 0;
		if (c >= '0' && c <= '9') digit = c - '0'; 
		else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10; 
		else if (c >= 'A' && c <= 'Z') digit = c - 'A' + 36;
		else assert(0);
		id = id * 62 + digit;
	}
	return id;
}

int main(int argc, char **argv)
{
	if (argc < 2) return 0;
	char url[10];
	unsigned long long id;
	id = djb2(argv[1]);
	printf("%llu\n", id);
	id2url(id % TINY6, url);
	printf("6: %s\n", url);
	//printf("6: %s\n", strrev(url));
	printf("6: %llu\n", url2id(url));
	id2url(id % TINY7, url);
	printf("7: %s\n", url);
	//printf("7: %s\n", strrev(url));
	printf("7: %llu\n", url2id(url));
}

