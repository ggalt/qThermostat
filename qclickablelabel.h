#ifndef QCLICKABLELABEL_H
#define QCLICKABLELABEL_H

#include <QObject>
#include <QLabel>


class qClickableLabel : public QLabel
{
    Q_OBJECT

public:
    qClickableLabel();
};

#endif // QCLICKABLELABEL_H


//void QAbstractButton::mousePressEvent(QMouseEvent *e)
//{
//    Q_D(QAbstractButton);
//    if (e->button() != Qt::LeftButton) {
//        e->ignore();
//        return;
//    }
//    if (hitButton(e->pos())) {
//        setDown(true);
//        d->pressed = true;
//        repaint(); //flush paint event before invoking potentially expensive operation
//        QApplication::flush();
//        d->emitPressed();
//        e->accept();
//    } else {
//        e->ignore();
//    }
//}

///*! \reimp */
//void QAbstractButton::mouseReleaseEvent(QMouseEvent *e)
//{
//    Q_D(QAbstractButton);
//    d->pressed = false;

//    if (e->button() != Qt::LeftButton) {
//        e->ignore();
//        return;
//    }

//    if (!d->down) {
//        // refresh is required by QMacStyle to resume the default button animation
//        d->refresh();
//        e->ignore();
//        return;
//    }

//    if (hitButton(e->pos())) {
//        d->repeatTimer.stop();
//        d->click();
//        e->accept();
//    } else {
//        setDown(false);
//        e->ignore();
//    }
//}

///*! \reimp */
//void QAbstractButton::mouseMoveEvent(QMouseEvent *e)
//{
//    Q_D(QAbstractButton);
//    if (!(e->buttons() & Qt::LeftButton) || !d->pressed) {
//        e->ignore();
//        return;
//    }

//    if (hitButton(e->pos()) != d->down) {
//        setDown(!d->down);
//        repaint(); //flush paint event before invoking potentially expensive operation
//        QApplication::flush();
//        if (d->down)
//            d->emitPressed();
//        else
//            d->emitReleased();
//        e->accept();
//    } else if (!hitButton(e->pos())) {
//        e->ignore();
//    }
//}

