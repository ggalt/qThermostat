#include "qclickablelabel.h"

qClickableLabel::qClickableLabel(QWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{

}

void qClickableLabel::mousePressEvent(QMouseEvent *e)
{

}

void qClickableLabel::mouseReleaseEvent(QMouseEvent *e)
{

}

void qClickableLabel::mouseMoveEvent(QMouseEvent *e)
{

}

bool qClickableLabel::hitLabel(const QPoint &pos) const
{
    return rect().contains(pos);
}

