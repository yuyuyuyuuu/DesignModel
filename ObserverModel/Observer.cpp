#include <iostream>
#include <list>

class Observer{
public:
    virtual void update(int) = 0;
};

class Subject{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
};

class ConcreteObserve1 : public Observer{
public:
    ConcreteObserve1(Subject* pSubject) : m_subject(pSubject) {};
    void update(int val){
        std::cout << "ConcreteOberver1 get the updated value: " << val << std::endl;
    }
private:
    Subject* m_subject;
};

class ConcreteObserve2 : public Observer{
public:
    ConcreteObserve2(Subject* pSubject) : m_subject(pSubject) {};
    void update(int val){
        std::cout << "ConcreteOberver2 get the updated value: " << val << std::endl;
    }
private:
    Subject* m_subject;
};

class ConcreteSubject : public Subject{
public:
    void Attach(Observer* observer){
        m_observers.push_back(observer);
    }
    void Detach(Observer* observer){
        m_observers.remove(observer);
    }
    void Notify(){
        std::list<Observer*>::iterator it = m_observers.begin();
        while(it != m_observers.end()){
            (*it)->update(m_state);
            ++it;
        }
    }
    void setState(int val){
        m_state = val;
    }

private:
    std::list<Observer*> m_observers;
    int m_state;
};

int main(){
    ConcreteSubject* subject = new ConcreteSubject();
    ConcreteObserve1* observer1 = new ConcreteObserve1(subject);
    ConcreteObserve2* observer2 = new ConcreteObserve2(subject);

    subject->setState(2);
    subject->Attach(observer1);
    subject->Attach(observer2);
    subject->Notify();
    subject->Detach(observer1);
    subject->setState(3);
    subject->Notify();

    delete observer1;
    delete observer2;
    delete subject;

    return 0;
}