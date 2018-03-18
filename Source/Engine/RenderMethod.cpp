#include "RenderMethod.h"
#include "Context.h"


RenderMethod::RenderMethod()
{
    Context::Instance().GetRender()->AddReceiver(this);
}

RenderMethod::~RenderMethod()
{
    Context::Instance().GetRender()->RemoveReceiver(this);
}
