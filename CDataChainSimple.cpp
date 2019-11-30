# 2001
#include "pch.h"
#include "CDataChainSimple.h"
using namespace std;

//êîíñòðóêòîð Chain
CDataChain::CDataChain()
{
}

//äåñòðóêòîð Chain
CDataChain::~CDataChain()
{
	m_sChain.clear();
}

//ïîâåðòàº äîâæèíó çãåíåðîâàíî¿ ïîñë³äîâíîñò³ öèôð
size_t CDataChain::GetLength()
{
	return m_sChain.length();
}

//ïîâåðòàº ïîçèö³þ âõîäæåííÿ ï³äñòð³÷êè sSubStr ïî÷èíàþ÷è ³ç nPos
// -1, ÿêùî ï³äñòð³÷êè íå çíàéäåíî
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

//ïîâåðòàº ï³äñòð³÷êó ïî÷èíàþ÷è ³ç nPos äîâæèíîþ nLength. àáî äî ê³íöÿ ïîñë³äîâíîñò³
string CDataChain::GetSubStr(int nPos, int nLength)
{
	string subStr;
	if ((nPos >= m_sChain.length()) || ((nPos + nLength) >= m_sChain.length()))
		return subStr;
	subStr = m_sChain.substr(nPos, nLength);
	return subStr;
}

//ïîâåðòàº âñþ çãåíåðîâàíó ïîñë³äîâí³ñòü öèôð
const char* CDataChain::GetFullString()
{
	return m_sChain.c_str();
}



//êîíñòðóêòîð Simple
CDataSimple::CDataSimple()
{
}

//äåñòðóêòîð Simple
CDataSimple::~CDataSimple()
{
}

//Ðåàë³çàö³ÿ ãåíåðàòîðà ïîâíî¿ ïîñë³äîâíîñò³ öèôð
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
