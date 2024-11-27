#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{}
{
    //cur_time = 0. ;
    //qTimer = new QTimer(this);
}
Stopwatch::~Stopwatch()
{
    qDebug() << "Signals delete";
}

/*void Stopwatch::sig_SendCircle(int m_, int s_, int ms_)
{
    m_ = m;
    s_ = s;
    ms_ = ms;
}*/
