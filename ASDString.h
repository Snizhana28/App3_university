#if !defined(ASD_STRING_H)
#define ASD_STRING_H
#include <iostream>
#include <cstdarg>
#include <stdio.h>
namespace ASD{
	class String{
			char *str;
		public:
			String(const char *s = 0) { str = 0; add(s); }
			String(String &s){ str=0; add(s.str);}
			String(char, int);
			~String(){empty();}
			int length(){return ((str)?strlen(str):0);}
			String & set(const char *s){empty();add(s);return *this;}
			String & add(const char *s);
			const char * get(){return ((str)?str:"");}
			String &  empty(){delete str;str=0;return *this;}
			char & operator [](int i){return str[i];}
			operator char *(){return (char *)get();}
			String & operator =(const char *s){return set(s);}
			String & operator =(String &s){
				return set(s.str);
			}
			String & operator +=(const char *s){return add(s);}
			String & operator +=(String &s){return add(s.str);}
			String & operator +=(char s){
				/*
				String s1(s,1);
				*this+=s1;
				return *this;
				*/
				return *this+=String(s,1);
			}

			String & RemoveAt(int pos) {
				if (pos < 0 || pos >= length()) return *this;
				for (int i = pos; i < length(); i++) {
					str[i] = str[i+1];
				}
				return *this;
			}

			String & InsertAt(int pos, char key) {
				if (pos < 0 || pos > length()) return *this;
				int len = length();
				char *str1 = new char[len + 2];
				for (int i = 0; i <= len; i++) {
					if (i == pos) {
						str1[i] = key;
					}
					else if (i > pos) {
						str1[i] = str[i - 1];
					}
					else {
						str1[i] = str[i];
					}
				}
				str1[len + 1] = 0;
				delete str;
				str = str1;
				return *this;
			}

			struct x
			{
				char y[1024];
			};

			String & Format(String format, double num) {
				char buf[255] = { 0 };
				sprintf_s(buf, 255, format.str, num);
				set(buf);
				return *this;
			}


			String & operator <<(const char *s){return add(s);}
			String & operator <<(String &s){return add(s.str);}
			String operator + (const char *s){return String(str).add(s);}
			String operator  + (String &s){
				return String(str).add(s.str);
			}
			int compare(const char *s){return strcmp(str,s);}
			bool operator ==(const char *s){return !compare(s);}
			bool operator !=(const char *s){return compare(s)!=0;}
			bool operator ==(String &s){return !compare(s.str);}
			bool operator !=(String &s){return compare(s.str)!=0;}
			bool operator !(){return length()==0;}
			friend String operator + (const char * str1, String & str2);
	};
}

#endif