#include "complex.h"


int main(int argc, char* argv[])
{
	complex<double> c1(1, 2);
	complex<double> c2(1, 1);

	c1 += c2;

	c2 = c1 + c2;

	cout << "c1:" << c1 << " c2:" << c2 << endl;

	if (c1 == c2)
		cout << "complex is equal" << endl;

	c1 = c1 + 2.0;

	cout << "c1 Conjugate plural: " << c1.conj() << endl;

	return 0;
}