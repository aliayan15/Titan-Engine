#include "SceneBase.h"

namespace te
{
	void SceneBase::EndScene()
	{
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

