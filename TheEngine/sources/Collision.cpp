#include "Collision.h"
#include <iostream>

bool Collision::RectCollider(float x, float y, float h, float w)
{
	m_CollideRect.push_back({ x, y, h, w });
	if (m_CollideRect.size() > 1)
	{
		for (int i = 0; i < m_CollideRect.size(); i++)
		{
			for (int j = i + 1; j < m_CollideRect.size(); j++)
			{

				if (m_CollideRect[i].x + m_CollideRect[i].w > m_CollideRect[j].x && m_CollideRect[i].x < m_CollideRect[i].x + m_CollideRect[j].w && m_CollideRect[i].y + m_CollideRect[i].h > m_CollideRect[j].y && m_CollideRect[i].y < m_CollideRect[j].y + m_CollideRect[j].h)
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

