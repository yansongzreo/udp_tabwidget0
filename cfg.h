/******from  https://blog.csdn.net/huixingshao/article/details/62223279******/
#include<iostream>
#include <fstream>
#include <vector>
#include<string>
using namespace std;

class CConfigOperator
{
public:
    CConfigOperator(void);
    ~CConfigOperator(void);
    void SetFilePath(const string &sFilePath);
    string GetFilePath();
    bool GetConfigValue(const string &sName, const string &skey, string &sValue, string &sError);
    bool ModefyConfigValue(const string &sName, const string &skey, const string &sValue, string &sError);
    bool GetConfigAllName( vector<string> &namelist,string &sError);

private:
    bool OpenFile();
    void FindName();
    string FindNamestr();

    bool FindKey();
    bool WriteFile();
    bool ModefyValue();
    void WriteToFile(vector<string> &vContent);

    fstream m_fout;
    ifstream m_fin;
    string m_sFilePath;
    string m_Name;
    string m_Key;
    string m_value;
    string m_sError;
    string m_sStr;
    bool m_bFindName;

};
