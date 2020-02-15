#ifndef READER_HPP
#define READER_HPP

class Reader;

#include "databookset.hpp"
#include "string.hpp"

// klasa ze zbiorem ksiazek reprezentujaca czytelnika
class Reader : public DataBookSet {
	protected:
		char * myName;
		char * mySurname;
		char * myAdress;
		char * myTelephone;
	public:
		// metody klasy
		Reader(const char * name, const char * surname, const char * adress, const char * telephone):
			myName(StringDuplicate(name)), mySurname(StringDuplicate(surname)), myAdress(StringDuplicate(adress)), myTelephone(StringDuplicate(telephone)) { }
		virtual ~Reader()
			{ if(myName) delete [] myName; if(mySurname) delete [] mySurname; if(myAdress) delete [] myAdress; if(myTelephone) delete [] myTelephone; }
			
		virtual int GetDataType() { return DATA_READER; }
		
		// metody dostepowe
		virtual void SetName(const char * name) { if(myName) delete [] myName; myName = StringDuplicate(name); }
		virtual void SetSurname(const char * surname) { if(mySurname) delete [] mySurname; mySurname = StringDuplicate(surname); }
		virtual void SetAdress(const char * adress) { if(myAdress) delete [] myAdress; myAdress = StringDuplicate(adress); }
		virtual void SetTelephone(const char * telephone) { if(myTelephone) delete [] myTelephone; myTelephone = StringDuplicate(telephone); }
		
		virtual const char * GetName() { return myName; }
		virtual const char * GetSurname() { return mySurname; }
		virtual const char * GetAdress() { return myAdress; }
		virtual const char * GetTelephone() { return myTelephone; }
		
		virtual bool operator< (const Reader & reader) {
			int cmp = strcmp(mySurname, reader.mySurname);
			if(!cmp) cmp = strcmp(myName, reader.myName);
			
			if(cmp < 0) return true;
			else return false;
		}
};

#endif
