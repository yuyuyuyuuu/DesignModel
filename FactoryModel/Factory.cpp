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
    Product* getProuct(const std::string str){
        if(str == "ProductA"){
            return new ProductA();
        }
        else if(str == "ProductB"){
            return new ProductB();
        }
        return nullptr;
    };
    ~Factory(){};
};

int main(){
    Factory* fac = new Factory;
    Product* proA = fac->getProuct("ProductA");
    proA->show();
    delete proA;
    Product* proB = fac->getProuct("ProductB");
    proB->show();
    delete proB;
    delete fac;
    return 0;
}

