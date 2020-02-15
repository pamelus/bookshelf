#ifndef BOOK_HPP
#define BOOK_HPP

class Book;

#include "data.hpp"
#include "writer.hpp"
#include "reader.hpp"
#include "string.hpp"

// klasa przechowywujaca dane o ksiazkach
class Book : public Data {
	protected:
		char * myTitle;
		char * myIsbn;
		char * myPublish; // data wydania
		char * myDate; // data wypozyczenia
		char * myVersion; // wydanie
		int myLength; // ilosc stron

		Writer * myWriter;
		Reader * myReader; // czytelenik aktualnie posiadajacy ksiazke
	public:
		// metody klasy
		Book(const char * title, const char * isbn, const char * publish, const char * version, int length, Writer * writer);
		virtual ~Book();
		
		virtual int GetDataType() { return DATA_BOOK; }
		
		virtual void OnLend(Reader * reader, const char * date);
		virtual void OnReturn();
		
		// metody dostepowe
		virtual void SetTitle(const char * title) { if(myTitle) delete [] myTitle; myTitle = StringDuplicate(title); }
		virtual void SetIsbn(const char * isbn) { if(myIsbn) delete [] myIsbn; myIsbn = StringDuplicate(isbn); }
		virtual void SetPublish(const char * publish) { if(myPublish) delete [] myPublish; myPublish = StringDuplicate(publish); }
		virtual void SetVersion(const char * version) { if(myVersion) delete [] myVersion; myVersion = StringDuplicate(version); }
		virtual void SetLength(int length) { myLength = length; }
		
		virtual const char * GetTitle() { return myTitle; }
		virtual const char * GetIsbn() { return myIsbn; }
		virtual const char * GetPublish() { return myPublish; }
		virtual const char * GetDate() { return myDate; }
		virtual const char * GetVersion() { return myVersion; }
		virtual int GetLength() { return myLength; }
		virtual Writer * GetWriter() { return myWriter; }
		virtual Reader * GetReader() { return myReader; } 
		
		virtual bool IsLend() { return (myReader) ? true : false; }
		
		virtual bool operator< (const Book & book) {
			int cmp = strcmp(myTitle, book.myTitle);
			if(!cmp) cmp = strcmp(myIsbn, book.myIsbn);
			
			if(cmp < 0) return true;
			else return false;
		}
};

#endif
