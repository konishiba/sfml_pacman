#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

class TextureManager : public Singleton<TextureManager>
{
	string prefix;
	string extention;
	bool resetTextureEnd;


public:
	inline void SetResetTextureEnd(bool _isReset)
	{
		resetTextureEnd = _isReset;
	}

public:
	TextureManager();

public:
	void InitShape(RectangleShape& _shape, Texture& _texture,const string& _path);

	void UpdateTexture(RectangleShape& _shape, Texture& _texture);

	void SetTextureRectOnShape(RectangleShape& _shape, const IntRect& _rect);
	void SetTextureRectOnShape(RectangleShape& _shape, Vector2i currentFrame, Vector2i _spriteSize);

};

