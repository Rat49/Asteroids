#include <Engine/UpdateMethod.h>
#include <Engine/Context.h>

using namespace sfe;

UpdateMethod::UpdateMethod()
{
    Context::Instance().GetUpdate()->AddReceiver(this);
}

UpdateMethod::~UpdateMethod()
{
    Context::Instance().GetUpdate()->RemoveReceiver(this);
}
