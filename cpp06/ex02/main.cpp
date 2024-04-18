#include <iostream>

#include <cstdlib>

#define TEST_FOR_PTR(name, ptr)				\
	if (dynamic_cast<name *>(ptr))			\
		std::cout << #name << std::endl;

class Base { public: virtual ~Base() {} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
		case 0: return (new A);
		case 1: return (new B);
		case 2: return (new C);
	}
	return (NULL);
}

void	identify(Base *ptr)
{
	TEST_FOR_PTR(A, ptr)
	else TEST_FOR_PTR(B, ptr)
	else TEST_FOR_PTR(C, ptr)
}

void	identify(Base &ref)
{
	TEST_FOR_PTR(A, &ref)
	else TEST_FOR_PTR(B, &ref)
	else TEST_FOR_PTR(C, &ref)
}

int	main(void)
{
	static const size_t	limit = 10;
	Base				*r;

	srand(time(NULL));
	for (size_t i = 0; i < limit; ++i)
	{
		r = generate();
		std::cout << "as ptr: "; identify(r);
		std::cout << "as ref: "; identify(*r);
		if (i + 1 < limit)
			std::cout << std::endl;
		delete r;
	}
}