#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<unordered_map>

#include "SFML/Graphics.hpp"

namespace te
{
	class AssetLoader
	{
	public:
		AssetLoader() = default;
		void loadAssets(const std::string& filePath);
		sf::Font& getFont(const std::string& name);
		sf::Texture& getTexture(const std::string& name);

	private:
		std::unordered_map<std::string, sf::Font> m_fonts;
		std::unordered_map<std::string, sf::Texture> m_textures;
	};
}
