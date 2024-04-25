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

	void TitanEngine::run(const std::string& startScene)
	{
		gameInit();
		changeScene(startScene);
		
		while (m_window.isOpen())
		{
			sf::Time elapsed = m_clock.restart();
			// user input check
			if (!m_isPaused && m_isFocused)
			{
				gameUpdate(elapsed.asSeconds());
			}
		}
	}
	void TitanEngine::gameInit()
	{
	}
	void TitanEngine::gameUpdate(float deltaTime)
	{

	}

	void TitanEngine::changeScene(const std::string& sceneName)
	{
	}

	sf::RenderWindow& TitanEngine::getWindow()
	{
		return m_window;
	}
	unsigned TitanEngine::windowHeight() const
	{
		return m_windowHeight;
	}
	unsigned TitanEngine::windowWidth() const
	{
		return m_windowWidth;
	}
	int TitanEngine::getFps() const
	{
		return m_fps;
	}
}