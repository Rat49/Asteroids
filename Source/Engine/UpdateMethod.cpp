#include <UpdateMethod.h>
#include <Context.h>

UpdateMethod::UpdateMethod()
{
    Context::Instance().GetUpdate()->AddReceiver(this);
}

UpdateMethod::~UpdateMethod()
{
    Context::Instance().GetUpdate()->RemoveReceiver(this);
}
