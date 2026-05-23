#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

static void* (*real_malloc)(size_t) = NULL;

void* malloc(size_t size)
{
    if(real_malloc == NULL)
    {
        real_malloc = dlsym(RTLD_NEXT, "malloc");

        if (NULL == real_malloc)
        {
            fprintf(stderr, "dlsym failed: %s\n", dlerror());
        }
    }

    fprintf(stderr, "malloc(%ld) = ", size);
    void *p = real_malloc(size);
    fprintf(stderr, "%p\n", p);
    return p;
}