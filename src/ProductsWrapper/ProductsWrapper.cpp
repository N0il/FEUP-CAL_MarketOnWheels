#include "ProductsWrapper.h"

using namespace std;

ProductsWrapper::ProductsWrapper(std::map<Product *, unsigned int> products) {
    this->products = move(products);
}

std::map<Product *, unsigned int> ProductsWrapper::getProducts() const {
    return this->products;
}

unsigned int ProductsWrapper::getNumOfProducts() {
    unsigned int diff = 0;
    for (auto &product : products) {
        diff += product.second;
    }
    return diff;
}

unsigned int ProductsWrapper::getNumOfDifProducts() {
    return products.size();
}

unsigned int ProductsWrapper::getQuantityOfProduct(Product *product) {
    if (products.find(product) == products.end()) throw ProductNotFound();
    return products.at(product);
}

void ProductsWrapper::addProduct(Product *product, unsigned int quantity) {
    if (products.find(product) != products.end()) {
        throw ProductAlreadyExists();
    } else {
        products.insert(pair<Product *, unsigned int>(product, quantity));
    }
}

void ProductsWrapper::removeProduct(Product *product) {
    if (products.find(product) == products.end()) throw ProductNotFound();
    else {
        products.erase(product);
    }
}

void ProductsWrapper::removeQuantityOfProduct(Product *product, unsigned int quantity) {
    if (products.find(product) == products.end()) throw ProductNotFound();

    int old_quantity = products.at(product);
    int new_quantity = old_quantity - quantity;

    products.erase(product);

    if (new_quantity > 0) products.insert(pair<Product *, unsigned int>(product, new_quantity));
    else throw InvalidQuantity();
}

void ProductsWrapper::addQuantityOfProduct(Product *product, unsigned int quantity) {
    if (products.find(product) == products.end()) throw ProductNotFound();

    int old_quantity = products.at(product);
    int new_quantity = old_quantity + quantity;

    products.erase(product);

    products.insert(pair<Product *, unsigned int>(product, new_quantity));
}

unsigned int ProductsWrapper::getSize() const {
    unsigned int size = 0;

    for (auto it = products.begin(); it != products.end(); it++) {

        size += (*it).second * (*it).first->getSize();
    }
    return size;
}

float ProductsWrapper::getPrice() const {
    float price = 0;
    for (auto &product : products) {
        price += (product.second * product.first->getPrice());
    }
    return price;
}

bool ProductsWrapper::searchProduct(std::string productName) const {
    for(auto it = products.begin(); it!=products.end(); it++){
        if((*it).first->getName() == productName) return true;
    }
    return false;
}
