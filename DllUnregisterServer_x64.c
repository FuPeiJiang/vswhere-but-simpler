#include <stdio.h>
#include <windows.h>
#include <olectl.h>

#pragma comment(lib, "Ole32.lib")

int main() {
    CoInitialize(0);

    HMODULE hModule = LoadLibraryA("C:\\ProgramData\\Microsoft\\VisualStudio\\Setup\\x64\\Microsoft.VisualStudio.Setup.Configuration.Native.dll");
    typeof(DllUnregisterServer) *myDllUnregisterServer = (typeof(DllUnregisterServer)*)GetProcAddress(hModule, "DllUnregisterServer");

    HRESULT hResult = myDllUnregisterServer();
    printf("%08lX\n",hResult);
}