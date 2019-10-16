#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <vector>
#include <random>

class model : public QObject
{
    Q_OBJECT
public:
    explicit model(QObject *parent = nullptr);
    int turnNum;
    std::vector<bool> compMove;
    int percentcomplete;
    void nextTurn();
   int addInput(bool b);
   void newGame();

signals:

public slots:

private:
    bool checksame();
    std::vector<bool> playerMove;
};

#endif // MODEL_H
