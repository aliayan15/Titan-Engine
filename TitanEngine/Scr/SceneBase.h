#pragma once
#include"Action.h"
#include<unordered_map>

namespace te
{
	class TitanEngine;
	class SceneBase
	{
	public:
		SceneBase();

		virtual void Init(TitanEngine* engine) = 0;
		virtual void Update() = 0;
		virtual void CheckInput(const Action& action) = 0;
		virtual void EndScene();

		/// <summary>
		/// Register new action for a key.
		/// </summary>
		/// <param name="key"></param>
		/// <param name="actionName"></param>
		void RegisterAction(const int key, const ActionName actionName);
		/// <summary>
		/// Remove action with a key.
		/// </summary>
		/// <param name="key"></param>
		void RemoveAction(const int key);
		const std::unordered_map<int, ActionName>& getActionMap() const;

	protected:
		TitanEngine* m_engine = nullptr;
		std::unordered_map<int, ActionName> m_actionMap;
	};

}