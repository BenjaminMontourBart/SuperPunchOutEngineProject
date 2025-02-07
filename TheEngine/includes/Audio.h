#pragma once
#include "ISound.h"
#include "SDL_mixer.h"
#include <map>

namespace Homer
{
	class Audio : public ISound
	{
	public:
		Audio();
		~Audio();
		virtual size_t LoadMusic(const std::string& filename);
		virtual size_t LoadSound(const std::string& filename);
		virtual void PlayMusic(size_t id);
		virtual void PlayMusic(size_t id, int loop);
		virtual void PlaySFX(size_t id);
		virtual void PlaySFX(size_t id, int loop);
		virtual void PauseMusic();
		virtual void StopMusic();
		virtual void ResumeMusic();
		virtual void SetVolume(int volume);
		virtual void SetVolume(size_t soundId, int volume);
	private:
		std::map<size_t, Mix_Chunk*> m_SoundCache;
		std::map<size_t, Mix_Music*> m_MusicCache;

	};
}

