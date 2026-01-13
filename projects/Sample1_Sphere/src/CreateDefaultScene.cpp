// CreateDefaultScene.cpp
// デフォルトのシーンを生成します

#include <numbers>

#include <UniDx.h>
#include <UniDx/Scene.h>
#include <UniDx/PrimitiveRenderer.h>

#include "ShpereController.h"

using namespace std;
using namespace UniDx;

unique_ptr<Scene> CreateDefaultScene()
{
    // シーンを作って戻す
    return make_unique<Scene>(

        // 球のGameObject
        make_unique<GameObject>(L"球",

            // 球コンポーネントを作成してアタッチ
            SphereRenderer::create<VertexPT>(L"resource/Albedo.hlsl", L"resource/wall.png"),

            // 球の操作プログラムを作成してアタッチ
            make_unique<ShpereController>()
        ),

        // カメラのGameObject
        make_unique<GameObject>(L"カメラ", Vector3(0, 0, -2),
            make_unique<Camera>()
        )
    );
}


void DestroyDefaultScene()
{
}