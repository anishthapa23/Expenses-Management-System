#include <iostream>
#include <cstring>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <map>
#include <conio.h> 
#include <iomanip> // Required for setw
using namespace std;

// Function to set console text color
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to display a header
void displayHeader(const string& title) {
    setColor(11); // Light cyan
    cout << "\n\t\t\t\t\t\t\t" << title << endl;
    cout << "\t\t\t\t\t\t\t";
    for (int i = 0; i < title.length(); ++i) cout << "=";
    cout << endl;
    setColor(7); // Reset to default color
}
void display(const string& title) {
    setColor(4); 
    cout << title << endl;
    for (int i = 0; i < title.length(); ++i) cout << "=";
    cout << endl;
    setColor(7); // Reset to default color
}
void dis(const string& title) {
    setColor(6); // Light cyan
    cout << title << endl;
    for (int i = 0; i < title.length(); ++i) cout << "=";
    cout << endl;
    setColor(7); // Reset to default color
}



class addItem {
private:
    int confirm;
    double price;
    string item, date;

public:
    void converter() {
        system("cls");
        double npr, usd, cnd, yen, aud, ind, yuan;
        displayHeader("Currency Converter");
        cout << "Enter amount in NPR: ";
        cin >> npr;
        system("cls");
        displayHeader("Currency Conversion Result");
        usd = npr / 138.36;
        cnd = npr / 96.15;
        yen = npr / 0.89;
        aud = npr / 86.76;
        ind = npr / 1.60;
        yuan = npr / 19.02;
        cout << "USD = $" << usd << "/-\t\tCanadian Dollar = $" << cnd << "/-\t\tJapanese Yen = " << yen << "/-" << endl;
        cout << "Australian Dollar = $" << aud << "/-\t\tIndian Rupees = Rs." << ind << "/-\t\tChinese Yuan = " << yuan << "/-" << endl;
        Sleep(10000);
    }

    void authenticate() {
        int choice;
        while (true) {
            displayHeader("Authentication");
            cout << "1. Login" << endl;
            cout << "2. Sign Up" << endl;
            cout << "3. Forgot Password" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice >= 1 && choice <= 4) break;
            cout << "Please enter between (1-4)!" << endl;
        }

