#include <QApplication>
#include <QPainter>
#include <QBrush>
#include <QColor>
#include <QGradient>

#include "qclickablelabel.h"

qClickableLabel::qClickableLabel(QWidget *parent, Qt::WindowFlags f) : QLabel(parent, f)
{

}

void qClickableLabel::mousePressEvent(QMouseEvent *e)
{
    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if (hitLabel(e->pos())) {
        m_pressed = true;
        emit pressed();
        e->accept();
    } else {
        e->ignore();
    }
}

void qClickableLabel::mouseReleaseEvent(QMouseEvent *e)
{
    bool curPressStatus = m_pressed; // preserve state for later
    m_pressed = false;

    if (e->button() != Qt::LeftButton) {
        e->ignore();
        return;
    }

    if (hitLabel(e->pos())) {
        emit released();
        if( curPressStatus )
            emit clicked();
        e->accept();
    } else {
        e->ignore();
    }
}

void qClickableLabel::mouseMoveEvent(QMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton) || !m_pressed) {
        e->ignore();
        return;
    }

    if (hitLabel(e->pos()) != m_pressed) {
        if (m_pressed)
            emit pressed();
        else
            emit released();
        e->accept();
    } else if (!hitLabel(e->pos())) {
        e->ignore();
    }
}

bool qClickableLabel::hitLabel(const QPoint &pos) const
{
    return rect().contains(pos);
}

