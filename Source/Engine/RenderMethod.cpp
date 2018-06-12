#include <Engine/RenderMethod.h>
#include <Engine/Context.h>


RenderMethod::RenderMethod()
{
    Context::Instance().GetRender()->AddReceiver(this);
}

RenderMethod::~RenderMethod()
{
    Context::Instance().GetRender()->RemoveReceiver(this);
}
