#include "SceneBase.h"

namespace te
{
	SceneBase::SceneBase(te::TitanEngine* engine) :m_engine(engine)
	{
	}
	void SceneBase::EndScene()
	{
	}
	void SceneBase::Render(sf::RenderWindow& window)
	{
		window.clear();
		auto ents = m_entityManager.GetEntities();
		for (auto& e : ents)
		{
			sf::Drawable* ptr_draw = nullptr;
			sf::Transformable* ptr_transform = nullptr;
			if (e->hasComponent<te::Components::CRectangleShape>())
			{
				ptr_draw = &e->getComponent<te::Components::CRectangleShape>().rectangleShape;
				ptr_transform = &e->getComponent<te::Components::CRectangleShape>().rectangleShape;
			}
			else if (e->hasComponent<te::Components::CSprite>())
			{
				ptr_draw = &e->getComponent<te::Components::CSprite>().sprite;
				ptr_transform = &e->getComponent<te::Components::CSprite>().sprite;
			}
			else if (e->hasComponent<te::Components::CText>())
			{
				ptr_draw = &e->getComponent<te::Components::CText>().text;
				ptr_transform = &e->getComponent<te::Components::CText>().text;
			}

			if (ptr_draw != nullptr)
			{
				auto e_transform = e->getComponent<te::Components::CTransform>();
				ptr_transform->setPosition(e_transform.position);
				ptr_transform->setRotation(e_transform.angleZ);
				window.draw(*ptr_draw);
			}
		}
		window.display();
	}
	void SceneBase::RegisterAction(const int key, const ActionName actionName)
	{
		m_actionMap[key] = actionName;
	}
	void SceneBase::RemoveAction(const int key)
	{
		m_actionMap.erase(key);
	}
	const std::unordered_map<int, ActionName>& SceneBase::getActionMap() const
	{
		return m_actionMap;
	}
}

