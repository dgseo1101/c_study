#include <iostream>
#include <fstream>
#include "json2.hpp"

using namespace namespace_json_2;

int main(){
    std::ifstream in("dgseo.json");

	auto s = JObject::Parse(in); // 이 함수를 통하여 json file을 parsing함.
	std::cout << "이름 : " << (*s)["이름"] << std::endl;	
	std::cout << "나이 : " << (*s)["나이"] << std::endl;
	std::cout << "성별 : " << (*s)["성별"] << std::endl;
	std::cout << "주소 : " << (*s)["주소"] << std::endl;
	std::cout << "배열 : " << (*s)["배열"] << std::endl;
	std::cout << "오브젝트 : " << (*s)["오브젝트"] << std::endl;
	std::cout << "오브젝트 안 인자 한개: " << find((*s)["오브젝트"], "주소") << std::endl;
	std::cout << "오브젝트 안 인자 여러개: " << find((*s)["오브젝트"], "나이, 성별, 이름") << std::endl;
	std::cout << "배열 인자 하자: " << find((*s)["배열"], "0") << std::endl;
	std::cout << "배열 인자 여러개: " << find((*s)["배열"], "0, 1, 2") << std::endl;
	

    return 0;
}