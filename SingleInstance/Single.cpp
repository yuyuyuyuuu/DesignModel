#include <iostream>
#include <pthread.h>

class SingleInstanceLazy{

public:
    static SingleInstanceLazy* getSingleInstanceLazy(){
        if(instance == nullptr){
            pthread_mutex_lock(&mutex);
            if(instance == nullptr){
                instance = new SingleInstanceLazy();
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    };
    ~SingleInstanceLazy(){};
    static pthread_mutex_t mutex;
private:
    SingleInstanceLazy(){};
    SingleInstanceLazy(const SingleInstanceLazy&other){};
    SingleInstanceLazy& operator=(const SingleInstanceLazy&other){return *this;};
    static SingleInstanceLazy* instance;
};
SingleInstanceLazy* SingleInstanceLazy::instance = nullptr;
pthread_mutex_t SingleInstanceLazy::mutex;

class SingleInstanceHungry{
public:
    static SingleInstanceHungry* getSingleInstanceHungry(){
        static SingleInstanceHungry instance;
        return &instance;
    };
private:
    SingleInstanceHungry(){};
    SingleInstanceHungry(const SingleInstanceHungry&other){};
    SingleInstanceHungry& operator=(const SingleInstanceHungry&other){return *this;};
};

int main(){
    SingleInstanceLazy* instanceLazy = SingleInstanceLazy::getSingleInstanceLazy();
    delete instanceLazy;
    std::cout << "懒汉" << std::endl;
    SingleInstanceHungry* instanceHungry = SingleInstanceHungry::getSingleInstanceHungry();
    std::cout << "饿汉" << std::endl;  
    return 0;
}