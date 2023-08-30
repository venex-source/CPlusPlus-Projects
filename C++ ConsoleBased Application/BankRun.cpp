#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "Account.cpp"

using namespace std;

const string ACCOUNT_NUMBER_INVALID{"\nSorry! These account number is either wrong or doesn't exist."};
const string USER_DEPOSIT_ACCOUNT{"\nHow much would you like to deposit ($0.00): "};
const string USER_INPUT_ACCOUNT_NUMBER{"\nPlease enter your account number: "};
const string LOW_AMOUNT{"\nInsufficient Amount! Please make sure you have money before any transaction."};

enum class Status{DELETE, FUND, WITHDRAW, CHECK_BALANCE};
Status bankStatus;

const void menu()
{
	cout << "Please choose an option below:\n"
		<< "\t1) Create Account\n"	
		<< "\t2) Delete Account\n"	
		<< "\t3) Check Balance\n"	
		<< "\t4) Withdraw Money\n"	
		<< "\t5) Fund Account\n"	
		<< "\t6) Transfer Money\n"
		<< "\t7) Exit\n" << endl;
}

const short userMenuChoice()
{
	short choice;
	menu();
	cout << "Please enter an option: ";
	cin >> choice;
	return choice;
}

void CreateNewAccount(vector<Account* >& account)
{
	string* name = new string;
	string* address = new string;
	int64_t* amount = new int64_t;
	
	cout << "Enter Your Name: "; cin >> *name;		
	cout << "Enter Your State: "; cin >> *address;
	cout << USER_DEPOSIT_ACCOUNT; cin >> *amount;
			
	account.push_back(new Account(*name, *address, 789, *amount));
	
	delete name;
	delete address;
	delete amount;
}

unsigned promptAccountNumber(const string& prompt)
{
	unsigned accNum;
	cout << prompt;
	cin >> accNum;
	return accNum;
}

void FundCurrentAccount(Account* currAcc)
{
	currAcc->FundOrWithdrawBalance(currAcc->promptAmount(USER_DEPOSIT_ACCOUNT));
}

void WithdrawCurrentAccount(Account* currAcc)
{
	int64_t* amount = new int64_t(currAcc->promptAmount(USER_DEPOSIT_ACCOUNT));
				
	if(currAcc->isFundSufficient(*amount)) currAcc->FundOrWithdrawBalance(-(*amount));
	else cout << LOW_AMOUNT << endl;
				
	delete amount;
}

void OptionMethodsCall(Account* userAccount)
{
	switch(bankStatus)
		{
			case Status::FUND:
				FundCurrentAccount(userAccount);
				break;
			
			case Status::DELETE:
				delete userAccount;
				cout << "\nAccount successfully deleted" << endl;
				break;
					
			case Status::WITHDRAW:
				WithdrawCurrentAccount(userAccount);
				break;
					
			case Status::CHECK_BALANCE:
				userAccount->DisplayAccountBalance();
				break;
		}
}

void LocateUserAccount(vector<Account* >& account)
{
	Account* userAccount = getUserAccount(promptAccountNumber(USER_INPUT_ACCOUNT_NUMBER), account);
	if(userAccount) OptionMethodsCall(userAccount);
	else cout << ACCOUNT_NUMBER_INVALID << endl;
	delete userAccount;
}

Account* getUserAccount(const unsigned& accNo, const vector<Account* >& account)
{
	for(Account* userAccount: account)
		if(userAccount->isAccount(accNo)) return &userAccount;
	return nullptr;
} 

void TransferMoney(vector<Account* >& account)
{
	Account* senderAccount = getUserAccount(promptAccountNumber("\nEnter the sender account number: "), account);
	if(senderAccount){
		Account* recepientAccount = getUserAccount(promptAccountNumber("\nEnter the recepient account number: "), account);
		if(recepientAccount){
			int64_t* amount = new int64_t(senderAccount->promptAmount("How much do you want to transfer: $"));
			if(senderAccount->isFundSufficient(*amount)){
				senderAccount->FundOrWithdrawBalance(-(*amount));
				recepientAccount->FundOrWithdrawBalance(*amount);
			}
			else cout << LOW_AMOUNT << endl;
			delete amount;
		}
		delete recepientAccNum;
	}
	delete senderAccNum;
	if(!senderAccount || !recepientAccount) cout << ACCOUNT_NUMBER_INVALID << endl;
}

int main(){
	
	vector<Account* > userAccount;
	
	while(true){
		switch(userMenuChoice())
		{
			case 1:
				CreateNewAccount(userAccount);	
				break;
				
			case 2:
				bankStatus = Status::DELETE;
				LocateUserAccount(userAccount);
				break;
					
			case 3:
				bankStatus = Status::CHECK_BALANCE;
				LocateUserAccount(userAccount);
				break;
				
			case 4:
				bankStatus = Status::WITHDRAW;
				LocateUserAccount(userAccount);
				break;
					
			case 5:
				bankStatus = Status::FUND;
				LocateUserAccount(userAccount);
				break;
					
			case 6:
				TransferMoney(userAccount);
				break;
					
			case 7:
				return EXIT_SUCCESS;
					
			default:
				cout << "Sorry! These is not an option. " << endl;
		}
	}
	return 0;
}
