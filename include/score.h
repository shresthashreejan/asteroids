#ifndef SCORE_H_
#define SCORE_H_

void UpdateScore();
void ResetScore();
void ScoreController();
int GetCurrentScore();
int LoadHighScore();
void SaveHighScore(int newScore);

#endif