#pragma once

#include "Data.hpp"

#include <stdint.h>

class Serialize
{
	public:
		static uintptr_t	serialize(Data *data_ptr);
		static Data			*deserialize(uintptr_t data);

	private:
		Serialize(void);
};