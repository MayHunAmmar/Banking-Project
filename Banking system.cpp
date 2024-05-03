#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>
#include<limits>
using namespace std;

class AccountDetail {
private:
    int createaccnum, createaccbal;
    string createaccname, accounttype;

public:
    AccountDetail() : accounttype(""), createaccnum(0), createaccbal(0), createaccname("") {}

    void get_AccountType(string acctype) {
        accounttype = acctype;
    }

    void get_AccountNumber(int accnum) {
        createaccnum = accnum;
    }

    void get_AccountBalance(int accbal) {
        createaccbal = accbal;
    }

    void get_createaccname(string accname) {
        createaccname = accname;
    }

    int getaccnum() {
        return createaccnum;
    }

    int getaccbal() {
        return createaccbal;
    }

    string getaccname() {
        return createaccname;
    }

    string getacctype() {
        return accounttype;
    }
};

void waitforenter(){
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    cin.get();
}

void create_account() {
    AccountDetail ad;
    system("cls");
    string accname, acctype;
    int accnum, accbal;

    cout <<endl<< "\t----------Create Account---------" << endl<<endl;
    cout << "\tEnter Account Number: ";
    cin >> accnum;
    ad.get_AccountNumber(accnum);

    cout << "\tEnter Account Holder Name: ";
    cin.ignore();
    getline(cin, accname);
    ad.get_createaccname(accname);

    cout << "\tEnter Initial Balance: ";
    cin >> accbal;
    ad.get_AccountBalance(accbal);

    cout << "\tAccount Type(C/S): ";
    cin >> acctype;
    ad.get_AccountType(acctype);

    ofstream outfile("AccountDetails.txt", ios::app);
    if (!outfile) {
        cout << "\tError: File opening error" << endl;
        return;
    }

    outfile << ad.getaccnum() << " : " << ad.getaccname() << " : " << ad.getaccbal() << " : " << ad.getacctype() << " : " << endl << endl;
    cout << "\tAccount Created successfully!" << endl;

    outfile.close();
	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();
}

void show_account() {
    int accnum, num;

    system("cls");
    cout << "\t---------------------------------" << endl;
    cout << "\t       Account Information       \n";
    cout << "\t---------------------------------\n";

    cout << "\tEnter Your Account Number: ";
    cin >> accnum;

    ifstream infile("AccountDetails.txt");
    if (!infile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string Accountnumber, accountname, accountbalance, accounttype;
        char delimiter;
        ss >> Accountnumber >> delimiter >> accountname >> delimiter >> accountbalance >> delimiter >> accounttype;
        
        stringstream(Accountnumber) >> num;
        
        if (accnum == num) {
            found = true;
            cout << "\t\tACCOUNT" << endl << endl;
            cout << "\tAccount Number: " << Accountnumber << endl;
            cout << "\tAccount Holder Name: " << accountname << endl;
            cout << "\tBalance amount: " << accountbalance << endl;
            cout << "\tType of Account : " << accounttype << endl;
            break;
        }
    }

    if (!found) {
        cout << "\n\tError: Account not found" << endl;
    }

    infile.close();
    	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();
}

void allaccholderlist() {
    system("cls");
    cout << "\t---------------------------------" << endl;
    cout << "\t  ALL ACCOUNT HOLDER LIST       \n";
    cout << "\t---------------------------------\n" << endl << endl;

        cout << "\t====================================================\n";
    cout << "\tA/c no.             NAME           Type       \n";
    cout << "\t====================================================\n" << endl;

    ifstream infile("AccountDetails.txt");
    if (!infile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string Accountnumber, accountname, accountbalance, accounttype;
        char delimiter;
        ss >> Accountnumber >> delimiter >> accountname >> delimiter >> accountbalance >> delimiter >> accounttype;
        cout << "\t" << Accountnumber << "                  " << accountname << "            " << accounttype << endl;
    }
    infile.close();
	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();
}

void Withdraw(){
		int accnum, num, amount;
	system("cls");
    cout<<"\t---------------------------------"<<endl;
    cout<<"\t          Withdraw Money        \n";
    cout<<"\t---------------------------------"<<endl;

    cout << "\tEnter Your Account Number: ";
    cin >> accnum;


    ifstream infile("AccountDetails.txt");
    ofstream outfile("AccountDetailsTemp.txt");
    if (!infile || !outfile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string accountname,  accounttype;
        int Accountnumber,accountbalance;
        char delimiter;
        ss >> Accountnumber >> delimiter >> accountname >> delimiter >> accountbalance >> delimiter >> accounttype;
        
        Accountnumber;
        
        if (accnum == Accountnumber) {
            found = true;
            cout<<"\tYour Account Balance is "<<accountbalance<<endl;
		    cout << "\n\tEnter withdrawal Amount: Rs ";
		     cin>> amount;
		     if (amount <= 0){
		     	cout << "\tInvalid Withdrawal Amount\n";
			 }
		    int newamount = accountbalance - amount ;
		    accountbalance = newamount;
		    
		    outfile <<Accountnumber << " : " << accountname << " : " << accountbalance << " : " << accounttype << " : " << endl << endl;
		    cout << "\tWithdraw Successful!\n";
        cout << "\tUpdated Balance: Rs " << accountbalance << "\n"; 
		break; 
	}
		else{
			outfile<<line<<endl;	
		}
};
	if (!found) {
        cout << "\n\tError: Account not found" << endl;
    }
	infile.close();
    outfile.close();
    remove("AccountDetails.txt");
	rename("AccountDetailsTemp.txt","AccountDetails.txt"); 		
	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();	
	};	


