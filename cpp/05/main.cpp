#include <iostream>

class Animal{
    private:
        int food;
        int weight;

    public:
        void set_animal(int _food, int _weight){
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc){
            food += inc;
            weight += (inc / 3);
        }

        void view_stat(){
            std::cout << "이 동물의 food : " << food << std::endl;
            std::cout << "이 동물의 weight : " << weight << std::endl;
        }
};

int main(){
    // 이전 강의에서 play(list[play_with]); 라 적은건 쫌 서순이 불편함.
    // 따라서 animal.play() 이렇게 하는게 좀 더 객체지향적임.

    // 컴퓨터 상에서 현실세계를 100프로 표현할 수 없기에, 적절하게 추상적으로 표현함. 이를 '추상화' 라고 함.
    // ex) 핸드폰의 경우, 전화를 한다. 문자를 보낸다. 등 핸드폰이 하는 것으로 추상화 시킬 수 있음.

    // 객체는 자기만의 정보를 나타내는 변수와, 이를 가지고 어떠한 작업을 하는 함수들로 둘러싸여 있음. 이러한 변수나 함수를 인스턴스 변수, 함수 라고 함.

    // 변수들이 외부로부터 보호 되고 있으며, 직접적으로 변수 값을 바꾸지 못하고 오직 객체의 인스턴스 함수를 통하여 바꿀 수 있음. 
    // ex) animal.food += 100; -> X
    // ex) animal.increase_food(100); -> O 
    // 이렇게 직접적으로 조절하는게 아닌, 간접적으로 조절하는 작업을 '캡슐화' 라고 함.

    Animal animal;
    animal.set_animal(100, 50);
    animal.increase_food(30);

    animal.view_stat();

    return 0;
}