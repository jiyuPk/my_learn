#pragma once
#include "instructions.h"
#include <cassert>
#include <iostream>

class Virtual_machine
{
public:
	Virtual_machine() = default;

	void interpret(std::vector<size_t> bytecodes) {

		for (int i = 0; i < bytecodes.size(); i++) {
			//std::cout << "number: "<< bytecodes[i] << "\n\n";


			switch (int instruction = int(bytecodes[i])) {
			case INST_LITERAL:
				{
				std::cout << "LITERAL" << "\n";
				push(int(bytecodes[i+1]), int(bytecodes[i+2]));
				i += 2;
				break;
				}
			case INST_ADD:
				{
				std::cout << "ADDITION" << "\n";
				i++;
				int a = pop(int(bytecodes[i]));
				i++;
				int b = pop(int(bytecodes[i]));
				i++;
				int c = a + b;
				push(int(bytecodes[i]), c);
				break;
				}
			case INST_SUB:
			{
				std::cout << "SUBTRACTION" << "\n";
				i++;
				int a = pop(int(bytecodes[i]));
				i++;
				int b = pop(int(bytecodes[i]));
				i++;
				int c = a - b;
				push(int(bytecodes[i]), c);
				break;
			}
			case INST_MUL:
			{
				std::cout << "MULTIPLICATION" << "\n";
				i++;
				int a = pop(int(bytecodes[i]));
				i++;
				int b = pop(int(bytecodes[i]));
				i++;
				int c = a * b;
				push(int(bytecodes[i]), c);
				break;
			}
			case INST_DIV:
			{
				std::cout << "DIVISION" << "\n";
				i++;
				int a = pop(int(bytecodes[i]));
				i++;
				int b = pop(int(bytecodes[i]));
				i++;
				int c = a / b;
				push(int(bytecodes[i]), c);
				break;
			}
			case INST_CON:
				std::cout << "address: " << int(bytecodes[++i]) << "\n";
				std::cout << pop(bytecodes[i++]) << "\n\n";
				break;
			}
		}
	}

private:
	static constexpr int Max_Address = 128;
	int register_[Max_Address];


	void push(int address, int value) {
		std::cout << "PUSH"<< "\n";
		std::cout << "address: " << address << "\n";
		std::cout << "value: " << value << "\n\n";
		register_[address] = value;
	}

	int pop(int address) {
		std::cout << "POP" << "\n";
		std::cout << "address: " << address << "\n";
		std::cout << "value: " << register_[address] << "\n\n";
		return register_[address];
	}
};

