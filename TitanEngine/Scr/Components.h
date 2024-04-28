#pragma once
#include"Utility/Vec2f.h"

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
}