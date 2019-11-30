#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class CDataChain
{
public:
	CDataChain(void);
	virtual ~CDataChain(void);

	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	size_t GetLength();

	int Find(const char* sSubStr, int nPos = 0);
	string GetSubStr(int nPos, int nLength = -1);
	const char* GetFullString();

protected:
	string m_sChain;
};

class CDataSimple : public CDataChain
{
public:
	CDataSimple(void);
	~CDataSimple(void);
	void Generate(int nDepth, int nMaxLength = 0);
};

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);
	void Init(int nDepth, int nLength);
	const char* GetChainString();

	bool Save(string& sFilepath);
	bool Load(string& sFilepath);

	//LinksArray m_aLinks;
	bool AddLink(int nStartPos, int nLength/*, CLink* pLink*/);
	bool RemoveLink(int nPosInList);
	bool GetAllLinks(/*LinksArray& aLinks*/);

	bool AddURL(const char* sSubStr, const char* sURL);
	bool AddPerson(const char* sSubStr, int nGroup, const char* sName);

private:
	CDataChain& m_refChain;
};

typedef void (*ptDlgCommandFunc)(CWorkspace& ws);

class CDlgCommand
{
public:
	CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = NULL);
	~CDlgCommand(void);
	const char* GetName() { return m_sName.c_str(); }
	void Run(CWorkspace& ws);
private:
	string m_sName;
	ptDlgCommandFunc m_pFunc;
};

class CDialogManager
{
public:
	CDialogManager(CWorkspace& ws);
	~CDialogManager(void);
	void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
	void Run();
private:
	vector <CDlgCommand*> m_aCommands;
	CWorkspace& m_refWorkspace;
};

CDialogManager::CDialogManager(CWorkspace& ws) :m_refWorkspace(ws)
{
	m_aCommands.push_back(new CDlgCommand("Quit"));
	m_aCommands.push_back(new CDlgCommand("Find substring"));
	m_aCommands.push_back(new CDlgCommand("Show All Links"));
	m_aCommands.push_back(new CDlgCommand("Add URL"));
	m_aCommands.push_back(new CDlgCommand("Remove Link"));
}

void ShowFullSequence(CWorkspace& ws)
{
	cout << ws.GetChainString() << endl;
}

void Init(CWorkspace& ws)
{

}

void Save(CWorkspace& ws)
{

}

void Load(CWorkspace& ws)
{

}

class CLink
{
public:
	CLink(CDataChain& refChain);
	virtual ~CLink(void);
	bool Attach(const char* sSubStr);
	virtual void Output(ostream& os);
	virtual bool Save(ostream& so);
	virtual bool Load(istream& is);
protected:
	CDataChain& m_refChain;
	int m_nPos;
	int m_nSize;
};

typedef vector<CLink*> LinksArray;

class CLinkURL : public CLink
{

public:
	CLinkURL(CDataChain& refChain);
	virtual ~CLinkURL(void);

private:
	string m_sURL;
};

class CLinkPerson : public CLink
{
public:
	int m_nGroupCode;
	string m_sName;
};

int main()
{
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	//mgr.RegisterCommand("Init sequence", Init);
	mgr.RegisterCommand("Show sequence", ShowFullSequence);
	//mgr.RegisterCommand("Save", Save);
	//mgr.RegisterCommand("Load", Load);
	mgr.Run();
	return 0;
}
