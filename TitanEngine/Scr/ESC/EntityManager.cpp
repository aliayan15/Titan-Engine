#include"EntityManager.h"

namespace te
{
	EntityManager::EntityManager()
	{
	}
	void EntityManager::Update()
	{
		// remove dead entities
		for (size_t i = 0; i < m_entities.size();)
		{
			if (!m_entities[i]->m_alive)
			{
				std::erase(m_entityMap.at(m_entities[i]->m_tag), m_entities[i]);
				std::erase(m_entities, m_entities[i]);
				continue;
			}
			i++;
		}
		// add new entities
		for (auto& e : m_toAdd)
		{
			m_entities.push_back(e);
			// add to entity map by tag
			if (m_entityMap.find(e->m_tag) == m_entityMap.end())
			{
				// no key found
				EntityVec newEVec;
				newEVec.push_back(e);
				m_entityMap[e->m_tag] = newEVec;
			}
			else
			{
				m_entityMap.at(e->m_tag).push_back(e);
			}
		}
		m_toAdd.clear();
	}

	
	std::shared_ptr<Entity> EntityManager::AddEntity(const std::string& tag, te::Utility::Vec2f position, float angleZ)
	{
		auto e = std::shared_ptr<Entity>(new Entity(tag));
		e->addComponent<te::Components::CTransform>(position, angleZ);
		m_toAdd.push_back(e);
		return e;
	}


	std::shared_ptr<Entity> EntityManager::AddEntity(te::Utility::Vec2f position, float angleZ)
	{
		auto e = std::shared_ptr<Entity>(new Entity());
		e->addComponent<te::Components::CTransform>(position, angleZ);
		m_toAdd.push_back(e);
		return e;
	}

	EntityVec& EntityManager::GetEntities()
	{
		return m_entities;
	}
	EntityVec& EntityManager::GetEntities(const std::string& tag)
	{
		if (m_entityMap.find(tag) == m_entityMap.end())
		{
			// no key found
			return m_emptyVec;
		}
		else
		{
			return m_entityMap.at(tag);
		}
	}
}