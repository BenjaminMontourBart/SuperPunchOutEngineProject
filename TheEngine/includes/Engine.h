#pragma once
#include <string>
#include "Game.h"


namespace Homer {
	class Engine final {
	public:
		bool Init(const std::string& title, int w, int h);
		void Start();
		void Exit();

	private:
		void Update(float dt);
		void Render();
		void Shutdown();

	private:

		Game* m_Game;
		bool m_IsInit;
		bool m_IsRunning;

		float SleepTime;
		float Timer;
	};

}