#pragma once
#include"../Utility/Vec2f.h"
#include"SFML/Graphics.hpp"

namespace te::Components
{
	struct ComponentBase
	{
		bool has = false;
		ComponentBase() {}
	};

	struct CTransform :public ComponentBase
	{
		te::Utility::Vec2f position;
		float angleZ = 0;

		CTransform() {}
		CTransform(const te::Utility::Vec2f& p)
			: position(p), angleZ(0)
		{
		}
		CTransform(const te::Utility::Vec2f& p, float a)
			: position(p), angleZ(a)
		{
		}
	};

	struct CSprite : public ComponentBase
	{
		sf::Sprite sprite;
		CSprite() = default;

		CSprite(const sf::Texture& texture, sf::Vector2f origin = sf::Vector2f(0.0f, 0.0f),
			sf::Vector2f scale = sf::Vector2f(1.0f, 1.0f))
		{
			sprite.setTexture(texture);
			sprite.setOrigin(origin);
			sprite.setScale(scale);
		}
	};

	struct CRectangleShape : public ComponentBase
	{
		sf::RectangleShape rectangleShape;
		CRectangleShape() {}
		CRectangleShape(sf::Vector2f size, sf::Vector2f origin = sf::Vector2f(0.0f, 0.0f))
		{
			rectangleShape.setSize(size);
			rectangleShape.setOrigin(origin);
		}
	};

	struct CText : public ComponentBase
	{
		sf::Text text;
		CText() = default;
	};
}