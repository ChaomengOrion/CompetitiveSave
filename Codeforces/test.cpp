#include <iostream>

using namespace std;

int main()
{
    system("chcp 65001");
	int x,a,b,c,d,e;
	while (cin >> x)
	{
		a = x / 10000;
		b = (x - 10000 * a) / 1000;
		c = (x - 10000 * a - 1000 * b) / 100;
		d = (x - 10000 * a - 1000 * b - 100 * c) / 10;
		e = (x - 10000 * a - 1000 * b - 100 * c - 10 * d);
		if (x<0||x<10000||x>99999)
		{
			cout << "输入不是5位正整数。"<<endl;
		}
		else cout << e << "  " << d << "  " << c << "  " << b << "  " << a << endl;
	}
	
	return 0;
}