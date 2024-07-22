// 교재 31 page ~
// Edit2(template method) vs Edit3(Strategy)

// Edit2.cpp
// 핵심 : NumEdit 가 "Edit 기능 + Validation 기능" 을 모두 포함
// 특징 #1. 실행시간에 validation 정책을 교체 할수 없다
//			NumEdit 클래스 자체가 정책 소유

// 특징 #2. NumEdit 외에 다른 클래스는 Validation 정책 사용못함
//         => Validation 정책은 NumEdit 소유


// Edit3.cpp
// Edit 기능과 Validation 기능이 별도의 클래스로 분리된 모델
// 특징 #1. 실행시간에 validation 정책을 교체 할수 있다.
//        => e.set_validator(&v1);
//        => e.set_validator(&v2);
// 
// 특징 #2. Edit 외에 다른 클래스도 Validation 정책 클래스 사용가능

// 유연성, 재활용성에서는 Edit3.cpp 가 좋습니다.
// 
// -----------------------------
// 그런데!

class Shape
{
public:
	void draw()
	{
		//....
		draw_imp();
		//....
	}
	virtual void draw_imp() = 0;
};

class Rect : public Shape
{
public:
	void draw_imp()
	{
		// 그림을 어떻게 그릴지 정책
		// 1. 이 정책은 Rect 만 사용하면 된다. 다른 곳에서는 필요 없다.
		// 2. 이 정책은 실행시간에 변경될 필요도 없습니다.
		// 3. 그리고, 정책을 담은 이 함수는 멤버 함수 입니다.
		//    => private 멤버 접근 가능합니다.
		//    => strategy 패턴은 별도의 클래스로 분리되므로 private 멤버접근 안됨.
	}
};

// 도형편집기 예제
// => 변하는 것을 "가상함수로(draw_imp)" 가 좋습니다.
// => template method 로 하라는 것!!

// Edit 예제
// => 변하는 것을 "다른 클래스로(IValidator인터페이스를 구현하는 클래스)" 가 좋습니다.
// => 즉, strategy pattern 을 사용하라는 것!