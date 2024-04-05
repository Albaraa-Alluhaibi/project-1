#include "../hpp/consumer.hpp"
#include "../hpp/buffer.hpp"




int main(int argc, char *argv[]) {

    int fd;
    char * shmpath;
    struct buffer *consBuffer;



    shmpath = argv[1];


    fd = shm_open(shmpath, O_RDWR, 0);



    ftruncate(fd, sizeof(*consBuffer));

    consBuffer = static_cast<buffer*>(mmap(NULL, sizeof(*consBuffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));

    for (int i = 4; i >= 0; --i) {

        sem_wait(&(consBuffer->full));
        sem_wait(&(consBuffer->mutex));

        int con_item;
        con_item = consBuffer->table[consBuffer->out];
        std::cout << "Consumed: " <<  con_item << std::endl;
        
        consBuffer->out = (consBuffer->out + 1) % TABLE_SIZE;


        sem_post(&(consBuffer->mutex));
        sem_post(&(consBuffer->empty));

        sleep(rand()%10);
    }


    shm_unlink(shmpath);


    return 0;

}