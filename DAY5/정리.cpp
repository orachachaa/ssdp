// 핵심 #1. 변하는 코드를 분리

/// 1. 변하는 것을 가상함수로 분리
// => template method
// => facory method
// => static factory method - Gof 패턴은 아님

/// 2. 변하는 것을 다른 클래스로 분리
// => 실행시간 교체, 정책을 다른 클래스도 사용가능..

// 변하는 거을 담은 클래스를 어떻게 교체 할것인가 ?
// => interface로 교체 : strategy, state, builder
// => template 인자로 교체 : policy base design

// 핵심 #2. 공통의 기반 클래스를 만들어서 같이 보관하는 것!

// composite : 재귀적 포함을 사용한 "복합객체" 만들기
// decorator : 재귀적 포함을 사용한 "객체에 동적인 기능 추가" 만들기
//              FileStream / ZipDecorator 예제

// 핵심 #3. 주어진 문제를 해결하기 위해 간접층을 만드는 것

// 사용자 ===== stack ========> list
//                  => adapter : 인터페이스 변경을 위한 중간층

// 사용자 ===== MP3 ========> IMP3
//                  => bridge : 구현과 추상의 상호 독립적 update
 
// 사용자 ===== TCPServer ========> Socket, IPAddress
//                  => facade : 사용하기 쉽게 하는 포괄적 개념의 클라이언트

// 사용자 ===== Cacl ========> 계산기 서버
//                  => proxy : 대행자를 만들어서 다양하게 활용가능

// 핵심 #4. 다양한 기능을 구현하기 위한 전형적인 코딩 기술들..

// Undo/Redo
// command : 명령의 취소 => WPF의 메뉴처리
// memento : 객체의 상태 저장

// 통보/전달
// observer : 등록된 모든 객체에 전달
// chain of responsibility : 처리되지 않은 경우 차례대로 전달

// 열거/방문
// iterator : 복합개체의 요소를 순차적으로 "접근"
// visitor  : 복합개체의 요소에 동일한 "연산을 수행"

// #5. Design Pattern Catalog - 교재 마지막 페이지
// => 분류 자체는 중요하지는 않고, 약간 모호하다는 평가

// 생성 패턴 5가지
// singleton : 한개만 만들게 하자.
// prototype : 견본을 만들고 복사를 통해 생성
// abstract factory : 공장도 인터페이스 부터
// factory method : 객체를 만들기 위한 순수 가상함수!!
// builder : 복잡한 객체를 만드는데, 공정은 동일하지만, 각 공정의 결과는 다르다.

// 구조 패턴 7가지
// 재귀점 포함 2개 : composite, decorate
// 간접층          : adapter, proxy, facade, bridge
// 속성이 동일하면 공유 : flyweight

// 행위 패턴 11가지
// 변하는 것 분리 : strategy, state, template method
// undo/redo      : command, mementor
// 전달/통보/열거/방문 : observer, chain of responsibiliter, iterator, visitor

// 중재자를 만들자 : mediator

// 컴파일러 만들때 사용했던 패턴 : iterpreter
