#pragma once
#include <iostream>
using namespace std;

template <typename Elem>
class complex;


/*
 * 1.������Ҫ�ı亯������ֵʱ�����ú�������Ϊ const
 * 2.������Ҫ�޸�ĳ��������ֵʱ�����ñ�������Ϊ const
 * 3.���ݲ���ʱ�����������ã��ٶȸ���
 * 4.��������ֵ�Ƿ�Ϊ���ã����Ƿ񷵻ؾֲ����������ؾֲ��������ܷ������ã���Ϊ�ֲ�������������Χ��������Զ����٣����ص���һ������ı����ռ�
 * 5.�����Ǳ����ı��������þ��Ǳ�������ָ����ָ������ı���
 * const ���ã����ô��ݣ��������ã� ��������� �������� thisָ��
 */

template <typename Elem>
class complex {
public:
	complex(Elem r = 0, Elem i = 0) :rm(r), im(i) {};
public:
	Elem getReal() const { return rm; };
	Elem getImag() const { return im; };

	complex& operator += (const complex& c);
	complex& conj();

	bool operator == (const complex& c);
private:
	Elem rm, im;

	template <typename Elem>
	friend complex<Elem>& _doapl(complex<Elem>& c1,const complex<Elem>& c2);

};

template <typename Elem>
complex<Elem>& _doapl(complex<Elem>& c1, const complex<Elem>& c2)
{
	c1.rm += c2.rm;
	c1.im += c2.im;

	return c1;
}

template <typename Elem>
inline complex<Elem>& complex<Elem>::operator += (const complex<Elem>& c)
{
	return _doapl(*this, c);
}

template <typename Elem>
inline complex<Elem>& complex<Elem>::conj()
{
	this->im = -this->im;
	return *this;
}

template <typename Elem>
ostream& operator << (ostream & o, const complex<Elem>&c)
{
	return o << "(" << c.getReal() << "," << c.getImag() << ")";
}

template <typename Elem>
inline bool complex<Elem>::operator == (const complex<Elem>& c)
{
	return (this->rm == c.rm) && (this->im == c.im);
}

template <typename Elem>
complex<Elem> operator + (complex<Elem>& c1, complex<Elem>& c2)
{
	//ʹ���๹�캯������һ����ʱ����
	return complex<Elem>(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}

template <typename Elem>
complex<Elem> operator + (complex<Elem>& c1,Elem rm)
{
	return complex<Elem>(c1.getReal() + rm, c1.getImag());
}







