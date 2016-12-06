#ifndef QCLICKABLELABEL_H
#define QCLICKABLELABEL_H

#include <QObject>
#include <QLabel>
#include <QRect>
#include <QPoint>

#include <QMouseEvent>


class qClickableLabel : public QLabel
{
    Q_OBJECT

public:
    qClickableLabel(QWidget * parent = 0, Qt::WindowFlags f = 0);

signals:
    void pressed(void);
    void released(void);
    void clicked(void);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

private:
    bool hitLabel(const QPoint &pos) const;

private:
    QRect myRect;
    bool m_pressed;

};

#endif // QCLICKABLELABEL_H


//QLabel(QWidget * parent = 0, Qt::WindowFlags f = 0)
//QLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0)

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

///*!
//Returns \c true if \a pos is inside the clickable button rectangle;
//otherwise returns \c false.
//By default, the clickable area is the entire widget. Subclasses
//may reimplement this function to provide support for clickable
//areas of different shapes and sizes.
//*/
//bool QAbstractButton::hitButton(const QPoint &pos) const
//{
//    return rect().contains(pos);
//}
