#include "TextureManager.h"

TextureManager::TextureManager()
{
	prefix = "Assets/Textures/";
	extention = ".png";
	resetTextureEnd = true;
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

void TextureManager::UpdateTexture(RectangleShape& _shape, Texture& _texture)
{
	IntRect _currentIntRect = _shape.getTextureRect();
	Vector2u _sheetSize = _shape.getTexture()->getSize(), _spriteOffset = { _sheetSize.y,0 };

	if (resetTextureEnd == false)
	{
		_currentIntRect.position = _currentIntRect.position != Vector2i(_sheetSize.x - _spriteOffset.x, 0)
			? _currentIntRect.position + Vector2i(_spriteOffset) : _currentIntRect.position;
	}
	else
	{
		_currentIntRect.position = _currentIntRect.position != Vector2i(_sheetSize.x - _spriteOffset.x, 0)
			? _currentIntRect.position + Vector2i(_spriteOffset) : Vector2i(0, 0);
	}

	_shape.setTextureRect(_currentIntRect);
}

void TextureManager::SetTextureRectOnShape(RectangleShape& _shape, const IntRect& _rect)
{
	_shape.setTextureRect(_rect);
}

void TextureManager::SetTextureRectOnShape(RectangleShape& _shape, Vector2i currentFrame, Vector2i _spriteSize)
{
}
