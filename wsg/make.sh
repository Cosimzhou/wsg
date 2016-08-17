#! /bin/bash

g++ -c core/wsg-util.cpp -o out/wsg-util.o
g++ -c core/hero.cpp -o out/hero.o
g++ -c core/card.cpp -o out/card.o -Wc++11-extensions
g++ -c core/skill.cpp -o out/skill.o
g++ -c core/fsm.cpp -o out/fsm.o
g++ -c core/game.cpp -o out/game.o
g++ -c core/interact.cpp -o out/interact.o
g++ -c core/fsm-status.cpp -o out/fsm-status.o -Wc++11-extensions
g++ -c core/player.cpp -o out/player.o
g++ -c core/wound.cpp -o out/wound.o
g++ -c main.cpp -o out/main.o

cd out
g++ wsg-util.o hero.o card.o skill.o fsm.o game.o interact.o fsm-status.o player.o wound.o main.o -o exe
