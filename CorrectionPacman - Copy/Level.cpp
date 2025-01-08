#include "Level.h"
#include "FileLoader.h"
#include "PacMan.h"
#include "Food.h"

Level::Level(const string& _name, RenderWindow* _window)
{
    name = _name;
    prefixPath = "Assets/Maps/";
    window = _window;
    points = 0;
    Generate();
}

Level::~Level()
{
    for (Entity* _entity : entities)
    {
        delete _entity;
    }
}

void Level::Update()
{
    for (Entity* _entity : entities)
    {
        _entity->Update();
    }
    Display();
}

Entity* Level::CheckCollision(const Vector2f& _targetPosition)
{
    for (Entity* _entity : entities)
    {
        if (_entity->GetPosition() == _targetPosition) return _entity;
    }

    return nullptr;
}

void Level::AddScore(const int _points)
{
    points += _points;
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
        mapSize = Vector2u(static_cast<unsigned>(_dataLineCount * _shapeSize.x),
                            static_cast<unsigned>(_dataCount * _shapeSize.y));

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
            return new Entity(this, "Walls/Wall", _shapeSize, CT_BLOCK);
        }},
        { '.', [&]() {
            return new Food(this,"Foods/Point" , _shapeSize, FT_EATABLE, 10);
        }},
        { '*', [&]() {
            return new Food(this,"Foods/Apple" , _shapeSize,  FT_EATABLE, 100);
        }},
        { 'C',  [&]() {
            return new PacMan(this, _shapeSize);
        }},
        { 'G', [&]() {
            return new Food(this,"Ghosts/Blue/BlueGhost_Vulnerable" , _shapeSize, FT_EATABLE, 1000);
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
    _entity->SetPosition(Vector2f(_x ,_y ) + _shapeSize / 2.0f);
}

void Level::Display() const
{
    for (Entity* _entity : entities)
    {
        window->draw(_entity->GetShape());
    }
}


