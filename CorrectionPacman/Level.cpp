#include "Level.h"


Level::Level(const string& _name)
{
	name = _name;
    prefixPath = "Assets/Maps/";
    Generate();
}

Level::~Level()
{
    for (Entity* _entity : entities)
    {
        delete _entity;
    }
}

void Level::Generate()
{
    try
    {
        const vector<string>& _data = FileLoader::GetInstance().ReadAll((prefixPath + name).c_str());
        Vector2f _shapeSize = Vector2f(20.0f, 20.0f);

        const int _dataCount = static_cast<const int>(_data.size());
        const int _dataLineCount = static_cast<const int>(_data[0].size());

        for (int _rowIndex = 0; _rowIndex < _dataLineCount; _rowIndex++)
        {
            for (int _columnIndex = 0; _columnIndex < _dataCount; _columnIndex++)
            {
                const char _symbol = _data[_columnIndex][_rowIndex];
                SpawnEntity(_symbol, Vector2f(_rowIndex, _columnIndex), _shapeSize);

            }
        }
        mapSize = Vector2u(static_cast<unsigned>(_dataLineCount * _shapeSize.x), static_cast<unsigned>(_dataCount * _shapeSize.y));

    }
    catch (const exception& _error)
    {
        cerr << _error.what() << endl;
    }
}

void Level::SpawnEntity(const char& _symbol, const Vector2f _coords, Vector2f& _shapeSize)
{
    map<char, function<Entity* ()>> _textureDatabase =
    {
        {'#', [&]() {
            return new Entity("Walls/Wall", _shapeSize);
        }},
        { '.', [&]() {
            return new Entity("Foods/Point" , _shapeSize);
        }},
        { '*', [&]() {
            return new Entity("Foods/Apple" , _shapeSize);
        }},
        { 'C',  [&]() {
            return new PacMan("Pacman/Moving/PacMan_Eating_1" , _shapeSize);
        }},
        { 'G', [&]() {
            return new Entity("Ghosts/Blue/BlueGhost_Vulnerable" , _shapeSize);
        }}
    };

    Entity* _entity = _textureDatabase[_symbol]();
    PlaceEntity(Vector2i(_coords.x, _coords.y), _shapeSize, _entity);
    entities.push_back(_entity);
}

void Level::PlaceEntity(Vector2i _coords, Vector2f& _shapeSize, Entity* _entity)
{
    const float _x = _coords.x * _shapeSize.x;
    const float _y = _coords.y * _shapeSize.y;
    _entity->SetPosition(Vector2f(_x ,_y ));
}

void Level::Display(RenderWindow& _window) const
{
    for (const Entity* _entity : entities)
    {
        _window.draw(_entity->GetShape());
    }
}

