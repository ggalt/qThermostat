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


/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::paint
/// \param painter
/// \param option
/// \param index
///

void thermoEventDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                         const QModelIndex &index) const
{
    QStyleOptionViewItemV4 opt = option;
    initStyleOption(&opt, index);

//    QString str_targetTemp = index.model()->data(index.model()->index(index.row(),))
    thermoEventListModel *tempModel = dynamic_cast<thermoEventListModel*>index.model();
    thermostatEvent *tempEvent = dynamic_cast<thermostatEvent*>tempModel->data(index,Qt::DisplayRole);


    QString line0 = index.model()->data(index.model()->index(index.row(), 1)).toString();
    QString line1 = index.model()->data(index.model()->index(index.row(), 2)).toString();

    // draw correct background
    opt.text = "";
    QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, opt.widget);

    QRect rect = opt.rect;
    QPalette::ColorGroup cg = opt.state & QStyle::State_Enabled ? QPalette::Normal : QPalette::Disabled;
    if (cg == QPalette::Normal && !(opt.state & QStyle::State_Active))
        cg = QPalette::Inactive;

    // set pen color
    if (opt.state & QStyle::State_Selected)
        painter->setPen(opt.palette.color(cg, QPalette::HighlightedText));
    else
        painter->setPen(opt.palette.color(cg, QPalette::Text));

    // draw 2 lines of text
    painter->drawText(QRect(rect.left(), rect.top(), rect.width(), rect.height()/2),
                      opt.displayAlignment, line0);
    painter->drawText(QRect(rect.left(), rect.top()+rect.height()/2, rect.width(), rect.height()/2),
                      opt.displayAlignment, line1);
}

QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    QSize result = QStyledItemDelegate::sizeHint(option, index);
    result.setHeight(result.height()*2);
    return result;
}
};
/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::sizeHint
/// \param option
/// \param index
/// \return
///

QSize thermoEventDelegate::sizeHint(const QStyleOptionViewItem &option,
                             const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::createEditor
/// \param parent
/// \param option
/// \param index
/// \return
///
QWidget *thermoEventDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const

{
    return QStyledItemDelegate::createEditor(parent, option, index);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::setEditorData
/// \param editor
/// \param index
///
void thermoEventDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::setModelData
/// \param editor
/// \param model
/// \param index
///
void thermoEventDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}


/////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief thermoEventDelegate::commitAndCloseEditor
///

void thermoEventDelegate::commitAndCloseEditor()
{
}
