#include <iostream>
using namespace std;

extern int read4(char buf[]);

int read(char buf[], int n) {
    char tmp[4];
    bool eof = false;
    int i, chunk, left, read, readBytes = 0;
    while (!eof && readBytes < n) {
        chunk = read4(tmp);
        if (chunk < 4) eof = true;
        left = n - readBytes;
        read = std::min(chunk, left);
        for (i = 0; i < read; i++)
            buf[readBytes++] = tmp[i];
        readBytes += read;
    }
    return readBytes;
}
