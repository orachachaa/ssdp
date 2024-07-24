#pragma once

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

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