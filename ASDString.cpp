#include <string.h>
#include "ASDString.h"


namespace ASD{
	String operator + (const char * str1, String & str2) {
		return String(str1).add(str2);
	}

	String::String(char c, int len){
		str=0;
		if (len<1) return;
		str=new char[len+1];
		for (int i=0;i<len;i++)str[i]=c;
		str[len]=0;
	}

	String & String::add(const char *s){
		if (!s) return *this;
		char *str1=new char[length()+strlen(s)+1];
		str1[0]=0;
		if (str) strcpy_s(str1,length()+strlen(s)+1,str);
		strcat_s(str1,length()+strlen(s)+1,s);
		delete str;
		str=str1;
		return *this;
	}

}


