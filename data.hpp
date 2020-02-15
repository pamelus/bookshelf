#ifndef DATA_HPP
#define DATA_HPP

enum {DATA_BOOK, DATA_WRITER, DATA_READER};

// predefinicje
class Book; class Writer; class Reader; class BookSet;

class Data {
	public:
		// metody abstrakcyjne
		Data() { }
		virtual ~Data() { }
		virtual int GetDataType() = 0;
};

#endif
