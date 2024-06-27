#pragma once
#include "ICollide.h"
#include <vector>
#include "Entity.h"
#include "RectF.h"


class Collision : public ICollide
{
	virtual bool RectCollider(float x, float y, float h, float w) override;
	virtual bool CercleCollider(float x, float y, float h, float xPlayer, float yPlayer, float hPlayer) override;
	virtual bool LineCollider(float x1, float y1, float x2, float y2, float xPlayer, float yPlayer, float hPlayer) override;

private:
	std::vector<RectF> m_CollideRect;

};

