#include "clsPerson.h"
#include <iostream>

void clsPerson::setFirstName(const std::string& FirstName)
{
	_FirstName = FirstName;
}

const std::string& clsPerson::getFirstName() const
{
	return _FirstName;
}

void clsPerson::setLastName(const std::string& LastName)
{
	_LastName = LastName;
}

const std::string& clsPerson::getLastName() const
{
	return _LastName;
}


std::string clsPerson::getFullName() const
{
	return FirstName + " " + LastName;
}

void clsPerson::setEmail(const std::string& Email)
{
	_Email = Email;
}

const std::string& clsPerson::getEmail() const
{
	return _Email;
}


void clsPerson::setPhone(const std::string& Phone)
{
	_Phone = Phone;
}

const std::string& clsPerson::getPhone() const
{
	return _Phone;
}
