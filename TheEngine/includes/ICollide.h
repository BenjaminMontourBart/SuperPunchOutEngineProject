#pragma once


enum ColliderType
{
	PlayerType,
	EnemyType,
	Collider,
	Trigger
};

class ICollide
{
public:
	//virtual void IsColliding(tilemap[][], rx, ry, rw, rh)
	virtual bool RectCollider(ColliderType type, float x, float y, float h, float w) = 0;
	virtual bool CercleCollider(float x, float y, float h, float xPlayer, float yPlayer, float hPlayer) = 0;
	virtual bool LineCollider(float x1, float y1, float x2, float y2, float xPlayer, float yPlayer, float hPlayer) = 0;

};
