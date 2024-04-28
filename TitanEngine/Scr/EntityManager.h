#pragma once
#include"Entity.h"
#include<vector>
#include<unordered_map>
#include"Components.h"

namespace te
{
	typedef std::vector<std::shared_ptr<Entity>> EntityVec;
	typedef std::unordered_map<std::string, EntityVec> EntityMap;

	class EntityManager
	{
	private:
		/// <summary>
		/// All entities.
		/// </summary>
		EntityVec m_entities;
		EntityVec m_toAdd;
		/// <summary>
		/// Entity map with string tag key. 
		/// </summary>
		EntityMap m_entityMap;
		EntityVec m_emptyVec;
	public:
		EntityManager();
		void Update();
		std::shared_ptr<Entity> AddEntity(const std::string& tag);
		std::shared_ptr<Entity> AddEntity(const std::string& tag, te::Utility::Vec2f position, float angleZ = 0);
		EntityVec& GetEntities();
		EntityVec& GetEntities(const std::string& tag);
	};
}
