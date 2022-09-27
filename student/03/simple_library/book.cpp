#include "book.hh"


Book::Book(const std::string &author,const std::string &title):
      author_(author),
      title_(title),
      loandate_(Date()),
      duedate_(Date())
{
  
}

void Book::print() const
{
  std::cout << author_ << " : " << title_ << std::endl;

  //check loan status
  if (is_loaned_)
    {
      std::cout << "- loaned: " ;
      loandate_.print();
      std::cout << "- to be returned" << std::endl;
      duedate_.print();
    }
  else {
      std::cout << "-avaible" << std::endl;
    }
}

void Book::loan(const Date &date)
{
     if (is_loaned_)
         {
         std::cout << "Already loaned: cannot be loaned" << std::endl;
          }
    else{
        loandate_=  date;
        duedate_ = loandate_;
        duedate_.advance(28);
        is_loaned_ = true;
    }
}


void Book::renew()
{
  if (is_loaned_)
     {
         duedate_.advance(28);
     }
    else {
            std::cout << "Not loaned: cannot be renewed" << std::endl;
    }

}

void Book::give_back()
{
  if (is_loaned_)
      {
     is_loaned_ = false;
    }
}
