#include "Serialize.hpp"

Serialize::Serialize(void)
{
}

uintptr_t	Serialize::serialize(Data *data_ptr)
{
	return (reinterpret_cast<uintptr_t>(data_ptr));
}

Data	*Serialize::deserialize(uintptr_t data)
{
	return (reinterpret_cast<Data *>(data));
}
