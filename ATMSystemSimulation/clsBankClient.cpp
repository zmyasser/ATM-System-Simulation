#include "clsBankClient.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
#include "clsUtility.h"



clsBankClient clsBankClient::_ConvertLineToClientObject(const std::string& Line, const std::string& Separator = "#//#")
{
	std::vector <std::string> vClient = clsString::Split(Line, Separator);
	return clsBankClient(enMode::enUpdate, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], clsUtility::DecryptText(vClient[5]), stod(vClient[6]));
}

std::string clsBankClient::_ConvertClientObjectToLine(const clsBankClient& Client, const std::string& Separator = "#//#")
{
	std::string Data = "";
	clsBankClient tempClient = Client;

	Data += tempClient.FirstName + Separator;
	Data += tempClient.LastName + Separator;
	Data += tempClient.Email + Separator;
	Data += tempClient.Phone + Separator;
	Data += tempClient.getAccountNumber() + Separator;
	Data += clsUtility::EncryptText(tempClient.PinCode) + Separator;
	Data += std::to_string(tempClient.getAccountBalance());

	return Data;
}

std::vector <clsBankClient> clsBankClient::_LoadClientDataFromFile()
{
	std::vector <clsBankClient> _vClient;

	std::fstream MyFile;
	MyFile.open("Clients.txt", std::ios::in);

	if (MyFile.is_open())
	{
		std::string Line;

		while (getline(MyFile, Line))
		{
			clsBankClient Client = _ConvertLineToClientObject(Line);
			_vClient.push_back(Client);
		}

		MyFile.close();

	}

	return _vClient;
}

void clsBankClient::_SaveClientDataToFile(std::vector <clsBankClient>& _vClient)
{
	std::string DataLine = "";
	std::fstream MyFile;
	MyFile.open("Clients.txt", std::ios::out);

	if (MyFile.is_open())
	{

		for (const clsBankClient& Client : _vClient)
		{
			DataLine = _ConvertClientObjectToLine(Client);
			MyFile << DataLine << std::endl;
		}

		MyFile.close();
	}

}

void clsBankClient::_SaveClientDataToFileAfterDelete(std::vector <clsBankClient>& _vClient)
{
	std::string DataLine = "";
	std::fstream MyFile;
	MyFile.open("Clients.txt", std::ios::out);

	if (MyFile.is_open())
	{

		for (const clsBankClient& Client : _vClient)
		{
			if (Client._MarkForDelete == false)
			{
				DataLine = _ConvertClientObjectToLine(Client);
				MyFile << DataLine << std::endl;
			}
		}

		MyFile.close();
	}
}


clsBankClient clsBankClient::_GetEmptyClientObject()
{
	return clsBankClient(enMode::enEmpty, "", "", "", "", "", "", 0);
}


bool clsBankClient::_IsEmpty() const
{
	return (_Mode == enMode::enEmpty);
}

void clsBankClient::_UpDate()
{

	std::vector <clsBankClient> _vClient = _LoadClientDataFromFile();

	for (clsBankClient& Client : _vClient)
	{
		if (Client.getAccountNumber() == getAccountNumber())
		{
			Client = *this;
			break;
		}
	}

	_SaveClientDataToFile(_vClient);
}

void clsBankClient::_AddNew()
{
	_AddDataLineToFile(_ConvertClientObjectToLine(*this));
}

void clsBankClient::_AddDataLineToFile(const std::string& DataLine)
{
	std::fstream MyFile;
	MyFile.open("Clients.txt", std::ios::app);

	if (MyFile.is_open())
	{
		MyFile << DataLine << std::endl;
		MyFile.close();
	}
}


std::string clsBankClient::_PrepareTransferRecord(const clsBankClient& DestinationClient, double Amount, const std::string& UserName, const std::string& Separator = "#//#")
{

	std::string TransferRecord = "";

	TransferRecord += clsDate::GetSystemDateTimeString() + Separator;
	TransferRecord += getAccountNumber() + Separator;
	TransferRecord += DestinationClient.getAccountNumber() + Separator;
	TransferRecord += std::to_string(Amount) + Separator;
	TransferRecord += std::to_string(getAccountBalance()) + Separator;
	TransferRecord += std::to_string(DestinationClient.getAccountBalance()) + Separator;
	TransferRecord += UserName;


	return TransferRecord;
}

