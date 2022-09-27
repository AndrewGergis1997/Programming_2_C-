#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    // More methods
    void set_credit_limit(const int &credit);
    void save_money(const int &amount);
    void take_money(const int &amount);
    void transfer_to(Account &a, const int &amount);
    void print();

private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
    int credit_limit;
    int balance;
    bool is_credit_card_account;

    std::string owner_name;
    std::string iban_;
};

#endif // ACCOUNT_HH
