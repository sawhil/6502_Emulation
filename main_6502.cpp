#include<stdio.h>
#include<stdlib.h>
using Byte = unsigned char;
using Word = unsigned short;
using u32 = unsigned int;

struct Mem {
	static constexpr u32 MAX_MEM = 1024 * 64;
	Byte Data[MAX_MEM];
	void init() {
		for (u32 i = 0; i < MAX_MEM; ++i) {
			Data[i] = 0;
		}
	}
};

struct CPU {
	Word PC; // program counter
	Word SP; // stack pointer
	
	Byte A, X, Y; // Registers
	// Flags
	Byte C : 1;
	Byte Z : 1;
	Byte I : 1;
	Byte D : 1;
	Byte B : 1;
	Byte V : 1;
	Byte N : 1;
	void Reset(Mem &memory) {
		PC = 0xFFFC;
		SP = 0x0100;
		C = Z = I = D = B = V = N = 0;
		A = X = Y = 0;
		memory.init();
	}

	Byte FetchByte(u32 &Cycles, Mem &memory) {
		Byte Data = memory[PC];
		PC++; // increment the Program Counter after fetching the instruction
		Cycles--; // Decrement the Cycles As One Operation is Being Fetched
		return Data;
	}
	void Execute(u32 Cycles, Mem &memory) {
		while(Cycles > 0) {
			Byte Instruction = FetchByte(Cycles, memory);
			
		}
	}
};

int main() {
	CPU cpu;
	Mem mem;
	cpu.Reset(mem);
	cpu.Execute(2, mem);
	return 0;
}