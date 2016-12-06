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
        repaint(); //flush paint event before invoking potentially expensive operation
        QApplication::flush();
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

}

bool qClickableLabel::hitLabel(const QPoint &pos) const
{
    return rect().contains(pos);
}

