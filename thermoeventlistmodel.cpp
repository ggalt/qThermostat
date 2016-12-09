#include "thermoeventlistmodel.h"

thermoEventListModel::thermoEventListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

thermoEventListModel::~thermoEventListModel()
{

}


int thermoEventListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant thermoEventListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if( row < 0 || row >= m_data.count() ) {    // make sure it's a sane request
        return QVariant();
    }

    QVariant retVal = QVariant::fromValue( m_data.value(row) );

    return retVal;
}

//QHash<int, QByteArray> thermoEventListModel::roleNames() const {

//    QHash<int, QByteArray> roles;
//    roles[valueRole]         = "valueRole";
//    return roles;
//}

int thermoEventListModel::addEvent(thermostatEvent *event)
{
    m_data.append(event);
    return m_data.count();
}


//void thermoEventDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
//                         const QModelIndex &index) const
//{
//    if (index.data().canConvert<QTime>()) {
//        StarRating starRating = qvariant_cast<StarRating>(index.data());

//        if (option.state & QStyle::State_Selected)
//            painter->fillRect(option.rect, option.palette.highlight());

//        starRating.paint(painter, option.rect, option.palette,
//                         StarRating::ReadOnly);
//    } else {
//        QStyledItemDelegate::paint(painter, option, index);
//    }
//}

//QSize thermoEventDelegate::sizeHint(const QStyleOptionViewItem &option,
//                             const QModelIndex &index) const
//{
//    if (index.data().canConvert<QTime>()) {
//        StarRating starRating = qvariant_cast<StarRating>(index.data());
//        return starRating.sizeHint();
//    } else {
//        return QStyledItemDelegate::sizeHint(option, index);
//    }
//}

//QWidget *thermoEventDelegate::createEditor(QWidget *parent,
//                                    const QStyleOptionViewItem &option,
//                                    const QModelIndex &index) const

//{
//    if (index.data().canConvert<StarRating>()) {
//        StarEditor *editor = new StarEditor(parent);
//        connect(editor, &StarEditor::editingFinished,
//                this, &thermoEventDelegate::commitAndCloseEditor);
//        return editor;
//    } else {
//        return QStyledItemDelegate::createEditor(parent, option, index);
//    }
//}

//void thermoEventDelegate::setEditorData(QWidget *editor,
//                                 const QModelIndex &index) const
//{
//    if (index.data().canConvert<StarRating>()) {
//        StarRating starRating = qvariant_cast<StarRating>(index.data());
//        StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
//        starEditor->setStarRating(starRating);
//    } else {
//        QStyledItemDelegate::setEditorData(editor, index);
//    }
//}

//void thermoEventDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
//                                const QModelIndex &index) const
//{
//    if (index.data().canConvert<StarRating>()) {
//        StarEditor *starEditor = qobject_cast<StarEditor *>(editor);
//        model->setData(index, QVariant::fromValue(starEditor->starRating()));
//    } else {
//        QStyledItemDelegate::setModelData(editor, model, index);
//    }
//}

//void thermoEventDelegate::commitAndCloseEditor()
//{
//    StarEditor *editor = qobject_cast<StarEditor *>(sender());
//    emit commitData(editor);
//    emit closeEditor(editor);
//}
