#include "model.h"

model::model(QObject *parent) : QObject(parent)
{
    turnNum = 0;
    percentcomplete = 0;
}

void model::nextTurn() {
    turnNum++;
    bool b = rand() % 2;
    compMove.push_back(b);
}

bool model::checksame() {
    for(unsigned long i = 0; i < playerMove.size(); i++){
        if(playerMove[i]!=compMove[i])
            return false;
    }
    return true;
}

int model::addInput(bool b){
    playerMove.push_back(b);
    bool b1 = checksame();
    percentcomplete = 100*((double)playerMove.size()/(double)compMove.size());
    if(playerMove.size() == compMove.size() && b1){
        return 2;
    }
    else if(b1){
        return 1;
    }
    else{
        return 0;
    }
}

void model::newGame(){
    turnNum = 0;
    percentcomplete = 0;
    playerMove.clear();
    compMove.clear();
}
