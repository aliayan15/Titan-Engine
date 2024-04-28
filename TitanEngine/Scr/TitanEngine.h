#pragma once
#include"SFML/Graphics.hpp"
#include<string>
#include"SceneBase.h"
#include<unordered_map>
#include "Action.h"

#include<iostream>

namespace te
{
	typedef std::shared_ptr<SceneBase> sceneType;
	class TitanEngine
	{
	public:
		TitanEngine();
		TitanEngine(unsigned windowWidth, unsigned windowHeight);
		TitanEngine(unsigned windowWidth, unsigned windowHeight, int fpsLimit);

		void Run(const sceneType startScene);
		void ChangeScene(const sceneType sceneName);
		

		sf::RenderWindow& GetWindow();
		unsigned WindowHeight() const;
		unsigned WindowWidth() const;
		int GetFps() const;

	private:
		void GameInit();
		void GameUpdate(float deltaTime);
		void UserInput();
		void KeyInput(bool isPressed);

	private:
		sf::RenderWindow m_window;
		unsigned m_windowHeight = 500;
		unsigned m_windowWidth = 800;
		sceneType m_currentScene = nullptr;
		std::string m_currentSceneName;
		bool m_isPaused = false;
		bool m_isFocused = true;
		int m_fps = 60;
		sf::Event m_input;
	};
}

