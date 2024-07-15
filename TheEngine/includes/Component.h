#pragma once


namespace Homer
{
	class Entity;
	class IInput;
	class ILogger;
	class IGFX;
	class ISound;
	class IWorld;

	class Component
	{
	public:
		virtual ~Component() = default;
		Component();
		Component(Entity* parent);
		virtual void Start() {}
		virtual void Destroy() {}
	protected:
		void Exit();
		IInput& Input() const;
		ILogger& Logger() const;
		IGFX& Graphics() const;
		ISound& Audio() const;
		IWorld& World() const;

		Entity* m_Entity = nullptr;
	};
}



