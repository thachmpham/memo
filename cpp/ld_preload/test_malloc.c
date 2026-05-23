#include <stdlib.h>

int main(int argc, char** argv)
{
    char *p = malloc(8);
    free(p);

    return 0;
}