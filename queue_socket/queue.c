#include "queue.h"

uint16_t next_index_circle(uint16_t index, uint16_t min_ind, uint16_t max_ind){
    if(index+1 <= max_ind){
        return index+1;
    }else{
        return min_ind;
    }
}

type_virt_mem* init(uint8_t amountVirtMems, uint16_t sizeVirtMem){
    type_virt_mem *res = (type_virt_mem*)malloc(amountVirtMems * sizeof(type_virt_mem));
    for(uint8_t i = 0; i < amountVirtMems; i++){
        res[i].isLock = 0;
        res[i].sizeFull = 0;
        res[i].maxSize = sizeVirtMem;
        res[i].index_read = 0; 
        res[i].index_write = 0;
        res[i].mem_Array = (memType*)malloc(sizeVirtMem * sizeof(memType));
    }
    return res;
}

uint16_t queue_put_data(memType *data, uint16_t size, type_virt_mem* mem_struct){
    mem_struct->isLock = 1;
    uint16_t i;
    for(i = 0; i < size; i++){
        if(mem_struct->sizeFull == mem_struct->maxSize){
            break;
        }
        mem_struct->sizeFull++;
        mem_struct->mem_Array[mem_struct->index_write] = data[i];
        mem_struct->index_write = next_index_circle(mem_struct->index_write, 0, mem_struct->maxSize-1);
    }
    mem_struct->isLock = 0;
    return i;
}

uint16_t queue_get_data(memType *data, uint16_t size, type_virt_mem* mem_struct){
    mem_struct->isLock = 1;
    uint16_t i;
    for(i = 0; i < size; i++){
        if(mem_struct->sizeFull == 0){
            break;
        }
        mem_struct->sizeFull--;
        data[i] = mem_struct->mem_Array[mem_struct->index_read];
        mem_struct->index_read = next_index_circle(mem_struct->index_read, 0, mem_struct->maxSize-1);
    }
    mem_struct->isLock = 0;
    return i;
}