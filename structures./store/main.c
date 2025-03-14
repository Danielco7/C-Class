#include <stdlib.h>
#include <stdio.h>
#include "store.h"

void main(){
    
    Store store;
    store.count = 0;
    store.categories = NULL; 
    
    loadDataFromFile(&store, "store.txt");
    

}
