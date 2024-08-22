#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>

using std::string;
using namespace std;

class Table;

//// --------------------------------------------Vector-----------------------------------------------------
class Vector {
    string* data;
    int capacity;
    int length;
    
    public:
        Vector(int n = 1);

        void push_back(string s);

        string operator[](int i);

        void remove(int x);

        int size();

        ~Vector();
};

Vector::Vector(int n) : data(new string[n]), capacity(n), length(0) {}

void Vector::push_back(string s){
    if (capacity <= length){
        string* temp = new string[capacity * 2];
        for (int i = 0; i < length; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity *= 2;
    }

    data[length] = s;
    length ++;
}

string Vector::operator[](int i) {return data[i]; }

void Vector::remove(int x){
    for (int i = x + 1; i < length; i++){
        data[i - 1] = data[i];
    }
    length--;
}

int Vector::size() {return length;}

Vector::~Vector(){
    if (data){
        delete[] data;
    }
}

//// --------------------------------------------Vector-----------------------------------------------------


//// --------------------------------------------stack-----------------------------------------------------
class Stack{
    struct Node{
        Node* prev;
        string s;

        Node(Node* prev, string s) : prev(prev),s(s) {}
    };

    Node* current;
    Node start;

    public:
        Stack();

        void push(string s);

        string pop();
        
        string peek();

        // void print_stack(Stack& s);

        bool is_empty();

        ~Stack();
};

class NumStack{
    struct Node{
        Node* prev;
        double s;

        Node(Node* prev, double s) : prev(prev), s(s) {} 
    };

    Node* current;
    Node start;

    public:
        NumStack();
        void push(double s);
        double pop();
        double peek();
        bool is_empty();

        ~NumStack();
};
//// --------------------------------------------stack-----------------------------------------------------



//// --------------------------------------------Cell-----------------------------------------------------
class Cell{
    protected:
        Table* table;
        std::string data;
        int x, y;

    public:
        virtual string stringify();
        virtual int to_numeric();

        Cell(int x, int y, Table* table);

        Cell(const std::string& data) : data(data){};
};

Cell::Cell(int x, int y, Table* table)
        : x(x), y(y), table(table) {}
string Cell::stringify() {return data;}
int Cell::to_numeric() {return 0;}

class StringCell : public Cell{
    string data;

    public:
        string stringify();
        int to_numeric();

        StringCell(string data, int x, int y, Table* t);
};

StringCell::StringCell(string data, int x, int y, Table* t)
        : data(data), Cell(x,y,t) {}
string StringCell::stringify() {return data;}
int StringCell::to_numeric() {return 0;}

class NumberCell : public Cell{
    int data;

    public:
        string stringify();
        int to_numeric();

        NumberCell(int data, int x, int y, Table* t);
};

NumberCell::NumberCell(int data, int x, int y, Table* t)
        : data(data), Cell(x, y, t) {}
string NumberCell::stringify() {return std::to_string(data) ; }
int NumberCell::to_numeric() {return data;}

class DateCell : public Cell{
    time_t data;

    public:
        string stringify();
        int to_numeric();

        DateCell(string s, int x, int y, Table* t);
};

string DateCell::stringify() {
    char buf[50];
    tm temp;
    localtime(&data);

    strftime(buf, 50, "%F", &temp);

    return string(buf);
}

int DateCell::to_numeric() {return static_cast<int>(data);}

DateCell::DateCell(string s, int x, int y, Table* t) : Cell(x,y,t){
    int year = atoi(s.c_str());
    int month = atoi(s.c_str() + 5);
    int day = atoi(s.c_str() + 8);

    tm timeinfo;
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;

    data = mktime(&timeinfo);
}

//// --------------------------------------------Cell-----------------------------------------------------


//// --------------------------------------------table-----------------------------------------------------
class Table{
    protected:
        int max_row_size, max_col_size;

        Cell*** data_table;
    
    public:
        Table(int max_row_size, int max_col_size);
        ~Table();

        void reg_cell(Cell* c, int row, int col);

        int to_numeric(const string& s);

        int to_numeric(int row, int col);

        string stringify(const string& s);
        string stringify(int row, int col);

        virtual string print_table() = 0;
};

Table::Table(int max_row_size, int max_col_size):max_row_size(max_row_size), max_col_size(max_col_size){
    data_table = new Cell**[max_row_size];
    for (int i = 0; i < max_row_size; i ++){
        data_table[i] = new Cell*[max_col_size];
        for (int j = 0; j < max_col_size; j++){
            data_table[i][j] = NULL;
        }
    }
    
}

Table::~Table(){
    for (int i = 0; i < max_row_size; i++){
        for (int j = 0; j < max_col_size; j++){
            if (data_table[i][j]) delete data_table[i][j];
        }
    }
    for (int i = 0; i < max_row_size; i++){
        delete[] data_table[i];
    }
    delete[] data_table;
}

void Table::reg_cell(Cell* c, int row, int col){
    if (!(row < max_row_size && col < max_col_size)) return;

    if (data_table[row][col]){
        delete data_table[row][col];
    }
    data_table[row][col] = c;
}

int Table::to_numeric(const string& s){
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size){
        if (data_table[row][col]){
            return data_table[row][col]->to_numeric();
        }
    }
    return 0;
}

