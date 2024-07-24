// ICalc.h
#pragma once

// 참조 계수 기반으로 객체의 수명을 관리하기로 했다면
// 참조 계수 함수는 반드시 인터페이스 레벨에서 제공되어야 합니다.

// 다양한 서버가 있고, 다양한 PRoxy 가 있을때
// 참조계수 기능을 모두 필요 합니다.
// 참조계수 함수는 "기반 클래스(인터페이스)"로 제공합니다.

struct IRefCount
{	
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};






ICalc* load_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	using F = ICalc * (*)();

	F f = (F)ec_get_function_address(addr, "create");

	ICalc* calc = f();
	return calc;
}