#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit)
{
    owner_name = owner;
    is_credit_card_account = has_credit;
    credit_limit = 0;
    balance = 0;
    iban_ = "";
    generate_iban();
}

void Account::set_credit_limit(const int &credit)
{
    if(is_credit_card_account){
        credit_limit = credit;
        //std::cout << "Credit limit set: " << credit << '\n';
    }
    else
        std::cout << "Cannot set credit limit: the account has no credit card\n";
}

void Account::save_money(const int &amount)
{
    balance += amount;
}

void Account::take_money(const int &amount)
{
    if(amount > balance && !is_credit_card_account)
        std::cout << "Cannot take money: balance underflow\n";
    else if ((balance - amount)*-1 > credit_limit)
       std::cout << "Cannot take money: credit limit overflow\n";
    else{
        balance -= amount;
        std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance << " euros\n";
    }
//    if(!is_credit_card_account){
//        if(amount <= balance ){
//            balance -= amount;
//            std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance << " euros\n";
//        }
//        else{
//            std::cout << "Cannot take money: balance underflow\n";
//        }
//    }
//    else{
//        balance -= amount;
//        std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance << " euros\n";
    //    }
}

void Account::transfer_to(Account &a, const int &amount)
{
    if(amount > balance && !is_credit_card_account){
        std::cout << "Cannot take money: balance underflow\n";
        std::cout << "Transfer from " << iban_ << " failed\n";
    }
    else if ((balance - amount)*-1 > credit_limit){
        std::cout << "Cannot take money: credit limit overflow\n";
        std::cout << "Transfer from " << iban_ << " failed\n";
    }
    else{
        balance -= amount;
        a.balance += amount;
        std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance << " euros\n";
    }

//    if(amount <= balance){
//        balance -= amount;
//        a.balance += amount;
//        std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance << " euros\n";
//    }
//    else{
//        std::cout << "Cannot take money: balance underflow\n";
//        std::cout << "Transfer from " << iban_ << " failed\n";
//    }

}

void Account::print(){
    std::cout << owner_name << " : " << iban_ << " : " << balance << " euros\n";
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
