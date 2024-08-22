#include <iostream>
#include <string>

class ICar{
    public:
        virtual void drive() = 0;
        virtual void turnleft() = 0;
        virtual void turnright() = 0;
};

class IBoat{
    public:
        virtual void steer() = 0;
        virtual void steerleft() = 0;
        virtual void steerright() = 0;
};

class GV80 : public ICar{
    virtual void drive() override{
        std::cout << "GV80 drive" << std::endl;
    }
    virtual void turnleft() override{
        std::cout << "GV80 turnleft" << std::endl;
    }
    virtual void turnright() override{
        std::cout << "GV80 turn right" << std::endl;
    }
};

class RubberBoat : IBoat{
    virtual void steer() override{
        std::cout << "RubberBoat steer" << std::endl;
    }
    virtual void steerleft() override{
        std::cout << "Rubberboat steer left" << std::endl;
    }
    virtual void steerright() override{
        std::cout << "RubberBoat steer right" << std::endl;
    }
};

class WaterCar : public ICar, public IBoat{
    virtual void drive() override{
        std::cout << "WaterCar drive" << std::endl;
    }
    virtual void turnleft() override{
        std::cout << "WaterCar turn left" << std::endl;
    }
    virtual void turnright() override{
        std::cout << "WaterCar turn right" << std::endl;
    }
    virtual void steer() override{
        std::cout << "WaterCar steer" << std::endl;
    }
    virtual void steerleft() override{
        std::cout << "WaterCar steer left" << std::endl;
    }
    virtual void steerright() override{
        std::cout << "WaterCar steer right" << std::endl;
    }
};

int main(){

    return 0;
}

