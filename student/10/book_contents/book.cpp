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
    }
    else{
        std::cout << "Error: Not found: " << params[0] << std::endl;
    }
}

void Book::openAll(Params params) const
{
    for (auto &ch : chapters_)
    {
        ch.second->isOpen_=true;
    }
}

void Book::printParentsN(Params params) const
{

}

void Book::printSubchaptersN(Params params) const
{

}

void Book::printSiblingChapters(Params params) const
{

}

void Book::printTotalLength(Params params) const
{


}

void Book::printLongestInHierarchy(Params params) const
{

}

void Book::printShortestInHierarchy(Params params) const
{

}

void Book::printParent(Params params) const
{

}

void Book::printSubchapters(Params params) const
{

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

