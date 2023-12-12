// Libs
#include<Windows.h>
#include<stdlib.h>
#include<iostream>


// Self Destruct Things
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

// Colors
void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

// Main
int main(){
        // Pre-Autoclick
        // Menu
        system("cls");

        // Choose CPS
        int left_cps;
        setcolor(6);
        std::cout<<"[+] How much CPS do you want do? (Right Clicker)"<<std::endl;
        std::cout<<" -> ";
        setcolor(12);
        std::cin>>left_cps;

        if(left_cps > 20){
            MessageBox(NULL, "Maximum CPS are 20!", "[NeverLose]", 0);
            main();
        }

        if(left_cps < 1){
            MessageBox(NULL, "Minimum CPS is 1!", "[NeverLose]", 0);
            main();
        }

        system("cls");

        // Toggle Defs
        bool normal_mode = true;
        bool consoleShown = true;

        // Instructions
        setcolor(6);
        std::cout<<"DELETE -> ";
        setcolor(12);
        std::cout<<"Self Destruct"<<std::endl;

        setcolor(6);
        std::cout<<"INSERT -> ";
        setcolor(12);
        std::cout<<"Hide or Show Menu"<<std::endl;

        setcolor(6);
        std::cout<<"] -> ";
        setcolor(12);
        std::cout<<"Toggle Clicker                                                                                                                                                                                                                               "<<std::endl;

        setcolor(6);
        std::cout<<"[+] Left Clicker -> ";
        setcolor(12);
        std::cout<<left_cps<<std::endl;

        while (true){

            int right_delay = (2200 / left_cps) / 1;

            if(normal_mode == true){
                if(GetAsyncKeyState(VK_RBUTTON)){
                    HWND Window = GetForegroundWindow(); // Get Window
                    if(FindWindowA(("LWJGL"), nullptr) == GetForegroundWindow()) {
                        SendMessageW(GetForegroundWindow(), WM_RBUTTONDOWN, MK_RBUTTON, MAKELPARAM(0, 0));
                        SendMessageW(GetForegroundWindow(), WM_RBUTTONUP, MK_RBUTTON, MAKELPARAM(0, 0));
                        Sleep(rand() % right_delay); // Sleep Delay Time
                    }
                }
            }

    
            // Menu Options
            // Hide and Show Window
            if(GetAsyncKeyState(VK_INSERT)){
                if(consoleShown){
                    HideConsole();
                    consoleShown = false;
                } else {
                    ShowConsole();
                    consoleShown = true;
                }
                Sleep(250);
            }
            
            //Toggle
            if(GetAsyncKeyState(0xDD)){
                if(normal_mode){
                    normal_mode = false;
                    std::cout<<"Toggled Off"<<std::endl;
                } else {
                    normal_mode = true;
                    std::cout<<"Toggled On"<<std::endl;
                }
                Sleep(250);
            }

            //Inv stop click
            if(GetAsyncKeyState(0xDD)){
                Sleep(400);
            }

            // Self Destruct
            if(GetAsyncKeyState(VK_DELETE)){
                MessageBox(NULL, "NeverLose sucefully destructed", "[NeverLose]", 0);

                // Delete Prefetch
                std::string command = "del /Q ";
                std::string path = "C:\\Windows\\Prefetch\\NeverLose.*.pf";
                system(command.append(path).c_str());

                // Clean DNS Cache
                BOOL (WINAPI *DoDnsFlushResolverCache)();
                *(FARPROC *) &DoDnsFlushResolverCache = GetProcAddress(LoadLibrary("dnsapi.dll"), "DnsFlushResolverCache");
                if (!DoDnsFlushResolverCache) return FALSE;
                return DoDnsFlushResolverCache();

                return 0;
            }
        }
}