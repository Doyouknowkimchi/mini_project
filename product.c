#include <stdio.h>
#include <stdlib.h>
#include "product.h"

int createProduct(Product* p) {

	printf("input name : ");
	fgets(p->name, sizeof(p->name), stdin);
	printf("\ninput inform : ");
	scanf("%s", &p->inform);
	printf("\ninput weight : ");
	scanf("%s", &p->weight);
	printf("\ninput price : ");
	scanf("%d", &p->price);
	printf("\ninput delivery : ");
	scanf("%d", &p->delivery);

	return 0;
}

int deleteProduct(Product* p) {
	strcpy(p->name, "empty");
	strcpy(p->inform, "empty");
	strcpy(p->weight, "empty");
	p->price = 0;
	p->delivery = 0;
}

int findName(Product* p, char* name) {
	//for, index 붙일 수도 있다
	printf("Search results for names\n");

	if (0 == strcmp(p->name, name)) {
		readProduct(*p);
	}
	else printf("No result");
}

int findPrice(Product* p, int price) {
	printf("Search results for price\n");

	if (p->price == price) {
		readProduct(*p);
	}
	else printf("No result");
}

int findDeliv(Product* p, int dlv) {
	printf("Search results for delivery\n");

	if (p->price == dlv) {
		readProduct(*p);
	}
	else printf("No result");
}

int readProduct(Product p) {
	printf("name : %s\ninform : %s\nweight : %s\nprice : %d\n", p.name, p.inform, p.weight, p.price);
	if (p.delivery == 1)
		printf("delivery : early-morning delivery\n\n");
	else
		printf("delivery : normal delivery\n\n");

	return 0;
}

int updateProduct(Product* p) {

	printf("input name : ");
	fgets(p->name, sizeof(p->name), stdin);
	printf("\ninput inform : ");
	scanf("%s", &p->inform);
	printf("\ninput name : ");
	scanf("%s", &p->weight);
	printf("\ninput price : ");
	scanf("%d", &p->price);
	printf("\ninput delivery : ");
	scanf("%d", &p->delivery);

	return 0;
}


int readFile(FILE* file, Product* p) {
	FILE* fp;
	char buf[1000];

	fp = fopen("input.txt", "r");

	if (!fp) {
		printf("파일이 없습니다");
		return 1;
	}
	while (fgets(buf, 1000, fp) != NULL) {
		//fread();
	} // name이나 inform 잘릴 것 같다...
	fclose(fp);
	return 0;
}

int saveFile(FILE* file, Product* p) {
	FILE* fp;
	int x;

	fp = fopen("output.txt", "w");

	if (!fp)
		return 1;

	for (x = 1; x <= 10; x++)
		fscanf(fp, "%s %s %s %d %d", p->name, p->inform, p->weight, &p->price, &p->delivery);

	fclose(fp);
	return  0;
}

int selectMenu() {
	int menu;
	printf("\n*** PizzaYaho ***\n");
	printf("1. 추가\n");
	printf("2. 조회\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 이름 검색\n");
	printf("6. 가격 검색\n");
	printf("0. 배송 검색\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);

	getchar();
	return menu;
}

int main(void) {
	Product temp;
	Product* temp_p = &temp;
	FILE* file = NULL;

	int select = 0;

	while(1) {

		select = selectMenu();

		if(select == 0) break; //end
		else if(select == 1) { //read
			createProduct(temp_p); //add product
		}
		else if (select == 2) {
			readProduct(temp); //show product
		}
		else if (select == 3) {
			updateProduct(temp_p); //update product
		}
		else if (select == 4) {
			deleteProduct(temp_p); //delete product
		}
		else if (select == 5) {
			char name[20];
			gets(name);

			findName(temp_p, name); // find by name
		}
		else if (select == 6) {
			int price;
			scanf("%d", &price);

			findPrice(temp_p, price); // find by price
		}
		else if (select == 7) {
			int dev;
			scanf("%d", &dev);

			findDeliv(temp_p, dev); // find by del
		}
		else if (select == 8) {
			//readFile(file); //load file
		}
		else if (select == 9) {
			//saveFile(file); //save file
		}
	}

	return 0;
}

