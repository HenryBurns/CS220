#include "LinkedList.h"
#include <iostream>
int main(){
	LLC* test = new LLC();
	test->insert("Hello");
	test->insert("middle");
	test->insert("Goodbye");
	LLC* test3 = new LLC(*test);
	std::cout << "test3" <<std::endl;
	LLC* test2 = new LLC();
	test2->insert("Hello2");
	test2->insert("middle2");
	test2->insert("Goodbye2");
	std::cout << *test2 << std::endl;	
	test->join(*test2);
	std::cout << "Test: " << *test << std::endl;
	*test = *test3;
	std::cout << "Should seg fault" << std::endl;
	std::cout << "Test: " << *test << std::endl;
	std::cout << "Test3 " << *test3 << std::endl;
	delete(test3);
	std::cout << "Test: " << *test << std::endl;
	std::cout << "Test: " << *test3 << std::endl;
	*test = *test+(*test2);
	std::cout << "Test: " << *test << std::endl;
	std::cout << "Num nodes: " << test->len() << std::endl;
	*test += 4;
	std::cout << "Test: " << *test << std::endl;
	}