void clsBankClient::_TransferRegister(const clsBankClient& DestinationClient, double Amount, const std::string& UserName)
{

	std::string stDataLine = _PrepareTransferRecord(DestinationClient, Amount, UserName);

	std::fstream MyFile;
	MyFile.open("TransferRegister.txt", std::ios::app);

	if (MyFile.is_open())
	{

		MyFile << stDataLine << std::endl;

		MyFile.close();
	}

}


clsBankClient::stTransferRegisterRecord clsBankClient::_ConvertTransferRegisterLineToRecord(const std::string& Line, const std::string& Separator = "#//#")
{
	stTransferRegisterRecord TransferRegisterRecord;
	std::vector <std::string> vTransferRegisterRecord = clsString::Split(Line, Separator);

	TransferRegisterRecord.DateTime = vTransferRegisterRecord[0];
	TransferRegisterRecord.SourceAccount = vTransferRegisterRecord[1];
	TransferRegisterRecord.DestinationAccount = vTransferRegisterRecord[2];
	TransferRegisterRecord.Amount = stod(vTransferRegisterRecord[3]);
	TransferRegisterRecord.SourceBalance = stod(vTransferRegisterRecord[4]);
	TransferRegisterRecord.DestinationBalance = stod(vTransferRegisterRecord[5]);
	TransferRegisterRecord.UserName = vTransferRegisterRecord[6];

	return TransferRegisterRecord;
}

std::string clsBankClient::_PrepareClientLoginLine(const std::string& Separator = "#//#")
{

	std::string LoginLine;

	LoginLine += clsDate::GetSystemDateTimeString() + Separator;
	LoginLine += FirstName + Separator;
	LoginLine += LastName + Separator;
	LoginLine += clsBankClient::getAccountNumber() + Separator;
	LoginLine += std::to_string(AccountBalance);

	return LoginLine;
}


const std::string& clsBankClient::getAccountNumber() const
{
	return _AccountNumber;
}


void clsBankClient::setPinCode(const std::string& PinCode)
{
	_PinCode = PinCode;
}

const std::string& clsBankClient::getPinCode() const
{
	return _PinCode;
}




void clsBankClient::setAccountBalance(double Salary)
{
	_AccountBalance = Salary;
}

double clsBankClient::getAccountBalance() const
{
	return _AccountBalance;
}



bool clsBankClient::getMarkForDelete() const
{
	return _MarkForDelete;
}

bool clsBankClient::isEmpty() const
{
	return _IsEmpty();
}

bool clsBankClient::LoginApproved()
{
	return true;
}

