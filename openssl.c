/* gcc -g -lcrypto
 */
#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    int i;
    unsigned char ibuf[] = "compute sha1";
    unsigned char obuf[32];

    SHA1(ibuf, strlen(ibuf), obuf);
    for (i = 0; i < 20; i++) {
        printf("%02x", obuf[i]);
    }
    printf("\n");

    SHA256(ibuf, strlen(ibuf), obuf);
    for (i = 0; i < 32; i++) {
        printf("%02x", obuf[i]);
    }
    printf("\n");

    return 0;
}
