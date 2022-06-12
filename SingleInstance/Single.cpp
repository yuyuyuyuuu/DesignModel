#include <iostream>
#include <pthread.h>

// 懒汉模式
class SingleInstanceLazy{
public:
    static SingleInstanceLazy* GetSingleInstanceLazy(){
        if(instance == nullptr){
            pthread_mutex_lock(&mutex);
            if(instance == nullptr){
                instance = new SingleInstanceLazy();
            }
            pthread_mutex_unlock(&mutex);
        }
        return instance;
    }
    ~SingleInstanceLazy(){};
    static pthread_mutex_t mutex;
private:
    SingleInstanceLazy(){};
    SingleInstanceLazy(const SingleInstanceLazy& other){};
    SingleInstanceLazy& operator=(const SingleInstanceLazy& other){return *this; };
    static SingleInstanceLazy* instance;
};
// 懒汉--静态变量需要定义
SingleInstanceLazy* SingleInstanceLazy::instance = nullptr;
pthread_mutex_t SingleInstanceLazy::mutex;

// 饿汉模式
class SingleInstanceHungry{
public:
    static SingleInstanceHungry* GetSingleInstanceHungry(){
        static SingleInstanceHungry instance;
        return &instance;
    }
    ~SingleInstanceHungry(){};
private:
    SingleInstanceHungry(){};
    SingleInstanceHungry(const SingleInstanceHungry& other){};
    SingleInstanceHungry operator=(const SingleInstanceHungry&other){return *this; };
};



int main(){
    // 懒汉
    SingleInstanceLazy* lazyInstance = SingleInstanceLazy::GetSingleInstanceLazy();
    std::cout << "懒汉创建成功" << std::endl;
    delete lazyInstance;
    // 饿汉
    SingleInstanceHungry* hungryInstance = SingleInstanceHungry::GetSingleInstanceHungry();
    std::cout << "饿汉创建成功" << std::endl;
    return 0;
}