#include <header.h>

int main(){


    FILE *file = popen("ls", "r");

    char buf[100]={0};

    fread(buf, 1, sizeof(buf), file);

    printf("buf: %s \n", buf);

    return 0;
}

