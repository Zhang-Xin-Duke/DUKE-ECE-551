#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

using std::cout;
using std::endl;
using std::list;
using std::unordered_map;
using std::pair;

class LRU
{
public:
    LRU(int sz)
    : _size(sz)
    {

    }

    void put(int key, int value)
    {
        //查看key值在unordered_map中是否存在
        auto it = _um.find(key);
        if(it != _um.end())
        {
            it->second->second = value;//更新value
            _nodes.splice(_nodes.begin(), _nodes, it->second);
        }
        else
        {
            //如果链表中的元素是满的
            if(_size == (int)_nodes.size())
            {
                //获取要删除的节点
                auto deleteNode = _nodes.back();
                //将list中最后一个元素删除
                _nodes.pop_back();
                //同时在unordered_map也删除
                _um.erase(deleteNode.first);

            }
            _nodes.push_front({key, value});
            _um[key] = _nodes.begin();
        }
    }

    int get(int key)
    {
        //查看key值在unordered_map中是否存在
        auto it = _um.find(key);
        if(it == _um.end())
        {
            return -1;
        }
        else
        {
            _nodes.splice(_nodes.begin(), _nodes, it->second);
            return it->second->second; 
        }
    }

    void print() const
    {
        for(auto &elem : _nodes)
        {
            cout << "(" << elem.first
                 << ", " << elem.second
                 << ")  ";
        }
    }
private:
    int _size;//存放的元素上限
    list<pair<int, int>> _nodes;//存放每一个节点
    unordered_map<int, list<pair<int, int>>::iterator> _um;//存放key与key在list中的位置
};

void test()
{
    LRU lru(4);

    lru.put(1, 10);
    lru.print();
    cout <<endl;

    lru.put(2, 20);
    lru.print();
    cout <<endl;

    lru.put(3, 30);
    lru.print();
    cout <<endl;

    cout << "lru.get(2) = " << lru.get(2) <<endl;
    lru.print();
    cout <<endl;

    lru.put(4, 40);
    lru.print();
    cout <<endl;

    lru.put(3, 33);
    lru.print();
    cout <<endl;

    lru.put(5, 50);
    lru.print();
    cout <<endl;

    cout << "lru.get(1) = " << lru.get(1) <<endl;
    lru.print();
    cout <<endl;

}

int main(int argc, char *argv[])
{
    test();
    return 0;
}

