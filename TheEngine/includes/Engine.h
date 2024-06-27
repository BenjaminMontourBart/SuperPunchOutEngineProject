#pragma once
#include <string>
#include "IGFX.h"
#include "IInput.h"
#include "ILogger.h"
#include "ISound.h"
#include "ICollide.h"
#include "IWorld.h"


namespace Homer {
	class Engine final {
	public:
		static Engine& Get();
		~Engine();
		bool Init(const std::string& title, int w, int h);
		void Start();
		void Exit(bool exit);
		IGFX& Gfx() { return *m_Gfx; };
		IInput& Input() { return *m_Input; };
		ISound& Sound() { return *m_Audio; };
		IWorld& World() { return *m_World; };
		ICollide& Collide() { return *m_Collide; };

	private:
		void Update(float dt);
		void Render();
		void Shutdown();

	private:
		IWorld* m_World;
		ISound* m_Audio;
		ILogger* m_Logger;
		IGFX* m_Gfx = nullptr;
		IInput* m_Input = nullptr;
		ICollide* m_Collide;
		bool m_IsInit;
		bool m_IsRunning;

		float SleepTime;
		float Timer;
	};

}