int Table::to_numeric(int row, int col){
    if (row < max_row_size && col < max_col_size && data_table[row][col]){
        return data_table[row][col]->to_numeric();
    }
    return 0;
}

string Table::stringify(const string& s){
    int col = s[0] - 'A';
    int row = atoi(s.c_str() + 1) - 1;

    if (row < max_row_size && col < max_col_size){
        if (data_table[row][col]){
            return data_table[row][col]->stringify();
        }
    }
    return 0;
}

string Table::stringify(int row, int col){
    if (row < max_row_size && col < max_col_size && data_table[row][col]){
        return data_table[row][col]->stringify();
    }
    return "";
}


class TxtTable : public Table{
    string repeat_char(int n, char c);

    string col_num_to_str(int n);

    public:
        TxtTable(int row, int col);

        string print_table();
};

string TxtTable::repeat_char(int n, char c){
    string s = "";
    for (int i = 0; i < n; i++) s.push_back(c);

    return s;
}

string TxtTable::col_num_to_str(int n){
    string s = "";
    if (n < 26){
        s.push_back('A' + n);
    } else{
        char first = 'A' + n / 26 - 1;
        char second = 'A' + n % 26;
        s.push_back(first);
        s.push_back(second);
    }

    return s;
}

TxtTable::TxtTable(int row, int col) : Table(row, col) {}

string TxtTable::print_table(){
    string total_table;

    int* col_max_wide = new int[max_col_size];

    for (int i = 0; i < max_col_size; i++){
        unsigned int max_wide = 2;
        for (int j = 0; j < max_row_size; j++){
            if (data_table[j][i] && data_table[j][i]->stringify().length() > max_wide){
                max_wide = data_table[j][i]->stringify().length();
            }
        }
        col_max_wide[i] = max_wide;
    }

    total_table += "    ";
    int total_wide = 4;

    for (int i = 0; i < max_col_size; i++){
        if (col_max_wide[i]){
            int max_len = std::max(2, col_max_wide[i]);
            total_table += " | " + col_num_to_str(i);
            total_table += repeat_char(max_len - col_num_to_str(i).length(), ' ');

            total_wide += (max_len + 3);
        }
    }

    total_table += "\n";
    for (int i = 0; i < max_row_size; i++){
        total_table += repeat_char(total_wide, '-');
        total_table += "\n" + std::to_string(i + 1);
        total_table += repeat_char(4 - std::to_string(i + 1).length(), ' ');

        for (int j = 0; j < max_col_size; j++){
            if (col_max_wide[j]){
                int max_len = std::max(2,col_max_wide[j]);

                string s = "";
                if (data_table[i][j]){
                    s = data_table[i][j]->stringify();
                }
                total_table += " | " + s;
                total_table += repeat_char(max_len - s.length(), ' ');
            }
        }
        total_table += "\n";
    }

    return total_table;
}



class CSVTable : public Table {
    public:
        CSVTable(int row, int col);

        string print_table();
};

CSVTable::CSVTable(int row, int col) : Table(row, col) {}

string CSVTable::print_table(){
    string s = "";
    for (int i = 0; i < max_row_size; i++){
        for (int j = 0; j < max_row_size; j++){
            if (j >= 1) s += ",";

            string temp;
            if (data_table[i][j]) temp = data_table[i][j]->stringify();

            for (int k = 0; k < temp.length(); k++){
                if (temp[k] == '"'){
                    temp.insert(k, 1, '"');

                    k++;
                }
            }

            temp = '"' + temp + '"';
            s += temp;
        }
        s += '\n';
    }
    return s;
}


