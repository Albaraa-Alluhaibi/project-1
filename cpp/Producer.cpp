#include "../hpp/producer.hpp"
#include "../hpp/buffer.hpp"



int main(int argc, char *argv[]) {

    
    int fd;
    char * shmpath;
    struct buffer *prodBuffer;


    shmpath = argv[1];


    fd = shm_open(shmpath, O_CREAT | O_EXCL | O_RDWR, 0600);


    ftruncate(fd, sizeof(*prodBuffer));

    prodBuffer = static_cast<buffer*>(mmap(NULL, sizeof(*prodBuffer), PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0));


    sem_init(&(prodBuffer->mutex), 1,1);
    
    sem_init(&(prodBuffer->full), 1,0);
    
    sem_init(&(prodBuffer->empty), 1, TABLE_SIZE);

    prodBuffer->in, prodBuffer->out = 0;

    for(int i = 4; i >= 0; --i) {

        sem_wait(&prodBuffer->empty);
        sem_wait(&prodBuffer->mutex);

        int prod_val = rand();

        std::cout << "Produced: " << prod_val << std::endl;

        prodBuffer->table[prodBuffer->in] = prod_val;


        prodBuffer->in = (prodBuffer->in + 1) % TABLE_SIZE;


        sem_post(&prodBuffer->mutex);
        sem_post(&prodBuffer->full);

        sleep(rand()%10);
    }

    shm_unlink(shmpath);


    return 0;
}