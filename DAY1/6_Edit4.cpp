// ���� 31 page ~
// Edit2(template method) vs Edit3(Strategy)

// Edit2.cpp
// �ٽ� : NumEdit �� "Edit ��� + Validation ���" �� ��� ����
// Ư¡ #1. ����ð��� validation ��å�� ��ü �Ҽ� ����
//			NumEdit Ŭ���� ��ü�� ��å ����

// Ư¡ #2. NumEdit �ܿ� �ٸ� Ŭ������ Validation ��å ������
//         => Validation ��å�� NumEdit ����


// Edit3.cpp
// Edit ��ɰ� Validation ����� ������ Ŭ������ �и��� ��
// Ư¡ #1. ����ð��� validation ��å�� ��ü �Ҽ� �ִ�.
//        => e.set_validator(&v1);
//        => e.set_validator(&v2);
// 
// Ư¡ #2. Edit �ܿ� �ٸ� Ŭ������ Validation ��å Ŭ���� ��밡��

// ������, ��Ȱ�뼺������ Edit3.cpp �� �����ϴ�.
// 
// -----------------------------
// �׷���!

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
		// �׸��� ��� �׸��� ��å
		// 1. �� ��å�� Rect �� ����ϸ� �ȴ�. �ٸ� �������� �ʿ� ����.
		// 2. �� ��å�� ����ð��� ����� �ʿ䵵 �����ϴ�.
		// 3. �׸���, ��å�� ���� �� �Լ��� ��� �Լ� �Դϴ�.
		//    => private ��� ���� �����մϴ�.
		//    => strategy ������ ������ Ŭ������ �и��ǹǷ� private ������� �ȵ�.
	}
};

// ���������� ����
// => ���ϴ� ���� "�����Լ���(draw_imp)" �� �����ϴ�.
// => template method �� �϶�� ��!!

// Edit ����
// => ���ϴ� ���� "�ٸ� Ŭ������(IValidator�������̽��� �����ϴ� Ŭ����)" �� �����ϴ�.
// => ��, strategy pattern �� ����϶�� ��!