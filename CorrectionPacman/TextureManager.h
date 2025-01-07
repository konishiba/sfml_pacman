#pragma once
#include "CoreMinimal.h"
#include "Singleton.h"

class TextureManager : public Singleton<TextureManager>
{
	string prefix;
	string extention;

public:
	TextureManager();

public:
	void InitShape(RectangleShape& _shape, Texture& _texture,const string& _path);
};

