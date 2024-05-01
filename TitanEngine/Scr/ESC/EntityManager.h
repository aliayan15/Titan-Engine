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
		/// <summary>
		/// Add new entity.
		/// </summary>
		/// <param name="tag"></param>
		/// <returns></returns>
		std::shared_ptr<Entity> AddEntity(const std::string& tag);
		/// <summary>
		/// Add new entity.
		/// </summary>
		/// <param name="tag"></param>
		/// <param name="position"></param>
		/// <param name="angleZ"></param>
		/// <returns></returns>
		std::shared_ptr<Entity> AddEntity(const std::string& tag, te::Utility::Vec2f position, float angleZ = 0);
		/// <summary>
		/// Add new entity.
		/// </summary>
		/// <param name="position"></param>
		/// <param name="angleZ"></param>
		/// <returns></returns>
		std::shared_ptr<Entity> AddEntity(te::Utility::Vec2f position= te::Utility::Vec2f(0,0), float angleZ = 0);
		EntityVec& GetEntities();
		EntityVec& GetEntities(const std::string& tag);
	};
}
