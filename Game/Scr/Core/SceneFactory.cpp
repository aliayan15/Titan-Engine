#include "SceneFactory.h"
#include"TestScene.h"

sceneType SceneFactory::CreateScene(SceneName name)
{
	switch (name)
	{
	case SceneName::None:
		break;
	case SceneName::Menu:
		break;
	case SceneName::Game:
		break;
	default:
		break;
	}
	return std::make_shared<TestScene>();
}
