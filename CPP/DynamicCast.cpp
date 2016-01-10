#include <iostream>
using namespace std;

class Foo1 {
    public:
    void show() { cout << "Foo1's show" << endl; }
};

class Foo2 : public Foo1 {
    public:
    virtual void show() { cout << "Foo2's show" << endl; };
    void show2() { cout << "Foo2's show2" << endl; };
};

class Foo3 : public Foo2 {
    public:
    void show() { cout << "Foo3's show" << endl; }
    void show2() { cout << "Foo3's show2" << endl; };
};


int main() {
    Foo1 f1;
    Foo2 f2;
    Foo3 f3;
    Foo1 *f1p;
    Foo2 *f2p;
    Foo3 *f3p;

    // complie error (down-cast)
    /*
    f2p = &f1; 
    f3p = dynamic_cast<Foo3 *>( f2p );
    */
    
    // complie error (non-polymorphic class Foo1 cannot cast)
    /*
    f1p = &f1;
    f2p = dynamic_cast<Foo2 *>( f1p );
    */
    
    // Foo2 instance cannot cast to Foo3*
    f2p = &f2;
    f3p = dynamic_cast<Foo3 *>( f2p );
    if( f3p == 0) {
        cout<<"Foo2 instance cannot cast to Foo3*"<<endl;
    } else {
        f3p->show();
        f3p->show2();
    }
    
    // Foo3 instance can cast to Foo3*
    f2p = &f3;
    f3p = dynamic_cast<Foo3 *>( f2p );
    if( f3p == 0) {
        cout<<"Foo3 instance cannot cast to Foo3*"<<endl; // won't be here
    } else {
        f3p->show();
        f3p->show2();
    }

    return 0;
}
