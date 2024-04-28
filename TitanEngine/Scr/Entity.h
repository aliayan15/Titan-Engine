#pragma once
#include <string>
#include<memory>
#include"Components.h"
#include<tuple>
#include <type_traits>

namespace te
{
	// Entities only can be created by Entity Manager 
	typedef std::tuple<
		te::Components::CTransform
	> ComponentTuple;

	class Entity
	{
		friend class EntityManager;
	public:
		void Destroy();
		const std::string& tag() const;
		bool isActive();
		~Entity() = default;

		template<typename T> T& getComponent()
		{
			static_assert(std::is_base_of<ComponentBase, T>::value,
				"T must be derived from ComponentBase");
			return std::get<T>(m_components);
		}
		template<typename T> const T& getComponent() const
		{
			static_assert(std::is_base_of<ComponentBase, T>::value,
				"T must be derived from ComponentBase");
			return std::get<T>(m_components);
		}
		template<typename T, typename... TArgs> T& addComponent(TArgs&&... mArgs)
		{
			static_assert(std::is_base_of<ComponentBase, T>::value,
				"T must be derived from ComponentBase");
			auto& component = getComponent<T>();
			component = T(std::forward<TArgs>(mArgs)...);
			component.has = true;
			return component;
		}
		template<typename T> bool hasComponent() const
		{
			static_assert(std::is_base_of<ComponentBase, T>::value,
				"T must be derived from ComponentBase");
			return std::get<T>(m_components).has;
		}
		template<typename T> void removeComponent()
		{
			static_assert(std::is_base_of<ComponentBase, T>::value,
				"T must be derived from ComponentBase");
			getComponent<T>() = T();
		}

	private:
		const std::string m_tag = "default";
		bool m_alive = true;
		ComponentTuple m_components;

		Entity(const std::string& tag);
	};
}
