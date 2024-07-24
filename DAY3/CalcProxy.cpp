// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};

// ������ ���� DLL ���� �Լ��� ���鶧�� �Ʒ� ó���ؾ� �մϴ�.
extern "C" __declspec(dllexport)
ICalc* create()
{
	return new Calc;
}

// �������� C++ �����Ϸ�        : g++
// visual studio �� C++�����Ϸ� : cl
// => ������ ���۹�ư������
// => "developer Command.... " �˻� �� ����
// => ��Ÿ���� â���� cl �̶�� �Է��� ������

// ���� �ҽ��� �ִ� ������ �̵��ؼ� �Ʒ� ó�� �����ϸ� DLL �����˴ϴ�.

// cl CalcProxy.cpp   /LD   /link user32.lib  gdi32.lib  kernel32.lib

// /LD : DLL�� �����϶�� �ɼ�

// /link user32.lib  gdi32.lib  kernel32.lib : cppmaster.h ���� IPC �������ϱ⶧����
