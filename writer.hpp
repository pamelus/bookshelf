#ifndef WRITER_HPP
#define WRITER_HPP

class Writer;

#include "databookset.hpp"
#include "string.hpp"

// klasa ze zbiorem ksiazek reprezentujaca autora
class Writer : public DataBookSet {
	protected:
		char * myName;
		char * mySurname;
	public:
		// metody klasy
		Writer(const char * name, const char * surname): myName(StringDuplicate(name)), mySurname(StringDuplicate(surname)) { }
		virtual ~Writer() { if(myName) delete [] myName; if(mySurname) delete [] mySurname; }
		
		virtual int GetDataType() { return DATA_WRITER; }
		
		// metody dostepowe
		virtual void SetName(const char * name) { if(myName) delete [] myName; myName = StringDuplicate(name); }
		virtual void SetSurname(const char * surname) { if(mySurname) delete [] mySurname; mySurname = StringDuplicate(surname); }		
		virtual const char * GetName() { return myName; }
		virtual const char * GetSurname() { return mySurname; }
		
		virtual bool operator< (const Writer & writer) {
			int cmp = strcmp(mySurname, writer.mySurname);
			if(!cmp) cmp = strcmp(myName, writer.myName);
			
			if(cmp < 0) return true;
			else return false;
		}
};

#endif
