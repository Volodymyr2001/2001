#include "pch.h"
#include "CDataChainSimple.h"
using namespace std;

//����������� Chain
CDataChain::CDataChain()
{
}

//���������� Chain
CDataChain::~CDataChain()
{
	m_sChain.clear();
}

//������� ������� ����������� ����������� ����
size_t CDataChain::GetLength()
{
	return m_sChain.length();
}

//������� ������� ��������� �������� sSubStr ��������� �� nPos
// -1, ���� �������� �� ��������
int CDataChain::Find(const char* sSubStr, int nPos)
{
	size_t length = strlen(sSubStr);
	for (size_t i = 0; i < m_sChain.length(); i++)
	{
		if (m_sChain[i] != sSubStr[0])
			continue;
		size_t j = 0;
		for (; j < length; j++)
		{
			if ((i + j) >= m_sChain.length())
				return -1; 
			if (m_sChain[i + j] != sSubStr[j])
				break;
		}
		if ((j == length) && (m_sChain[i + j] == sSubStr[j - 1]))
			return i;
	}
	return -1;
}

//������� �������� ��������� �� nPos �������� nLength. ��� �� ���� �����������
string CDataChain::GetSubStr(int nPos, int nLength)
{
	string subStr;
	if ((nPos >= m_sChain.length()) || ((nPos + nLength) >= m_sChain.length()))
		return subStr;
	subStr = m_sChain.substr(nPos, nLength);
	return subStr;
}

//������� ��� ����������� ����������� ����
const char* CDataChain::GetFullString()
{
	return m_sChain.c_str();
}



//����������� Simple
CDataSimple::CDataSimple()
{
}

//���������� Simple
CDataSimple::~CDataSimple()
{
}

//��������� ���������� ����� ����������� ����
void CDataSimple::Generate(int nDepth, int nMaxLength)
{
	while (m_sChain.length() <= (size_t)nMaxLength)
	{
		int num = rand() % (10 * nDepth);
		m_sChain.append(std::to_string(num));
	}
	if (m_sChain.length() > nMaxLength)
		m_sChain.resize(nMaxLength);
}
