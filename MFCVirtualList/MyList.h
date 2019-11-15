#pragma once
#include <stddef.h>
#include <iostream>
#include <string> 

class MyList {
	int Int;
	double Double;
	wchar_t* String;
public:
	MyList(int i = 0, double d = false, wchar_t* s = NULL) {
		Int = i;
		Double = d;
		if(s)wcscpy_s(String, 20, s);
		else String = NULL;
	}
	MyList& operator =(const MyList& a) {
		Int = a.GetInt();
		Double = a.GetDouble();
		if(!String) String = new wchar_t[20];
		wcscpy_s(String, 20, a.GetString());
		return *this;
	}
	void SetData(int i, double d, wchar_t* s) {
		Int = i;
		Double = d;
		if (!String)String = new wchar_t[20];
		wcscpy_s(String, 20, s);
	}
	MyList(const MyList&a) {
		Int = a.GetInt();
		Double = a.GetDouble();
		String = new wchar_t[20];
		wcscpy_s(String, 20, a.GetString());
	}
	int GetInt() const {
		return Int;
	}
	wchar_t* GetIntAsWSTR() const {
		wchar_t istr[32];
		_itow_s(Int, istr, 10);
		return istr;
	}
	double GetDouble() const {
		return Double;
	}
	wchar_t* GetDoubleAsWSTR() const {
		wchar_t istr[32];
		std::wstring str = std::to_wstring(Double);
		const wchar_t * wstr = str.c_str();
		wcscpy_s(istr, 30, wstr);
		return istr;
	}
	wchar_t* GetString() const {
		return String;
	}
	~MyList() {
		if (String) delete[] String;
	}
};