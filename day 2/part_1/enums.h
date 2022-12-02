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

enum recommendedMoves_decrypted
{
    recommendedMoves_rock = (int)'X',
    recommendedMoves_paper = (int)'Y',
    recommendedMoves_scissors = (int)'Z',
};

enum opponentMoves_decrypted
{
    opponentMoves_rock = (int)'A',
    opponentMoves_paper = (int)'B',
    opponentMoves_scissors = (int)'C',
};