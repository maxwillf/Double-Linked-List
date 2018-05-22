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
	std::cout << "Teste push_front e push_back " << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;

	auto itr = lista.begin();
	itr = itr+ 2;
	auto x = lista.insert(itr,{-1,-2,-3,-4,-5});

	std::cout << "Teste insert initializer list" << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "Teste retorno insert: " << *x << std::endl;

	x = lista.insert(lista.begin(),lista.begin()+2,lista.end());
	std::cout << "Teste retorno insert: " << *x << std::endl;
	
	std::cout << "Teste insert [first,last) " << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	
	std::cout << "Teste size: " << lista.size() << std::endl;
	return 0;
}
