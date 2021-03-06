#include "ClockMenus.h"

void CPUMenu::Update(StateMachine &stateMachine, u64 kDown)
{
    if (kDown & KEY_UP)
        selection--;

    if (kDown & KEY_DOWN)
        selection++;

    long int size = CPUClocks.size();
    if (selection < 0)
        selection = size - 1;
    if (size <= selection)
        selection = 0;

    if (kDown & KEY_A)
    {
        Utils::changeConfiguration(CPUClocks, selection);
        stateMachine.PushState("config");
        return;
    }

    Utils::printItems(CPUClocks, "CPU Clocks", selection);

    if (kDown & KEY_B)
    {
        stateMachine.PushState("config");
        return;
    }
}

void GPUMenu::Update(StateMachine &stateMachine, u64 kDown)
{
    if (kDown & KEY_UP)
        selection--;

    if (kDown & KEY_DOWN)
        selection++;

    long int size = GPUClocks.size();
    if (selection < 0)
        selection = size - 1;
    if (size <= selection)
        selection = 0;

    if (kDown & KEY_A)
    {
        Utils::changeConfiguration(GPUClocks, selection);
        stateMachine.PushState("config");
        return;
    }

    Utils::printItems(GPUClocks, "GPU Clocks", selection);

    if (kDown & KEY_B)
    {
        stateMachine.PushState("config");
        return;
    }
}

void MEMMenu::Update(StateMachine &stateMachine, u64 kDown)
{
    if (kDown & KEY_UP)
        selection--;

    if (kDown & KEY_DOWN)
        selection++;

    long int size = MEMClocks.size();
    if (selection < 0)
        selection = size - 1;
    if (size <= selection)
        selection = 0;

    if (kDown & KEY_A)
    {
        Utils::changeConfiguration(MEMClocks, selection);
        stateMachine.PushState("config");
        return;
    }

    Utils::printItems(MEMClocks, "MEM Clocks", selection);

    if (kDown & KEY_B)
    {
        stateMachine.PushState("config");
        return;
    }
}