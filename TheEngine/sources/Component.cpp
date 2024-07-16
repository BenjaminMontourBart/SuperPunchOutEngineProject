#include "Component.h"
#include <Engine.h>


Homer::Component::Component(Entity* parent) : m_Entity(parent)
{ 
}
Homer::IInput& Homer::Component::Input() const
{
    return Engine::Get().Input();
}
Homer::ILogger& Homer::Component::Logger() const
{
    return Engine::Get().Logger();
}
Homer::IGFX& Homer::Component::Graphics() const
{
    return Engine::Get().Gfx();
}

Homer::ISound& Homer::Component::Audio() const
{
    return Engine::Get().Sound();
}

Homer::IWorld& Homer::Component::World() const
{
    return Engine::Get().World();
}
