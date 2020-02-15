#ifndef STRING_HPP
#define STRING_HPP

#include <string.h>

inline char * StringDuplicate(const char * psz) {
	char * tmp = new char[strlen(psz) + 1];
	strcpy(tmp, psz);
	return tmp;
}

#endif
