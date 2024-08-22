#include <iostream>

class Parent{
    public:
        Parent() {std::cout << "Parent 생성자 호출" << std::endl;}
        virtual ~Parent() {std::cout << "Parent 소멸자 호출" << std::endl;}  // virtual로 만들어주지 않으면 호출이 되지 않아 메모리 누수 생김.
};

class Child : public Parent{
    public :
        Child() : Parent() {std::cout << "child 생성자 호출" << std::endl;}
        ~Child() {std::cout << "child 소멸자 호출" << std::endl;}
};

class A{
    public:
        virtual void show() {std::cout << "Parent !" << std::endl;}
};

class B : public A{
    public:
        void show() override {std::cout << "Child !" << std::endl;}
};

void destructor_ex(){
    std::cout << "평범한 child" << std::endl;
    {Child c;}
    std::cout << "Parent -> Child " << std::endl;
    {
        Parent *p = new Child();
        delete p;
    }
}

class Animal{
    public:
        Animal() {}
        virtual ~Animal() {}
        virtual void speak() = 0; // = 0 으로 정의되는 함수는 무조건 override가 되야하는 "순수 가상 함수" 임
                                  // 이렇게 순수 가상 함수를 최소 한개 이상 포함하고 있는, 반드시 상속되어야 하는 클래스를 "추상 클래스" 라고 함.
};

class Dog : public Animal {
    public:
        Dog() : Animal() {}
        void speak() override {std::cout << "왈왈" << std::endl;}
};

class Cat : public Animal{
    public:
        Cat() : Animal() {}
        void speak() override { std::cout << "야옹야옹" << std::endl; }
};

class Q{
    public:
        int a;

        Q() {std::cout << "A 생성자" << std::endl;} 
};

class W{
    public:
        int b;

        W() {std::cout << "B 생성자" << std::endl;}
};

class E : public Q, public W{
    public : 
        int c;

        E() : Q(), W() {std::cout << "C 생성자" << std::endl;}
};

void test(A& a) {a.show();}

void virtual_ex(){
    A a;
    B b;
    test(a);
    test(b);
}

void animal_ex(){
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();


}

int main(){
    E c;

    return 0;
}