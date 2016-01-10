/*********************************************************************
 * This sample code shows some C++ features:
 * virtual function:
 *     - class destructor should add virtual to make derived class execute its destructor in polymorphism
 *     - Once virtual is declared , all the derived function inherates this effectiveness
 * function overloading:
 *     - derived object overloads the first upper class type
 * friend class:
 *     - friend class can access even private menbers
 *     - But it is not a friend of derived class
 * inheritance:
 *     - private menber cannot be accessed in derived class
 *
 * Dec, 2015 nyphoon
 * ******************************************************************/
#include <iostream>
using namespace std;

class FriendOfFoo1;

class Foo1 {
    friend class FriendOfFoo1;
    private:
    int i1;
    public:
    Foo1():i1(1) {cout << "Foo1's constructor" << endl; }
    virtual ~Foo1(){ cout << "Foo1's destructor" << endl; }
    void show() { cout << "Foo1's show" << endl; }
};

class Foo2 : public Foo1 {
    private:
    int i2;
    public:
    Foo2():i2(2) { cout << "Foo2's constructor" << endl; }
    ~Foo2(){ cout << "Foo2's destructor" << endl; } //non-virtual in derived class Foo2
    virtual void show() {
	cout << "Foo2's show" << endl;
	// child cannot access parent;s private member
	//cout << "Foo2 shows i1 of Foo1:" << i1 << endl;
    }
};

class Foo3 : public Foo2 {
    int i3;
    public:
    Foo3():i3(3) { cout << "Foo3's constructor" << endl; }
    ~Foo3(){ cout << "Foo3's destructor" << endl; }
    void show() { //Foo2 make this still be a virtual function
	cout << "Foo3's show" << endl;
    }
};


class FriendOfFoo1{
    public:
	void touch1(Foo1 &t){
	    cout<< __func__ <<endl;
	    cout<< "friend can touch private member i1=" << t.i1 <<endl;
	    t.show();
	}
	void touch2(Foo2 &t){
	    cout<< __func__ <<endl;
	    cout<< "friend can touch private member i1=" << t.i1 <<endl;
	    // parents's friend is not your friend ...
	    //cout<< "friend can touch private member i2=" << t.i2 <<endl;
	    t.show();
	}
	void touch3(Foo3 &t){
	    cout<< __func__ <<endl;
	    t.show();
	}
};

/////////////////////////////// function overloading test //////////////////////////////////////
void showFooByPtr(Foo1 *foo) {
    cout<< __func__ << "Foo1" << endl;
    foo->show();
}
void showFooByPtr(Foo2 *foo) {
    cout<< __func__ << "Foo2" << endl;
    foo->show();
}

void showFooByRef(Foo2 &foo) {
    cout<< __func__ <<endl;
    foo.show();
}
////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
    cout<<endl<<"contructor:"<<endl;
    Foo1 f1;
    Foo2 f2;
    Foo3 f3;
    FriendOfFoo1 f;

    // friend class
    cout<<endl<<"friend class:"<<endl;
    f.touch1(f3);
    f.touch2(f3);
    f.touch3(f3);

    cout<<endl<<"function overloading:"<<endl;
    showFooByPtr(&f1);
    showFooByPtr(&f2);
    showFooByPtr(&f3); // call showFooByPtr(Foo2 *foo)

    cout<<endl;
    //showFooByRef(f1); // derived class cannot reference to base class
    showFooByRef(f2);
    showFooByRef(f3);

    // Virtual destructor test
    cout<<endl<<"virtual destructor in polymorphism:"<<endl;
    Foo1 *ptr1 = new Foo2;
    delete ptr1; //virtual destructor in Foo1

    cout<<endl;
    Foo2 *ptr2 = new Foo3;
    ptr2->show(); //virtual
    delete ptr2; //virtual destructor in Foo1

    cout<<endl;

    // mian function destructor
    cout<<endl<<"last line of main function..."<<endl;
    return 0;
}
