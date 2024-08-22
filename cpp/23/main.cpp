#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <functional>

template <typename T>
void print_vector(std::vector<T>& vec){
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr){
        std::cout << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>& vec){
    for (const auto& elem : vec){
        std::cout << elem << std::endl;
    }
}

template <typename T>
void print_list(std::list<T>& lst){
    std::cout << "[ ";
    for (const auto& elem : lst){
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void print_deque(std::deque<T>& dq){
    std::cout << "[ ";
    for (const auto& elem : dq){
        std::cout << elem << " "; 
    }
    std::cout << "]" << std::endl;
} 

template <typename T>
void print_set(std::set<T>& s){
    std::cout << "[ ";
    for (const auto& elem : s){
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename K, typename V>
void print_map(std::map<K, V>& m){
    for (const auto& kv : m){
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

template <typename K, typename V>
void search_and_print(std::map<K, V>&m, K key){
    auto itr = m.find(key);
    if (itr != m.end()){
        std::cout << key << " --> " << itr->second << std::endl;
    } else{
        std::cout << key << "은(는) 목록에 없습니다" << std::endl;
    }
}

template <typename K>
void print_set(const std::multiset<K>& s){
    for (const auto& elem : s){
        std::cout << elem << std::endl;
    }
}

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m){
    for (const auto& kv : m){
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m){
    for (const auto& elem : m){
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>&s, K key){
    auto itr = s.find(key);
    if (itr != s.end()){
        std::cout << key << "가 존재" << std::endl;
    }else{
        std::cout << key << "가 없다" << std::endl;
    }
}

template <typename Iter>
void print(Iter begin, Iter end){
    while(begin != end){
        std::cout << *begin <<" ";
        begin ++;
    }
    std::cout << std::endl;
}

struct int_compare{
    bool operator()(const int& a, const int& b) const {return a > b;}
};


template <typename Iter>
void print_2(Iter begin, Iter end){
    while (begin != end){
        std::cout << "[" << *begin << "]";
        begin++;
    }
    std::cout << std::endl;
}

struct is_odd{
    int* num_delete;

    is_odd(int* num_delete) : num_delete(num_delete) {}

    bool operator()(const int& i){
        if(*num_delete >= 2) return false;

        if (i % 2 == 1){
            (*num_delete)++;
            return true;
        }

        return false;
    }
};

struct User{
    std::string name;
    int age;

    User(std::string name, int age) : name(name), age(age) {}
    bool operator<(const User& u) const {return age < u.age;}
};

std::ostream& operator<<(std::ostream& o, const User& u){
    o << u.name << " , " << u.age;
    return o;
}


class Todo{
    int priority;
    std::string job_desc;

    public:
        Todo(int priority, std::string job_desc): priority(priority), job_desc(job_desc) {}

        bool operator<(const Todo& t) const{
            if (priority == t.priority){
                return job_desc < t.job_desc;
            }
            return priority > t.priority;
        }

        bool operator==(const Todo& t) const{
            if (priority == t.priority && job_desc == t.job_desc) return true;
            return false;
        }

        friend struct TodoCmp;
        friend struct std::hash<Todo>;
        friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

struct TodoCmp{
    bool operator()(const Todo& t1, const Todo& t2) const {
        if(t1.priority == t2.priority){
            return t1.job_desc < t2.job_desc;
        }
        return t1.job_desc > t2.job_desc;  
    }
};

namespace std{
template <>
struct hash<Todo>{
    size_t operator()(const Todo& t) const {
        hash<string> hash_func;

        return t.priority ^ (hash_func(t.job_desc));
    }
};
}

struct GameUser{
    std::string name;
    int level;

    GameUser(std::string name, int level) : name(name), level(level) {}
    bool operator==(const GameUser& user) const{
        if(name == user.name && level == user.level) return true;
        return false;
    }
};

class Party{
    std::vector<GameUser> users;

    public:
        bool add_user(std::string name, int level){
            GameUser new_user(name, level);
            if (std::find(users.begin(), users.end(), new_user) != users.end()){
                return false;
            }
            users.push_back(new_user);
            return true;
        }

        bool can_join_dungeon(){
            return std::all_of(users.begin(), users.end(), [](GameUser& user) {return user.level >= 15;}); // all_of 는, 모든 원소들이 전부 조건을 충족해야 true를 리턴함.
        } 

        bool can_use_special_item(){
            return std::any_of(users.begin(), users.end(), [](GameUser& user) {return user.level >= 19;}); // any_of는, 하나라도 충족한다면 true를 리턴함.
        }
};

std::ostream& operator<<(std::ostream& o, const Todo& td){
    o << "[ 중요도 : " << td.priority << "] " << td.job_desc;
    return o;
}

void ex1(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);
    std::cout << "-------------" << std::endl;

    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    std::cout << "------------" << std::endl;
    vec.erase(vec.begin() + 3);
    print_vector(vec);
}

void ex2(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);


    for (std::vector<int>::size_type i = 0; i != vec.size(); i++){
        if (vec[i] == 20){
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    std::cout << "값이 20인 원소를 지운다 ! " << std::endl;
    print_vector(vec);
}

void ex3(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    std::cout << "처음 벡터 상태" << std::endl;
    print_vector(vec);

    std::cout << "reverse vector" << std::endl;
    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++){
        std::cout << *r_iter << std::endl;
    }

}

void ex4(){
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    print_vector(vec);
    print_vector_range_based(vec);
}

void ex5(){
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr){
        if (*itr == 20){
            lst.insert(itr,50);
        }
    }

    print_list(lst);

    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr){
        if (*itr == 30){
            lst.erase(itr);
            break;
        }
    
    }

    print_list(lst);
}

void ex6(){
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);

    print_deque(dq);

    dq.pop_front();
    print_deque(dq);
}

void ex7(){
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    print_set(s);

    auto itr = s.find(20);
    if (itr != s.end()){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    itr = s.find(25);
    if (itr != s.end()){
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
}

void ex8(){
    std::set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(20);
    s.insert(10);

    print_set(s);
}

void ex9(){
    std::set<Todo> todos;

    todos.insert(Todo(1, "play basket ball"));
    todos.insert(Todo(2, "study math"));
    todos.insert(Todo(1, "programming"));
    todos.insert(Todo(3, "meet friend"));
    todos.insert(Todo(2, "watch movie"));

    print_set(todos);

    std::cout << "-----------" << std::endl;
    std::cout << "if end homework" << std::endl;
    todos.erase(todos.find(Todo(2, "study math")));
    print_set(todos);
}

void ex10(){
    std::map<std::string, double> pitcher_list;

    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커", 2.93));
    pitcher_list.insert(std::pair<std::string, double>("피어밴드", 2.95));

    pitcher_list.insert(std::make_pair("차우찬", 3.04));
    pitcher_list.insert(std::make_pair("장원준", 3.05));
    pitcher_list.insert(std::make_pair("헥터", 3.09));

    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;
    pitcher_list["켈리"] = 3.90;

    print_map(pitcher_list);

    std::cout << "박세웅 방어율은 ? :: " << pitcher_list["박세웅"] << std::endl;
}

void ex11(){
    std::map<std::string, double> pitcher_list;

    pitcher_list["오승환"] = 3.58;

    print_map(pitcher_list);
    std::cout << "----------------" << std::endl;

    search_and_print(pitcher_list, std::string("오승환"));
    search_and_print(pitcher_list, std::string("류현진"));
}

void ex12(){
    std::multiset<std::string> s;

    s.insert("a");
    s.insert("b");
    s.insert("a");
    s.insert("c");
    s.insert("d");
    s.insert("c");

    print_set(s);

    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    print_map(m);

    std::cout << "--------------" << std::endl;
    std::cout << m.find(1)->second << std::endl;
    
}

void ex13(){
    std::unordered_set<std::string> s;
    
    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("dgseo");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");
    
    print_unordered_set(s); //랜덤한 순서로 출력됨.
    std::cout << "---------" << std::endl;
    is_exist(s, std::string("c++"));
    is_exist(s, std::string("c"));

    std::cout << "------------" << std::endl;
    std::cout << "'hi' 를 삭제" << std::endl;
    s.erase(s.find("hi"));
    is_exist(s, std::string("hi"));
}

void ex14(){
    std::unordered_set<Todo> todos;

    todos.insert(Todo(1, "play basket ball"));
    todos.insert(Todo(2, "study math"));
    todos.insert(Todo(1, "programming"));
    todos.insert(Todo(3, "meet friend"));
    todos.insert(Todo(2, "watch movie"));
    print_unordered_set(todos);

    std::cout << "-----------" << std::endl;
}

void ex15(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);
    
    std::cout << "정렬 전 ----" << std::endl;
    print(vec.begin(), vec.end());

    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    print(vec.begin(), vec.end());
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    std::cout << "정렬 후 ----" << std::endl;
    print(vec.begin(), vec.end());
}

void ex16(){
    std::vector<User> vec;
    for (int i = 0; i < 100; i ++){
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i % 26);
        vec.push_back(User(name, static_cast<int>(rand() % 10)));
    }

    std::vector<User> vec2 = vec;

    std::cout << "정렬 전 -----" << std::endl;
    print_2(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());

    std::cout << "정렬 후 ----" << std::endl;
    print_2(vec.begin(), vec.end());

    std::cout << "stable_sort 의 경우 ---" << std::endl;
    std::stable_sort(vec2.begin(), vec2.end());
    print_2(vec2.begin(), vec2.end());
}

void ex17(){
    [](int i) {return i % 2 == 1;}(3); // true <= 이렇게도 람다식을 사용할 수 있고,
    auto func = [](int i){return i % 2 == 1;};
    func(4); // 이렇게도 람다식을 사용할 수 있음.
}

void ex18(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "처음 vec 상태 ---- " << std::endl;
    print_2(vec.begin(), vec.end());

    std::cout << "벡터에서 3인 원소 제거"  << std::endl;
    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());
    print_2(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 앞의 2개 제거" << std::endl;
    int num_delete = 0;
    // vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd(&num_delete)), vec.end());
    // vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i)->bool {return i % 2 == 1;}), vec.end()); // 람다식, [capture list] (받는 인자) -> 리턴 타입 {함수 본체}
                                                                                                        // 혹은 [capture list] (받는 인자) {함수 본체}

    int num_erased = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [&num_erased](int i) {
        if (num_erased >= 2) 
            return false; 
        else if (i % 2 == 1) {
            num_erased++; 
            return true;
        } 
        return false;}), vec.end());

    
    print_2(vec.begin(), vec.end());
}

void ex19(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::vector<int> vec2(6, 0);

    std::cout << "처음 vec 상태 -----" << std::endl;
    print_2(vec.begin(), vec.end());
    print_2(vec2.begin(), vec2.end());

    std::cout << "벡터 전체에 1을 더함" << std::endl;
    std::transform(vec.begin(), vec.end(), vec2.begin(), [](int i) {return i + 1;});

    print_2(vec.begin(), vec.end());
    print_2(vec2.begin(), vec2.end());
}

void ex20(){
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    auto current = vec.begin();

    while (true){
        current = std::find(current, vec.end(), 3);
        if (current == vec.end()) break;
        std::cout << "3은 "<< std::distance(vec.begin(), current) + 1 << " 번째 원소" << std::endl;
        current++;
    }

    auto current_2 = vec.begin();
    while (true){
        current_2 = std::find_if(current_2, vec.end(), [](int i) {return i % 3 == 2;});
        if (current_2 == vec.end()) break;
        std::cout << "3으로 나눈 나머지가 2인 원소는"<< *current_2 << " 번째 원소" << std::endl;
        current_2++;
    }
}

int main(){
    Party party;
    party.add_user("철수", 15);
    party.add_user("영희", 18);
    party.add_user("민수", 12);
    party.add_user("수빈", 19);

    std::cout << std::boolalpha;
    std::cout << "던전 입장 가능 ?" << party.can_join_dungeon() << std::endl;
    std::cout << "특별 아이템 사용 가능 ?" << party.can_use_special_item() << std::endl;

    return 0;
}