class HTMLTable : public Table{
    public:
        HTMLTable(int row, int col);

        string print_table();
};

HTMLTable::HTMLTable(int row, int col) : Table(row, col) {}
string HTMLTable::print_table(){
    string s = "<table border = '1' cellpadding='10'>";
    for (int i = 0; i < max_row_size; i ++){
        s += "<tr>";
        for (int j = 0; j < max_col_size; j++){
            s += "<td>";
            if (data_table[i][j]) s += data_table[i][j]->stringify();
            s += "</td>";
        }
        s += "</tr>";
    }
    s += "</table>";
    return s;
}

//// --------------------------------------------table-----------------------------------------------------


class ExprCell : public Cell {
    string data;
    string* parsed_expr;

    Vector exp_vec;

    int precedence(char c);

    void parse_expression();

    public:
        ExprCell(string data, int x, int y, Table* t) : Cell(x,y,t), data(data), parsed_expr(nullptr) {parse_expression();}

        string stringify();
        int to_numeric();
};

string ExprCell::stringify(){return data;}

int ExprCell::to_numeric(){
    double result = 0;
    NumStack stack;

    for (int i = 0; i < exp_vec.size(); i++){
        string s = exp_vec[i];

        if (isalpha(s[0])){
            stack.push(table->to_numeric(s));
        }
        else if (isdigit(s[0])){
            stack.push(atoi(s.c_str()));
        }else {
            double y = stack.pop();
            double x = stack.pop();
            switch (s[0]){
                case '+':
                    stack.push(x + y);
                    break;
                case '-':
                    stack.push(x - y);
                    break;
                case '*':
                    stack.push(x * y);
                    break;
                case '/':
                    stack.push(x / y);
                    break;
            }
        }
    }
    return stack.pop();
}

