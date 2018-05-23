#include "list.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	ls::list<int> lista;
	lista.push_back(6);
	lista.push_front(5);
	auto y = lista.insert(lista.begin()+1,3);
	std::cout << *y << std::endl;
	std::cout << "Teste push_front e push_back " << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;

	auto x = lista.insert(lista.begin(),{-1,-2,-3,-4,-5});

	std::cout << "Teste insert initializer list" << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout <<  std::endl;
	std::cout << "Teste retorno insert: initializer list: " << *x << std::endl;

	x = lista.insert(lista.begin(),lista.begin()+2,lista.end());
	
	std::cout << "Teste insert [first,last) " << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "Teste retorno insert [first,last): " << *x << std::endl;
	
	std::cout << "Teste size: " << lista.size() << std::endl; 

	x = lista.erase(lista.begin());
	std::cout << "Teste erase pos "<< *x << std::endl;
	std::cout <<  std::endl;

	for (auto i = lista.begin(); i != lista.end(); ++i) {
		std::cout << *i << std::endl;
	}

	x = lista.erase(lista.begin()+3,lista.end());
	std::cout << "Teste erase  [first,last) " << std::endl;
	for (auto i = lista.begin(); i != lista.end(); ++i) {
		std::cout << *i << std::endl;
	}
	//lista.clear();
	//std::cout << "list size after clear : " << lista.size() << std::endl;
	
	
	ls::list<int> lista2{{1,2,3,4}};
	std::cout << "list2 itializer list : " << lista2.size() << std::endl;

	for (auto i = lista2.begin(); i != lista2.end(); ++i) {
		std::cout << *i << std::endl;
	}
	lista2.assign(5,7);
	std::cout << "list2 assign: "  << std::endl;
	for (auto i = lista2.begin(); i != lista2.end(); ++i) {
		std::cout << *i << std::endl;
	}

	lista2.assign(lista.begin(),lista.end());
	
	std::cout << "list2 assign [first,last): "  << std::endl;
	for (auto i = lista2.begin(); i != lista2.end(); ++i) {
		std::cout << *i << std::endl;
	}

	lista2.assign({1,2,3,4,5});
	
	std::cout << "list2 assign initializer list: "  << std::endl;
	for (auto i = lista2.begin(); i != lista2.end(); ++i) {
		std::cout << *i << std::endl;
	}

	ls::list<int> lista3 = lista2;
	std::cout << "list3 assignment operator: "  << std::endl;
	for (auto i = lista3.begin(); i != lista3.end(); ++i) {
		std::cout << *i << std::endl;
	}
	
	ls::list<int> lista4(lista3);
	
	std::cout << "list4 copy constructor: "  << std::endl;
	for (auto i = lista4.begin(); i != lista4.end(); ++i) {
		std::cout << *i << std::endl;
	}
	std::cout << "list3 size : " << lista3.size() << std::endl;
	std::cout << "list4 size : " << lista4.size() << std::endl;

	std::cout << "Teste operator lista4 == lista3 " << (lista4 == lista3) << std::endl;
	std::cout << "Teste operator lista == lista3 " << (lista == lista3) << std::endl;
	std::cout << "Teste operator lista4 != lista3 " << (lista4 != lista3) << std::endl;

	ls::list<int> lista5(5);

	for (auto i = lista5.begin(); i != lista5.end(); ++i) {
		std::cout << *i << std::endl;
	}
	return 0;
}