clsBankClient clsBankClient::Find(const std::string& AccountNumber)
{

	std::fstream MyFile;

	MyFile.open("Clients.txt", std::ios::in);

	if (MyFile.is_open())
	{
		std::string Line;

		while (getline(MyFile, Line))
		{
			clsBankClient Client = _ConvertLineToClientObject(Line);
			{
				if (Client.getAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}

		}

		MyFile.close();
	}

	return _GetEmptyClientObject();
}


clsBankClient clsBankClient::Find(const std::string& AccountNumber, const std::string& PinCode)
{

	std::fstream MyFile;

	MyFile.open("Clients.txt", std::ios::in);

	if (MyFile.is_open())
	{
		std::string Line;

		while (getline(MyFile, Line))
		{
			clsBankClient Client = _ConvertLineToClientObject(Line);
			{
				if (Client.getAccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}

		}

		MyFile.close();
	}

	return _GetEmptyClientObject();
}


bool clsBankClient::IsClientExist(const std::string& AccountNumber)
{
	clsBankClient Client = clsBankClient::Find(AccountNumber);
	return (!Client._IsEmpty());

}

bool clsBankClient::IsClientExist(const std::string& AccountNumber, const std::string& PinCode)
{
	clsBankClient Client = clsBankClient::Find(AccountNumber, PinCode);
	return (!Client._IsEmpty());
}


clsBankClient::enSaveResult clsBankClient::Save()
{

	switch (_Mode)
	{

	case enMode::enEmpty:
	{
		if (_IsEmpty())
		{
			return enSaveResult::svFailedObjEmpty;
		}
	}

	case enMode::enUpdate:
	{
		_UpDate();
		return enSaveResult::svSucceded;
	}

	case enMode::enAddNew:
	{
		if (clsBankClient::IsClientExist(getAccountNumber()))
		{
			return enSaveResult::svFailedAccNumExists;
		}

		else
		{
			_AddNew();
			_Mode = enMode::enUpdate;
			return enSaveResult::svSucceded;
		}
	}


	}
}

clsBankClient clsBankClient::getAddNewClientObject(const std::string& AccountNumber)
{
	return clsBankClient(enMode::enAddNew, "", "", "", "", AccountNumber, "", 0);
}

bool clsBankClient::Delete()
{

	std::vector <clsBankClient> _vClient = _LoadClientDataFromFile();

	for (clsBankClient& Client : _vClient)
	{
		if (Client.getAccountNumber() == getAccountNumber())
		{
			Client._MarkForDelete = true;
			break;
		}
	}

	_SaveClientDataToFileAfterDelete(_vClient);
	*this = _GetEmptyClientObject();

	return true;
}


std::vector <clsBankClient> clsBankClient::GetClientsList()
{
	return _LoadClientDataFromFile();
}


double clsBankClient::GetTotalBalances()
{
	double TotalBalances = 0;

	std::vector <clsBankClient> vClient = _LoadClientDataFromFile();


	for (clsBankClient& Client : vClient)
	{
		TotalBalances += Client.getAccountBalance();
	}

	return TotalBalances;

}

bool clsBankClient::Deposit(double Amount)
{
	_AccountBalance += Amount;
	return Save() == svSucceded;
}

bool clsBankClient::Withdraw(double Amount)
{
	if (Amount > getAccountBalance())
	{
		return false;
	}

	else
	{
		_AccountBalance -= Amount;
		return Save() == svSucceded;
	}

}

bool clsBankClient::Transfer(clsBankClient& DestinationClient, double Amount, const std::string& UserName)
{
	if (Amount > getAccountBalance())
	{
		return false;
	}

	Withdraw(Amount);
	DestinationClient.Deposit(Amount);
	_TransferRegister(DestinationClient, Amount, UserName);
	return true;
}


std::vector <clsBankClient::stTransferRegisterRecord> clsBankClient::GetTransferRegisterList()
{
	std::vector <stTransferRegisterRecord> vTransferRegisterRecord;

	std::fstream MyFile;
	MyFile.open("TransferRegister.txt", std::ios::in);//read Mode

	if (MyFile.is_open())
	{

		std::string Line;
		stTransferRegisterRecord sTransferRegisterRecord;

		while (getline(MyFile, Line))
		{
			sTransferRegisterRecord = _ConvertTransferRegisterLineToRecord(Line);
			vTransferRegisterRecord.push_back(sTransferRegisterRecord);
		}

		MyFile.close();
	}

	return vTransferRegisterRecord;
}

void clsBankClient::RegisterClientLoginInFile()
{

	std::string ClientLoginLine = _PrepareClientLoginLine();

	std::fstream MyFile;
	MyFile.open("RegisterClientLogin.txt", std::ios::app);

	if (MyFile.is_open())
	{
		MyFile << ClientLoginLine << std::endl;
	}

	MyFile.close();
}

bool clsBankClient::ChangeClientPinCode(const std::string& NewPinCode)
{
	PinCode = NewPinCode;
	return Save() == svSucceded;
}

bool clsBankClient::ChangeClientPhone(const std::string& NewPhone)
{
	Phone = NewPhone;
	return Save() == svSucceded;
}

bool clsBankClient::ChangeClientEmail(const std::string& NewEmail)
{
	Email = NewEmail;
	return Save() == svSucceded;
}



