#include "Data.hpp"
#include "Serialize.hpp"

#include <iostream>

int	main(void)
{
	Data		*data_ptr = new Data;
	uintptr_t	data = Serialize::serialize(data_ptr);
	Data		*data_ptr2 = Serialize::deserialize(data);

	std::cout << data_ptr << std::endl;
	std::cout << data << std::endl;
	std::cout << data_ptr2 << std::endl;

	delete data_ptr;
	return (0);
}
