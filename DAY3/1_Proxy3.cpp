int main()
{
	// 스마트 포인터는
	// => 포인터의 기능 + "AddRef, Release" 또는 "delete" 기능을 추가합니다
	// => Decrator 패턴아닌가요 ?

	// Decorator 와 Proxy 는 유사해 보입니다
	// => 기존 객체의 추가의 기능을 제공한다는 점에서
	// => DNSProxy 는 DNS 에 캐쉬기능을 추가.

	// Decorator : 객체를 생성후에 기능을 추가 하는 것, 
	//			   기능 추가 이전의 "original 객체"도 계속 사용가능

	FileStream fs("a.txt"); // 객체 생성후에
	ZipDecorator zd(&fs);   // 기능 추가
						    // original 객체인 fs도 직접 접근해서 사용가능

	// Proxy 는 대부분 "original 객체를 숨기고, 대신 사용"하는 용도 입니다.
	DNSProxy dns("www.naver.com");
	dns.get_ip();   // 내부적으로만 DNS 사용
					// 즉, 사용자에게 DNS를 사용하지 말고, Proxy 를 사용하라는것!
}