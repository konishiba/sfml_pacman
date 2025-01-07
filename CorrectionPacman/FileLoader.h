#pragma once
#include "Singleton.h"

class FileLoader : public Singleton<FileLoader>
{
	string extention;

public:
	FileLoader();
public:
	vector<string> ReadAll(const char* _path) const;
};
