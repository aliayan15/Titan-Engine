#include"AssetLoader.h"

namespace te
{
	void AssetLoader::loadAssets(const std::string& filePath)
	{
		std::fstream file;
		file.open(filePath, std::ios::in); // read
		if (file.fail())
		{
			std::cerr << "File fail to read!!" << std::endl;
			throw std::runtime_error("File fail to read");
			return;
		}

		std::string assetType;
		while (file >> assetType)
		{
			std::string name;
			std::string path;
			file >> name >> path;
			//std::cout << "type: " << assetType << " name: " << name << " path: " << path << std::endl;
			if (assetType == "texture")
			{
				// texture load
				sf::Texture texture;
				if (!texture.loadFromFile(path))
				{
					// error...
					std::cerr << "Fail to load texture!! path: " << path << std::endl;
					throw std::runtime_error("Fail to load texture!!");
				}
				texture.setSmooth(true);
				m_textures[name] = texture;
			}
			else if (assetType == "font")
			{
				sf::Font font;
				if (!font.loadFromFile(path))
				{
					// error...
					std::cerr << "Fail to load font!! path: " << path << std::endl;
					throw std::runtime_error("Fail to load font!!");
				}
				m_fonts[name] = font;
			}
		}
	}

	sf::Font& AssetLoader::getFont(const std::string& name)
	{
		auto it = m_fonts.find(name);
		if (it == m_fonts.end())
		{
			// Font not found
			std::cerr << "Font '" << name << "' not found!" << std::endl;
			throw std::runtime_error("Font not found");
		}
		else
		{
			return it->second;
		}
	}

	sf::Texture& AssetLoader::getTexture(const std::string& name)
	{
		auto it = m_textures.find(name);
		if (it == m_textures.end())
		{
			// Font not found
			std::cerr << "Texture '" << name << "' not found!" << std::endl;
			throw std::runtime_error("Texture not found");
		}
		else
		{
			return it->second;
		}
	}
}