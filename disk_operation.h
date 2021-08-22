#ifndef DISK_OPERATION_H
#define DISK_OPERATION_H

#include <stdio.h>
#include <stdlib.h>

#define system_storage 100*1024*1024
#define block_size 1024
#define block_count system_storage/block_size
#define dir_table_max_size 100

struct dir_unit{
    char file_name[100];
    char type; //0 for dir, 1 for file
    int start_block;
};

struct dir_table{
    int unit_amount;
    dir_unit dirs[dir_table_max_size];
};

struct fcb{
    int block_number;
    int file_size;
    int data_size;
    int read_ptr;
    int link;
};

void init_system();

int get_block(int size);

char* get_block_addr(int block_number);

int get_addr_block(char* addr);

int release_block(int block_numebr, int size);

void exit_system();

#endif // DISK_OPERATION_H
