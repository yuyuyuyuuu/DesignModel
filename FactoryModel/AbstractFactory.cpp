#include <iostream>

class Product{
public:
    Product(){};
    virtual void show() = 0;
    virtual ~Product(){};
};

class ProductA : public Product{
public:
    ProductA(){};
    void show(){
        std::cout << "This is Product A!" << std::endl;
    }
    ~ProductA(){};
};

class ProductB : public Product{
public:
    ProductB(){};
    void show(){
        std::cout << "This is Product B!" << std::endl;
    }
    ~ProductB(){};
};

class Factory
{
public:
    Factory(){};
    virtual Product* createProduct() = 0;
    virtual ~Factory(){};
};

class Factory_A : public Factory{
public:
    Factory_A(){};
    Product* createProduct(){
        return (new ProductA());
    }
    ~Factory_A(){};
};

class Factory_B : public Factory{
public:
    Factory_B(){};
    Product* createProduct(){
        return (new ProductB());
    }
    ~Factory_B(){};
};

int main(){
    Product* product = nullptr;
    auto myFacatoryA = new Factory_A();
    product = myFacatoryA->createProduct();
    product->show();
    delete product;

    auto myFacatoryB = new Factory_B();
    product = myFacatoryB->createProduct();
    product->show();
    delete product;

    return 0;
}

