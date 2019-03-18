#include "mytablewidgetitem.h"

MyTableWidgetItem::MyTableWidgetItem (QString data)
{
    m_data = data;
}

bool MyTableWidgetItem::operator <(const QTableWidgetItem &other) const
{
    return text().toInt() < other.text().toInt();
}

QVariant MyTableWidgetItem::data(int role) const
{
    if (role==Qt::EditRole)
        return m_data;
    else if (role==Qt::DisplayRole)
        return m_data;
    else if (role==Qt::TextAlignmentRole)
        return Qt::AlignRight;
    else
        return QTableWidgetItem::data(role);
}
