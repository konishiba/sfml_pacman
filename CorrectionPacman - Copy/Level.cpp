#include "Level.h"


Level::Level(const string& _name, RenderWindow* _window)
{
	name = _name;
    prefixPath = "Assets/Maps/";
    window = _window;
    Generate();
}

Level::~Level()
{
    for (Entity* _entity : entities)
    {
        if (PacMan* _pacMan = dynamic_cast<PacMan*>(_entity))
        {
            delete _pacMan;
        }
        else if (Wall* _wall = dynamic_cast<Wall*>(_entity))
        {
            delete _wall;
        }
        else if (Food* _food = dynamic_cast<Food*>(_entity))
        {
            delete _food;
        }
        else if (Ghost* _ghost = dynamic_cast<Ghost*>(_entity))
        {
            delete _ghost;
        }
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
            return new Wall("Walls/Wall", _shapeSize);
        }},
        { '.', [&]() {
            return new Food("Foods/Point" , _shapeSize);
        }},
        { '*', [&]() {
            return new Food("Foods/Apple" , _shapeSize);
        }},
        { 'C',  [&]() {
            return new PacMan("Pacman/Moving/PacMan_Eating" , _shapeSize);
        }},
        { 'G', [&]() {
            return new Ghost("Ghosts/Blue/BlueGhost_Vulnerable" , _shapeSize);
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
    for (const Entity* _entity : entities)
    {
        window->draw(*_entity->GetShape());
    }
}

Entity* Level::checkCollision(const Vector2f& _targetPosition)
{
    for (Entity* _entity : entities)
    {
        if()
    }
    return nullptr;
}

