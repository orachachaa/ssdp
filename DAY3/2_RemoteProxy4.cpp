#define USING_GUI
#include "cppmaster.h"


// #1. Ŭ���̾�Ʈ �����ڴ� ���� �����ڿ��� �Ʒ� 2���� ������  �޾ƾ� �մϴ�
// ICalc.h        : �������̽��� �ִ� ����
// CalcProxy.dll  : Proxy �� �ִ� ���� ���
// 

// #2. dll �� load �ؼ� Proxy �� �����ؼ� ����ϸ� �˴ϴ�.
#include "ICalc.h"

ICalc* load_proxy()
{

}



int main()
{
	ICalc* calc = create();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





