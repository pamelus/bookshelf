#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "reader.hpp"
#include "writer.hpp"
#include "book.hpp"
#include "set.hpp"

class Database {
	private:
		Set<Writer> * myWriters;
		Set<Reader> * myReaders;
		SetEx<Book> * myBooks;
	public:
		Database();
		~Database();
		
		void AddWriter(const char * name, const char * surname);
		void AddReader(const char * name, const char * surname, const char * adress, const char * telephone);
		void AddBook(const char * title, const char * isbn, const char * publish, const char * version, int length, Writer * writer);
		
		void DeleteWriter(Writer * writer);
		void DeleteReader(Reader * reader);
		void DeleteBook(Book * book);
		
		void ResetWriters() { myWriters->ResetData(); }
		void ResetReaders() { myReaders->ResetData(); }
		void ResetBooks() { myBooks->ResetData(); }
		
		Writer * GetNextWriter() { return myWriters->GetNextData(); }
		Reader * GetNextReader() { return myReaders->GetNextData(); }
		Book * GetNextBook() { return myBooks->GetNextData(); }
};

#endif
