#include "Audio.h"


Homer::Audio::Audio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

Homer::Audio::~Audio()
{
	Mix_CloseAudio();
	if (m_SoundCache.size() > 0)
	{
		delete &m_SoundCache;
		m_SoundCache = std::map<size_t, Mix_Chunk*>();
	}
	if (m_MusicCache.size() > 0)
	{
		delete& m_MusicCache;
		m_MusicCache = std::map<size_t, Mix_Music*>();
	}
	
}

size_t Homer::Audio::LoadMusic(const std::string& filename)
{
	const size_t _musId = std::hash<std::string>()(filename);
	if (m_MusicCache.count(_musId) > 0)
	{
		return _musId;
	}

	Mix_Music* _mus = Mix_LoadMUS(filename.c_str());
	if (_mus)
	{
		m_MusicCache.emplace(_musId, _mus);
		return _musId;
	}

	return 0;
}

size_t Homer::Audio::LoadSound(const std::string& filename)
{
	const size_t _sfxId = std::hash<std::string>()(filename);
	if (m_SoundCache.count(_sfxId) > 0)
	{
		return _sfxId;
	}

	Mix_Chunk* _sfx = Mix_LoadWAV(filename.c_str());
	if (_sfx)
	{
		m_SoundCache.emplace(_sfxId, _sfx);
		return _sfxId;
	}

	return 0;
}

void Homer::Audio::PlayMusic(size_t id)
{
	PlayMusic(id, -1);
}

void Homer::Audio::PlayMusic(size_t id, int loop)
{
	Mix_PlayMusic(m_MusicCache[id], loop);
}

void Homer::Audio::PlaySFX(size_t id)
{
	PlaySFX(id, 0);
}

void Homer::Audio::PlaySFX(size_t id, int loop)
{
	Mix_PlayChannel(-1, m_SoundCache[id], loop);
}

void Homer::Audio::PauseMusic()
{
	Mix_PauseMusic();
}

void Homer::Audio::StopMusic()
{
	Mix_HaltMusic();
}

void Homer::Audio::ResumeMusic()
{
	Mix_ResumeMusic();
}

void Homer::Audio::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void Homer::Audio::SetVolume(size_t soundId, int volume)
{
	Mix_VolumeChunk(m_SoundCache[soundId], volume);
}