void Deposit(){
	int accnum, num, amount;
	system("cls");
    cout<<"\t---------------------------------"<<endl;
    cout<<"\t          Deposit Money        \n";
    cout<<"\t---------------------------------"<<endl;

    cout << "\tEnter Your Account Number: ";
    cin >> accnum;


    ifstream infile("AccountDetails.txt");
    ofstream outfile("AccountDetailsTemp.txt");
    if (!infile || !outfile) {
        cout << "\n\tError: File opening error" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        stringstream ss(line);
        string accountname,  accounttype;
        int Accountnumber,accountbalance;
        char delimiter;
        ss >> Accountnumber >> delimiter >> accountname >> delimiter >> accountbalance >> delimiter >> accounttype;
        
        Accountnumber;
        
        if (accnum == Accountnumber) {
            found = true;   
		    cout<<"\tYour Account Balance is "<<accountbalance<<endl;
		    cout << "\n\tEnter Deposit Amount: Rs ";
		     cin>> amount;
		     if (amount <= 0){
		     	cout << "\tInvalid Deposit Amount\n";
			 }
		    int newamount = accountbalance + amount ;
		    accountbalance = newamount;
		    
		    outfile <<Accountnumber << " : " << accountname << " : " << accountbalance << " : " << accounttype << " : " << endl << endl;
		    cout << "\tDeposit Successful!\n";
        cout << "\tUpdated Balance: Rs " << accountbalance << "\n"; 
		break; 
		}
		else{
			outfile<<line<<endl;	
		}
};
	if (!found) {
        cout << "\n\tError: Account not found" << endl;
    }
	infile.close();
    outfile.close();
    remove("AccountDetails.txt");
	rename("AccountDetailsTemp.txt","AccountDetails.txt"); 		
	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();	

	};

void DeleteAccount() {
    string confirmation, accnum;
    main:
    
    system("cls");
    cout << "\t---------------------------------\n";
    cout << "\t        Delete Account           \n";
    cout << "\t---------------------------------\n";
    
    cout << "\tEnter Your Account Number: ";
    cin >> accnum;
    
    ifstream infile("AccountDetails.txt");
    ofstream outfile("AccountDetailsTemp.txt");
    
    if (!infile || !outfile) {
        cout << "Error: File opening error" << endl;
        return;
    } else {
        string line;
        bool found = false;
        
        while (getline(infile, line)) {
            stringstream ss(line);
            string accountname, accounttype, Accountnumber;
            int accountbalance;
            char delimiter;
            ss >> Accountnumber >> delimiter >> accountname >> delimiter >> accountbalance >> delimiter >> accounttype;
            
            if (accnum == Accountnumber) {
                found = true;
                cout << "\t\tACCOUNT" << endl << endl;
                cout << "\tAccount Number: " << Accountnumber << endl;
                cout << "\tAccount Holder Name: " << accountname << endl;
                cout << "\tBalance amount: " << accountbalance << endl;
                cout << "\tType of Account: " << accounttype << endl << endl;
                cout << "\tAre you sure you want to delete this account? (Y/N): ";
                cin >> confirmation;
                
                if (confirmation == "N" || confirmation == "n") {
                    cout << "\tDeletion Canceled\n";
                    goto main;
                    break;
                }
                else if(confirmation == "Y" || confirmation == "ys"){
                	cout << "\tAccount Deleted\n";
				}
            } else {
                outfile << line << endl;
            }
        }
        
        if (!found) {
            cout << "\n\tError: Account not found" << endl;
        }
    }
    
    infile.close();
    outfile.close();
    remove("AccountDetails.txt");
	rename("AccountDetailsTemp.txt","AccountDetails.txt"); 		
	cout<<"\t---------------------------------"<<endl;
	cout<<"\tPress Enter To Continue...";
    waitforenter();	
}



int main() {
    int num;
    main:
    do {
        system("cls");
        cout << "\t=================================" << endl;
        cout << "\t\tBanking System" << endl;
        cout << "\t=================================" << endl;
        cout << "\t\t<--Main-Menu-->\n" << endl;
        cout << "\t(1). Create Account" << endl;
        cout << "\t(2). Account Details" << endl;
        cout << "\t(3). All Account Holder List" << endl;
        cout << "\t(4). Withdraw" << endl;
        cout << "\t(5). Deposit" << endl;
        cout << "\t(6). Delete Account" << endl;
        cout << "\t(7). Exit" << endl;

        cout << "\tEnter Option(1-6): ";
        cin >> num;

        switch (num) {
            case 1:
                create_account();
                break;
            case 2:
            	show_account();
                break;
            case 3:
            	allaccholderlist();
                break;
            case 4:
            	Withdraw();
                break;
            case 5:
            	Deposit();
                break;
            case 6:
            	DeleteAccount();
                break;
            case 7:
            cout << "\t---------Exiting Program---------" << endl;
            break;
            default:
                cout << "\tInvalid Option" << endl;
                cout << "\tPress Enter To Continue...";
                cin.ignore();
                cin.get();
        }
    } while (num != 7);
    return 0;
};

