#pragma once
#include "Component.h"
#include "IUpdatable.h"
#include "IDrawable.h"
#include <string>

namespace Homer
{

	class BackGround :
		public Component,
		public IUpdatable,
		public IDrawable
	{
	public:
		virtual void Start();
		virtual void Update(float dt);
		void LoadTexture(const std::string filename);
		virtual void Draw();

	};
}


