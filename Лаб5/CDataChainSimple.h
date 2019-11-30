#pragma once
#include <string>
using namespace std;

class CDataChain
{
public:
	CDataChain(void);//конструктор
	virtual ~CDataChain(void);//деструктор

	//віртуальна функція, що має генерувати повну послідовність цифр.
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;

	//повертає довжину згенерованої послідовності цифр.
	size_t GetLength();

	//повертає позицію входження підстрічки sSubStr починаючи із nPos.
	// -1, якщо підстрічки не знайдено
	int Find(const char* sSubStr, int nPos = 0);

	//повертає підстрічку починаючи із nPos довжиною nLength. або до кінця послідовності
	string GetSubStr(int nPos, int nLength = -1);

	//повертає всю згенеровану послідовність цифр
	const char* GetFullString();

protected:
	//стрічка із згенерованою послідовністю цифр
	string m_sChain;
};
class CDataSimple : public CDataChain
{
public:
	CDataSimple(void);//конструктор
	~CDataSimple(void);//деструктор

	//Реалізація генератора повної послідовності цифр
	void Generate(int nDepth, int nMaxLength = 0);
};

