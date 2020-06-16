#include "Child.h"
#include <iostream>

using namespace std;


ostream& operator<<(ostream& output, const Child &child)
{
	output << child.firstName << child.lastName << child.age;
	return output;
}


Child::Child()
{
	firstName = " ";
	lastName = " ";
	age = 0;
}

Child::Child(string fName, string lName, int age) 
{
	firstName = fName;
	lastName = lName;
	this->age = age;
}

Child::~Child()
{
}


bool Child::operator< (const Child &child) const
{

		for (int i = 0; i < this->firstName.length(); i++)
		{
			if ((i + 1) > child.lastName.length())
			{
				return false;
			}
			if (this->lastName[i] < child.lastName[i])
			{
				return true;
			}
			if (this->lastName[i] > child.lastName[i])
			{
				return false;
			}
		}
	


		for (int i = 0; i < this->firstName.length(); i++)
		{
			if ((i + 1) > child.firstName.length())
			{
				return false;
			}
			if (this->firstName[i] < child.firstName[i])
			{
				return true;
			}
			if (this->firstName[i] > child.firstName[i])
			{
				return false;
			}
		
	}

	if (this->age < child.age)
	{
		return true;
	}
	return false;
}
bool Child::operator> (const Child &child) const
{

	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) > child.lastName.length())
		{
			return false;
		}
		if (this->lastName[i] > child.lastName[i])
		{
			return true;
		}
		if (this->lastName[i] < child.lastName[i])
		{
			return false;
		}
	}


	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) < child.firstName.length())
		{
			return false;
		}
		if (this->firstName[i] > child.firstName[i])
		{
			return true;
		}
		if (this->firstName[i] < child.firstName[i])
		{
			return false;
		}

	}
	if (this->age < child.age)
	{
		return true;
	}
	return false;
}
bool Child::operator<= (const Child &child) const
{
	if (*this == child)
	{
		return true;
	}
	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) > child.lastName.length())
		{
			return false;
		}
		if (this->lastName[i] < child.lastName[i])
		{
			return true;
		}
		if (this->lastName[i] > child.lastName[i])
		{
			return false;
		}
	}


	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) > child.firstName.length())
		{
			return false;
		}
		if (this->firstName[i] < child.firstName[i])
		{
			return true;
		}
		if (this->firstName[i] > child.firstName[i])
		{
			return false;
		}

	}
	if (this->age < child.age)
	{
		return true;
	}
	return false;
}
bool Child::operator>= (const Child &child) const
{
	if (*this == child)
	{
		return true;
	}

	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) > child.lastName.length())
		{
			return false;
		}
		if (this->lastName[i] > child.lastName[i])
		{
			return true;
		}
		if (this->lastName[i] < child.lastName[i])
		{
			return false;
		}
	}


	for (int i = 0; i < this->firstName.length(); i++)
	{
		if ((i + 1) < child.firstName.length())
		{
			return false;
		}
		if (this->firstName[i] > child.firstName[i])
		{
			return true;
		}
		if (this->firstName[i] < child.firstName[i])
		{
			return false;
		}

	}
	if (this->age < child.age)
	{
		return true;
	}
	return false;
}
bool Child::operator== (const Child &child) const
{
	if (firstName==child.firstName&&lastName==lastName&&this->age == child.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Child::operator!= (const Child &child) const
{
	return ! (*this == child);
}
Child Child::operator= (const Child &child)
{
	this->age = child.age;
	this->firstName = child.firstName;
	this->lastName = child.lastName;

	return *this;
}

string Child::getFirstName()const
{
	return firstName;
}
void Child::setFirstName(string name)
{
	firstName = name;
}

string Child::getLastName()const
{
	return lastName;
}

void Child::setLastName(string name)
{
	lastName = name;
}

int Child::getAge()const
{
	return age;
}

void Child::setAge(int yearsOld)
{
	age = yearsOld;
}
