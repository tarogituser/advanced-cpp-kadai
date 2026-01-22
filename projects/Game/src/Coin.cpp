#include "Coin.h"

using namespace UniDx;

void Coin::OnEnable()
{
	yRot = transform->rotation.get().y;
}

void Coin::Update()
{
	float xRot = transform->rotation.get().x;
	float zRot = transform->rotation.get().z;

	//‰ñ“]ˆ—
	yRot += rotateSpeed * Time::deltaTime;
	transform->rotation = Quaternion::Euler(xRot, yRot, zRot);
}