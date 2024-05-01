#include "Entity.h"

void te::Entity::Destroy()
{
	m_alive = false;
}

te::Entity::Entity(const std::string& tag) :m_tag(tag)
{
}

const std::string& te::Entity::tag() const
{
	return m_tag;
}

bool te::Entity::isActive()
{
	return m_alive;
}

