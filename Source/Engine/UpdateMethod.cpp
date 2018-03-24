#include <UpdateMethod.h>
#include <Context.h>

using namespace sfe;

UpdateMethod::UpdateMethod()
{
    Context::GetUpdate()->AddReceiver(this);
}

UpdateMethod::~UpdateMethod()
{
    Context::GetUpdate()->RemoveReceiver(this);
}
