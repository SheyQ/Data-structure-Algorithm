#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct node {
    string key;
    int fre;
    int value;
};

class LFU {
   public:
    LFU(int size) {
        cap = size;
        minfre = 100;
    };
    node* Get(string key) {
        if (vnode.find(key) == vnode.end()) {
            return nullptr;
        }
        auto i = vnode[key];
        auto fre = (*i)->fre;
        auto value = (*i)->value;
        fnode[fre].erase(i);
        delete *i;
        if (fnode[fre].size() == 0 && minfre == fre) {
            minfre++;
        }
        fre++;
        node* newnode = new node{key, fre, value};
        fnode[fre].push_front(newnode);
        return newnode;
    };
    node* Set(string key, int value) {
        if (vnode.size() < cap) {
            node* newnode = new node{key, 1, value};
            fnode[1].push_front(newnode);
            vnode.insert({key, list<node*>::iterator(fnode[1].begin())});
            if (minfre > 1) {
                minfre = 1;
            }
            return nullptr;
        }
        auto i = fnode[minfre].rbegin();
        vnode.erase((*i)->key);
        fnode[minfre].pop_back();
        node* newnode = new node{key, 1, value};
        fnode[1].push_front(newnode);
        vnode.insert({key, list<node*>::iterator(fnode[1].begin())});
        if (minfre > 1) {
            minfre = 1;
        }
        return *i;
    };

    void Print() {
        cout << "print begin" << endl;
        for (auto i : fnode) {
            cout << "fre:" << i.first << endl;
            for (auto j : i.second) {
                cout << j->value << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

   private:
    unordered_map<string, list<node*>::iterator> vnode;
    unordered_map<int, list<node*>> fnode;
    int cap;
    int minfre;
};

int main() {
    LFU foo(3);
    foo.Set("hello", 10);
    foo.Set("world", 2);
    foo.Set("ni", 1);
    foo.Set("hao", 33);
    foo.Get("ni");
    foo.Get("ni");
    foo.Set("wo", 123);
    foo.Get("wo");
    foo.Get("wo");
    foo.Get("hao");
    foo.Get("hao");
    foo.Set("shi", 111);
    foo.Print();
};