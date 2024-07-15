#pragma once
#include "ICollide.h"
#include <map>
#include "Entity.h"
#include "RectF.h"

namespace Homer
{
	class Collision : public ICollide
	{
		virtual bool RectCollider(ColliderType type, float x, float y, float h, float w) override;
		virtual bool CercleCollider(float x, float y, float h, float xPlayer, float yPlayer, float hPlayer) override;
		virtual bool LineCollider(float x1, float y1, float x2, float y2, float xPlayer, float yPlayer, float hPlayer) override;

	private:
		std::map<ColliderType, RectF> m_CollideMap;

	};
}

