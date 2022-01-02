#include "pPlayer.h"

pPlayer::pPlayer() {}
pPlayer::~pPlayer() {}

pPlayer::pPlayer(int x, int y, int width, int height, int red, int grn, int blu, int a, int d) :
pMovers(x, y, width, height, red, grn, blu, a), _dir(d) {}

int pPlayer::getDirection() const {
    return _dir;
    }
void pPlayer::resetDirection() {
    _dir = 0;
    }
void pPlayer::updateDirection(const int d) {
    _dir += d;
    }
