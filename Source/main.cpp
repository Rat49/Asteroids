#include "Context.h"

void WinMain()
{
    Context::Instance().GetUpdate()->FixFrequency(75);
    Context::Instance().GetUpdate()->Run();
}
