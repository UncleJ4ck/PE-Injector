#pragma once

#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
#include <string>
#include <iomanip>
#include <Shlwapi.h>
#include <thread>

class PortableExecutable {
    private:
        PROCESSENTRY32 pinfo;
        ProcessesShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // Taking a snapshot to save all your processes
        HANDLE ProcessesShot; // Taking a snapshot to save all your processes
        char ModuleFileName[128];
    public:
        DWORD GetPid(LPCTSTR ProcessName);
        DWORD Inject();
};


typedef struct BASE_RELOCATION_ENTRY {
    USHORT Offset : 12;
    USHORT Type : 4;
} BASE_RELOCATION_ENTRY, * PBASE_RELOCATION_ENTRY;

