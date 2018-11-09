#include <iostream>
using namespace std;

class Reader4 {
public:
    int read4(char buf[]) {
        // TBD
    }
};
class Reader: public Reader4 {
    char tmp[4];
    int offset = 0, chunk = 0; 
public:
int read(char buf[], int n) {
    char tmp[4];
    bool eof = false;
    int i, left, read, readBytes = 0;
    while (!eof && readBytes < n) {
        if (chunk == 0) {
            chunk = read4(tmp);
            if (chunk < 4) eof = true;
        }
        left = n - readBytes; // buffer left
        read = std::min(chunk, left); // this read

        for (i = offset; i < read; i++)
            buf[readBytes++] = tmp[i];

        offset = (offset + read) % 4; // tmp (chunk) left in offset 
        chunk -= read; // tmp (chunk) left in bytes
        readBytes += read;
    }
    return readBytes;
}
};
