#include<stdio.h>
#include<stdlib.h>
void funA();
void funB();
void funC();

class funPr{
public:
	char* fName;
	funPr(char* in_file)
	{
		fName = in_file;
		printf("%s() start\n", fName);
	}
	~funPr()
	{
		printf("%s() end\n", fName);
	}
};

int main()
{
	funPr a((char*)__FUNCTION__);
	funA();
}

void funA()
{
	funPr a((char*)__FUNCTION__);
	funB();
}
void funB()
{
	funPr a((char*)__FUNCTION__);
	funC();
}
void funC()
{
	funPr a((char*)__FUNCTION__);
}