# project-1

# Producer-Consumer Problem

This program simulates the producer-consumer problem using threads, semaphores, and shared memory in C++ on Linux/Unix systems.

## Overview

In the producer-consumer problem, there are two types of threads: producers and consumers. Producers generate items and place them into a shared buffer, while consumers retrieve items from the buffer and process them. The buffer has limited capacity, and synchronization mechanisms such as semaphores are used to ensure that producers and consumers operate correctly without conflicts.

## Requirements

- Linux/Unix environment
- GCC compiler
- POSIX Threads (pthread) library
- POSIX Semaphores (semaphore.h)
- Shared memory (sys/mman.h, fcntl.h)

## Usage

### Compilation

To compile the producer and consumer programs, use the following commands:

############

-Make consumer

cmpiles consumer by using : g++ "./cpp/consumer.cpp" -pthread -lrt -o ./output/consumer

###############

-Make producer

compile producer by using : g++ "./cpp/producer.cpp" -pthread -lrt -o ./output/producer

############

Then to show output bu using this command: ./output/producer shmfile & ./output/consumer shmfile
 
this will output the result in the terminal  
