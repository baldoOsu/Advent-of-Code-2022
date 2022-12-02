#pragma once

enum gameStatePoints
{
    losePoints = 0,
    winPoints = 6,
    drawPoints = 3
};

enum movePoints
{
    rockPoints = 1,
    paperPoints = 2,
    scissorsPoints = 3
};

enum opponentMoves_decrypted
{
    opponentMoves_rock = (int)'A',
    opponentMoves_paper = (int)'B',
    opponentMoves_scissors = (int)'C',
};

enum recommendedGameState_decrypted
{
    recommendedGameState_lose = (int)'X',
    recommendedGameState_draw = (int)'Y',
    recommendedGameState_win = (int)'Z',
};