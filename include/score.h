#ifndef SCORE_H_
#define SCORE_H_

void UpdateScore(void);
void ResetScore(void);
void ScoreController(void);
int GetCurrentScore(void);
int LoadHighScore(void);
void SaveHighScore(int newScore);

#endif