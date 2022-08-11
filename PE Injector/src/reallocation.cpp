#include "..\inc\main.hpp"


PortableExecutable::void Reallocation() {
    // Rellocation of the memory allocated 
    PIMAGE_BASE_RELOCATION relocationTable = (PIMAGE_BASE_RELOCATION)((DWORD_PTR)allocmem + pnths->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress);
    DWORD relocationEntriesCount = 0;
    PDWORD_PTR patchedAddress;
    PBASE_RELOCATION_ENTRY relocationRVA = NULL;
    // Iterate the reloc table of the local image and modify all absolute addresses to work at the address returned by VirtualAllocEx
    while (relocationTable->SizeOfBlock > 0) {
        relocationEntriesCount = (relocationTable->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(USHORT);
        relocationRVA = (PBASE_RELOCATION_ENTRY)(relocationTable + 1);
        for (short i = 0; i < relocationEntriesCount; i++) {
            if (relocationRVA[i].Offset) {
                patchedAddress = (PDWORD_PTR)((DWORD_PTR)allocmem + relocationTable->VirtualAddress + relocationRVA[i].Offset);
                *patchedAddress += BaseOffset;
            }
        }
        relocationTable = (PIMAGE_BASE_RELOCATION)((DWORD_PTR)relocationTable + relocationTable->SizeOfBlock);
    }
}