#include <iostream>
#include "Chess.h"

int main()
{
    setlocale(LC_ALL, "RUS");

    Chess chess;

    Result* res1 = new Russian_Championship("11.11.11", 5);
    Result* res2 = new Russian_Championship("11.11.11", 1);

    Result* res3 = new European_championship("17.10.12", 6);
    Result* res4 = new European_championship("17.10.12", 2);

    Result* res5 = new World_cup("29.04.13", 4);
    Result* res6 = new World_cup("29.04.13", 3);

    Player a("Петров ", 2000, "Россия ", "Мастер спорта ", 1032);
    a.addResults(res1);
    a.addResults(res3);
    a.addResults(res5);
    Player b("Иванов ", 2000, "Россия ", "Мастер спорта ", 1047);
    b.addResults(res2);
    b.addResults(res4);
    b.addResults(res6);

    chess.addChessPlayer(a);
    chess.addChessPlayer(b);

    chess.getChessPlayer();

    return 0;
}
