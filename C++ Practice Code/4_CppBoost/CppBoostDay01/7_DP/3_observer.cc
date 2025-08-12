#include <iostream>
#include <string>
#include <list>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::unique_ptr;

class Observer
{
public:
    virtual void update(int status) = 0;
    virtual ~Observer() {}
};

class ConcreteObserverA
: public Observer
{
public:
    ConcreteObserverA(const string &name)
    : _name(name)
    {

    }

    virtual void update(int status) override
    {
        cout << "ConcreteObserverA name = " << _name 
             << " , status = " << status << endl; 
    }

private:
    string _name;

};

class ConcreteObserverB
: public Observer
{
public:
    ConcreteObserverB(const string &name)
    : _name(name)
    {

    }

    virtual void update(int status) override
    {
        cout << "ConcreteObserverB name = " << _name 
             << " , status = " << status << endl; 
    }

private:
    string _name;

};

class Subject
{
public:
    //添加
    virtual void attach(Observer *pobserver ) = 0;
    //删除
    virtual void detach(Observer *pobserver ) = 0;
    //通知
    virtual void notify() = 0;

    virtual ~Subject() {}
};

class ConcreteSubject
: public Subject
{
public:
    //添加
    virtual void attach(Observer *pobserver ) override
    {
        if(pobserver)
        {
            _obList.push_back(pobserver);//添加到list中存起来
        }
    }

    //删除
    virtual void detach(Observer *pobserver ) override
    {
        if(pobserver)
        {
            _obList.remove(pobserver);//从list中删除
        }
    }

    //添加
    virtual void notify() override
    {
        for(auto &pob : _obList)
        {
            //满足动态多态被激活的五个条件
            pob->update(_status);//发通知给每一个观察者
        }
    }

    void setStatus(int status)
    {
        _status = status;
    }

    int getStatus()
    {
        return _status;
    }

private:
    list<Observer *> _obList;//存放观察者的数据结构
    int _status;//状态

};

void test()
{
    //创建了两个具体的观察者对象
    unique_ptr<Observer> poa(new ConcreteObserverA("lili"));
    unique_ptr<Observer> pob(new ConcreteObserverB("lucy"));

    //创建主题的对象
    unique_ptr<ConcreteSubject> psub(new ConcreteSubject());

    //将两个观察者添加到主题中
    psub->attach(poa.get());
    psub->attach(pob.get());

    //设置主题的状态
    psub->setStatus(10);

    //当主题的状态发生变更之后，会通知所有的观察者
    psub->notify();

    cout << endl << endl;
    //观察者B不想关注主题了，那么就会取消关注
    psub->detach(pob.get());

    //如果此时主题的状态发生变更
    psub->setStatus(20);
    
    //当主题的状态发生变更之后，会通知所有的观察者
    psub->notify();

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

