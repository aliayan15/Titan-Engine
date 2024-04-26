#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include"SceneBase.h"
#include<unordered_map>

namespace te
{
	typedef std::shared_ptr<SceneBase> sceneType;
	class TitanEngine
	{
	public:
		TitanEngine();
		TitanEngine(unsigned windowWidth, unsigned windowHeight);
		TitanEngine(unsigned windowWidth, unsigned windowHeight, int fpsLimit);

		void Run(const std::string& startScene);
		void ChangeScene(const std::string& sceneName);
		void AddScene(const std::string& sceneName, sceneType scene);
		sf::RenderWindow& GetWindow();
		unsigned WindowHeight() const;
		unsigned WindowWidth() const;
		int GetFps() const;

	private:
		void GameInit();
		void GameUpdate(float deltaTime);

	private:
		sf::RenderWindow m_window;
		unsigned m_windowHeight = 500;
		unsigned m_windowWidth = 800;
		sceneType m_currentScene = nullptr;
		std::unordered_map<std::string, sceneType> m_sceneMap;
		std::string m_currentSceneName;
		bool m_isPaused = false;
		bool m_isFocused = true;
		int m_fps = 60;
	};
}

