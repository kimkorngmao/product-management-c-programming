#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
};

struct Product products[MAX_PRODUCTS];
int productCount = 0;

void createProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Cannot add more products. Database is full.\n");
        return;
    }

    struct Product newProduct;
    newProduct.id = productCount + 1;

    printf("Enter product name: ");
    scanf("%s", newProduct.name);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[productCount++] = newProduct;

    printf("Product added successfully.\n");
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products to display.\n");
        return;
    }

    printf("ID\tName\tPrice\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

void updateProduct() {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Enter new name: ");
            scanf("%s", products[i].name);

            printf("Enter new price: ");
            scanf("%f", &products[i].price);

            printf("Product updated successfully.\n");
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

void deleteProduct() {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product deleted successfully.\n");
            return;
        }
    }

    printf("Product with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\nProduct Management System\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
