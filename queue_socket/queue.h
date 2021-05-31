#ifndef QUEUE_H
    #define QUEUE_H

    #include <stdlib.h>
    #include <stdint.h>

    typedef uint8_t memType;

    typedef struct virtual_memory{
        uint8_t isLock;         //state of lock access;
        uint16_t sizeFull;      //
        uint16_t maxSize;
        uint16_t index_write;
        uint16_t index_read;
        memType *mem_Array;
    }type_virt_mem;

    typedef struct virtual_memory_array{
        uint8_t size;
        type_virt_mem *v_mem_arr;
    }type_v_mem_array;

    uint16_t next_index_circle(uint16_t index, uint16_t min_ind, uint16_t max_ind);
    type_virt_mem* init(uint8_t amountVirtMems, uint16_t sizeVirtMem);
    uint16_t queue_put_data(memType *data, uint16_t size, type_virt_mem* mem_struct);
    uint16_t queue_get_data(memType *data, uint16_t size, type_virt_mem* mem_struct);


#endif