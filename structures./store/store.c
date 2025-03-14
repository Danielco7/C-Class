#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "store.h"

void addCategory(Store* store, const char* categoryName) {
    
    store->categories = realloc(store->categories, (store->count + 1) * sizeof(Category));

    Category* newCategory = &store->categories[store->count];
    strcpy(newCategory->categoryName, categoryName);
    newCategory->count = 0;
    newCategory->products = NULL;
    store->count++;
}

void addProductToCategory(Store* store, const Product* product, const char* categoryName) {
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->categories[i].categoryName, categoryName) == 0) { 
            Category* category = &store->categories[i];

            if (category->count < MAX_PRODUCTS) { 
                category->products = realloc(category->products, (category->count + 1) * sizeof(Product));
                category->products[category->count] = *product;
                category->count++;
                return;
            }
        }
    }

    store->categories = realloc(store->categories, (store->count + 1) * sizeof(Category));

    Category* newCategory = &store->categories[store->count]; 
    strcpy(newCategory->categoryName, categoryName);
    newCategory->count = 1;
    newCategory->products = malloc(sizeof(Product)); 

    newCategory->products[0] = *product;
    store->count++;
}

void loadDataFromFile(Store* store, const char* filename){
    FILE *file=fopen(filename,"r");
    
    char categoryName[LEN] , countprodacts[10] , name[LEN] , price[10];
    while(fgets(categoryName,LEN,file)&&fgets(countprodacts,sizeof(countprodacts),file)){
    categoryName[strcspn(categoryName, "\n")] = '\0';
    countprodacts[strcspn(countprodacts, "\n")] = '\0';
    
    addCategory(store,categoryName);
    
    for(int i =0;i<atoi(countprodacts);i++){
        fgets(name,LEN,file);
        fgets(price,LEN,file);
        name[strcspn(name, "\n")] = '\0';
        price[strcspn(price, "\n")] = '\0';
        
        Product product;
        strncpy(product.name, name, LEN);
        product.price = atoi(price);
        
        addProduct(store, &product,categoryName);
    }
        
    }
    
    
    fclose(file);
}
