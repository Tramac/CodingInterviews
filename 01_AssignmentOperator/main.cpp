# include <string>
#include <tchar.h> 

class CMyString
{
public:
	CMyString(char* pData = NULL);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString& operator=(const CMyString& str);
	void Print();
private:
	char* m_pData;
};

CMyString::CMyString(char *pData)
{
	if (pData == NULL)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString &str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)   //"返回类型声明为该类型的引用，并把传入的参数的类型声明为常量引用"
{
	if (this == &str) // "判断传入的参数和当前的实例是否为同一个实例"
	{
		return *this;
	}
	delete[] m_pData;   //"释放实例自身已有的内存"
	m_pData = NULL;
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;   //"返回*this"
}

void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test1();

	return 0;
}
