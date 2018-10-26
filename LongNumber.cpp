// LongNumber.cpp
// Thomas Wise
// COSC 2030
// Project01
// 26 Oct 2018

#include "LongNumber.h"

longNumber::longNumber(void)
{
	num = 0;
	overflow = 0;
	fraction = 0;
}

longNumber::longNumber(float x)
{
	*this = x;
}

longNumber::longNumber(unsigned long long int n, unsigned long long int oflow, float frac)
{
	num = n;
	overflow = oflow;
	fraction = frac;
}

longNumber::longNumber(const longNumber& x)
{
	num = x.getNum();
	overflow = x.getOverflow();
	fraction = x.getFraction();
}

unsigned long long int longNumber::getNum(void) const
{
	return num;
}

unsigned long long int longNumber::getOverflow(void) const
{
	return overflow;
}

float longNumber::getFraction(void) const
{
	return fraction;
}

void longNumber::setNum(unsigned long long int x)
{
	num = x;
}

void longNumber::setOverflow(unsigned long long int x)
{
	overflow = x;
}

void longNumber::setFraction(float x)
{
	fraction = x;
}

bool longNumber::operator>(const longNumber& right) const
{
	if (overflow > right.getOverflow())
	{
		return true;
	}
	else if (overflow < right.getOverflow())
	{
		return false;
	}
	if (num > right.getNum())
	{
		return true;
	}
	if (num < right.getNum())
	{
		return false;
	}
	if (fraction > right.getFraction())
	{
		return true;
	}
	return false;
}

longNumber longNumber::operator+(const longNumber& right) const
{
	unsigned long long int tempOverflow = overflow, tempNum = num;
	float tempFrac = fraction + right.getFraction();
	if (tempFrac >= 1)
	{
		tempNum++;
		tempFrac = tempFrac - 1;
	}
	tempNum = tempNum + right.getNum();
	if (tempNum < num || (right.getNum() == ULLONG_MAX && tempNum == num))
	{
		tempOverflow++;
		tempNum++;
	}
	return longNumber(tempNum, tempOverflow, tempFrac);
}

longNumber longNumber::operator+(float right)
{
	longNumber tempLong;
	tempLong = right;
	tempLong = tempLong + *this;
	return tempLong;
}

longNumber longNumber::operator-(const longNumber& right) const
{
	if (right > *this)
	{
		return (right - *this);
	}

	longNumber temp;

	if (fraction >= right.getFraction())
	{
		temp.setFraction(fraction - right.getFraction());
	}
	else
	{
		temp.setFraction((1 + fraction) - right.getFraction());
		if (num == 0)
		{
			temp.setNum(ULLONG_MAX);
			temp.setOverflow(overflow - 1);
		}
		else
		{
			temp.setNum(num - 1);
		}
	}

	if (num >= right.getNum())
	{
		temp.setNum(num - right.getNum());
	}
	else
	{
		temp.setNum(ULLONG_MAX - (right.getNum() - num));
		temp.setOverflow(overflow - 1);
	}
}

longNumber longNumber::operator=(const longNumber& right)
{
	num = right.getNum();
	overflow = right.getOverflow();
	fraction = right.getFraction();
	longNumber temp(num, overflow, fraction);
	return temp;
}

longNumber longNumber::operator=(float right)
{
	unsigned long long int tempOflow = 0, tempNum = right;
	float tempFrac = right - tempNum;
	longNumber temp(tempNum, tempOflow, tempFrac);
	num = temp.getNum();
	overflow = temp.getOverflow();
	fraction = temp.getFraction();
	return temp;
}

ostream& operator<<(ostream& out, const longNumber& longNum)
{
	if (longNum.getOverflow() > 0)
	{
		out << "(" << longNum.getOverflow() << ")"
			<< "(" << ULLONG_MAX << ")" << "+";
	}
	out << longNum.getNum() << "+" << longNum.getFraction();
	return out;
}

istream& operator>>(istream& in, longNumber& longNum)
{
	float input;
	in >> input;
	longNum = input;
	return in;
}