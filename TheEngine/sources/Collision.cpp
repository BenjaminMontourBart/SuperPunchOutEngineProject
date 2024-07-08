#include "Collision.h"
#include <iostream>
#include <string>

bool Collision::RectCollider(ColliderType type, float x, float y, float h, float w)
{

	if (m_CollideMap.find(type) != m_CollideMap.end())
	{
		m_CollideMap[type] = { x, y, h, w };
	}
	else
	{
		m_CollideMap.insert({ type, { x, y, h, w } });
	}


	if (m_CollideMap.size() > 1)
	{
		std::map<ColliderType, RectF>::iterator it;

		for (it = m_CollideMap.begin(); it != m_CollideMap.end(); it++)
		{
			if (it->first != type)
			{

				if (m_CollideMap[type].x + m_CollideMap[type].w > it->second.x && m_CollideMap[type].x < it->second.x + it->second.w && m_CollideMap[type].y + m_CollideMap[type].h >  it->second.y && m_CollideMap[type].y < it->second.y + it->second.h)
				{
					std::cout << "wtf" << std::endl;
					return true;
				}
			}
		}
	}
	return false;

}

bool Collision::CercleCollider(float x, float y, float h, float xPlayer, float yPlayer, float hPlayer)
{
	if (hPlayer + h > (x - xPlayer) && hPlayer + h > (y - yPlayer))
	{
		return true;
	}
	return false;
}

bool Collision::LineCollider(float x1, float y1, float x2, float y2, float xPlayer, float yPlayer, float hPlayer)
{
	return nullptr;
}

