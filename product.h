#include<stdio.h>

typedef struct Product {
	char name[20];
	char inform[200];
	char weight[10];
	int price;
	int delivery;
}Product;

int createProduct(Product* p); //add product
int readProduct(Product p); //show product
int updateProduct(Product* p); //update product
int deleteProduct(Product* p); //delete product
int findName(Product* p, char* name); // find by name
int findPrice(Product* p, int price); // find by price
int findDeliv(Product* p, int dlv); // find by delivery
int readFile(FILE* file, Product* p); //load file
int saveFile(FILE* file, Product* p); //save file
