#ifndef POINTDECOURBE_H
#define POINTDECOURBE_H

#include <QPointF>

class PointDeCourbe : public QPointF
{
public:
  PointDeCourbe(qreal x,qreal y);
  PointDeCourbe();
  bool operator < (const QPointF &point);
};

#endif // POINTDECOURBE_H
