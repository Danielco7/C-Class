#pragma once



#define LEN 50

typedef struct {
    char name[LEN];
    float price;
} Product;

typedef struct {
    char categoryName[LEN];
    Product* products;
    int count;
} Category;

typedef struct {
    Category* categories;
    int count;
} Store;


void loadDataFromFile(Store* store, const char* filename);
void addCategory(Store* store, const char* categoryName);
void addProduct(Store* store, const Product* product, const char* categoryName);
