#include <iostream>
long int ck = 0, sv = 0, tr = 0, de = 0, a, b, c, d, x, y;
char A;
int password= 1234;

//Declarations
void savings();
void checking();
void trsv();
void trck();
void dpsv();
void dpck();
void wdck();
void wdsv();
void atm();
void security();
void chpi();

//Security
void security() //adds a password, meaning only certain people can see the code
{
    std::cout << "Please enter your pin number.\n";
    int entry;
    std::cin >> entry;
    if (entry != password) {
        exit(0);
    }
}

//Checking balances of accounts
void checking() 
{
  std::cout << "Here is your checking account balance: $" << ck << "\n";
}

void savings() 
{
    std::cout << "Here is your savings account balance: $" << sv << "\n";
}

//Transferring money
void trsv()
{
  std::cout << "How much would you like to transfer? ($):\n";
  std::cin >> x;
  sv += x;
  ck -= x;
  std::cout << "Successfully transferred $" << x << " to savings.\n";
}

void trck()
{
    std::cout << "How much would you like to transfer? ($):\n";
    std::cin >> y;
    ck += y;
    sv -= y;
    std::cout << "Successfully transferred $" << y << " to checking.\n";
}

//Depositing money
void dpsv()
{
    std::cout << "How much would you like to deposit? ($):\n";
    std::cin >> a;
    sv += a;
    std::cout << "Successfully deposited $" << a << " to savings.\n";
}

void dpck()
{
    std::cout << "How much would you like to deposit? ($):\n";
    std::cin >> b;
    ck += b;
    std::cout << "Successfully deposited $" << b << " to checking.\n";
}

//Making withdrawals
void wdsv()
{
    std::cout << "How much would you like to withdraw? ($):\n";
    std::cin >> c;
    sv -= c;
    std::cout << "Successfully withdrew $" << c << " from savings.\n";
}

void wdck()
{
    std::cout << "How much would you like to withdraw? ($):\n";
    std::cin >> d;
    sv -= d;
    std::cout << "Successfully withdrew $" << d << " from checking.\n";
}

int user;
bool quit = false;

//Navigation 
void navigation() {
  std::cout << "Is there anything else you would like to do? (y/n)\n";
  std::cin >> A;
  if (A == 'y') {
    atm();
  }
  else {
    std::cout << "Have a good day!\n";
    quit = true;
  }
}

//ATM Functions
void atm() {
  std::cout << 
    "What would you like to do?:\n"<< "(1) Check savings balance\n" << "(2) Check checking balance\n" << "(3) Transfer money to savings\n" << "(4) Transfer money to checking account\n" << "(5) Deposit money to savings account\n" << "(6) Deposit money to checking account\n" << "(7) Withdraw money from savings account\n" << "(8) Withdraw money from checking account\n" << "(9) Change pin number\n";
    std::cin >> user;
  do {
        switch (user) 
    {
        case 1:
          savings();
          navigation();
          break;
        case 2:
          checking();
          navigation();
          break;
        case 3:
          trsv();
          navigation();
          break;
        case 4:
          trck();
          navigation();
          break;
        case 5:
          dpsv();
          navigation();
          break;
        case 6:
          dpck();
          navigation();
          break;
        case 7:
          wdsv();
          navigation();
          break;
        case 8:
          wdck();
          navigation();
          break;
        case 9:
          chpi();
          navigation();
          break;
    }
  }while (quit == false);
}

//Change Pincode
void chpi() {
  std::cout << "What would you like your new pin number to be?\n";
  std::cin >> password;
  std::cout << "Successfully changed your pin number.\n";
}

//ATM Interface
int main()
{
  security();
  atm();
}