int ExprCell::precedence(char c){
    switch(c) {
        case '(':
        case '[':
        case '{':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return 0;
}


// void print_stack(Stack& s){
//     for (const auto& elem : s){
//         std::cout << elem << std::endl;
//     }
// }

void ExprCell::parse_expression(){
    Stack stack;

    data.insert(0, "(");
    data.push_back(')');

    for (int i = 0; i< data.length(); i++){
        if (isalpha(data[i])){
            exp_vec.push_back(data.substr(i, 2));
            i++;
        } else if(isdigit(data[i])){
            exp_vec.push_back(data.substr(i, 1));
        } else if(data[i] == '(' || data[i] == '[' || data[i] == '{') {
            stack.push(data.substr(i, 1));
        } else if (data[i] == ')' || data[i] == ']' || data[i] == '}') {
            string t = stack.pop();
            while (t != "(" && t != "[" && t != "{"){
                exp_vec.push_back(t);
                t = stack.pop();
            }
        } else if (data[i] == '+' || data[i] == '-' || data[i] == '*' || data[i] == '/'){
            while (!stack.is_empty() && precedence(stack.peek()[0]) >= precedence(data[i])){
                exp_vec.push_back(stack.pop());
            }
            stack.push(data.substr(i,1));
        }
        // print_stack(stack);
    }
}


std::ostream& operator<<(std::ostream& o, Table& table) {
    o << table.print_table();
    return o;
}


//// --------------------------------------------Excel-----------------------------------------------------
class Excel{
    Table* current_table;

    public:
        Excel(int max_row, int max_col, int choice);

        int parse_user_input(string s);
        void command_line();
};

Excel::Excel(int max_row, int max_col, int choice = 0){
    switch(choice){
        case 0:
            current_table = new TxtTable(max_row, max_col);
            break;

        case 1:
            current_table = new CSVTable(max_row, max_col);
            break;
        default:
            current_table = new HTMLTable(max_row, max_col);
    }
}

int Excel::parse_user_input(string s){
    int next = 0;
    string command = "";
    for (int i = 0; i < s.length(); i ++){
        if (s[i] == ' '){
            command = s.substr(0, i);
            next = i + 1;
            break;
        } else if (i == s.length() - 1){
            command = s.substr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    string to = "";
    for (int i = next; i < s.length(); i++){
        if (s[i] == ' ' || i == s.length() - 1){
            to = s.substr(next, i - next);
            next = i + 1;
            break;
        } else if (i == s.length() - 1){
            to = s.substr(0, i + 1);
            next = i + 1;
            break;
        }
    }

    int col = to[0] - 'A';
    int row = atoi(to.c_str() + 1) - 1;

    string rest = s.substr(next);

    if (command == "sets"){
        current_table->reg_cell(new StringCell(rest, row, col, current_table), row, col);
    } else if (command == "setn"){
        current_table->reg_cell(new NumberCell(atoi(rest.c_str()), row, col, current_table), row, col);
    } else if (command == "setd"){
        current_table->reg_cell(new DateCell(rest, row, col , current_table), row, col);
    } else if (command == "sete"){
        current_table->reg_cell(new ExprCell(rest, row, col, current_table), row, col);
    } else if (command == "out"){
        ofstream out(to);
        out << *current_table;
        std::cout << to << "에 내용이 저장되었습니다. " << std::endl;
    } else if (command == "exit"){
        return 0;
    }

    return 1;
}

void Excel::command_line() {
    string s;
    std::getline(cin, s);

    while (parse_user_input(s)){
        std::cout << *current_table << std::endl << ">> ";
        getline(cin, s);
    }
}

//// --------------------------------------------Excel-----------------------------------------------------


//// --------------------------------------------stack-----------------------------------------------------

Stack::Stack() : start(NULL, "") {current = &start; }

void Stack::push(string s){
    Node* n = new Node(current, s);
    current = n;
}

string Stack::pop() {
    if (current == &start) return "";

    string s = current->s;
    Node* prev = current;
    current = current->prev;

    delete prev;
    return s;
}

string Stack::peek() {return current->s;}

bool Stack::is_empty() {
    if (current == &start) return true;
    return false;
}

Stack::~Stack(){
    while (current != &start){
        Node* prev = current;
        current = current->prev;
        delete prev;
    }
}

NumStack::NumStack() : start(NULL, 0) {current = &start; }
void NumStack::push(double s){
    Node* n = new Node(current, s);
    current = n;
}

double NumStack::pop() {
    if (current == &start) return 0;

    double s = current->s;
    Node* prev = current;
    current = current->prev;

    delete prev;
    return s;
}

double NumStack::peek() {return current->s;}

bool NumStack::is_empty(){
    if (current == &start) return true;
    return false;
}

NumStack::~NumStack(){
    while(current != & start){
        Node* prev = current;
        current = current->prev;
        delete prev;
    }
}
//// --------------------------------------------stack-----------------------------------------------------


void ex1(){
    CSVTable table(5,5);
    table.reg_cell(new NumberCell(2, 1, 1, &table), 1, 1);
    table.reg_cell(new NumberCell(3, 1, 2, &table), 1, 2);

    table.reg_cell(new NumberCell(4, 2, 1, &table), 2, 1);
    table.reg_cell(new NumberCell(5, 2, 2, &table), 2, 2);
    table.reg_cell(new ExprCell("B2+B3*(C2+C3-2)", 3, 3, &table), 3, 2);
    table.reg_cell(new StringCell("B2 + B3 * ( C2 + C3 - 2 ) = ", 3, 2, &table),3, 1);

    std::cout << table;
}

void ex2(){
    CSVTable table(5, 5);
    std::ofstream out("test.csv");

    table.reg_cell(new StringCell("Hello~", 0, 0, &table), 0, 0);
    table.reg_cell(new StringCell("C++", 0, 1, &table), 0, 1);

    table.reg_cell(new StringCell("Programming", 1, 1, &table), 1, 1);
    out << table;

    HTMLTable table2(5, 5);
    std::ofstream out2("test.html");

    table2.reg_cell(new StringCell("Hello~", 0, 0, &table), 0, 0);
    table2.reg_cell(new StringCell("C++", 0, 1, &table), 0, 1);
    table2.reg_cell(new StringCell("Programming", 1, 1, &table), 1, 1);
    out2 << table2;
}

int main(){
    std::cout << "테이블 (타입) (최대 행 크기) (최대 열 크기) 를 순서대로 입력해주세요" << std::endl;
    std::cout << "* 참고 * " << std::endl;
    std::cout << "1 : 텍스트 테이블, 2 : CSV 테이블, 3 : HTML 테이블"
                << std::endl;

    int type, max_row, max_col;
    std::cin >> type >> max_row >> max_col;
    Excel m(max_row, max_col, type - 1);
    m.command_line();
    
    ex1();
    ex2();
    return 0;
}