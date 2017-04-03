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
			std::cout << "완성형 글자가 아닙니다." << std::endl;
		}
		else if(!WordFilter.IsNotSlangReservedWord(name))
		{
			std::cout << "사용할 수 없는 이름입니다." << std::endl;
		}

		std::cout << "input Chatting Message: ";
		std::getline(std::cin, msg);

		std::cout << "Say: "<< WordFilter.ChattingFilter(msg) << std::endl;;
	}

	return 0;
}