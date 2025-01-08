#include "TextureManager.h"

TextureManager::TextureManager()
{
	prefix = "Assets/Textures/";
	extention = ".png";
}

void TextureManager::InitShape(RectangleShape& _shape, Texture& _texture,const string& _path)
{
	if (_texture.loadFromFile(prefix + _path + extention))
	{
		_shape.setTexture(&_texture);
	}
	else 
	{
		cerr << "pd" << endl;
	}
}