        system("cls");
        switch (choice) {
            case 1: login(); break;
            case 2: signUp(); break;
            case 3: forgotPassword(); break;
            case 4: exit(0);
        }
    }

    void login() {
        displayHeader("Login");
        fstream fio;
        string uname, loginpass;
        char password[50], shows;
        int forgot;
        cout << "Username: ";
        fflush(stdin);
        getline(cin, uname);

        cout << "Password: ";
        fflush(stdin);
        int j = 0;
        char pw;
        while ((pw = _getch()) != 13) {
            if (pw == 8) {
                if (j > 0) {
                    j--;
                    cout << "\b \b";
                }
            } else {
                password[j] = pw;
                j++;
                cout << "*";
            }
        }
        password[j] = '\0';
        cout << endl << "Show Password[Y/N]? ";
        cin >> shows;
        if (shows == 'Y' || shows == 'y') cout << "Password: " << password << endl;

        fstream fir;
        fir.open("authenticationdb.txt", ios::in);
        if (fir.is_open()) {
            string fileUsername, filePassword, fname, mname, lname, dob, phone;
            bool loginSuccess = false;

            while (getline(fir, fileUsername)) {
                getline(fir, filePassword);
                getline(fir, fname);
                getline(fir, mname);
                getline(fir, lname);
                getline(fir, dob);
                getline(fir, phone);

                if (uname == fileUsername && strcmp(password, filePassword.c_str()) == 0) {
                    cout << "\t\t\t\t Logged in Successfully! " << endl;
                    Sleep(2000);
                    loginSuccess = true;
                    break;
                }
            }

            if (!loginSuccess) {
                cout << "\t\t\t\t Incorrect Password! " << endl;
                cout << "Forgot Password? (Press 1 to Confirm 0 to Cancel)" << endl;
                cin >> forgot;
                if (forgot == 1) forgotPassword();
                else authenticate();
            }

            fir.close();
        } else cout << "Error opening file!" << endl;
    }

    void signUp() {
        displayHeader("Sign Up");
        string fname, lname, mname, username, dob;
        char pass[50], rpass[50], show;
        int skip;
        long long int phone;
        cout << "Enter your First Name: ";
        fflush(stdin);
        getline(cin, fname);
        cout << "Enter your Middle Name: (0-Skip & 1-Enter)" << endl;
        cin >> skip;
        fflush(stdin);
        if (skip == 1) {
            cout << "Enter your Middle Name: ";
            getline(cin, mname);
        } else mname = "";
        cout << "Enter your Family Name: ";
        getline(cin, lname);
        fflush(stdin);
        cout << "Enter your Date of Birth (YYYY/MM/DD): ";
        cin >> dob;
        fflush(stdin);
        cout << "Enter your Phone Number: ";
        cin >> phone;
        fflush(stdin);
        cout << "Username: ";
        fflush(stdin);
        getline(cin, username);
        fflush(stdin);
        cout << "Password: ";
        fflush(stdin);
        int j = 0;
        char ch;
        while ((ch = _getch()) != 13) {
            if (ch == 8) {
                if (j > 0) {
                    j--;
                    cout << "\b \b";
                }
            } else {
                pass[j] = ch;
                j++;
                cout << "*";
            }
        }
        pass[j] = '\0';

        cout << endl << "Show Password[Y/N]? ";
        cin >> show;
        if (show == 'Y' || show == 'y') cout << "Password: " << pass << endl;

        int i = 0;
        cout << "Re-enter to confirm: ";
        while ((ch = _getch()) != 13) {
            if (ch == 8) {
                if (i > 0) {
                    i--;
                    cout << "\b \b";
                }
            } else {
                rpass[i] = ch;
                i++;
                cout << "*";
            }
        }
        rpass[i] = '\0';

        cout << endl << "Show Password[Y/N]? ";
        cin >> show;
        if (show == 'Y' || show == 'y') cout << "Password: " << rpass << endl;

        if (strcmp(rpass, pass) != 0) {
            cout << "Re-entered password is incorrect!" << endl;
            cout << "Please try again." << endl;
            Sleep(1000);
            system("cls");
            authenticate();
            return;
        }

        cout << "Password setup successful!" << endl;

        fstream fio;
        fio.open("authenticationdb.txt", ios::app | ios::out);
        if (fio.is_open()) {
            fio << username << endl;
            fio << pass << endl;
            fio << fname << endl;
            fio << mname << endl;
            fio << lname << endl;
            fio << dob << endl;
            fio << phone << endl;
            fio.close();
            cout << "Sign Up Successful! Please login to continue." << endl;
        } else cout << "Error opening file!" << endl;

        Sleep(10000);
        system("cls");
        authenticate();
    }

    void forgotPassword() {
        displayHeader("Forgot Password");
        fstream fio;
        string uname, newPassword;
        char npass[50], nrpass[50], show;
        long long int phone;
        cout << "Enter your Phone Number: ";
        cin >> phone;

        fio.open("authenticationdb.txt", ios::in);
        if (fio.is_open()) {
            string fileUsername, filePassword, fname, mname, lname, dob, filePhone;
            bool userFound = false;

            while (getline(fio, fileUsername)) {
                getline(fio, filePassword);
                getline(fio, fname);
                getline(fio, mname);
                getline(fio, lname);
                getline(fio, dob);
                getline(fio, filePhone);

                if (stoll(filePhone) == phone) {
                    userFound = true;
                    cout << "Enter your New Password: ";
                    int j = 0;
                    char ch;
                    while ((ch = _getch()) != 13) {
                        if (ch == 8) {
                            if (j > 0) {
                                j--;
                                cout << "\b \b";
                            }
                        } else {
                            npass[j] = ch;
                            j++;
                            cout << "*";
                        }
                    }
                    npass[j] = '\0';

                    cout << endl << "Show Password[Y/N]? ";
                    cin >> show;
                    if (show == 'Y' || show == 'y') cout << "Password: " << npass << endl;

                    int i = 0;
                    cout << "Re-enter to confirm: ";
                    while ((ch = _getch()) != 13) {
                        if (ch == 8) {
                            if (i > 0) {
                                i--;
                                cout << "\b \b";
                            }
                        } else {
                            nrpass[i] = ch;
                            i++;
                            cout << "*";
                        }
                    }
                    nrpass[i] = '\0';

                    cout << endl << "Show Password[Y/N]? ";
                    cin >> show;
                    if (show == 'Y' || show == 'y') cout << "Password: " << nrpass << endl;

                    if (strcmp(nrpass, npass) != 0) {
                        cout << "Re-entered password is incorrect!" << endl;
                        cout << "Please try again." << endl;
                        Sleep(1000);
                        system("cls");
                        forgotPassword();
                        return;
                    }

                    cout << "New Password setup successful!" << endl;

                    fstream tempFile;
                    tempFile.open("temp.txt", ios::out);
                    fio.close();
                    fio.open("authenticationdb.txt", ios::in);

                    while (getline(fio, fileUsername)) {
                        getline(fio, filePassword);
                        getline(fio, fname);
                        getline(fio, mname);
                        getline(fio, lname);
                        getline(fio, dob);
                        getline(fio, filePhone);

                        if (stoll(filePhone) == phone) {
                            tempFile << fileUsername << endl;
                            tempFile << npass << endl;
                        } else {
                            tempFile << fileUsername << endl;
                            tempFile << filePassword << endl;
                        }
                        tempFile << fname << endl;
                        tempFile << mname << endl;
                        tempFile << lname << endl;
                        tempFile << dob << endl;
                        tempFile << filePhone << endl;
                    }

                    fio.close();
                    tempFile.close();

                    remove("authenticationdb.txt");
                    rename("temp.txt", "authenticationdb.txt");

                    cout << "Password updated successfully!" << endl;
                    Sleep(1000);
                    system("cls");
                    authenticate();
                    return;
                }
            }

            if (!userFound) {
                cout << "User not found!" << endl;
                Sleep(1000);
                system("cls");
                authenticate();
            }

            fio.close();
        } else cout << "Error opening file!" << endl;
    }
};
class view {
	public:

