// 정리

// 디자인 패턴의 핵심 #1
// => 공통성과 가변성의 분리
// => 변해야 코드는 분리하자는 것!!!


// 1. 변하는 것을 가상함수로 분리 : template method
//	  => 도형편집기 draw()/draw_imp() 예제

// 2. 변하는 것을 별도의 클래스로 분리

// 정책클래스를 어떻게 교체 할것인가 ?
// 인터페이스로 교체 : strategy
//					 Edit/IValidator 예제
// 
// 템플릿 인자로 교체 : policy base design ( C++ Idioms )
//					   std::vector<int, debug_alloc<int>> 예제!!!
//					   STL 이 대부분 이방식으로 설계..!