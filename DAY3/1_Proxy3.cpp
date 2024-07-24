int main()
{
	// ����Ʈ �����ʹ�
	// => �������� ��� + "AddRef, Release" �Ǵ� "delete" ����� �߰��մϴ�
	// => Decrator ���ϾƴѰ��� ?

	// Decorator �� Proxy �� ������ ���Դϴ�
	// => ���� ��ü�� �߰��� ����� �����Ѵٴ� ������
	// => DNSProxy �� DNS �� ĳ������� �߰�.

	// Decorator : ��ü�� �����Ŀ� ����� �߰� �ϴ� ��, 
	//			   ��� �߰� ������ "original ��ü"�� ��� ��밡��

	FileStream fs("a.txt"); // ��ü �����Ŀ�
	ZipDecorator zd(&fs);   // ��� �߰�
						    // original ��ü�� fs�� ���� �����ؼ� ��밡��

	// Proxy �� ��κ� "original ��ü�� �����, ��� ���"�ϴ� �뵵 �Դϴ�.
	DNSProxy dns("www.naver.com");
	dns.get_ip();   // ���������θ� DNS ���
					// ��, ����ڿ��� DNS�� ������� ����, Proxy �� ����϶�°�!
}