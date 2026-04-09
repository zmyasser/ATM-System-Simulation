#pragma once
#include <iostream>


class clsPerson
{

private:

	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;

public:

	clsPerson(const std::string &FirstName, const std::string &LastName, const std::string &Email, const std::string &Phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	void setFirstName(const std::string& FirstName);
	const std::string& getFirstName() const;
	_declspec(property(get = getFirstName, put = setFirstName)) std::string FirstName;


	void setLastName(const std::string& LastName);
	const std::string& getLastName() const;
	_declspec(property(get = getLastName, put = setLastName)) std::string LastName;


	std::string getFullName() const;


	void setEmail(const std::string& Email);
	const std::string& getEmail();
	_declspec(property(get = getEmail, put = setEmail)) std::string Email;



	void setPhone(const std::string& Phone);
	const std::string& getPhone();
	_declspec(property(get = getPhone, put = setPhone)) std::string Phone;

};

