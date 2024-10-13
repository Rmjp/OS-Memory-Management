#include <stdio.h>
#include <stdlib.h>

char g1;
char g2;
char g3;


void f1(){
    char local;
    printf("stack local: %p\n", &local);
    return;
}

void f2(){
    char local;
    printf("stack local: %p\n", &local);
    f1();
    return;
}

void f3(){
    char local;
    printf("stack local: %p\n", &local);
    f2();
    return;
}

int main() {
    printf("global g1: %p\n", &g1);
    printf("global g2: %p\n", &g2);
    printf("global g3: %p\n", &g3);

    char *p1 = (char *)malloc(16);
    char *p2 = (char *)malloc(16);
    char *p3 = (char *)malloc(16);

    printf("malloc p1: %p\n", p1);
    printf("malloc p2: %p\n", p2);
    printf("malloc p3: %p\n", p3);

    f3();
    return 0;
}