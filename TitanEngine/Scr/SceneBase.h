#pragma once


namespace te
{
	class TitanEngine;
	class SceneBase
	{
	public:
		SceneBase();

		virtual void Init(TitanEngine* engine) = 0;
		virtual void Update() = 0;
		virtual void EndScene();

	protected:
		TitanEngine* m_engine = nullptr;
	};

}