#include "GraLib.h"
namespace gra
{
	void MemsetQuad(void* dest, unsigned int val, int cnt)
	{
		_asm
		{
			mov edi, dest;
			mov ecx, cnt;
			mov eax, val;
			rep stosd;
		}
		return;
	}

	void MemsetWord(void* dest, unsigned int val, int cnt)
	{
		_asm
		{
			mov edi, dest;
			mov ecx, cnt;
			mov ax, val;
			rep stosw;
		}
		return;
	}
}