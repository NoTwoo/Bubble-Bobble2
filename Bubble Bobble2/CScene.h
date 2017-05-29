#pragma once

#include "macro.h"
#include "enum.h"

class CScene
{
public:
	virtual void Initialize() = 0;
	virtual SCENE_ID Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	CScene() = default;
	virtual ~CScene() = default;
};