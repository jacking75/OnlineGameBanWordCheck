#include <iostream>
#include "WordFilter.h"


int main()
{
	CWordFilter WordFilter;
	WordFilter.TestInit();

	std::string name;
	std::string msg;

	while(1)
	{
		std::cout << "input your name: " ;
		std::getline(std::cin, name);

		if(!WordFilter.IsWangSungWord(name))
		{
			std::cout << "�ϼ��� ���ڰ� �ƴմϴ�." << std::endl;
		}
		else if(!WordFilter.IsNotSlangReservedWord(name))
		{
			std::cout << "����� �� ���� �̸��Դϴ�." << std::endl;
		}

		std::cout << "input Chatting Message: ";
		std::getline(std::cin, msg);

		std::cout << "Say: "<< WordFilter.ChattingFilter(msg) << std::endl;;
	}

	return 0;
}