// �ٽ� #1. ���ϴ� �ڵ带 �и�

/// 1. ���ϴ� ���� �����Լ��� �и�
// => template method
// => facory method
// => static factory method - Gof ������ �ƴ�

/// 2. ���ϴ� ���� �ٸ� Ŭ������ �и�
// => ����ð� ��ü, ��å�� �ٸ� Ŭ������ ��밡��..

// ���ϴ� ���� ���� Ŭ������ ��� ��ü �Ұ��ΰ� ?
// => interface�� ��ü : strategy, state, builder
// => template ���ڷ� ��ü : policy base design

// �ٽ� #2. ������ ��� Ŭ������ ���� ���� �����ϴ� ��!

// composite : ����� ������ ����� "���հ�ü" �����
// decorator : ����� ������ ����� "��ü�� ������ ��� �߰�" �����
//              FileStream / ZipDecorator ����

// �ٽ� #3. �־��� ������ �ذ��ϱ� ���� �������� ����� ��

// ����� ===== stack ========> list
//                  => adapter : �������̽� ������ ���� �߰���

// ����� ===== MP3 ========> IMP3
//                  => bridge : ������ �߻��� ��ȣ ������ update
 
// ����� ===== TCPServer ========> Socket, IPAddress
//                  => facade : ����ϱ� ���� �ϴ� ������ ������ Ŭ���̾�Ʈ

// ����� ===== Cacl ========> ���� ����
//                  => proxy : �����ڸ� ���� �پ��ϰ� Ȱ�밡��

// �ٽ� #4. �پ��� ����� �����ϱ� ���� �������� �ڵ� �����..

// Undo/Redo
// command : ����� ��� => WPF�� �޴�ó��
// memento : ��ü�� ���� ����

// �뺸/����
// observer : ��ϵ� ��� ��ü�� ����
// chain of responsibility : ó������ ���� ��� ���ʴ�� ����

// ����/�湮
// iterator : ���հ�ü�� ��Ҹ� ���������� "����"
// visitor  : ���հ�ü�� ��ҿ� ������ "������ ����"

// #5. Design Pattern Catalog - ���� ������ ������
// => �з� ��ü�� �߿������� �ʰ�, �ణ ��ȣ�ϴٴ� ��

// ���� ���� 5����
// singleton : �Ѱ��� ����� ����.
// prototype : �ߺ��� ����� ���縦 ���� ����
// abstract factory : ���嵵 �������̽� ����
// factory method : ��ü�� ����� ���� ���� �����Լ�!!
// builder : ������ ��ü�� ����µ�, ������ ����������, �� ������ ����� �ٸ���.

// ���� ���� 7����
// ����� ���� 2�� : composite, decorate
// ������          : adapter, proxy, facade, bridge
// �Ӽ��� �����ϸ� ���� : flyweight

// ���� ���� 11����
// ���ϴ� �� �и� : strategy, state, template method
// undo/redo      : command, mementor
// ����/�뺸/����/�湮 : observer, chain of responsibiliter, iterator, visitor

// �����ڸ� ������ : mediator

// �����Ϸ� ���鶧 ����ߴ� ���� : iterpreter
