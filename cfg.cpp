#include "cfg.h"
CConfigOperator::CConfigOperator(void)
{
}

CConfigOperator::~CConfigOperator(void)
{
}
/************************************
���������ļ�·��
************************************/
void CConfigOperator::SetFilePath(const string &sFilePath)
{
    m_sFilePath = sFilePath;
}



/************************************
�õ������ļ�·��
************************************/

string CConfigOperator::GetFilePath()
{
    return this->m_sFilePath;
}



/************************************
�������ļ�
************************************/
bool CConfigOperator::OpenFile()
{
    if (true == m_fin.is_open())
    {
        m_fin.close();
    }

    m_fin.open(m_sFilePath.c_str());
//	if (NULL == m_fin)
    if (m_fin.is_open() == false)
    {
        m_sError = "can not open file " + m_sFilePath;
        return false;
    }
    return true;
}

/************************************
���������ļ�������
input m_sStr   m_Name
output  �Ƿ��ҵ�m_sStr������ֵ�section
************************************/
void CConfigOperator::FindName()
{
    if (-1 != m_sStr.find('['))
    {
        //name
        string sTemp = m_sStr.substr(m_sStr.find('[') + 1, m_sStr.find(']') - m_sStr.find('[') - 1);
        //string sTemp = m_sStr.substr(0, m_sStr.find('['));
        //std::cout<<sTemp<<std::endl;
        string::size_type idx = sTemp.find(m_Name);
        if (idx != string::npos)
        //if (0 == strcmp(sTemp.c_str(), m_Name.c_str()))
        {
            m_bFindName = true;
            m_sError = "Find Name But Not Find Key";
        }
        else
        {
            m_bFindName = false;
        }
    }
}

/************************************
���������ļ�������
input m_sStr  ��m_Name
output  namestr
************************************/
string CConfigOperator::FindNamestr()
{
    string sTemp = "";
    if (-1 != m_sStr.find('['))
    {
        //name
        sTemp = m_sStr.substr(m_sStr.find('[') + 1, m_sStr.find(']') - m_sStr.find('[') - 1);
        //string sTemp = m_sStr.substr(0, m_sStr.find('['));
        //std::cout<<sTemp<<std::endl;

    }
    return sTemp;
}

/************************************
���������ļ���Key
************************************/
bool  CConfigOperator::FindKey()
{
    int iDelePlace = m_sStr.find('//');
    int iFindEqual = m_sStr.find('=');
    //��ע�͵��У������ǰ���key�����Ѿ���ע�ӵ��ˣ�����

    if ((-1 != iDelePlace && iDelePlace <  iFindEqual) || (-1 != iDelePlace && -1 == iFindEqual) || -1 == iFindEqual)
    {
        return false;
    }

    //key
    string sKey = m_sStr.substr(m_sStr.find('[') + 1, m_sStr.find(']') - m_sStr.find('[') - 1);
    //if (0 == strcmp(sKey.c_str(), m_Key.c_str()))

    string::size_type idx = sKey.find(m_Key);
    if (idx != string::npos)
    {
        m_value = m_sStr.substr(m_sStr.find('=') + 1, m_sStr.length() - m_sStr.find('=') - 1);
        return true;
    }
    return false;
}



/************************************
��ȡ�����ļ�NEMA KEY ��Ӧ��Value��Ϣ
************************************/
bool CConfigOperator::GetConfigValue(const string &sName, const string &skey, string &sValue, string &sError)
{
    m_sError = "";
    m_Name = sName;
    m_Key = skey;
//printf("0\n");
    if (false == OpenFile())
    {
        sError = m_sError;
        return false;
    }
//printf("1\n");
    char str[1024];
    m_bFindName = false;

    //while (NULL != m_fin.getline(str, sizeof(str)))
    while (!m_fin.eof())
    {
        //printf("2\n");
        m_fin.getline(str, sizeof(str));
        m_sStr = str;
        //std::cout<<"m_sStr"<<m_sStr<<std::endl;
        FindName();
        if (true == m_bFindName)
        {
            //printf("FindName");
            if (true == FindKey())
            {
                m_fin.close();
                sError = "";
                sValue = m_value;
                return true;
            }
        }
    }

    sError = m_sError;
    m_fin.close();
    return false;

}

