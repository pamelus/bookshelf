#include "database.hpp"

Database::Database(){
	myWriters = new Set<Writer>;
	myReaders = new Set<Reader>;
	myBooks = new SetEx<Book>;
}

Database::~Database() {
	Book * book; myBooks->ResetData();
	while(book = myBooks->GetNextData()) {
		myBooks->DeleteData(book);
		myBooks->ResetData();
		delete book;
	}
	
	Writer * writer; myWriters->ResetData();
	while(writer = myWriters->GetNextData()) {
		myWriters->DeleteData(writer);
		myWriters->ResetData();
		delete writer;
	}
	
	Reader * reader; myReaders->ResetData();
	while(reader = myReaders->GetNextData()) {
		myReaders->DeleteData(reader);
		myReaders->ResetData();
		delete reader;
	}
}

void Database::AddWriter(const char * name, const char * surname) {
	Writer * writer = new Writer(name, surname);
	myWriters->AddData(writer);
}

void Database::AddReader(const char * name, const char * surname, const char * adress, const char * telephone) {
	Reader * reader = new Reader(name, surname, adress, telephone);
	myReaders->AddData(reader);
}

void Database::AddBook(const char * title, const char * isbn, const char * publish, const char * version, int length, Writer * writer) {
	Book * book = new Book(title, isbn, publish, version, length, writer);
	myBooks->AddData(book);	
}

void Database::DeleteWriter(Writer * writer) {
	Book * book; writer->ResetBooks();
	while(book = writer->GetNextBook()) {
		this->DeleteBook(book);
		writer->ResetBooks();
	}
	myWriters->DeleteData(writer);
	delete writer;
}

void Database::DeleteReader(Reader * reader) {
	myReaders->DeleteData(reader);
	delete reader;
}

void Database::DeleteBook(Book * book) {
	myBooks->DeleteData(book);
	delete book;
}
