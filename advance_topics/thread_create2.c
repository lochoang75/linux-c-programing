#include <pthread.h>
#include <stdio.h>

/* Parameters to print_function. */
struct char_print_params 
{
    /* The chacracter to print. */
    char character;
    /* The number of times to print it. */
    int count;
};

/* Prints a number of characters to stderr, as given by PARAMETERS,
 * which is a pointer to a struct char_print_params. */
void* char_print(void *parameters)
{
    /* Cast the cookie pointer to the right type.*/
    struct char_print_params *p = (struct char_print_params*) parameters;
    int i;

    for (i = 0; i < p->count; ++i) {
        fputc(p->character, stderr);
    }
    return NULL;
}

/* The main program */
int main(int argc, char *argv[])
{
    pthread_t thread1_id;
    pthread_t thread2_id;
    struct char_print_params thread1_args;
    struct char_print_params thread2_args;
    
    /* Create a new thread to print 30,000 'x's. */
    thread1_args.character = 'x';
    thread1_args.count = 30000;
    pthread_create(&thread1_id, NULL, &char_print, &thread1_args);

    /* Create a new thread to print 20,000 'o's. */
    thread2_args.character = 'o';
    thread2_args.count = 20000;
    pthread_create(&thread2_id, NULL, &char_print, &thread2_args);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    return 0;
}
