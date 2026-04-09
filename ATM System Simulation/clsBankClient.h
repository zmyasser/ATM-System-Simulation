#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"

class clsBankClient : public clsPerson
{

private:

	enum enMode { enUpdate = 0, enEmpty = 1, enAddNew = 2 };

	enMode _Mode;
	std::string _AccountNumber;
	std::string _PinCode;
	double _AccountBalance = 0;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(const std::string& Line, const std::string& Separator);
	
	static std::string _ConvertClientObjectToLine(const clsBankClient& Client, const std::string& Separator);
	
	static std::vector <clsBankClient> _LoadClientDataFromFile();
	
	void _SaveClientDataToFile(std::vector <clsBankClient>& _vClient);
	
	void _SaveClientDataToFileAfterDelete(std::vector <clsBankClient>& _vClient);
	
	static clsBankClient _GetEmptyClientObject();
	
	bool _IsEmpty() const;
	
	void _UpDate();
	
	void _AddNew();
	
	void _AddDataLineToFile(const std::string& DataLine);

	std::string _PrepareTransferRecord(const clsBankClient& DestinationClient, double Amount, const std::string& UserName, const std::string& Separator);
	
	void _TransferRegister(const clsBankClient& DestinationClient, double Amount, const std::string& UserName);
	
	struct stTransferRegisterRecord;
	static stTransferRegisterRecord _ConvertTransferRegisterLineToRecord(const std::string& Line, const std::string& Separator);
	
	std::string _PrepareClientLoginLine(const std::string& Separator);
	

public:

	struct stTransferRegisterRecord
	{
		std::string DateTime;
		std::string SourceAccount;
		std::string DestinationAccount;
		double Amount = 0;
		double SourceBalance = 0;
		double DestinationBalance = 0;
		std::string UserName;
	};

	clsBankClient(enMode Mode, const std::string &FirstName, const std::string &LastName, const std::string &Email, const std::string &Phone, 
		const std::string &AccountNumber, const std::string &PinCode, double Salary) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = Salary;

	}


	const std::string& getAccountNumber() const;
	
	void setPinCode(const std::string& PinCode);
	const std::string& getPinCode() const;
	_declspec(property(get = getPinCode, put = setPinCode)) std::string PinCode;

	void setAccountBalance(double Salary);
	double getAccountBalance() const;
	_declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;

	bool getMarkForDelete() const;
	
	bool isEmpty() const;
	
	static bool LoginApproved();
	
	static clsBankClient Find(const std::string& AccountNumber);
	static clsBankClient Find(const std::string& AccountNumber, const std::string& PinCode);
	
	static bool IsClientExist(const std::string& AccountNumber);
	static bool IsClientExist(const std::string& AccountNumber, const std::string& PinCode);
	

	enum enSaveResult { svFailedObjEmpty = 0, svSucceded = 1, svFailedAccNumExists };

	enSaveResult Save();
	
	static clsBankClient getAddNewClientObject(const std::string& AccountNumber);
	
	bool Delete();
	
	static std::vector <clsBankClient> GetClientsList();

	static double GetTotalBalances();
	
	bool Deposit(double Amount);
	
	bool Withdraw(double Amount);
	
	bool Transfer(clsBankClient& DestinationClient, double Amount, const std::string& UserName);
	
	static std::vector <stTransferRegisterRecord> GetTransferRegisterList();
	
	void RegisterClientLoginInFile();
	
	bool ChangeClientPinCode(const std::string& NewPinCode);
	
	bool ChangeClientPhone(const std::string& NewPhone);
	
	bool ChangeClientEmail(const std::string& NewEmail);
	
};

