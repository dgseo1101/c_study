#include <iostream>

template <typename T, unsigned int N>
class Array{
    T data[N];

    public:
        Array(T (&arr)[N]){
            for (int i = 0; i < N; i++){
                data[i] = arr[i];
            }
        }

        T* get_array() {return data;}

        unsigned int size() {return N;}

        void print_all(){
            for (int i = 0; i < N; i++){
                std::cout << data[i] << ", ";
            }
            std::cout << std::endl;
        }
};

template <int N>
struct Int{
    static const int num = N;
};

template <typename T, typename U>
struct add{
    typedef Int<T::num + U::num> result; // 두개의 타입을 받아 그 타입의 num을 더해 새로운 타입인 result를 만들어냄
};

// 이런 형식을 템플릿 메타 프로그래밍 이라고 하며, 작성된 코드는 컴파일에 모든 연산이 끝나기에, 프로그램 실행 속도를 향상시킬 수 있음. (컴파일 시간은 길어짐.)
// 하지만 구현이 복잡하고, 디버깅이 불편하다는 단점이 있음.
template <int N>
struct Factorial{
    static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<1>{
    static const int result = 1;
};

int gcd(int a, int b){
    if (b == 0){
        return a;
    }

    return gcd(b, a%b);
}

// 위 코드를 TMP로 구현하면 아래와 같음.

template <int X, int Y>
struct GCD{
    static const int value = GCD<Y, X % Y>::value;
};

template <int X>
struct GCD<X, 0>{
    static const int value = X;
};

template <int N, int D = 1>
struct Ratio{
    private:
        const static int _gcd = GCD<N, D>::value;

    public:
        typedef Ratio<N / _gcd,D /_gcd> type;
        static const int num = N / _gcd;
        static const int den = D / _gcd;
};

template <class R1, class R2>
struct _Ratio_add{
    typedef Ratio<R1::num * R2::den + R2::num * R1::den, R1::den * R2::den> type;
};

template <class R1, class R2>
struct Ratio_add : _Ratio_add<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_subtract{
    using type = Ratio<R1::num * R2::den - R2::num * R1::den, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_subtract : _Ratio_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_multiply {
    using type = Ratio<R1::num * R2::num, R1::den * R2::den>;
};

template <class R1, class R2>
struct Ratio_multiply : _Ratio_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Ratio_divide{
    using type = Ratio<R1::num * R2::den, R1::den * R2::num>;
};

template <class R1, class R2>
struct Ratio_divide : _Ratio_divide<R1, R2>::type {};

void TMP_ex(){
    int arr[3] = {1,2,3};

    Array<int, 3> arr_w(arr);

    arr_w.print_all();

    typedef Int<1> one;
    typedef Int<2> two;

    typedef add<one, two>::result three;

    std::cout << "Addtion result : " << three::num << std::endl; // one + two를 나타내는 타입이 result이며, 이를 three라 하였음
    
    std::cout << "6 ! = 1*2*3*4*5*6 = " << Factorial<6>::result << std::endl;

    std::cout << "GCD (36, 24) :: " << GCD<36, 24>::value << std::endl;

    typedef Ratio<2, 3> rat;
    typedef Ratio<3, 2> rat2;
    // typedef Ratio_add<rat, rat2> rat3; // 이렇게 해도 되고,
    using rat3 = Ratio_add<rat, rat2>; // c++11 부턴 이렇게 해도 됨. (더 직관적)

    // typedef 부분도 모두 using rat = Ratio<2, 3>; 으로 해도 됨.

    std::cout << rat3::num << " / " << rat3::den << std::endl;
}

int main(){
    using r1 = Ratio<2, 3>;
    using r2 = Ratio<3, 2>;

    using r3 = Ratio_add<r1, r2>;
    std::cout << "2/3 + 3/2 = " << r3::num << " / " << r3::den << std::endl;

    using r4 = Ratio_multiply<r1, r3>;
    std::cout << "13 / 6 * 2 /3 = " << r4::num << " / " << r4::den << std::endl;

    return 0;
}