/************************************
��ȡ�����ļ�NEMA KEY ��Ӧ��Value��Ϣ
************************************/
bool CConfigOperator::GetConfigAllName( vector<string> &namelist,string &sError)
{
    m_sError = "";

    if (false == OpenFile())
    {
        sError = m_sError;
        return false;
    }

    char str[1024];
    m_bFindName = false;

    //while (NULL != m_fin.getline(str, sizeof(str)))
    while (!m_fin.eof())
    {
        m_fin.getline(str, sizeof(str));
        m_sStr = str;
        //std::cout<<"m_sStr"<<m_sStr<<std::endl;
        string tmpname = FindNamestr() ;
        if(tmpname != "")
        {
            std::cout<<"FindName"<<tmpname<<std::endl;
            namelist.push_back(tmpname);

        }
    }

    sError = m_sError;
    m_fin.close();
    return true;

}
/************************************
д�ķ�ʽ���ļ�
************************************/
bool CConfigOperator::WriteFile()
{
    m_fout.close();
    //�رպ�Ҫ�����һ�£������´δ򿪻����

    m_fout.clear();
    m_fout.open(m_sFilePath.c_str(), ios::in | ios::out);
    //if (NULL == m_fout)
    if (m_fout.is_open() == false)
    {
        m_sError = "can not open file " + m_sFilePath;
        return false;
    }
    return true;
}



/************************************
�޸������ļ�Key��Ӧ��ֵ
************************************/

bool  CConfigOperator::ModefyValue()
{
    int iDelePlace = m_sStr.find('//');
    int iFindEqual = m_sStr.find('=');
    //��ע�͵��У������ǰ���key�����Ѿ���ע�ӵ��ˣ�����

    if ((-1 != iDelePlace && iDelePlace <  iFindEqual) || (-1 != iDelePlace && -1 == iFindEqual) || -1 == iFindEqual)
    {
        return false;
    }

    //key
    string sKey = m_sStr.substr(m_sStr.find('[') + 1, m_sStr.find(']') - m_sStr.find('[') - 1);
    //if (0 == strcmp(sKey.c_str(), m_Key.c_str()))

    string::size_type idx = sKey.find(m_Key);
    if (idx != string::npos)
    {
        m_sStr = m_sStr.substr(0, m_sStr.find('=') + 1) + m_value;
        return true;
    }
    return false;

}

/************************************
�޸ĺ�������ļ���Ϣ����д���ļ�
************************************/
void CConfigOperator::WriteToFile(vector<string> &vContent)
{
    if (false == WriteFile())
    {
        m_fout.close();
        return;
    }

    for (size_t iIndex = 0; iIndex < vContent.size(); iIndex++)
    {
        m_fout << vContent[iIndex] << endl;
    }

    m_fout.close();
    vector<string>().swap(vContent);
}

/************************************
�޸������ļ�NEMA KEY ��Ӧ��Value��Ϣ
************************************/

bool CConfigOperator::ModefyConfigValue(const string &sName, const string &skey, const string &sValue, string &sError)
{
    m_sError = "";
    m_Name = sName;
    m_Key = skey;
    m_value = sValue;
    if (false == WriteFile())
    {
        sError = m_sError;
        return false;
    }

    char str[1024];
    m_bFindName = false;
    vector<string> vContent;
    bool isModefy = false;

    //while (NULL != m_fout.getline(str, sizeof(str)))
    while (!m_fout.eof())
    {
        m_fout.getline(str, sizeof(str));
        m_sStr = str;

        FindName();
        if (true == m_bFindName)
        {
            if (true == ModefyValue())
            {
                isModefy = true;
            }
        }

        vContent.push_back(m_sStr);
    }

    sError = m_sError;
    WriteToFile(vContent);
    m_fout.close();
    return isModefy;

}

