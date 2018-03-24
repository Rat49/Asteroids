#include <RenderMethod.h>
#include <Context.h>

using namespace sfe;

RenderMethod::RenderMethod()
{
    Context::GetRender()->AddReceiver(this);
}

RenderMethod::~RenderMethod()
{
    Context::GetRender()->RemoveReceiver(this);
}
