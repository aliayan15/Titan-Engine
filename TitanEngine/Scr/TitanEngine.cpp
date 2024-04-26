#include "TitanEngine.h"
#include<iostream>

namespace te
{
	TitanEngine::TitanEngine()
	{
	}
	TitanEngine::TitanEngine(unsigned windowWidth, unsigned windowHeight)
		:m_windowHeight(windowHeight), m_windowWidth(windowWidth)
	{
	}
	TitanEngine::TitanEngine(unsigned windowWidth, unsigned windowHeight, int fpsLimit)
		:m_windowHeight(windowHeight), m_windowWidth(windowWidth), m_fps(fpsLimit)
	{
	}

	void TitanEngine::Run(const std::string& startScene)
	{
		GameInit();
		ChangeScene(startScene);

		while (m_window.isOpen())
		{
			static sf::Clock clock;
			float dt = clock.restart().asSeconds();
			// user input check
			if (!m_isPaused && m_isFocused)
			{
				GameUpdate(dt);
			}
		}
	}
	void TitanEngine::GameInit()
	{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 4;
		m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), "Titan Engine", sf::Style::Close, settings);
		m_window.setFramerateLimit(m_fps);
		m_window.setKeyRepeatEnabled(false);
	}
	void TitanEngine::GameUpdate(float deltaTime)
	{
		m_currentScene->Update();
	}

	void TitanEngine::ChangeScene(const std::string& sceneName)
	{
		if (m_sceneMap.find(sceneName) == m_sceneMap.end())
		{
			std::cout << "Scene is not found: " << sceneName << std::endl;
			return;
		}
		if (m_currentScene != nullptr)
			m_currentScene->EndScene();
		m_currentScene = m_sceneMap.at(sceneName);
		m_currentScene->Init(this);
	}

	void TitanEngine::AddScene(const std::string& sceneName, sceneType scene)
	{
		m_sceneMap[sceneName] = scene;
	}

	sf::RenderWindow& TitanEngine::GetWindow()
	{
		return m_window;
	}
	unsigned TitanEngine::WindowHeight() const
	{
		return m_windowHeight;
	}
	unsigned TitanEngine::WindowWidth() const
	{
		return m_windowWidth;
	}
	int TitanEngine::GetFps() const
	{
		return m_fps;
	}
}