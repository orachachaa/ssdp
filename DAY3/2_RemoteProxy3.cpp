#define USING_GUI
#include "cppmaster.h"

// Proxy �� Update �ɼ� �ֽ��ϴ�
// ��ü ������ ���踦 ���ؼ� �������̽��� ���� ����
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); };
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); };
};
// Proxy �� Client �����ڰ� ���� ��ü �����Ϸ��� Ŭ���� �̸��� �ʿ� �մϴ�.
// => ���Ѱ����� �˴ϴ�.

// ���� �����ڰ� Proxy �� �����ϴ� �Լ��� �����մϴ�
ICalc* create()
{
	return new Calc;
}



// Proxy �� ����� ���   : Server ������
// Proxy �� ����ϴ� ��� : Client ������

int main()
{
	// Proxy �� �Ʒ� ó�� ����ϸ� 
	// "���Ѱ���" �� �˴ϴ�.
	// ���ο� Proxy �� �����Ǹ� �Ʒ� �ڵ�� �����Ǿ�� �մϴ�.
	// OCP ����
	// Calc* calc = new Calc;

	// ���Ѱ������� ����ؾ� �մϴ�.

//	ICalc* calc = new ? ; // ? �� ��� �ؾ� �ұ�� ?
	ICalc* calc = create();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





