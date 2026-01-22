#pragma once

#include <UniDx.h>
#include <vector>

using namespace UniDx;

namespace UniDx
{
    class Scene;
    class TextMesh;
}

class MainGame : public UniDx::Singleton<MainGame>
{
public:
    virtual ~MainGame();

    void AddScore(int n);
    void CheckGameClear();

    unique_ptr<UniDx::Scene> CreateScene();

protected:
    int score = 0;
    unique_ptr<UniDx::GameObject> mapObj;
    UniDx::TextMesh* scoreTextMesh;
    UniDx::TextMesh* gameClearTextMesh;
    std::vector<GameObject*> coinObjects;
    Player* player;

    void createMap();
};