#pragma once
#include"SFML/Graphics.hpp"
#include<string>

namespace te
{

	class TitanEngine
	{
	public:
		TitanEngine();
		TitanEngine(unsigned windowWidth, unsigned windowHeight);
		TitanEngine(unsigned windowWidth, unsigned windowHeight, int fpsLimit);

		void run(const std::string& startScene);
		void changeScene(const std::string& sceneName);
		sf::RenderWindow& getWindow();
		unsigned windowHeight() const;
		unsigned windowWidth() const;
		int getFps() const;

	private:
		void gameInit();
		void gameUpdate(float deltaTime);

	private:
		sf::RenderWindow m_window;
		sf::Clock m_clock;
		unsigned m_windowHeight = 500;
		unsigned m_windowWidth = 800;
		bool m_isPaused = false;
		bool m_isFocused = true;
		int m_fps = 60;
	};
}

