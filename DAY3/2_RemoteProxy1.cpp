// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

// 아래 처럼 작성하면 단점이!!

// 1. 모든 Client 제작자가 IPC 기술을 알아야 합니다.
// 
// 2. 덧셈은 1, 뺄셈은 2라는 명령 코드를 외워야 합니다.(실전이라면 아주 많을것입니다.)

// 3. 서버에 장애 발생시, Client가 각각 장애 처리를 해야 합니다
//	  (서버 장애시, 백업서버에 연결 하기로 했다면, 모든 클라이언트가 따로 작업)
// 
// 4. 자주 사용되는 연산이 있을때, 매번 서버에 접속하는 것은 성능이 좋지 않습니다.
//     1+1 이 자주 요청되면 결과를 캐쉬 하면 성능향상


int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





