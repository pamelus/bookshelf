#ifndef DATABOOKSET_HPP
#define DATABOOKSET_HPP

#include "data.hpp"
#include "set.hpp"

// rozszerzenie klasy abstrakcyjnej data o zbior ksiazek
class DataBookSet : public Data {
	protected:
		SetEx<Book> myBooks;
	public:
		// metody klasy
		DataBookSet() { }
		virtual ~DataBookSet() { }
		
		virtual int GetDataType() = 0;
		
		virtual void AddBook(Book * book) { myBooks.AddData(book); }
		virtual void DeleteBook(Book * book) { myBooks.DeleteData(book); }
		
		virtual void ResetBooks() { myBooks.ResetData(); }
		virtual Book * GetNextBook() { return myBooks.GetNextData(); }
};

#endif
