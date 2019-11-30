#pragma once
#include <string>
using namespace std;

class CDataChain
{
public:
	CDataChain(void);//�����������
	virtual ~CDataChain(void);//����������

	//��������� �������, �� �� ���������� ����� ����������� ����.
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;

	//������� ������� ����������� ����������� ����.
	size_t GetLength();

	//������� ������� ��������� �������� sSubStr ��������� �� nPos.
	// -1, ���� �������� �� ��������
	int Find(const char* sSubStr, int nPos = 0);

	//������� �������� ��������� �� nPos �������� nLength. ��� �� ���� �����������
	string GetSubStr(int nPos, int nLength = -1);

	//������� ��� ����������� ����������� ����
	const char* GetFullString();

protected:
	//������ �� ������������ ����������� ����
	string m_sChain;
};
class CDataSimple : public CDataChain
{
public:
	CDataSimple(void);//�����������
	~CDataSimple(void);//����������

	//��������� ���������� ����� ����������� ����
	void Generate(int nDepth, int nMaxLength = 0);
};

