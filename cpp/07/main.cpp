#include <iostream>
#include <string.h>

class Marine{
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name; 

    public:
        Marine();
        Marine(int x, int y, const char*marine_name);
        ~Marine();

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);
        void show_status();
};

Marine::Marine(){
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name){
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}

void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}

int Marine::attack() {return damage;}
void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if (hp <= 0) is_dead = true;
}

void Marine::show_status(){
    std::cout << "*** Marine ***" << std::endl;
    std::cout << "Location : (" << coord_x << " , " << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl; 

}

Marine::~Marine(){
    std::cout << name << "의 소멸자 호출" << std::endl;

    if (name != NULL){
        delete[] name;
    }
}

class Photon_Cannon{
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
        Photon_Cannon(int x, int y, const char *cannon_name);
        Photon_Cannon(const Photon_Cannon& PC);
        ~Photon_Cannon();

        void show_status();    
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout << "복사 생성자 호출" << std::endl; 
    hp = pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;

    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}

Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name){
    std::cout << "생성자 호출 !" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}

void Photon_Cannon::show_status(){
    std::cout << "Photon Cannon" << std::endl;
    std::cout << "Location : (" << coord_x << " , " << coord_y << ")" << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

Photon_Cannon::~Photon_Cannon(){
    if (name) delete[] name;
}

// void temp_ex(){
//     Marine marine1(2, 3);
//     Marine marine2(3,5);

//     marine1.show_status();
//     marine2.show_status();

//     std::cout << std::endl << "marine 1 attack marine 2 !" << std::endl;

//     marine2.be_attacked(marine1.attack());

//     marine1.show_status();
//     marine2.show_status();
// }

void marine_ex(){
    Marine* marines[100];

    marines[0] = new Marine(2, 3, "marine 1");
    marines[1] = new Marine(3,5, "marine 2");

    marines[0]->show_status();
    marines[1]->show_status();

    std::cout << std::endl << "marine1 attack marine2" << std::endl;

    marines[0]->be_attacked(marines[1]->attack());
    marines[0]->show_status();
    marines[1]->show_status();

    delete marines[0];
    delete marines[1];
}


int main(){
    Photon_Cannon pc1(3,3, "cannon");
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
    
    return 0;
}