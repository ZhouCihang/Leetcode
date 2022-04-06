#include <iostream>
using namespace std;

class Singleton
{
public:
    //This is how client can access the single instance
    static Singleton *getInstance()
    {
        if (inst_ == NULL)
        {
            inst_ = new Singleton();
        }
        return (inst_);
    }
    void setVal(int val) { value_ = val; }
    int getVal() { return (value_); }
    ~Singleton()
    {
        cout << "destructor called!" << endl;
    }

protected:
    int value_;

private:
    static Singleton *inst_;
    Singleton()
    {
        value_ = 0;
        cout << "constructor called!" << endl;
    }
    Singleton(const Singleton &);
    Singleton &operator=(const Singleton &);
};

Singleton *Singleton::inst_ = NULL;

int main()
{
    Singleton *p1 = Singleton::getInstance();
    p1->setVal(10);
    Singleton *p2 = Singleton::getInstance();
    cout << "Value = " << p2->getVal() << '\n';
    return 0;
}