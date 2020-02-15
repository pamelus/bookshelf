#include "book.hpp"

Book::Book(const char * title, const char * isbn, const char * publish, const char * version, int length, Writer * writer):
myDate(0), myReader(0), myTitle(StringDuplicate(title)), myIsbn(StringDuplicate(isbn)), myPublish(StringDuplicate(publish)), myVersion(StringDuplicate(version)), myLength(length), myWriter(writer) {	
	myWriter->AddBook(this);
}

Book::~Book() {
	if(myTitle) delete [] myTitle;
	if(myIsbn) delete [] myIsbn;
	if(myPublish) delete [] myPublish;
	if(myVersion) delete [] myVersion;
	if(myDate) delete [] myDate;
	
	myWriter->DeleteBook(this);
	if(myReader) myReader->DeleteBook(this);
}

void Book::OnLend(Reader * reader, const char * date) {
	reader->AddBook(this); myReader = reader;
	if(myDate) delete [] myDate;
	myDate = StringDuplicate(date);
}

void Book::OnReturn() {
	myReader->DeleteBook(this); myReader = 0;
	if(myDate) delete [] myDate;
	myDate = 0;
}
