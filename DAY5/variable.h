// variable.h
#pragma once

// �Ʒ� �ڵ�� �������� "g" �� ����� ��(definition, ����)
// �� �ƴմϴ�.
// ��򰡿� g�� �ִٰ� �̸��� �˸��� ��(����, declaration) �Դϴ�.
// �ҽ��� �ִ� �������� g �� �ٸ� ���Ͽ����� ��밡���ϰ� �ϴ°�
extern int g;


// C++ 17 �� inline variable
// => mutiple definition �� ����� �޶�.
// => ����� ���������� �־ �˴ϴ�.
// => ��������� �������Ͽ��� g2�� �Ѱ� �Դϴ�.
inline int g2 = 0;