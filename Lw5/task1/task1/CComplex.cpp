#include "CComplex.h"

using namespace std;

CComplex::CComplex(double real, double image)
	:m_real(real),
	m_image(image)
{
}

double CComplex::Re() const
{
	return m_real;
}

double CComplex::Im() const
{
	return m_image;
}

double CComplex::GetMagnitude() const
{
	return sqrt(pow(Re(), 2) + pow(Im(), 2));
}

double CComplex::GetArgument() const
{
	if (Re() >= 0)
	{
		return atan(Im() / Re());
	}
	else
	{
		return atan(Im() / Re() + M_PI);
	}
}

CComplex const CComplex::operator+(CComplex const& complex) const
{
	return CComplex(Re() + complex.Re(), Im() + complex.Im());
}

CComplex const CComplex::operator+(double real) const
{
	return *this + CComplex(real);
}

CComplex const CComplex::operator-(CComplex const& complex) const
{
	return CComplex(Re() - complex.Re(), Im() - complex.Im());
}

CComplex const CComplex::operator-(double real) const
{
	return *this - CComplex(real);
}

CComplex const CComplex::operator*(CComplex const& complex) const
{
	return CComplex((Re() * complex.Re()) - (Im() * complex.Im()), (Im() * complex.Re()) + (Re() * complex.Im()));
}

CComplex const CComplex::operator*(double real) const
{
	return *this * CComplex(real);
}

CComplex const CComplex::operator/(CComplex const& complex) const
{
	if (complex.NotZero())
	{
		double real = (Re() * complex.Re() + Im() * complex.Im()) / (pow(complex.Re(), 2) + pow(complex.Im(), 2));
		double image = (Im() * complex.Re() - Re() * complex.Im()) / (pow(complex.Re(), 2) + pow(complex.Im(), 2));

		return CComplex(real, image);
	}

	return *this;
}

CComplex const CComplex::operator/(double real) const
{
	return *this / CComplex(real);
}

CComplex const CComplex::operator+() const
{
	return *this;
}

CComplex const CComplex::operator-() const
{
	return CComplex(-Re(), -Im());
}

CComplex& CComplex::operator+=(CComplex const& complex)
{
	m_real += complex.Re();
	m_image += complex.Im();

	return *this;
}

CComplex& CComplex::operator-=(CComplex const& complex)
{
	m_real -= complex.Re();
	m_image -= complex.Im();

	return *this;
}

CComplex& CComplex::operator*=(CComplex const& complex)
{
	m_real = (Re() * complex.Re()) - (Im() * complex.Im());
	m_image = (Im() * complex.Re()) + (Re() * complex.Im());

	return *this;
}

CComplex& CComplex::operator/=(CComplex const& complex)
{
	if (complex.NotZero())
	{
		m_real = (Re() * complex.Re() + Im() * complex.Im()) / (pow(complex.Re(), 2) + pow(complex.Im(), 2));
		m_image = (Im() * complex.Re() - Re() * complex.Im()) / (pow(complex.Re(), 2) + pow(complex.Im(), 2));
	}

	return *this;
}

bool CComplex::operator==(CComplex const& complex) const
{
	return (fabs(Re() - complex.Re()) < DBL_EPSILON) && (fabs(Im() - complex.Im()) < DBL_EPSILON);
}

bool CComplex::operator==(double real) const
{
	return *this == CComplex(real);
}

bool CComplex::operator!=(CComplex const& complex) const
{
	return !(*this == complex);
}

bool CComplex::operator!=(double real) const
{
	return !(*this == CComplex(real));
}

ostream& operator<<(ostream& output, CComplex const& complex)
{
	if (complex.Im() >= 0)
	{
		output << complex.Re() << '+' << complex.Im() << 'i';
	}
	else
	{
		output << complex.Re() << complex.Im() << 'i';
	}

	return output;
}

istream& operator>>(istream& input, CComplex& complex)
{
	string str;
	input >> str;
	smatch matches;
	if (regex_match(str, matches, COMPLEX_REGEX))
	{
		complex = CComplex(stod(matches[1].str()), stod(matches[2].str()));
	}

	return input;	
}

bool CComplex::NotZero() const
{
	return Re() != 0 && Im() != 0;
}

CComplex const operator+(double real, CComplex const& complex)
{
	return CComplex(real) + complex;
}

CComplex const operator-(double real, CComplex const& complex)
{
	return CComplex(real) - complex;
}

CComplex const operator*(double real, CComplex const& complex)
{
	return CComplex(real) * complex;
}

CComplex const operator/(double real, CComplex const& complex)
{
	return CComplex(real) / complex;
}

bool operator==(double real, CComplex const& complex)
{
	return CComplex(real) == complex;
}

bool operator!=(double real, CComplex const& complex)
{
	return !(CComplex(real) == complex);
}
