#pragma once
#include"SceneBase.h"

enum class SceneName
{
	None = 0,
	Menu,
	Game
};

typedef std::shared_ptr<te::SceneBase> sceneType;

/// <summary>
/// Responsible for creating scenes.
/// </summary>
class SceneFactory
{
	
public:
	SceneFactory() = default;
	sceneType CreateScene(SceneName name, te::TitanEngine* engine);
};

