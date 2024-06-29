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
		for (int i = 0; i < m_CollideMap.size(); i++)
		{
			if (m_CollideMap.emplace(i).first != m_CollideMap.find(type))
			{
				float a = m_CollideMap.emplace(i).second;//(x)
				/*for (int j = i + 1; j < m_CollideMap.size(); j++)
				{

					if (m_CollideMap[type].x + m_CollideMap[type].w > m_CollideMap.emplace(i).second.x && m_CollideRect[i].x < m_CollideRect[i].x + m_CollideRect[j].w && m_CollideRect[i].y + m_CollideRect[i].h > m_CollideRect[j].y && m_CollideRect[i].y < m_CollideRect[j].y + m_CollideRect[j].h)
					{
						std::cout << "wtf" << std::endl;
						return true;
					}
				}*/
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

