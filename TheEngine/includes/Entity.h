#pragma once
#include "IDrawable.h"
#include "IUpdatable.h"
#include <Component.h>
#include <RectF.h>
#include <vector>
#include <map>
#include <string>

namespace Homer
{
	class Entity
	{
	public:
		~Entity();
		Entity(const char* name);
		const char* GetName() { return m_Name; }
		void Update(float dt);
		void Draw();

		void SetPosition(float x, float y)
		{
			m_X = x;
			m_Y = y;
		}

		void SetSize(float w, float h)
		{
			m_Width = w;
			m_Height = h;
		}

		void Translate(float dx, float dy)
		{
			m_X += dx;
			m_Y += dy;
		}

		void Scale(float dw, float dh)
		{
			m_Width *= dw;
			m_Width *= dh;
		}

		void Rotate(double angle)
		{
			m_Angle += angle;
		}
		void SetRotation(double angle)
		{
			m_Angle = angle;
		}
		float GetX() const { return m_X; }
		float GetY() const { return m_Y; }
		float GetWidth() const { return m_Width; }
        float GetHeight() const { return m_Height; }

		double GetRotation() const { return m_Angle; }

		void GetRect(RectF* rect)
		{
			*rect = {
				m_X, m_Y,
				m_Width, m_Height
			};
		}
		template<typename T>T* AddComponent()
		{
			T* cmp = new T();
			const type_info* type = &typeid(*cmp);
			m_Components.emplace(type, cmp);
			IUpdatable* update = dynamic_cast<IUpdatable*>(cmp);
			if (update != nullptr)
			{
				m_Update.push_back(update);
			}
			IDrawable* draw = dynamic_cast<IDrawable*>(cmp);
			if (draw != nullptr)
			{
				m_Draw.push_back(draw);
			}
			return cmp;
		}
		template<typename T>T* GetComponent()
		{
			const type_info* type = &typeid(T);
			return m_Components.at(type);
		}


	private:

		std::map<const type_info*, Component*> m_Components;
		std::vector<IUpdatable*> m_Update;
		std::vector<IDrawable*> m_Draw;

		float m_X = 0.0f;
		float m_Y = 0.0f;
		double m_Angle = 0.0;
		float m_Width = 1.0f;
		float m_Height = 1.0f;
		const char* m_Name;

	};
}
