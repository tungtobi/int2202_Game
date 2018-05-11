#ifndef MIXER_H_
#define MIXER_H_

#define SOUNDS_NUMBER 6

#include <iostream>
#include <vector>
#include <SDL2/SDL_mixer.h>

enum SoundType
{
    HURTED_SOUND = 0,
    EATING_SOUND,
    GAMEOVER_SOUND,
    DROP_SOUND,
    BROKEN_SOUND,
    WARNING_SOUND
};

class MixManager
{
private:
    const char* BG_MUSIC = "res/sound/backgroundMusic.wav";
    const std::string soundPaths[SOUNDS_NUMBER] =
    {
        "res/sound/hungry.wav", // hurted pig
        "res/sound/score.wav", // pig eat fruit
        "res/sound/over.wav",
        "res/sound/drop.wav",
        "res/sound/broken.wav",
        "res/sound/warning.wav"
    };
    Mix_Music* bgMusic = NULL;
    std::vector<Mix_Chunk*> sounds{SOUNDS_NUMBER, NULL};
public:
    MixManager();
    bool isMuted = false;
    void muted();
    void playMusic();
    void playSoundEffect(SoundType type);
    void initSounds();
    ~MixManager();
};

#endif // MIXER_H_
