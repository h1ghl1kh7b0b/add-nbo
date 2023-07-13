#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t transfer(char *filename){
    FILE* fp = fopen(filename, "rb");
    uint8_t buf[4];
    fread(buf, 4, 1, fp);
    uint32_t n = *(uint32_t *)buf;
    fclose(fp);
    return ntohl(n);
}

int main(int argc, char *argv[]) {
    uint32_t a = transfer(argv[1]);
    uint32_t b = transfer(argv[2]);
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,a+b,a+b);
}