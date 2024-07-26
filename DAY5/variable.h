// variable.h
#pragma once

// 아래 코드는 전역변수 "g" 는 만드는 것(definition, 정의)
// 가 아닙니다.
// 어딘가에 g가 있다고 이름을 알리는 것(선언, declaration) 입니다.
// 소스에 있는 전역변수 g 를 다른 파일에서도 사용가능하게 하는것
extern int g;


// C++ 17 의 inline variable
// => mutiple definition 을 허용해 달라.
// => 헤더에 전역변수를 넣어도 됩니다.
// => 최종결과인 실행파일에서 g2는 한개 입니다.
inline int g2 = 0;