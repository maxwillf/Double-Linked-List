#include "list.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	ls::list<int> lista;
	lista.push_front(5);
	auto x =  lista.begin() ;
	std::cout << *x << std::endl;

	return 0;
}