    int choices() 
	{
        int choice;
        while (true) {
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Select an option (1/2): ";
            cin >> choice;
            if (choice == 1 || choice == 2) {
                return choice;
            }
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }
    }
	
	void printBillHeader() 
	{
	    cout << "=============================================" << endl;
	    	dis("|               EXPENSE BILL                |");
	    cout << "=============================================" << endl;
	  		dis("| Expense Category          | Amount        |");
	    cout << "=============================================" << endl;
	}

	void printBillFooter(double total,double value)
	{
	    cout << "=============================================" << endl;
	    cout<< "| Total                     | "<< setw(12) << total << " |" << endl;
	    cout << "=============================================" << endl;
		cout << "| " << setw(25) <<"Income"<< " | " << setw(12) << right << value << " |" << endl;
		cout << "=============================================" << endl;
	    Sleep(10000);
	}
    void mainview() {
		        long long int num;
		    cout << "Enter your Registered number: ";
		    cin >> num;
		    system("CLS");
		    string filename = "expenses_" + to_string(num) + ".txt";
		
		    ifstream fin(filename);
		    if (!fin.is_open()) {
		        cout << "File Does Not Exist!" << endl;
		        cout << "Do you want to search again? " << endl;
		        int conf = choices();
		        if (conf == 1) {
		            // Assuming this is inside a loop, otherwise, you need to handle the loop logic
		            // continue;
		        } else {
		            cout << "Terminated." << endl;
		            exit(0);
		        }
		    } else {
		        cout << "Your current expenses..." << endl;
		        printBillHeader();
		
		        string line;
		        double total = 0.0;
		        double value;
		        while (getline(fin, line)) {
		            stringstream ss(line);
		            string key;
		            double amount;
		            getline(ss, key, '=');
		            ss >> amount;
		        	if(key=="income")
		        	{
		        		 value = amount;
					}
		    		if(key!="income")        
		    		{
		    			cout << "| " << setw(25) <<key<< " | " << setw(12) << right << amount << " |" << endl;
		    			total +=amount;
					}
		    }
		        fin.close();
			
		        printBillFooter(total,value);
            }
       }
} ;
class Exp:public view,public addItem
{
public:
    map<string, int> expenses;

    string filename;

    void file() {
    	system("CLS");
        long long int phone;
        displayHeader("Number");
        display("NOTE:Please remember this number for future reference.");
		 
        cout << "Enter your phone number again: ";
        cin >> phone;
        filename = "expenses_" + to_string(phone) + ".txt";
   		Sleep(500);
        
    }

    int choices() {
        int choice;
        while (true) {
            cout << endl<<"1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Select an option (1/2): ";
            cin >> choice;
            if (choice == 1 || choice == 2) {
                return choice;
            }
            cout << "Invalid choice! Please enter 1 or 2." << endl;
        }
    }

    void income() {
        int income;
        system("CLS");
        displayHeader("Income");
        cout << "Have you already entered your income? " << endl;
        int choice = choices();

        if (choice == 2) {    
            cout << "Enter your total income: ";
            cin >> income;
            system("CLS");
			 displayHeader("EMI");
            cout << "Do you have to pay any monthly installment? ";
            int choice1 = choices();
            system("CLS");

            if (choice1 == 1) {
                int loan;
                cout << "Enter your monthly installment amount: ";
                cin >> loan;
                income -= loan;
                system("CLS");
                cout << "Your total income after deducting monthly installment is: " << income << endl;
            }

            ofstream fin;
            fin.open(filename, ios::out);
            if (fin.is_open()) {
                fin << "income=" << income << endl;
                fin.close();
            } else {
                cout << "Error opening file!" << endl;
            }
			
            tracking();
        } else {
        	system("CLS");
            tracking();
        }
    }

