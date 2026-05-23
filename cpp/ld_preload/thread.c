#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>
#include <pthread.h>


static int (*real_pthread_mutex_lock)(pthread_mutex_t *mutex) = NULL;

int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    if(real_pthread_mutex_lock == NULL)
    {
        real_pthread_mutex_lock = dlsym(RTLD_NEXT, "pthread_mutex_lock");

        if (NULL == real_pthread_mutex_lock)
        {
            fprintf(stderr, "dlsym failed: %s\n", dlerror());
        }
    }

    fprintf(stderr, "pthread_mutex_lock(%p) = ", mutex);
    int n = real_pthread_mutex_lock(mutex);
    fprintf(stderr, "%d\n", n);
    return n;
}