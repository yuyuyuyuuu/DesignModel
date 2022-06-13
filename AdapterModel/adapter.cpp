#include <iostream>
#include <list>
using namespace std;

//目标抽象类Robot（机器人接口）
class Robot{
public:
    virtual void eat() = 0;
    virtual void sleep() = 0;
}; 

//适配者类Douya（Douya类）
class Douya{
public:
    void eat(){
        cout << "豆芽吃饭" << endl;    
    }

    void sleep(){
        cout << "豆芽睡觉" << endl;    
    }
}; 

//适配器类DouyaAdapter（DouyaAdapter类） 
class DouyaAdapter : public Robot, public Douya{
public:
    void eat(){
        cout << "机器人模仿：" ;
        Douya::eat();
    }

    void sleep(){
        cout << "机器人模仿：" ;
        Douya::sleep(); 
    }
};

//客户端测试类Client 
int main(void){
    Robot *robot = (Robot*)new DouyaAdapter();
    robot->eat(); // 机器人模仿：豆芽吃饭
    robot->sleep(); // 机器人模仿：豆芽睡觉
    delete robot;
    return 0;
} 