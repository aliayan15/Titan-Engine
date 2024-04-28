#include "Entity.h"

void te::Entity::Destroy()
{
	m_alive = false;
}

const std::string& te::Entity::tag() const
{
	return m_tag;
}

bool te::Entity::isActive()
{
	return m_alive;
}

