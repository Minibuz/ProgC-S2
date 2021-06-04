#include <stdio.h>

void swap_mem(void* z1, void* z2, size_t size);

int main() {
    double a = 1457865;
    double b = 485127;

    printf("a:%f, b:%f\n",a,b);

    swap_mem(&a,&b,sizeof(double));

    printf("a:%f, b:%f\n",a,b);
    return 0;
}

void swap_mem(void* z1, void* z2, size_t size) {
    unsigned char* a;
    unsigned char* b;
    unsigned char* size_ = (unsigned char*)z1 + size;
    for( a=z1, b=z2; a<size_ ;a++, b++) {
        unsigned char t = *a;
        *a = *b;
        *b = t;
    }
}