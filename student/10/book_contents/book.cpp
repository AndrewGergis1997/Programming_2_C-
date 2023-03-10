/*
 * Name: Andrew Gergis
 * Student number: 150905291
 * UserID: mqange ( Necessary due to gitlab folder naming. )
 * E-Mail: andrew.gergis@tuni.fi
 */

#include "book.hh"
Book::Book()
{

}

Book::~Book()
{
  // deallocate memory
  for (std::pair<std::string, Chapter*> ch : chapters_)
    {
      delete ch.second;
    }
}

void Book::addNewChapter(const std::string &id, const std::string &fullName, int length)
{
  // check if book already exists
  if (chapters_.find(id) != chapters_.end())
    {
      std::cout<< ERROR << std::endl;
      return;
    }

  // Add new chapter
  // allocating memory
  Chapter *new_chapter = new Chapter {id, fullName, length};

  // Add to datat structure
  chapters_.insert({new_chapter->id_,
                    new_chapter});

}

void Book::addRelation(const std::string &subchapter, const std::string &parentChapter)
{
  // check if chapter exist
  if(chapters_.find(subchapter) == chapters_.end()
     || chapters_.find(parentChapter) == chapters_.end())
    return;

  // Fetch the sub chapter
  Chapter *sub_ptr = chapters_.at(subchapter),
      *parent_ptr = chapters_.at(parentChapter);

  // Add subchapter to parent
  parent_ptr->subchapters_.push_back(sub_ptr);
  sub_ptr->parentChapter_ = parent_ptr;
}

void Book::printIds(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }
  std::map<std:: string, std::string> fullChapter = {};
  std::cout << "Book has " << chapters_.size() << " chapters:" << std::endl;

  for (auto &chap : chapters_)
    {
      fullChapter.insert({chap.second->fullName_, chap.second->id_});
    }

  for (auto &ch : fullChapter)
    {
      std::cout << ch.first << " --- " << ch.second << std::endl;
    }
}

void Book::printContents(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }
  // avoid repetetive prints finding the top chapter first
  std::set<Chapter*> topmost = {};

  for (auto &ch : chapters_)
    {
      // top most chapters ----- > Doesn't have parent chapter
      if(ch.second->parentChapter_ == nullptr)
        {
          topmost.insert(ch.second);
        }
    }
  int counter = 1;
  for (Chapter *ch : topmost )
    {
      printChapterRecursively(ch, "",counter++);
    }
}

void Book::close(Params params) const
{

  Chapter *ch = findChapter(params[0]);
  if (ch != nullptr)
    {
      ch->isOpen_=false;
    }
  else{
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }

}

void Book::open(Params params) const
{
  Chapter *ch = findChapter(params[0]);
  if (ch != nullptr)
    {
      ch->isOpen_=true;
      for (Chapter *x : ch->subchapters_)
        {
          if(x->subchapters_.size() !=0)
            x->isOpen_=false;
        }
    }
  else{
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }
}

void Book::openAll(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }
  for (auto &ch : chapters_)
    {
      ch.second->isOpen_=true;
    }
}

void Book::printParentsN(Params params) const
{
  if (stoi(params[1]) < 1)
    {
      std::cout<<"Error. Level can't be less than 1."<<std::endl;
      return;
    }
  Chapter *chap = findChapter(params[0]);
  if (chap != nullptr)
    {
      if (chap->parentChapter_ == nullptr)
        {
          std::cout<< params[0] <<" has no parent chapters."<<std::endl;
          return;
        }
      std::vector<Chapter*> vec;
      int count = stoi(params[1]);
      vec.push_back(chap->parentChapter_);
      std::set<std::string> parents;
      int gen=0;
      while (vec.size() != 0 && count!=0)
        {
          parents.insert(vec.at(0)->id_);
          count--;
          if(vec.at(0)->parentChapter_ != nullptr)
          vec.push_back(vec.at(0)->parentChapter_);
          vec.erase(vec.begin());
          gen++;
        }
      std::cout << params[0] << " has " << gen << " parent chapters:" << std::endl;
      for(auto it = parents.begin(); it!=parents.end(); ++it){
          std::cout << *it << std::endl;
        }
    }
  else {
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }

}

void Book::printSubchaptersN(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }

}

void Book::printSiblingChapters(Params params) const
{
  std::set<std::string> sibChaps;
  Chapter *ch = findChapter(params[0]);
  int count = 0;
  if (ch != nullptr)
    {
      if (ch->parentChapter_ != nullptr)
        {
          std::string parent = ch->parentChapter_->id_;
          for (auto &chap : chapters_)
            {
              if (chap.second->parentChapter_ != nullptr &&
                  chap.second->parentChapter_->id_ == parent &&
                  chap.first != params[0])
                {
                  count++;
                  sibChaps.insert(chap.first);
                }
            }
          std::cout<< params[0] <<" has " << count << " sibling chapters:" << std::endl;
        }
      else
        std::cout<< params[0] <<" has no sibling chapters."<< std::endl;
      for(auto it = sibChaps.begin(); it!=sibChaps.end(); ++it){
          std::cout << *it << std::endl;
        }
    }
  else{
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }

}

