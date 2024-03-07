#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5
void *thread_function(void *thread_id) {
    int tid = *(int *)thread_id;
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
        if (result != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads have completed\n");
    return 0;
}
