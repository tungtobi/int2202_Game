#include "Mixer.h"

MixManager::MixManager()
{

}

void MixManager::playMusic()
{
    bgMusic = Mix_LoadMUS(BG_MUSIC);
    Mix_PlayMusic(bgMusic, -1);
    initSounds();
}

void MixManager::initSounds()
{
    for (int i = 0; i < SOUNDS_NUMBER; i++)
    {
        sounds[i] = Mix_LoadWAV(soundPaths[i].c_str());
    }
}

void MixManager::playSoundEffect(SoundType type)
{
    if (!isMuted)
    {
        Mix_PlayChannel(-1, sounds[type], 0);
    }
}

void MixManager::muted()
{
    isMuted = !isMuted;
    if (isMuted)
    {
        Mix_PauseMusic();
        Mix_Pause(-1);
    }
    else
    {
        Mix_ResumeMusic();
        Mix_Resume(-1);
    }
}

MixManager::~MixManager()
{
    Mix_FreeMusic(bgMusic);
    bgMusic = NULL;
    for (int i = 0; i < SOUNDS_NUMBER; i++)
    {
        Mix_FreeChunk(sounds[i]);
        sounds[i] = NULL;
    }
}
