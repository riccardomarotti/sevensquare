/*
 * cubecellitem.cpp
 *
 * Copyright 2012-2012 Yang Hong
 *
 */

#include <QDebug>
#include <QPainter>

#include "cubescene.h"
#include "cubecellitem.h"

CubeCellItem::CubeCellItem()
{
    cube = 0;
    virtual_key = 0;
}

CubeCellItem::CubeCellItem(const QPixmap &pixmap) :
    pixmap(pixmap),
    cube(0),
    virtual_key(0)
{
    //setFlag(QGraphicsItem::ItemIsSelectable);
    //setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF CubeCellItem::boundingRect() const
{
    return QRectF(pixmap.rect());
}

void CubeCellItem::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (pixmap.isNull()) {
        return;
    }

    painter->drawPixmap(pixmap.rect(), pixmap);
}

void CubeCellItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug() << "Cell Item pressed: " << virtual_key;
    setCubePos(QPoint(1.5, 1) + curr_pos);
}

void CubeCellItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

void CubeCellItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCubePos(curr_pos - QPoint(1.5, 1));
    //qDebug() << "Cell Item released: " << virtual_key;

    if (cube) {
        cube->sendVirtualKey(virtual_key);
    }
}