    void tracking()
	 {
	 	displayHeader("Tracking");
        cout << "Do you want to start tracking expenses? ";
        int choice2 = choices();
        if (choice2 == 1) {
        			up:
					system("CLS");
					displayHeader("Add Expenses");
	                cout << "1. Housing" << endl;
	                cout << "2. Groceries" << endl;
	                cout << "3. Healthcare" << endl;
	                cout << "4. Education" << endl;
	                cout << "5. Transportation" << endl;
	                cout << "6. Entertainment" << endl;
	                cout << "7. Miscellaneous" << endl;
	                cout << "8. Exit" << endl;
	                cout << "Enter your choice: ";
	                int expenseChoice;
	                cin >> expenseChoice;
	
	                	if (expenseChoice<=0||expenseChoice>8) 
	    				{
					    	system("CLS");
					    	display("INVALID CHOICE");
					    	display("Enter the number between 1-8.");
        					Sleep(1000);
				    		goto up;
				        }
					
	                switch (expenseChoice) {
	                    case 1: addExpense("Housing"); break;
	                    case 2: addExpense("Groceries"); break;
	                    case 3: addExpense("Healthcare"); break;
	                    case 4: addExpense("Education"); break;
	                    case 5: addExpense("Transportation"); break;
	                    case 6: addExpense("Entertainment"); break;
	                    case 7:{
	                    	string app;
		                    cout<<"Enter your expenses type: ";
		                    cin>>app;
							addExpense(app); 
							break;
						}
	
	                    case 8: 
						{
							displayHeader("You are Terminated");
							Sleep(2000);
							exit(0);
							break;
						}
	                }
                
        } else cout << "YOU ARE TERMINATED!" << endl;
    }
	int imp()
	{
		while(true)
		{
			system("CLS");
			jmp:
			int select;
	        displayHeader("Expenses Tracker");
	        cout << "1. Add Expenses" << endl;
	        cout << "2. View Expenses" << endl;
	        cout << "3. Edit or Delete Expenses" << endl;
	        cout << "4. Currency Converter" << endl;
	        cout << "5. Exit" << endl;
	        cout << "Enter the number you want to access: ";
	   		cin >> select;
			if (select <=0 && select >= 5) 
			{
                display("INVALID CHOICE");
               goto jmp;
            }
          switch (select) {
		        case 1: 
		        	{
			         file();
			         income();
			            break;
					}
		           
		        case 2:
		        	{
		    			mainview();
		                break;
					}
		        case 3:
		            edit();
		            break;
		        case 4:{
		            converter();
					break;
				}
				case 5:
					display("You are terminated");
					exit(0);
					
		    }
    }
  }
  
  	void edit()
			{
				long long int num;
				string filename;
				system("CLS");
			    displayHeader("Edit or Delete");
				cout<<"Enter your registered number: "<<endl;
				cin>>num;
				filename = "expenses_" + to_string(num) + ".txt";
			    ifstream fin(filename, ios::in);
			    if (!fin) {
			        cout << "FILE DOES NOT EXIST, CREATING NEW FILE..." << endl;
			        return;
			    }
			
			    string get;
			    string key;
			    int amount;
			    string cet;
			     int val;
			    while (getline(fin, get))
				 {
			        stringstream ss(get);
			        getline(ss, key, '=');
			        ss >> amount;
			        expenses[key] = amount;
			    }
			    cout<<"Enter which category you want to edit: ";
			    cin>>cet;
			    if( expenses.find(cet) != expenses.end())
			   {
			   		if(expenses[cet] >= amount)
			   		{	
			   			val = expenses[cet];
			   			expenses.erase(cet);
			   			display("Removed Successfully");
					}
			   }
			    fin.close();
			    int value ;
			    int cet2;
			   addExpense(cet);
	}
	
    void writeFile() 
	{
        ofstream fout(filename,ios::out|ios::app);
        if (fout.is_open()) {
            for (auto &expense : expenses) {
                fout << expense.first << "=" << expense.second << endl;
            }
            fout.close();
        } 
		else 
		{
            cout << "Error opening file!" << endl;
        }
    }

    void addExpense(string category) {
        int amount;
        cout << "Enter your amount for " << category << ": ";
        cin >> amount;
        Sleep(2000); 
        expenses[category] = amount;
        display("Your expences has been added");
        cout <<endl<< "Amount in " << category << ": " << expenses[category] << endl;
       Sleep(1000);
        writeFile();
    }
};
int main() {
	addItem obj;
	view obj2;
    int select;
    obj.authenticate();
	Exp obj3;
	obj3.imp();
	return 0;
}


