// 컴파일러 : 각 소스파일을 object file로 변경하는 역할.
// 링커 : 모든 object file을 하나의 object file(executabel file)로 합침
// 로더 : executable file을 읽음, 메인 메모리에 object file에 있는 내용들을 올리고
// context들을 만들고 프로그램을 실행시킬 수 있도록 함.

// 프로그램이 빌드가 되는 과정은,
// 각각의 소스 파일들이 오브젝트 파일로 변환이 되고 (컴파일 됨)
// 링커가 여러개의 object file들을 묶어 하나의 executable file을 만듬
// 이렇게 생긴 exe 파일을 실행시키면 OS의 로더에 의해 메모리에 할당되게 되며
// 그 프로세스들에게 필요한 context 들이 생겨나며 프로그램이 실행되게 됨.

// 링커에서 하나의 프로그램으로 묶을때 문제가 발생하게 되는데,
// 소스파일은 여러개로 쪼개져 있고, 링킹 하기 전 오브젝트 파일도 여러개로 쪼개져 있어 컴파일러가 한 오브젝트 파일을 만지고 있는 동안, 다른 오브젝트 파일의 symbol 주소를 알수 없음.
// 이 이것을 cross-reference라고 하며, 이것을 해결하는게 링커의 몫임.

// 컴파일러가 심볼을 읽게 되면, 그 심볼에 해당하는 진입점을 심볼테이블에 넣고
// 그 심볼의 주소를 알수 있다면 section 주소와 offset으로 채워넣음. (이러한 주소를 internal reference라고 함.)
// 이때 주소를 알 수 있다는 것은 자신과 같은 오브젝트 파일을 생성할때 알 수 있음. 

// relocation table
// section 시작 주소 + offset주소로 파악된 심볼 주소를 PC relative 한주소로 변환함. (PC 상대 주소로 변환함)
// 전체 section의 위치가 변경되어도, PC로 부터의 상대적인 주소는 바뀌지 않기 때문임.
// 그래서 call local_func -> call PC+0x1B와 같이 PC realative 한 주소로 변환하여 사용함.

// Cross reference는, 링커가 cross reference들의 주소를 모르기 때문에, 모른다고 체크(0으로 채움) 해두고 internal reference를 우선으로 처리함.
// call printf -> call 0x0
// 추가적으로 relocation table에 이 cross reference 의 위치를 기입해둠.

