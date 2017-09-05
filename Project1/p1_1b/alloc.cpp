#include "alloc.h"
#include <stdlib.h>

int* alloc(int size){
    int* array;
    array=new int [size];

    return array;
}
