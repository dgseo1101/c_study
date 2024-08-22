#include <iostream>

class Marine{
    static int total_marine_num;
    const static int i = 0;

    int hp;
    int coord_x, coord_y;
    bool is_dead;

    const int defalut_damage;

    public:
        Marine();
        Marine(int x, int y);
        Marine(int x, int y, int defalut_damage);

        int attack() const;
        Marine& be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();

        ~Marine() {total_marine_num--;}
};
int Marine::total_marine_num = 0;

Marine::Marine() : hp(50), coord_x(0), coord_y(0), defalut_damage(5), is_dead(false) { //초기화 리스트 라고 함. 생성자 호출과 동시에 멤버 변수들을 초기화해주게됨.
    total_marine_num++;                                                                        // 이럴 경우 int a; a = 10 -> int a = 10; 이라고 하는것과 같음
} 
        
Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), defalut_damage(5), is_dead(false) {
        total_marine_num++;
    }

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x), coord_y(y), hp(50), defalut_damage(default_damage), is_dead(false) {
        total_marine_num++;
    }

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() const {return defalut_damage;}
Marine& Marine::be_attacked(int damage_earn){
    this->hp -= damage_earn;
    if (this->hp <= 0) this->is_dead = true;

    return *this;
}

void Marine::show_status(){
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : (" << coord_x << " , " << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
    std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine(){
    Marine marine3(10, 10, 4);
    marine3.show_status();
}

class C{
    int x;

    public:
        C(int c) : x(c) {}

        int& access_x() {return x;}
        int get_x() {return x;}
        void show_x() {std::cout << x << std::endl;} 
};

void temp_func(){
    C a(5);
    a.show_x();

    int& c = a.access_x();
    c = 4;
    a.show_x();

    int d = a.access_x();
    d = 3;
    a.show_x();

    int& e = a.access_x();
    e = 2;
    a.show_x();

    a.access_x() = 3;
    a.show_x();
}

class A {
  int x;

 public:
  A(int c) : x(c) {}
  A(const A& a) {
    x = a.x;
    std::cout << "복사 생성" << std::endl;
  }
};

class B {
  A a;

 public:
  B(int c) : a(c) {}
  B(const B& b) : a(b.a) {}
  A get_A() {
    A temp(a);
    return temp;
  }
};

int main(){
    B b(10);

    std::cout << "---------" << std::endl;
    A a1 = b.get_A();

    Marine marine1(2,3, 10);
    marine1.show_status();

    Marine marine2(3,5, 10);
    marine2.show_status();

    std::cout << std::endl << "marine 1 attack marine 2 !" << std::endl;

    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    return 0;
}