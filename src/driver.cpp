#include "list.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	ls::list<int> lista;
	lista.push_back(6);
	lista.push_back(7);
	lista.push_back(8);
	lista.push_front(5);
	lista.push_front(6);
	lista.push_front(7);
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	return 0;
}
