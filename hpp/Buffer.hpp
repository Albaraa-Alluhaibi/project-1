#ifndef BUFFER_HPP
#define  BUFFER_HPP
    #include <stdlib.h>
    #include <sys/shm.h>
    #include <sys/ipc.h>
    #include <semaphore.h>

   
    #define TABLE_SIZE 2


 
    struct buffer {

        int table[TABLE_SIZE];

        int in;
        int out;

        sem_t mutex;
        sem_t empty;
        sem_t full;

    };


#endif