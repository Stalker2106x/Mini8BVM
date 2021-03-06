#include "Cc/InstructionDef.hh"
#include "Computer/Computer.hh"
#include "bitset_utils.hh"

void LDAExecutor(Computer &computer)
{
    computer._MAR.write(bitsetRange<DWORD_SIZE, WORD_SIZE>(computer._IR.read(), 0, WORD_SIZE));//Extract adress from IR
    computer._accumulator.write(computer._RAM[computer._MAR.read()].read());
}

void ADDExecutor(Computer &computer)
{
    computer._MAR.write(bitsetRange<DWORD_SIZE, WORD_SIZE>(computer._IR.read(), 0, WORD_SIZE));//Extract adress from IR
    computer._Breg.write(computer._RAM[computer._MAR.read()].read());
    computer._accumulator += computer._Breg;
}

void SUBExecutor(Computer &computer)
{
    computer._MAR.write(bitsetRange<DWORD_SIZE, WORD_SIZE>(computer._IR.read(), 0, WORD_SIZE));//Extract adress from IR
    computer._Breg.write(computer._RAM[computer._MAR.read()].read());
    computer._accumulator -= computer._Breg;
}

void MULExecutor(Computer &computer)
{
    computer._MAR.write(bitsetRange<DWORD_SIZE, WORD_SIZE>(computer._IR.read(), 0, WORD_SIZE));//Extract adress from IR
    computer._Breg.write(computer._RAM[computer._MAR.read()].read());
    computer._accumulator *= computer._Breg;
}


void OUTExecutor(Computer &computer)
{
    computer._output.write(computer._accumulator.read()); //Extract acc to output
}

void HLTExecutor(Computer &computer)
{
    computer.halt();
}