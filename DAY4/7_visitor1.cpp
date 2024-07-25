﻿#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거(순회)
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
// => 요소 한개에 대한 연산을 정의하고, 
// => 그연산을 모든 요소에 대해서 적용하는 것


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 방법 #1. 외부에서 모든 요소를 꺼내서 2배로!
	for (auto& e : s)
		s *= 2;

	// 방법 #2. 방문자 패턴
	TwiceVisitor<int> tv; // 요소를 2배로 하는 방문자 객체
	s.accept( &tv );	  // s의 모든 요소 방문

	ShowVisitor<int> sv;  // 요소 한개를 출력하는 방문자
	s.accept( &sv );	  // s의 모든 요소 방문(출력)


}





