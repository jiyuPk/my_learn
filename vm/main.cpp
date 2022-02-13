#include <vector>
#include <cstddef>
#include "virtual_machine.h"

int main()
{
	std::vector<size_t> insts;
	insts.push_back(0x00000011);
	insts.push_back(0x00000000);
	insts.push_back(0x000000DA);
	insts.push_back(0x00000011);
	insts.push_back(0x00000001);
	insts.push_back(0x0000026A);
	insts.push_back(0x00000012);
	insts.push_back(0x00000000);
	insts.push_back(0x00000001);
	insts.push_back(0x00000002);

	Virtual_machine vm;

	vm.interpret(insts);
}


