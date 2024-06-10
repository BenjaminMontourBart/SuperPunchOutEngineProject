#include "Audio.h"

Audio::Audio()
{
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	music = Mix_LoadMUS("CottonEyeJoe.mp3");
	sound = Mix_LoadWAV("Chipeur.mp3");
	
}

Audio::~Audio()
{
	Mix_CloseAudio();
}

size_t Audio::LoadMusic(const std::string& filename)
{
	return size_t();
}

size_t Audio::LoadSound(const std::string& filename)
{
	return size_t();
}

void Audio::PlayMusic(size_t id)
{
	Mix_PlayMusic(music, id);
}

void Audio::PlayMusic(size_t id, int loop)
{
}

void Audio::PlaySFX(size_t id)
{
	if (!Mix_Playing(1))
	{
		Mix_PlayChannel(-1, sound, id);

	}
}

void Audio::PlaySFX(size_t id, int loop)
{
}

void Audio::PauseMusic()
{
}

void Audio::StopMusic()
{
}

void Audio::ResumeMusic()
{
}

void Audio::SetVolume(int volume)
{
	sound->volume = volume;
}

void Audio::SetVolume(size_t soundId, int volume)
{
}
