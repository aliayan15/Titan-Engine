#include "TitanEngine.h"



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

	void TitanEngine::Run(const sceneType startScene)
	{
		GameInit();
		ChangeScene(startScene);

		while (m_window.isOpen())
		{
			static sf::Clock clock;
			float dt = clock.restart().asSeconds();
			UserInput();
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
		m_currentScene->Update(deltaTime);
	}

	void TitanEngine::ChangeScene(const sceneType scenePtr)
	{
		if (scenePtr == nullptr)
		{
			std::cout << "Null Scene!!" << std::endl;
			return;
		}
		if (m_currentScene != nullptr)
			m_currentScene->EndScene();
		m_currentScene = scenePtr;
		m_currentScene->Init(this);
	}


	void TitanEngine::UserInput()
	{
		// check all the window's events that were triggered since the last iteration of the loop
		while (m_window.pollEvent(m_input))
		{
			if (m_input.type == sf::Event::Closed)
				m_window.close();

			switch (m_input.type)
			{
			case sf::Event::KeyPressed:
				if (m_input.key.scancode == sf::Keyboard::Scan::P) // Pause
					m_isPaused = !m_isPaused;
				KeyInput(true);
				break;
			case sf::Event::KeyReleased:
				KeyInput(false);
				break;
			case sf::Event::MouseButtonPressed:
				break;
			case sf::Event::LostFocus:
				m_isFocused = false;
				break;
			case sf::Event::GainedFocus:
				m_isFocused = true;
				break;
			default:
				break;
			}
		}
	}

	void TitanEngine::KeyInput(bool isPressed)
	{
		if (!m_isPaused && m_isFocused) return;
		if (m_currentScene->getActionMap().find(m_input.key.code) == m_currentScene->getActionMap().end()) return;

		ActionType actionType = isPressed ? ActionType::Pressed : ActionType::Released;
		m_currentScene->CheckInput(Action(m_currentScene->getActionMap().at(m_input.key.code), actionType));
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