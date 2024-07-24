// ���� ������
// PointImpl.h
class PointImpl
{
	int x, y;
	int debug;

public:
	void print();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { } 






//=============================================
// �߻���(�߰���)
// Point.h

class PointImpl; // �ٽ� : ���漱�� ������ ������ ������ ���𰡴�
				// ��, �߻����� ������� �������� �����
				// ������ �ʿ� ����.
class Point
{
	// �������� ����Ű�� ������
	PointImpl* impl; 
public:
	Point();
	void print();
};

// Point.cpp
#include "PointImpl.h" // ���⼭�� ��� �ʿ�
#include "Point.h"

Point::Point() { impl = new PointImpl; }
void Point::print() { impl->print(); }



// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}




// �� �ڵ尡 C++ IDioms �� "PIMPL(Pointer to IMPlementation)" �̶�� ���
// => ������ �ð� ��ȭ��
// => �ڵ�(���)�� ��ȭ�� ���涧 �ٸ� �ҽ��� �ٽ� �����ϵǴ� ���� ���°�

// ���� 1. ������ �ð� ��������
// ���� 2. �Ϻ��� ��������, ��������ڿ��� ������ ����� ������ �ʿ� ����.
//		   �߻����� ����� �����ϸ� �ȴ�.
