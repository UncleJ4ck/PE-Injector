#include "..\inc\main.hpp"

PortableExecutable::DWORD Inject() {
    GetModuleFileNameA(0, ModuleFileName, sizeof(ModuleFileName)); // if it didn't work replace it with sizeof(ModuleFileName)
    MessageBoxA(0, ModuleFileName, "INJECTED XD", 0);
    return 0;
} 