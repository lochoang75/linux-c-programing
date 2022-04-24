#include <pthread.h>
#include <stdio.h>

/* Print x's stderr. The parameter is unused. Does not return. */
void *print_xs(void *unused)
{
    while (1) {
        fputc('x', stderr);
    }
    return NULL;
}

int main(int argc, char* argv[])
{
    pthread_t thread_id;
    /* Create a new thread. the new thread will run the print_xs
     * function. */
    pthread_create(&thread_id, NULL, &print_xs, NULL);
    /* Print o's continuously to stderr. */
    while (1) {
        fputc ('o', stderr);
    }

    return 0;
}
