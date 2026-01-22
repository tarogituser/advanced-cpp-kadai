#pragma once

#include <UniDx.h>

class Coin : public UniDx::Behaviour
{
protected:
	virtual void OnEnable() override;
	virtual void Update() override;

	float yRot;
	float rotateSpeed = 240.0f;
};

