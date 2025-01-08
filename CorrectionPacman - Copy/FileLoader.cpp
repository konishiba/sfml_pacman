#include "FileLoader.h"

FileLoader::FileLoader()
{
	extention = ".txt";
}

vector<string> FileLoader::ReadAll(const char* _path) const
{

	const string& _filePath = string(_path);
	const string& _finalFileName = _filePath.empty() ? "Unknown" : _filePath + extention;

	ifstream _stream = ifstream(_finalFileName);

	if (!_stream.is_open())
	{
		throw exception(string("impossible de charger le fichier : " + _finalFileName).c_str());
	}

	vector<string> _content;
	string _line;
	while (getline(_stream, _line))
	{
		_content.push_back(_line);
	}
	return _content;
}
