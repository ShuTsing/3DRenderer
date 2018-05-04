#include "GraLib.h"
namespace gra
{
	//四字节填充
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

	//二字节填充
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