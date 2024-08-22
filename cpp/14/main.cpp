#include <iostream>
#include <string>

void string_ex(){
    std::string s = "abc";
    std::string t = "def";
    std::string s2 = s;

    std::cout << s << " 의 길이 : " << s.length() << std::endl; // length 외에도 insert, erase, replace 등 도 사용 가능.
    std::cout << s << " 뒤에" << t << " 를 붙히면 : " << s + t << std::endl;

    if (s == s2){ // string class 를 사용하면 비교가 가능함.
        std::cout << s << " 와 " << s2 << "는 같다 " << std::endl;
    }
    if (s != t){
        std::cout << s << " 와" << t  << "는 다르다" << std::endl;
    }

    std::cout << s << std::endl;
}

class Employee{
    protected:
        std::string name;
        int age;

        std::string position;
        int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank):
            name(name), age(age), position(position), rank(rank) {}
        Employee(const Employee& employee){
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        virtual void print_info(){
            std::cout << name << " (" << position << " , " << age << ") ==> " << calculate_pay() << " 만원" << std::endl;
        }

        virtual int calculate_pay() {return 200 + rank * 50; }
};

class Manager : public Employee{
    int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service):
            year_of_service(year_of_service), Employee(name, age, position, rank) {}

        Manager(const Manager& manager):
            Employee(manager.name, manager.age, manager.position, manager.rank){
                year_of_service = manager.year_of_service;
            }

        Manager() {}

        int calculate_pay() override {return 200 + rank * 50 + 5 * year_of_service;}

        void print_info() override {
            std::cout << name << " (" << position << " , " << age << ", " << year_of_service << "년차) ==> " << calculate_pay() << "마농" << std::endl;
        }
};

class EmployeeList{
    int alloc_employee;
    int current_employee;

    Employee** employee_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee){
            employee_list = new Employee*[alloc_employee];

            current_employee = 0;
        }  

        void add_employee(Employee* employee){
            employee_list[current_employee] = employee;
            current_employee++;
        }

        int current_employee_num() {return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++){
                employee_list[i]->print_info();
                total_pay += employee_list[i]->calculate_pay();
            }

            std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
        }

        ~EmployeeList(){
            for (int i = 0; i < current_employee; i++){
                delete employee_list[i];
            }

            delete[] employee_list;
        }
};

class Base{
    std::string s;

    public:
        Base() : s("기반") {std::cout << "기반 클래스" << std::endl;}

        virtual void what() {std::cout << s << std::endl;} 

        virtual void incorrect() {std::cout << "기반 클래스" << std::endl;} 
};

class Derived : public Base{
    std::string s;

    public:
        Derived() : s("파생"), Base(){std::cout << "파생 클래스" << std::endl;}

        void what() override {std::cout << s << std::endl;}

        void incorrect() override {std::cout << "파생클래스" << std::endl;}
};

void employee_ex(){
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.add_employee(new Employee("하하", 34, "평사원", 1));

    emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
    emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
    emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
    emp_list.add_employee(new Employee("정현돈", 36, "대리", 2));
    emp_list.add_employee(new Employee("길", 36, "인턴", -2));
    emp_list.print_employee_info();
}

void inheritance_ex(){
    std::cout << "=== 기반 클래스 생성 ===" << std::endl;
    Base p;

    std::cout << "=== 파생 클래스 생성 ===" << std::endl;
    Derived c;
}

void inheritance_ex_2(){
    std::cout << "기반 클래스 생성" << std::endl;
    Base p;

    p.what();

    std::cout << "파생 클래스 생성" << std::endl;
    Derived c;

    c.what();
}

void inheritance_ex_2_pointer_v(){
    Base p;
    Derived c;

    std::cout << "포인터 버전" << std::endl;
    Base* p_c = &c;
    p_c->what();
}

void inheritance_ex_2_pointer_v_down_casting(){
    Base p;
    Derived c;

    std::cout << "포인터 버전" << std::endl;
    Derived* p_p = &c;

    Derived* p_c = p_p;
    p_c->what();
}

void virtual_ex(){
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout << "실제 객체는 Base " << std::endl;
    p_p->what(); // 얘는 그냥 Base에 Base니까 그대로 호출

    std::cout << "실제 객체는 Derived" << std::endl;
    p_c->what(); // p_c 는 Base 포인터니까 Base에 what을 실행해야하지만, what이 virtual이라, Derived 에 what이 호출됨.
                    // 이걸 동적 바인딩 이라함.
}

void override_ex(){
    Base p;
    Derived c;

    Base* p_c = &c;
    Base* p_p = &p;

    std::cout << "실제 객체는 Base" << std::endl;
    p_p->incorrect();

    std::cout << "실제 객체는 Derived" << std::endl;
    p_c->incorrect();
}

int main(){
    employee_ex();

    return 0;

}