void Book::printTotalLength(Params params) const
{
  Chapter *chap = findChapter(params[0]);
  int length =0;
  if (chap != nullptr)
    {
      std::vector<Chapter*> vec;
      vec.push_back(chap);
      while (vec.size() != 0)
        {
          length += vec.at(0)->length_;
          vec.insert( vec.end(), vec.at(0)->subchapters_.begin(), vec.at(0)->subchapters_.end());
          vec.erase(vec.begin());
        }
      std::cout << "Total length of " << chap->id_ << " is " << length << "." << std::endl;
    }
  else {
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }
}

void Book::printLongestInHierarchy(Params params) const
{

  Chapter *chap = findChapter(params[0]);
  int length =0;
  std::string name = "";
  if (chap != nullptr)
    {
      std::vector<Chapter*> vec;
      vec.push_back(chap);
      while (vec.size() != 0)
        {
          if( length < vec.at(0)->length_)
            {
              length = vec.at(0)->length_ ;
              name = vec.at(0)->id_;
            }

          vec.insert( vec.end(), vec.at(0)->subchapters_.begin(), vec.at(0)->subchapters_.end());
          vec.erase(vec.begin());
        }
      if (name != params[0])
        std::cout << "With the length of " << length << ", " << name <<
                     " is the longest chapter in " << params[0] << "'s hierarchy." <<std::endl;
      else
        std::cout << "With the length of " << length << ", " << name <<
                     " is the longest chapter in their hierarchy." <<std::endl;
    }
  else {
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }
}



void Book::printShortestInHierarchy(Params params) const
{
  Chapter *chap = findChapter(params[0]);
  int length;
  std::string name;
  if (chap != nullptr)
    {
       length =chap->length_;
       name = chap->id_;
      std::vector<Chapter*> vec;
      vec.push_back(chap);
      while (vec.size() != 0)
        {
          if( length > vec.at(0)->length_)
            {
              length = vec.at(0)->length_ ;
              name = vec.at(0)->id_;
            }

          vec.insert( vec.end(), vec.at(0)->subchapters_.begin(), vec.at(0)->subchapters_.end());
          vec.erase(vec.begin());
        }
      if (name != params[0])
        std::cout << "With the length of " << length << ", " << name <<
                     " is the shortest chapter in " << params[0] << "'s hierarchy." <<std::endl;
      else
        std::cout << "With the length of " << length << ", " << name <<
                     " is the shortest chapter in their hierarchy." <<std::endl;
    }
  else {
      std::cout << "Error: Not found: " << params[0] << std::endl;
    }
}

void Book::printParent(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }

}

void Book::printSubchapters(Params params) const
{
  while(0)
    {
      std::vector<std::string> trivial = params;
      trivial = {" "};
    }
}

Chapter *Book::findChapter(const std::string &id) const
{
  Chapter *chapter_ptr = nullptr;
  // check if chapter is in the book
  Data::const_iterator iter = chapters_.find(id);
  if (iter != chapters_.end())
    {
      chapter_ptr = chapters_.at(id);
    }
  return chapter_ptr;
}

void Book::printGroup(const std::string &id, const std::string &group, const IdSet &container) const
{
  while(0)
    {
      std::string trivial1 = id;
      std::string trivial2 = group;
      std::set<std::string> trivial3 = container;
      trivial1 = " ";
      trivial2 = " ";
      trivial3 = { };
    }

}

IdSet Book::vectorToIdSet(const std::vector<Chapter *> &container) const
{
  IdSet idSet = {};
  for (const Chapter *p : container)
    {
      idSet.insert(p->id_);
    }
  return idSet;
}

void Book::printChapterRecursively(const Chapter *ptr,
                                   const std::string &indents,
                                   int index) const
{
  // head recursive
  // trivial case is when chapert does not have subchapter
  char sign = ptr->isOpen_? '-' : '+';
  std::cout  << sign << " " << indents << index << ". "<<
                ptr->fullName_ << " ( " << ptr->length_ << " ) " <<
                std::endl;

  // Check if opened
  if (ptr->isOpen_)
    {
      int counter = 1;
      for (Chapter *ch : ptr->subchapters_)
        {
          printChapterRecursively(ch,
                                  indents + "  ",
                                  counter++);
        }
    }
}

