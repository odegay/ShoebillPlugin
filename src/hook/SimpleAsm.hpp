/**
* Copyright (C) 2014 MK124
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#ifndef __SIMPLEASM_H__
#define __SIMPLEASM_H__

#include <stdint.h>
#include <vector>
#include <cstring>

class SimpleAsm
{
public:
	SimpleAsm() : _address(nullptr)
	{
	}

	explicit SimpleAsm(void *address) : _address((unsigned char *)address)
	{
	}

	void init(void *address)
	{
		_address = (unsigned char *)address;
		_origin.clear();
	}

	void jmp(void *address)
	{
		_origin.insert(_origin.end(), _address, _address + 5);
		*(_address++) = 0xE9;
		*((uint32_t *)_address) = (uint32_t)address - ((uint32_t)_address + 4);
		_address += 4;
	}

	void reset()
	{
		_address -= _origin.size();
		std::memcpy(_address, &_origin[0], _origin.size());
		_origin.clear();
	}

private:
	unsigned char *_address;
	std::vector<unsigned char> _origin;

	SimpleAsm(const SimpleAsm &) = delete;

	SimpleAsm &operator=(const SimpleAsm &) = delete;
};

#endif