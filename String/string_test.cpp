#include "string.h"

int main(int argc,char* argv[])
{
	String s1(NULL);
	String s2("Hello World!");

	String s3(s1);

	cout << s3 << endl;

	s3 = s2;

	cout << s3 << endl;

	return 0;
}