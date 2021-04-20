#pragma once
#include "stdafx.h"

using namespace std;

const regex COMPLEX_REGEX("([-+]?[0-9]+(?:[.][0-9]+)?)([-+]+[0-9]+(?:[.][0-9]+)?)i");

class CComplex
{
public:
	CComplex(double real = 0, double image = 0);

	double Re() const;
	double Im() const;
	double GetMagnitude() const;
	double GetArgument() const;

	CComplex const operator +(CComplex const& complex) const;
	CComplex const operator +(double real) const;
	CComplex const operator -(CComplex const& complex) const;
	CComplex const operator -(double real) const;
	CComplex const operator *(CComplex const& complex) const;
	CComplex const operator *(double real) const;
	CComplex const operator /(CComplex const& complex) const;
	CComplex const operator /(double real) const;
	CComplex const operator +() const;
	CComplex const operator -() const;
	CComplex& operator +=(CComplex const& complex);
	CComplex& operator -=(CComplex const& complex);
	CComplex& operator *=(CComplex const& complex);
	CComplex& operator /=(CComplex const& complex);
	bool operator ==(CComplex const& complex) const;
	bool operator ==(double real) const;
	bool operator !=(CComplex const& complex) const;
	bool operator !=(double real) const;

private:
	double m_real, m_image;

	bool NotZero() const;
};

CComplex const operator +(double real, CComplex const& complex);
CComplex const operator -(double real, CComplex const& complex);
CComplex const operator *(double real, CComplex const& complex);
CComplex const operator /(double real, CComplex const& complex);
bool operator ==(double real, CComplex const& complex);
bool operator !=(double real, CComplex const& complex);
ostream& operator <<(ostream& output, CComplex const& complex);
istream& operator >>(istream& input, CComplex& complex);
