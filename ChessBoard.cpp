#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rock.h"
#include "Pawn.h"

ChessBoard::ChessBoard(bool boolStd)
    {
    for (int i = 0; i < 8; i++) //체스판 NULL값으로 초기화
        {
        for (int j = 0; j < 8; j++) {
            pBoard[i][j] = 0;
        }
    }

    if (boolStd) //말 초기화(배치)
    {
        int Team = Pieces::Black;
        int Position[2] = { 0, 1 };

        for (int i = 0; i < 2; i++)
        {
            pBoard[Position[0]][3]  = new King(Team);
            pBoard[Position[0]][4]  = new Queen(Team);
            pBoard[Position[0]][2]  = new Bishop(Team);
            pBoard[Position[0]][5]  = new Bishop(Team);
            pBoard[Position[0]][1]  = new Knight(Team);
            pBoard[Position[0]][6]  = new Knight(Team);
            pBoard[Position[0]][0]  = new Rock(Team);
            pBoard[Position[0]][7]  = new Rock(Team);
            
            for (int j = 0; j < 8; j++)
            {
                pBoard[Position[1]][j] = new Pawn(Team);
            }

            Position[0] = 7;
            Position[1] = 6;
            Team = Pieces::White;
        }
    }
}

Pieces *ChessBoard::GetPiece(int x, int y) //말 선택
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
    {
        return pBoard[x][y];
    }

    return 0;
}

bool ChessBoard::MoveTo(int ax, int ay, int bx, int by) //말 이동
{
    if (pBoard[ax][ay])
    {
        delete pBoard[ax][ay];
    }

    pBoard[ax][ay] = pBoard[bx][by];

    pBoard[bx][by] = 0;

    return true;
}

ChessBoard::~ChessBoard(void) //소멸자
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pBoard[i][j] != 0)
            {
                delete pBoard[i][j];
            }
        }
    }
}
