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
		static Engine& Get()
		{
			static Engine _instance;
			return _instance;
		}
		~Engine();
		bool Init(const std::string& title, int w, int h);
		void Start();
		IGFX& Gfx() const { return *m_Gfx; };
		IInput& Input() const { return *m_Input; };
		ILogger& Logger() const { return *m_Logger; }
		ISound& Sound() const { return *m_Audio; };
		IWorld& World() const { return *m_World; };
		ICollide& Collide() const { return *m_Collide; };
	private:
		void Exit();
		void Update(float dt);
		void Render();
		void Shutdown();

	private:
		IWorld* m_World = nullptr;
		ISound* m_Audio = nullptr;
		ILogger* m_Logger = nullptr;
		IGFX* m_Gfx = nullptr;
		IInput* m_Input = nullptr;
		ICollide* m_Collide = nullptr;
		bool m_IsInit;
		bool m_IsRunning;

		float SleepTime;
		float Timer;
	};

}