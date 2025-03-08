#include "raylib.h"

static Music loopingSound;
static Sound deathSound;
static Sound fireSound;
static Sound explosionSound;

void LoadAllSounds(void) {
    loopingSound = LoadMusicStream("./assets/sounds/Mesmerizing-Galaxy-Loop.ogg");
    deathSound = LoadSound("./assets/sounds/Death-Sound.mp3");
    fireSound = LoadSound("./assets/sounds/Laser.mp3");
    explosionSound = LoadSound("./assets/sounds/Explosion.mp3");
}

void UnloadAllSounds(void) {
    UnloadMusicStream(loopingSound);
    UnloadSound(deathSound);
    UnloadSound(fireSound);
    UnloadSound(explosionSound);
    CloseAudioDevice();
}

void UpdateLoopingSound(void) {
    UpdateMusicStream(loopingSound);
}

void SoundController(void) {
    InitAudioDevice();
    LoadAllSounds();
    SetMusicVolume(loopingSound, 0.5f);
    loopingSound.looping = true;
	PlayMusicStream(loopingSound);
}

void PlayDeathSound(void) {
    SetSoundVolume(deathSound, 1.5f);
    PlaySound(deathSound);
}

void PlayFireSound(void) {
    SetSoundVolume(fireSound, 0.75f);
    PlaySound(fireSound);
}

void PlayExplosionSound(void) {
    SetSoundVolume(explosionSound, 0.5f);
    PlaySound(explosionSound);
}