#ifndef BOOK_HH
#define BOOK_HH
#include "date.hh"
#include <string>
#include <iostream>

class Book
{
  public:
    Book (std::string const &author,std::string const &title);
    void print() const;
    void loan (Date const &date);
    void renew();
    void give_back();

   private:
    std::string author_;
    std::string title_;
    Date loandate_;
    Date duedate_;
    bool is_loaned_ = false;

};

#endif // BOOK_HH
