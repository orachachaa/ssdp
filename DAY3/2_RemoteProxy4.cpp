// 32bit ȯ�濡�� ������ �ؾ� �մϴ�. 
// => "x64" �� �ƴ� "x86"

#define USING_GUI
#include "cppmaster.h"

#include "ICalc.h"



int main()
{
	//Calc* calc = new Calc;

	//ICalc* calc = new ?
	ICalc* calc = load_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;
}





